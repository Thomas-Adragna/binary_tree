#ifndef TREE_H
#define TREE_H

typedef struct node_s {
    int value;
    struct node_s *left;
    struct node_s *right;
} node_t;

typedef node_t* tree_t;


int build_tree(tree_t *pnew_tree, int value, tree_t left, tree_t right); // permet de construire un arbre binaire en initialisant un nœud avec une valeur et ses sous-arbres gauche et droit.
int node_number(tree_t tree); // calcule le nombre total de nœuds présents dans l'arbre binaire.
int tree_deep(tree_t tree); // détermine la profondeur maximale (hauteur) de l'arbre binaire.
int delete_tree(tree_t *tree); // libère la mémoire occupée par tous les nœuds de l'arbre binaire.
void show_tree_prefix(tree_t tree); // affiche les nœuds de l'arbre binaire en parcours préfixe (racine, gauche, droite).
void show_tree_infix(tree_t tree); // affiche les nœuds de l'arbre binaire en parcours infixe (gauche, racine, droite).
void show_tree_postfix(tree_t tree); // affiche les nœuds de l'arbre binaire en parcours postfixe (gauche, droite, racine).




#endif // TREE_H
