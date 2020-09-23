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
	int ordre[NBMAX_SOMMETS] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::ifstream stream("graph.dat");
	int nbArcs, nbSommets;
	std::ostringstream oss;
	std::istringstream iss;
	std::string buffer;
	

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
			int src, cout;
			stream >> src >> cout;
			numSucc = (srcPrec == src) ? numSucc++ : 1;
			mon_graphe.l[src][numSucc] = cout;
			srcPrec = src;
		}
		/* FIN LECTURE */

		//calculer_chemin(mon_graphe, 1, 34, ma_solution);
		//afficher_solution(ma_solution, 34);
	}



	/*initGraphe(mon_graphe);
	//calculer_chemin(mon_graphe, 1, 9, ma_solution);
	//Bellman(mon_graphe, ordre, , ma_solution);
	afficher_solution(ma_solution, 9);*/
}

