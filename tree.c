#include "tree.h"

#include <stdio.h>
#include <stdlib.h>

int build_tree(tree_t *pnew_tree, int value, tree_t left, tree_t right) {
    if (pnew_tree == NULL) {
        return -1; // Pointeur invalide
    }

    // Allouer un nouveau noeud
    *pnew_tree = (tree_t)malloc(sizeof(node_t));
    if (*pnew_tree == NULL) {
        return -1; // Échec de l'allocation
    }

    // Initialiser les champs du noeud
    (*pnew_tree)->value = value;
    (*pnew_tree)->left = left;
    (*pnew_tree)->right = right;

    return 0; // Succès
}

int node_number(tree_t tree) {
    if (tree == NULL) {
        return 0; // Aucun noeud
    }

    // Compter les noeuds dans les sous-arbres gauche et droit
    return 1 + node_number(tree->left) + node_number(tree->right);
}

int tree_deep(tree_t tree) {
    if (tree == NULL) {
        return 0; // Arbre vide
    }

    // Calculer récursivement la profondeur des sous-arbres
    int left_depth = tree_deep(tree->left);
    int right_depth = tree_deep(tree->right);

    return 1 + (left_depth > right_depth ? left_depth : right_depth);
}

int delete_tree(tree_t *tree) {
    if (tree == NULL || *tree == NULL) {
        return -1; // Rien à supprimer
    }

    // Supprimer récursivement les sous-arbres gauche et droit
    delete_tree(&((*tree)->left));
    delete_tree(&((*tree)->right));

    // Libérer le noeud courant
    free(*tree);
    *tree = NULL;

    return 0; // Succès
}


void show_tree_prefix(tree_t tree) {
    if (tree == NULL) {
        return; // Arbre vide
    }

    printf("%d ", tree->value);
    show_tree_prefix(tree->left);
    show_tree_prefix(tree->right);
}



void show_tree_infix(tree_t tree) {
    if (tree == NULL) {
        return; // Arbre vide
    }

    show_tree_infix(tree->left);
    printf("%d ", tree->value);
    show_tree_infix(tree->right);
}



void show_tree_postfix(tree_t tree) {
    if (tree == NULL) {
        return; // Arbre vide
    }

    show_tree_postfix(tree->left);
    show_tree_postfix(tree->right);
    printf("%d ", tree->value);
}


