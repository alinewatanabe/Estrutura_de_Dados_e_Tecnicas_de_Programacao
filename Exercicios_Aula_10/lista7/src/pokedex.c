#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "pokedex.h"

Pokemon _pokemons[151] = {
    {"Bulbasaur", 45, 49, 49, 45},
    {"Ivysaur", 60, 62, 63, 60},
    {"Venusaur", 80, 82, 83, 80},
    {"Charmander", 39, 52, 43, 65},
    {"Charmeleon", 58, 64, 58, 80},
    {"Charizard", 78, 84, 78, 100},
    {"Squirtle", 44, 48, 65, 43},
    {"Wartortle", 59, 63, 80, 58},
    {"Blastoise", 79, 83, 100, 78},
    {"Caterpie", 45, 30, 35, 45},
    {"Metapod", 50, 20, 55, 30},
    {"Butterfree", 60, 45, 50, 70},
    {"Weedle", 40, 35, 30, 50},
    {"Kakuna", 45, 25, 50, 35},
    {"Beedrill", 65, 90, 40, 75},
    {"Pidgey", 40, 45, 40, 56},
    {"Pidgeotto", 63, 60, 55, 71},
    {"Pidgeot", 83, 80, 75, 101},
    {"Rattata", 30, 56, 35, 72},
    {"Raticate", 55, 81, 60, 97},
    {"Spearow", 40, 60, 30, 70},
    {"Fearow", 65, 90, 65, 100},
    {"Ekans", 35, 60, 44, 55},
    {"Arbok", 60, 85, 69, 80},
    {"Pikachu", 35, 55, 40, 90},
    {"Raichu", 60, 90, 55, 110},
    {"Sandshrew", 50, 75, 85, 40},
    {"Sandslash", 75, 100, 110, 65},
    {"Nidoran_F", 55, 47, 52, 41},
    {"Nidorina", 70, 62, 67, 56},
    {"Nidoqueen", 90, 92, 87, 76},
    {"Nidoran_M", 46, 57, 40, 50},
    {"Nidorino", 61, 72, 57, 65},
    {"Nidoking", 81, 102, 77, 85},
    {"Clefairy", 70, 45, 48, 35},
    {"Clefable", 95, 70, 73, 60},
    {"Vulpix", 38, 41, 40, 65},
    {"Ninetales", 73, 76, 75, 100},
    {"Jigglypuff", 115, 45, 20, 20},
    {"Wigglytuff", 140, 70, 45, 45},
    {"Zubat", 40, 45, 35, 55},
    {"Golbat", 75, 80, 70, 90},
    {"Oddish", 45, 50, 55, 30},
    {"Gloom", 60, 65, 70, 40},
    {"Vileplume", 75, 80, 85, 50},
    {"Paras", 35, 70, 55, 25},
    {"Parasect", 60, 95, 80, 30},
    {"Venonat", 60, 55, 50, 45},
    {"Venomoth", 70, 65, 60, 90},
    {"Diglett", 10, 55, 25, 95},
    {"Dugtrio", 35, 80, 50, 120},
    {"Meowth", 40, 45, 35, 90},
    {"Persian", 65, 70, 60, 115},
    {"Psyduck", 50, 52, 48, 55},
    {"Golduck", 80, 82, 78, 85},
    {"Mankey", 40, 80, 35, 70},
    {"Primeape", 65, 105, 60, 95},
    {"Growlithe", 55, 70, 45, 60},
    {"Arcanine", 90, 110, 80, 95},
    {"Poliwag", 40, 50, 40, 90},
    {"Poliwhirl", 65, 65, 65, 90},
    {"Poliwrath", 90, 95, 95, 70},
    {"Abra", 25, 20, 15, 90},
    {"Kadabra", 40, 35, 30, 105},
    {"Alakazam", 55, 50, 45, 120},
    {"Machop", 70, 80, 50, 35},
    {"Machoke", 80, 100, 70, 45},
    {"Machamp", 90, 130, 80, 55},
    {"Bellsprout", 50, 75, 35, 40},
    {"Weepinbell", 65, 90, 50, 55},
    {"Victreebel", 80, 105, 65, 70},
    {"Tentacool", 40, 40, 35, 70},
    {"Tentacruel", 80, 70, 65, 100},
    {"Geodude", 40, 80, 100, 20},
    {"Graveler", 55, 95, 115, 35},
    {"Golem", 80, 120, 130, 45},
    {"Ponyta", 50, 85, 55, 90},
    {"Rapidash", 65, 100, 70, 105},
    {"Slowpoke", 90, 65, 65, 15},
    {"Slowbro", 95, 75, 110, 30},
    {"Magnemite", 25, 35, 70, 45},
    {"Magneton", 50, 60, 95, 70},
    {"Farfetch'd", 52, 65, 55, 60},
    {"Doduo", 35, 85, 45, 75},
    {"Dodrio", 60, 110, 70, 100},
    {"Seel", 65, 45, 55, 45},
    {"Dewgong", 90, 70, 80, 70},
    {"Grimer", 80, 80, 50, 25},
    {"Muk", 105, 105, 75, 50},
    {"Shellder", 30, 65, 100, 40},
    {"Cloyster", 50, 95, 180, 70},
    {"Gastly", 30, 35, 30, 80},
    {"Haunter", 45, 50, 45, 95},
    {"Gengar", 60, 65, 60, 110},
    {"Onix", 35, 45, 160, 70},
    {"Drowzee", 60, 48, 45, 42},
    {"Hypno", 85, 73, 70, 67},
    {"Krabby", 30, 105, 90, 50},
    {"Kingler", 55, 130, 115, 75},
    {"Voltorb", 40, 30, 50, 100},
    {"Electrode", 60, 50, 70, 140},
    {"Exeggcute", 60, 40, 80, 40},
    {"Exeggutor", 95, 95, 85, 55},
    {"Cubone", 50, 50, 95, 35},
    {"Marowak", 60, 80, 110, 45},
    {"Hitmonlee", 50, 120, 53, 87},
    {"Hitmonchan", 50, 105, 79, 76},
    {"Lickitung", 90, 55, 75, 30},
    {"Koffing", 40, 65, 95, 35},
    {"Weezing", 65, 90, 120, 60},
    {"Rhyhorn", 80, 85, 95, 25},
    {"Rhydon", 105, 130, 120, 40},
    {"Chansey", 250, 5, 5, 50},
    {"Tangela", 65, 55, 115, 60},
    {"Kangaskhan", 105, 95, 80, 90},
    {"Horsea", 30, 40, 70, 60},
    {"Seadra", 55, 65, 95, 85},
    {"Goldeen", 45, 67, 60, 63},
    {"Seaking", 80, 92, 65, 68},
    {"Staryu", 30, 45, 55, 85},
    {"Starmie", 60, 75, 85, 115},
    {"Mr. Mime", 40, 45, 65, 90},
    {"Scyther", 70, 110, 80, 105},
    {"Jynx", 65, 50, 35, 95},
    {"Electabuzz", 65, 83, 57, 105},
    {"Magmar", 65, 95, 57, 93},
    {"Pinsir", 65, 125, 100, 85},
    {"Tauros", 75, 100, 95, 110},
    {"Magikarp", 20, 10, 55, 80},
    {"Gyarados", 95, 125, 79, 81},
    {"Lapras", 130, 85, 80, 60},
    {"Ditto", 48, 48, 48, 48},
    {"Eevee", 55, 55, 50, 55},
    {"Vaporeon", 130, 65, 60, 65},
    {"Jolteon", 65, 65, 60, 130},
    {"Flareon", 65, 130, 60, 65},
    {"Porygon", 65, 60, 70, 40},
    {"Omanyte", 35, 40, 100, 35},
    {"Omastar", 70, 60, 125, 55},
    {"Kabuto", 30, 80, 90, 55},
    {"Kabutops", 60, 115, 105, 80},
    {"Aerodactyl", 80, 105, 65, 130},
    {"Snorlax", 160, 110, 65, 30},
    {"Articuno", 90, 85, 100, 85},
    {"Zapdos", 90, 90, 85, 100},
    {"Moltres", 90, 100, 90, 90},
    {"Dratini", 41, 64, 45, 50},
    {"Dragonair", 61, 84, 65, 70},
    {"Dragonite", 91, 134, 95, 80},
    {"Mewtwo", 106, 110, 90, 130},
    {"Mew", 100, 100, 100, 100}
};

void GerarTimes(Pokemon p1[6], Pokemon p2[6]) {
    int i, j, pos;
    int jafoi[151];
    srand((unsigned)time(NULL));

    for (i = 0; i < 151; i++) {
        jafoi[i] = 0;
        for (j = strlen(_pokemons[i].Nome); j < 20; j++)
            _pokemons[i].Nome[j] = ' ';
        _pokemons[i].Nome[j - 1] = '\0';
    }

    for (i = 0; i < 6; i++) {
        do
            pos = rand() % 151;
        while (jafoi[pos] != 0);
        jafoi[pos] = 1;

        p1[i] = _pokemons[pos];

        do
            pos = rand() % 151;
        while (jafoi[pos] != 0);
        jafoi[pos] = 1;

        p2[i] = _pokemons[pos];
    }
}

