// TP Graphes.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include "Graph.h"


int main()
{
	graphe_t mon_graphe;
	solution_t ma_solution;
	int ordre[NBMAX_SOMMETS] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	initGraphe(mon_graphe);
	//calculer_chemin(mon_graphe, 1, ma_solution);
	Bellman(mon_graphe, ordre, ma_solution);
	afficher_solution(ma_solution, 9);
}

