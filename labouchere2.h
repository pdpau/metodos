#ifndef METODOS_LABOUCHERE2_H
#define METODOS_LABOUCHERE2_H

#include "lista_enlazada.h"

#define WON 1
#define LOST 2

int random_choice2(int n);

void create_first(List* list, int want);

void bet_won2(List* list);
void bet_lost2(List* list, int bet);

int play2(int money, int to_win);


#endif //METODOS_LABOUCHERE2_H
