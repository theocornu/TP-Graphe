// TP Graphes.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include "Graph.h"


int main()
{
	graphe_t mon_graphe;
	solution_t ma_solution;

	initGraphe(mon_graphe);
	calculer_chemin(mon_graphe, 1, 9, ma_solution);
	afficher_solution(ma_solution, 9);
}

