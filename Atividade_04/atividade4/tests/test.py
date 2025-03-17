#! /usr/bin/python3
# -*- coding: utf-8 -*-
import os
import subprocess
from subprocess import PIPE
from ctypes import CDLL, Structure, c_double, c_int, c_wchar_p, c_char, byref, POINTER

class Gps(Structure):
    _fields_ = [("lat", c_double),
                ("lon", c_double),
                ("alt", c_double),
                ("tempo", c_int),]


def test_compile(fname):
    command = ['gcc', fname, '-o', 'dll/gps.so', '-fPIC', '-shared']
    result = subprocess.run(command,
            stdin=PIPE,
            stdout=PIPE,
            stderr=PIPE,
            encoding='utf-8')
    return result.returncode

def test_troca_char(clib):
    troca_char = clib.troca_char
    inp = (c_char*100)(*"24,177;47,024;98;0".encode('utf-8'))
    exp = (c_char*100)(*"24.177;47.024;98;0".encode('utf-8'))
    troca_char.argtypes = [c_char*100, c_char, c_char]
    troca_char(inp, 
            c_char(','.encode('utf-8')), 
            c_char('.'.encode('utf-8')))
    if(inp.value == exp.value):
        print("[SUCESSO] Função validada =)")
    else:
        print(f"[ERRO] Esperava 'linha = {exp}', recebi 'linha = {inp}'")

def test_ler_ponto(clib):
    ler_ponto = clib.ler_ponto
    linha = (c_char*100)(*"24,177;47,024;98;0".encode('utf-8'))
    inp = Gps(0, 0, 0, 0)
    exp = Gps(24.177,47.024,98,0)
    ler_ponto.argtypes = [c_char*100, POINTER(Gps)]
    ler_ponto(linha, byref(inp))
    if(all([inp.lat == exp.lat, inp.lon == exp.lon])):
        print("[SUCESSO] Função validada =)")
    else:
        print(f"[ERRO] Esperava ({exp.lat, exp.lon, exp.alt, exp.tempo}), recebi ({inp.lat, inp.lon, inp.alt, inp.tempo})")

def test_calcula_distancia(clib):
    calcula_distancia = clib.calcula_distancia
    calcula_distancia.argtypes = [Gps, Gps]
    calcula_distancia.restype = c_double
    out = calcula_distancia(Gps(-24.177337, -47.024178, 98, 0), Gps(-24.177353, -47.024119, 97, 1))
    if(6 <= out <= 6.5):
        print("[SUCESSO] Função validada =)")
    else:
        print(f"[ERRO] Esperava ~{6.32}, recebi {out}")

def test_calcula_velocidade(clib):
    calcula_velocidade = clib.calcula_velocidade
    calcula_velocidade.argtypes = [Gps, Gps]
    calcula_velocidade.restype = c_double
    out = calcula_velocidade(Gps(-24.177337, -47.024178, 98, 0), Gps(-24.177353, -47.024119, 97, 1))
    if(22 <= out <= 23):
        print("[SUCESSO] Função validada =)")
    else:
        print(f"[ERRO] Esperava ~{22.77}, recebi {out}")

def test_ler_arquivo(clib):
    ler_arquivo = clib.ler_arquivo
    ler_arquivo.argtypes = [c_char*100, Gps*4]
    ler_arquivo.restype = c_int
    gps_in = (Gps*4)(Gps(0,0,0,0), Gps(0,0,0,0), Gps(0,0,0,0), Gps(0,0,0,0))
    out = ler_arquivo((c_char*100)(*"tests/teste.csv".encode('utf-8')), gps_in)
    if(out == 4):
        print("[SUCESSO] Função validada =)")
    else:
        print(f"[ERRO] Esperava ler 4 dados, mas recebi {out}")


def main():
    print("[TESTE] Verificando compilação...")
    if test_compile("src/gps.c") == 0:
        print("[SUCESSO] Atividade compilada com sucesso")
    else:
        print("[ERRO] Erro ao compilar atividade. Verifique com 'make gps'")
        return 1
    clib = CDLL("dll/gps.so")
    print("[TESTE] Verificando função troca_char...")
    test_troca_char(clib)
    print("[TESTE] Verificando função ler_ponto...")
    test_ler_ponto(clib)
    print("[TESTE] Verificando função calcula_distancia...")
    test_calcula_distancia(clib)
    print("[TESTE] Verificando função calcula_velocidade...")
    test_calcula_velocidade(clib)
    print("[TESTE] Verificando função ler_arquivo...")
    test_ler_arquivo(clib)
    print("[TESTE] Testando a função main...")
    clib.main()
    try:
        with open('gabarito.csv', 'r') as gabarito, open('saida.csv', 'r') as saida:
            if gabarito.readlines() == saida.readlines():
                print("[SUCESSO] main validado com sucesso =)")
            else:
                print("[ERRO] Há alguma diferença entre os arquivos 'saida.csv' e 'gabarito.csv'")

    except OSError:
        print("[ERRO] Arquivos não encontrados. Verifique se está lendo 'entrada.csv' e salvando em 'saida.csv'. Também verifique se tem um arquivo 'gabarito.csv'.")



if __name__ == "__main__":
    main()
