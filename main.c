#include <stdio.h>
#include "tree.h"
#include "parcours_largeur.h"

int main() {
    // Variables pour les arbres
    tree_t root = NULL;
    tree_t left = NULL, right = NULL;
    tree_t n1 = NULL, n2 = NULL, n3 = NULL, n4 = NULL;

    // 1. Test d'un arbre vide
    printf("Test 1 : Arbre vide\n");
    printf("Parcours en largeur : ");
    show_tree_width(root);
    printf("Nombre total de noeuds : %d\n", node_number(root));
    printf("Profondeur de l'arbre : %d\n", tree_deep(root));
    printf("\n");

    // 2. Test d'un arbre avec un seul nœud
    printf("Test 2 : Arbre avec un seul noeud\n");
    build_tree(&root, 1, NULL, NULL);
    printf("Parcours prefixe : ");
    show_tree_prefix(root);
    printf("\n");
    printf("Parcours en largeur : ");
    show_tree_width(root);
    printf("Nombre total de noeuds : %d\n", node_number(root));
    printf("Profondeur de l'arbre : %d\n", tree_deep(root));
    delete_tree(&root);
    printf("\n");

    // 3. Test d'un arbre complet avec 3 niveaux
    printf("Test 3 : Arbre complet avec 3 niveaux\n");
    build_tree(&n1, 4, NULL, NULL);
    build_tree(&n2, 5, NULL, NULL);
    build_tree(&n3, 6, NULL, NULL);
    build_tree(&n4, 7, NULL, NULL);
    build_tree(&left, 2, n1, n2);
    build_tree(&right, 3, n3, n4);
    build_tree(&root, 1, left, right);
    printf("Parcours prefixe : ");
    show_tree_prefix(root);
    printf("\n");
    printf("Parcours infixe : ");
    show_tree_infix(root);
    printf("\n");
    printf("Parcours postfixe : ");
    show_tree_postfix(root);
    printf("\n");
    printf("Parcours en largeur : ");
    show_tree_width(root);
    printf("Nombre total de noeuds : %d\n", node_number(root));
    printf("Profondeur de l'arbre : %d\n", tree_deep(root));
    delete_tree(&root);
    printf("\n");

    // 4. Test d'un arbre asymétrique
    printf("Test 4 : Arbre asymetrique\n");
    build_tree(&n1, 8, NULL, NULL);
    build_tree(&n2, 9, NULL, NULL);
    build_tree(&left, 4, n1, n2);
    build_tree(&right, 5, NULL, NULL);
    build_tree(&root, 1, left, right);
    printf("Parcours prefixe : ");
    show_tree_prefix(root);
    printf("\n");
    printf("Parcours infixe : ");
    show_tree_infix(root);
    printf("\n");
    printf("Parcours postfixe : ");
    show_tree_postfix(root);
    printf("\n");
    printf("Parcours en largeur : ");
    show_tree_width(root);
    printf("Nombre total de noeuds : %d\n", node_number(root));
    printf("Profondeur de l'arbre : %d\n", tree_deep(root));
    delete_tree(&root);
    printf("\n");

    // 5. Test de suppression multiple
    printf("Test 5 : Suppression d'un arbre deja vide\n");
    delete_tree(&root); // Suppression d'un arbre déjà vide
    printf("Arbre vide apres suppression :\n");
    printf("Parcours en largeur : ");
    show_tree_width(root);
    printf("\n");

    printf("Tests termines.\n");
    return 0;
}
