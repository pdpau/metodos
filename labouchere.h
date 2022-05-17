#ifndef METODOS_LABOUCHERE_H
#define METODOS_LABOUCHERE_H

#include "lista_enlazada.h"

#define WON 1
#define LOST 2

int random_choice(int n);

void create_first_part(List* list, int want_to_win);
int create_last_part(List* list, int want_to_win);
int create_play(List* list, int want_to_win);

void bet_won(List* list);
void bet_lost(List* list, int bet);

int play(int money, int to_win);

#endif //METODOS_LABOUCHERE_H
