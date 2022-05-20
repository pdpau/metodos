#include "labouchere2.h"
#include <stdio.h>
#include <stdlib.h>

int random_choice2(int n) {
    int value = rand()%n;
    return value;
}

// ------------------------ PROVA ----------------------------
void create_first(List* list, int want) {
    int random = 0;
    int total = 0;
    int rest;

    while (total+random <= want) {
        random = random_choice2(want/2);
        if (random != 0) {
            add_last(list, random);
            total += random;
        }
    }
    if (total < want) {
        rest = want-total;
        add_last(list, rest);
    }
}

// ------------------------ PROVA ----------------------------

void bet_won2(List* list) {
    if (length(list) > 1) {
        remove_last(list);
        remove_first(list);
    } else {
        remove_first(list);
    }
}
void bet_lost2(List* list, int bet) {
    add_last(list, bet);
}

int play2(int money, int to_win) {
    List* list;
    list = (List*) malloc(sizeof(List));
    init_list(list);

    int rounds_counter = 0;
    int random_val;
    int new_money = money;
    create_first(list, to_win);
//    print_list(list);

//    printf("---------------------------\n");

    int bet = get_element(0, list) + get_element(length(list)-1, list); // = primer y ultimo numero de la lista

    while ((bet <= new_money) && (new_money != money+to_win)) { // jugada apostar
//        printf("Round: %d\n", rounds_counter);
//        printf("Bet: %d\n", bet);

        random_val = random_choice2(2);
        if (random_val == 0) {
            bet_won2(list);
            new_money = new_money + bet;
            rounds_counter++;
//            printf("Money after round %d: %d\n", rounds_counter, new_money);
        } else if (random_val == 1) {
            bet_lost2(list, bet);
            new_money = new_money - bet;
            rounds_counter++;
//            printf("Money after round %d: %d\n", rounds_counter, new_money);
        } else {
            printf("random has a problem\n");
        }
        if (length(list) > 1) {
            bet = get_element(0, list) + get_element(length(list)-1, list);
        } else {
            bet = get_element(0, list);
        }

//        print_list(list);
//        printf("--------------------------------\n");
    }

    if (new_money == money+to_win) {
//        printf("YOU WON\n");
        return WON;
    } else {
//        printf("YOU LOST\n");
        return LOST;
    }
}
