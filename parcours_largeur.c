//
// Created by Thomas on 03/12/2024.
//

#include "parcours_largeur.h"
#include <stdlib.h>
#include <stdio.h>


// Fonctions de la file
void enqueue(queue_t *queue, tree_t tree) {
    queue_node_t *new_node = (queue_node_t *)malloc(sizeof(queue_node_t));
    if (new_node == NULL) {
        printf("Erreur d'allocation memoire\n");
        return;
    }
    new_node->tree = tree;
    new_node->next = NULL;

    if (queue->rear == NULL) { // File vide
        queue->front = new_node;
        queue->rear = new_node;
    } else { // Ajouter à la fin de la file
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

tree_t dequeue(queue_t *queue) {
    if (queue->front == NULL) { // File vide
        return NULL;
    }

    queue_node_t *temp = queue->front;
    tree_t tree = temp->tree;

    queue->front = queue->front->next;
    if (queue->front == NULL) { // Si la file devient vide
        queue->rear = NULL;
    }

    free(temp);
    return tree;
}

int is_queue_empty(queue_t *queue) {
    return queue->front == NULL;
}

// Parcours en largeur
int show_tree_width(tree_t tree) {
    if (tree == NULL) {
        return -1; // Arbre vide
    }

    queue_t queue = {NULL, NULL}; // Initialisation de la file

    enqueue(&queue, tree); // Ajouter la racine à la file

    while (!is_queue_empty(&queue)) {
        tree_t current = dequeue(&queue);

        // Afficher la valeur du noeud courant
        printf("%d ", current->value);

        // Ajouter les fils gauche et droit à la file
        if (current->left != NULL) {
            enqueue(&queue, current->left);
        }
        if (current->right != NULL) {
            enqueue(&queue, current->right);
        }
    }

    printf("\n");
    return 0; // Succès
}
