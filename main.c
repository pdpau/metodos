#include <stdio.h>
#include "labouchere.h"

int main() {
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

    return 0;
}
