#include "labouchere.h"
//#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

int random_choice(int n) { // n = 2
    int value = rand()%n;
    return value; // devuelve un valor 0 o 1
}

void create_first_part(List* list, int want_to_win) {
    int counter = 0;
    int val_to_add = 1;
    while (counter <= want_to_win/4) {
        add_first(list, val_to_add);
        //printf("%d\n", val_to_add);
        counter = counter + val_to_add;
        val_to_add++;
    }

    printf("Vas a jugar a por %d dolares\n", counter*2);
    printf("Tu estrategia tiene %d pasos\n", (val_to_add*2)-2);
}
int create_last_part(List* list, int want_to_win) {
    int counter = 0;
    int val_to_add = 1;
    while (counter <= want_to_win/4) {
        add_last(list, val_to_add);
        //printf("%d\n", val_to_add);
        counter = counter + val_to_add;
        val_to_add++;
    }

    printf("Vas a jugar a por %d dolares\n", counter*2);
    printf("Tu estrategia tiene %d pasos\n", (val_to_add*2)-2);
    // devolvemos lo que el jugador va a poder ganar
    return counter*2;
}

int create_play(List* list, int want_to_win) {
    //init_list(list);
    // primero añadimos del medio al principio (add first)
    create_first_part(list, want_to_win);
    // despues añadimos del medio al final (add_last)
    int valor_real_a_ganar = create_last_part(list, want_to_win);
    printf("You will be playing to get %d dollars\n", valor_real_a_ganar);
    return valor_real_a_ganar;
}

void bet_won(List* list) {
    if (length(list) > 1) {
        remove_last(list);
        remove_first(list);
    } else {
        remove_first(list);
    }
}
void bet_lost(List* list, int bet) {
    add_last(list, bet);
}

int play(int money, int to_win) {
    List* list;
    list = (List*) malloc(sizeof(List));
    init_list(list);

    int rounds_counter = 0;
    int random_val;
    int new_money = money;
    int real_to_win = create_play(list, to_win);

    printf("---------------------------\n");

    int bet = get_element(0, list) + get_element(length(list)-1, list); // = primer y ultimo numero de la lista

    while ((bet <= new_money) && (new_money != money+real_to_win)) { // jugada apostar
        printf("Round: %d\n", rounds_counter);
        printf("Bet: %d\n", bet);

        random_val = random_choice(2);
        if (random_val == 0) {
            bet_won(list);
            new_money = new_money + bet;
            rounds_counter++;
            printf("Money after round %d: %d\n", rounds_counter, new_money);
        } else if (random_val == 1) {
            bet_lost(list, bet);
            new_money = new_money - bet;
            rounds_counter++;
            printf("Money after round %d: %d\n", rounds_counter, new_money);
        } else {
            printf("random has a problem\n");
        }
        if (length(list) > 1) {
            bet = get_element(0, list) + get_element(length(list)-1, list);
        } else {
            bet = get_element(0, list);
        }

        print_list(list);
        printf("--------------------------------\n");
    }

    if (new_money == money+real_to_win) {
        printf("YOU WON\n");
        return WON;
    } else {
        printf("YOU LOST\n");
        return LOST;
    }
}
