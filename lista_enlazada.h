#ifndef METODOS_LISTA_ENLAZADA_H
#define METODOS_LISTA_ENLAZADA_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _element {
    int val;
    //struct _element *prev;
    struct _element *next;
} Element;

typedef struct _list {
    Element* head;
    int length;
} List;

void init_list(List* list);

Element* create_element(int number);
void free_element(Element* elem);
int length(List* list);
bool is_empty(List* list);

void add_first(List* list, int number);
void add_last(List* list, int number);
void add_after(int n, List* list, int num); // NOT NEEDED

int get_element(int n, List* list);

void remove_first(List* list);
void remove_last(List* list);
void remove_element(int n, List* list); // NOT NEEDED

void print_list(List* list);
void clear_list(List* list);

#endif //METODOS_LISTA_ENLAZADA_H
