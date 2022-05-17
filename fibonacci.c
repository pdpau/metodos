//
// Created by pdpau on 11/05/2022.
//
#include "fibonacci.h"

int fibonacci_r(int num) {
    if (num%1 != 0 || num < 0) {
        return -1;
    } else {
        if (num == 1 || num == 0){
            return num;
        } else {
            return fibonacci_r(num-1) + fibonacci_r(num-2);
        }
    }
}

//void create_first(List* list, int want) {
//    double random;
//    double total = 0;
//
//    while (total <= want) {
//        random = random_choice(want/2);
//        if (random != 0) {
//            add_first(list, random);
//            total += random;
//        }
//    }
//}
