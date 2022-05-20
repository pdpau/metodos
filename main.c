#include <stdio.h>
#include "labouchere.h"
#include "labouchere2.h"

void amb_enters() {
    int choice = 2;

    while (choice != 0) {
        printf("What do you want to do ??\n");
        printf("(1) Play\n");
        printf("(0) Quit\n");
        scanf("%d", &choice);

        double total_investment;
        double total_retorn;
        double total_benefici;

        if (choice == 1) {
            int money;
            int want;
            int rounds_number;
            int won_or_lost;
            int plays_won = 0;
            int total_plays = 0;
            float percent;

            printf("Money you are playing with: \n");
            scanf("%d", &money);

            printf("Extra money yo want to get: \n");
            scanf("%d", &want);

            printf("Rounds you want to play: \n");
            scanf("%d", &rounds_number);

            while (rounds_number > 0) {
                won_or_lost = play(money, want);
                if (won_or_lost == WON) {
                    plays_won++;
                }
                rounds_number--;
                total_plays++;
            }

            printf("End of the algorithm\n");
            printf("You won %d times out of %d plays\n", plays_won, total_plays);
            percent = (100*(float)plays_won/(float)total_plays);
            printf("That is a %f percent of effectivity\n", percent);

            total_investment = money * total_plays;
            printf("Total diners invertits: %f\n", total_investment);

            // TODO: Arreglar que total_retorn et dona money+want i hauria de fer money+aposta_real
            total_retorn = ((float)money+(float)want) * (float)total_plays * (percent/100);
            printf("Total diners retornats: %f\n", total_retorn);

            total_benefici = total_retorn - total_investment;
            printf("Total diners guanyats: %f\n", total_benefici);

        }
    }
}

void proves() {
    List* list = (List*) malloc(sizeof(List));
    init_list(list);

    create_first(list, 23);
    print_list(list);
}

void amb_enters2() {
    int choice = 2;

    while (choice != 0) {
        printf("What do you want to do ??\n");
        printf("(1) Play\n");
        printf("(0) Quit\n");
        scanf("%d", &choice);

        double total_investment;
        double total_retorn;
        double total_benefici;
        double percent_benefici;

        if (choice == 1) {
            int money;
            int want;
            int rounds_number;
            int won_or_lost;
            int plays_won = 0;
            int total_plays = 0;
            double percent;

            printf("Money you are playing with: \n");
            scanf("%d", &money);

            printf("Extra money yo want to get: \n");
            scanf("%d", &want);

            printf("Rounds you want to play: \n");
            scanf("%d", &rounds_number);

            while (rounds_number > 0) {
                won_or_lost = play2(money, want);
                if (won_or_lost == WON) {
                    plays_won++;
                }
                rounds_number--;
                total_plays++;
            }

            printf("End of the algorithm\n");
            printf("You won %d times out of %d plays\n", plays_won, total_plays);
            percent = (100*(float)plays_won/(float)total_plays);
            printf("That is a %f percent of effectivity\n", percent);

            total_investment = money * total_plays;
            printf("Total diners invertits: %f\n", total_investment);

            // TODO: Arreglar que total_retorn et dona money+want i hauria de fer money+aposta_real
            total_retorn = ((float)money+(float)want) * (float)total_plays * (percent/100);
            printf("Total diners retornats: %f\n", total_retorn);

            total_benefici = total_retorn - total_investment;
            printf("Total diners guanyats: %f\n", total_benefici);

            percent_benefici = 100*total_benefici/total_investment;
            printf("That is a %f percent ROE\n", percent_benefici);
        }
    }
}

double algoritme_prova_numeros(int money, int want, int num_of_rounds) {
    double total_investment;
    double total_retorn;
    double total_benefici;
    double percent_benefici;

    int won_or_lost;
    int plays_won = 0;
    int total_plays = 0;
    double percent;

//    printf("Money you are playing with: \n");
//    scanf("%d", &money);
//
//    printf("Extra money yo want to get: \n");
//    scanf("%d", &want);
//
//    printf("Rounds you want to play: \n");
//    scanf("%d", &rounds_number);

    while (num_of_rounds > 0) {
        won_or_lost = play2(money, want);
        if (won_or_lost == WON) {
            plays_won++;
        }
        num_of_rounds--;
        total_plays++;
    }

//    printf("End of the algorithm\n");
//    printf("You won %d times out of %d plays\n", plays_won, total_plays);
    percent = (100*(float)plays_won/(float)total_plays);
//    printf("That is a %f percent of effectivity\n", percent);

    total_investment = money * total_plays;
//    printf("Total diners invertits: %f\n", total_investment);

    total_retorn = ((float)money+(float)want) * (float)total_plays * (percent/100);
//    printf("Total diners retornats: %f\n", total_retorn);

    total_benefici = total_retorn - total_investment;
//    printf("Total diners guanyats: %f\n", total_benefici);

    percent_benefici = 100*total_benefici/total_investment;
//    printf("That is a %f percent ROE\n", percent_benefici);

    return percent_benefici;
}



int main() {
    // amb_enters();

    //proves();

    //amb_enters2();

    int comb[2] = {0, 0};
    double per = -1000;
    double new_per;
    for (int money = 30; money <= 750; money++) {
        for (int want = 2; want <= 50; want++) {
            new_per = algoritme_prova_numeros(money, want, 100); // TODO: Al canviar el numero de rondes, canvia la combinació
            if (new_per > per) {
                per = new_per;
                comb[0] = money;
                comb[1] = want;
            }
        }
    }
    printf("Best combination\n");
    printf("Money: %d ", comb[0]);
    printf("Want: %d\n", comb[1]);
    printf("Best ROE: %f\n", per);

    return 0;
}
