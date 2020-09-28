// TP Graphes.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Graph.h"

using std::cout;
using std::endl;

int main()
{
	graphe_t mon_graphe;
	solution_t ma_solution;
	int ordre[NBMAX_SOMMETS+1] = { 0 }, ordre2[NBMAX_SOMMETS+1] = { 0 };
	int ordreGris[NBMAX_SOMMETS + 1] = {0,8,26,41,58,60,95,114,155,168,148,199,207},
		ordreGrisInv[NBMAX_SOMMETS + 1] = {0,207,199,148,168,155,114,95,60,58,41,26,8};
	std::ifstream stream("graph.dat");
	int nbArcs, nbSommets;
	std::string buffer;

	// initialisation ordres
	ordre[1] = 1;
	ordre2[1] = 1;
	ordre[210] = 210;
	ordre2[210] = 210;
	for (int i = 2; i < NBMAX_SOMMETS; i++)
	{
		ordre[i] = i; // 1, 2, ..., 209, 210
		ordre2[i] = NBMAX_SOMMETS + 1 - i; // 1, 209, 208, ..., 3, 2, 210
	}	

	if (stream) {
		/* LECTURE GRAPHE */
		stream >> nbSommets;
		mon_graphe.n = nbSommets;
		stream >> nbArcs;
		// lecture des successeurs
		for (int i = 1; i <= nbSommets; i++)
		{
			int cpt = 0;
			stream >> buffer;
			while (buffer != "*")
			{
				cpt++;
				mon_graphe.s[i][cpt] = stoi(buffer);
				stream >> buffer;
			}
			mon_graphe.ns[i] = cpt;
		}
		// lecture des arcs
		for (int i = 1, numSucc=1, srcPrec=-1; i <= nbArcs; i++)
		{	
			int src;
			float poids;
			stream >> src >> poids;
			numSucc = (srcPrec == src) ? numSucc + 1 : 1;
			mon_graphe.l[src][numSucc] = poids;
			srcPrec = src;
		}
		/* FIN LECTURE */


		for (int i = 1; i < 13; i++)
		{
			calculer_chemin(mon_graphe, ordreGris[i], -1, ma_solution);
			for (int j = 1; j <= 13; j++)
			{
				afficher_solution(ma_solution, ordreGris[j]);
			}
			cout << endl;
		}

		//calculer_chemin(mon_graphe, 207, 8, ma_solution);
		//Bellman(mon_graphe, ordre, ma_solution);
		//Bellman(mon_graphe, ordre2, ma_solution);
		//afficher_solution(ma_solution, 8);
	}



	/*initGraphe(mon_graphe);
	//calculer_chemin(mon_graphe, 1, 9, ma_solution);
	//Bellman(mon_graphe, ordre, , ma_solution);
	afficher_solution(ma_solution, 9);*/
}

