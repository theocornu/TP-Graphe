#include <iostream>
#include "Graph.h"


void initGraphe(graphe_t& graphe) {
	graphe.n = 9;

	graphe.ns[1] = 2;
	graphe.s[1][1] = 4;
	graphe.l[1][1] = 4;
	graphe.s[1][2] = 2;
	graphe.s[1][2] = 10;

	graphe.ns[2] = 2;
	graphe.s[2][1] = 3;
	graphe.l[2][1] = 1;
	graphe.s[2][2] = 5;
	graphe.l[2][2] = 2;

	graphe.ns[3] = 2;
	graphe.s[3][1] = 6;
	graphe.l[3][1] = 4;
	graphe.s[3][2] = 8;
	graphe.l[3][2] = 2;

	graphe.ns[4] = 1;
	graphe.s[4][1] = 6;
	graphe.l[4][1] = 12;

	graphe.ns[5] = 2;
	graphe.s[5][1] = 3;
	graphe.l[5][1] = 9;
	graphe.s[5][2] = 8;
	graphe.l[5][2] = 3;

	graphe.ns[6] = 1;
	graphe.s[6][1] = 7;
	graphe.l[6][1] = 5;

	graphe.ns[7] = 2;
	graphe.s[7][1] = 9;
	graphe.l[7][1] = 3;
	graphe.s[7][2] = 8;
	graphe.l[7][2] = 3;

	graphe.ns[8] = 1;
	graphe.s[8][1] = 9;
	graphe.l[8][1] = 3;

	graphe.ns[9] = 0;
}

// M�thode de Djikstra
void calculer_chemin(graphe_t& graphe, int start, int end, solution_t& solution) {
	int nb_sommets = graphe.n;
	int T[NBMAX_SOMMETS] = { 0 };

	for (int i = 1; i <= n; i++) {
		solution.m[i] = INF;
		solution.pere[i] = -1;
	}
	solution.m[start] = 0;Z


	for (int i = 1; i <= n; i++) {
		int min = INF, imin = -1;
		// Recherche sommet avec marque min et non trait�
		for (int j = 1; j <= n; j++) {
			int marque_cour = solution.m[j];
			if (marque_cour < min && T[j] == 0) {
				min = marque_cour;
				imin = j;
			}
		}
		int nb_succ = graphe.ns[imin];
		int marque_min = solution.m[imin];
		// Actualisation de la solution
		for (int j = 1; j <= nb_succ; j++) {
			int k = graphe.s[imin][j];
			int cout_succ = graphe.l[imin][k];
			int marque_succ = solution.m[k];
			if (marque_min + cout_succ < marque_succ) {
				solution.m[k] = marque_min + cout_succ;
				solution.pere[k] = imin;
			}
		}
		// Sommet imin trait�
		T[imin] = 1;
	}
}

void afficher_solution(solution_t& solution) {

}