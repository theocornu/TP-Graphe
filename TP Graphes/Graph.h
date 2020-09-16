#ifndef GRAPH_H
#define GRAPH_H

const int NBMAX_SOMMETS = 20; // nb max de sommmets du graphe
const int NBMAX_SUCC = 4; // nb max de successeurs par sommet
const int INF = 9999;


typedef struct graphe_t {
	int n; // nombre de sommets
	int s[NBMAX_SOMMETS+1][NBMAX_SUCC+1]; // s[i][j] => j-ieme successeur de i
	int l[NBMAX_SOMMETS+1][NBMAX_SUCC+1]; // cout de l'arc s[i][j]
	int ns[NBMAX_SOMMETS + 1]; // nombre de successeurs d'un sommet
}graphe_t;


typedef struct solution_t {
	int m[NBMAX_SOMMETS + 1];
	int pere[NBMAX_SOMMETS + 1];
}solution_t;


void initGraphe(graphe_t& graphe);
void calculer_chemin(graphe_t& graphe, int start, int end, solution_t& solution);
void afficher_solution(solution_t& solution);


#endif
