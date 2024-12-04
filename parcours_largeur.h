//
// Created by Thomas on 03/12/2024.
//

#ifndef PARCOURS_LARGEUR_H
#define PARCOURS_LARGEUR_H
#include "tree.h"

// Structure pour la file (Queue)
typedef struct queue_node_s {
    tree_t tree; // Pointeur vers le noeud de l'arbre
    struct queue_node_s *next;
} queue_node_t;

typedef struct queue_s {
    queue_node_t *front; // Premier élément de la file
    queue_node_t *rear;  // Dernier élément de la file
} queue_t;

void enqueue(queue_t *queue, tree_t tree);
tree_t dequeue(queue_t *queue);

int is_queue_empty(queue_t *queue);
int show_tree_width(tree_t tree);

#endif //PARCOURS_LARGEUR_H
