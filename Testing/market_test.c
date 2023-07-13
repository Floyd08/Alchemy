#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include "market.h"

int main (void) {

    char news[REPORTBUFF * MAXCHANGED] = "\0";
    char marketReport[REPORTBUFF * MAXCHANGED] = "\0";
    char marketState[REPORTBUFF * MAXCHANGED] = "\0";
    
    printf("test starting\n");

    //TRY SAVING THE MARKET REPORT TO A LOCAL STRING, THEN CONCATINATING

    for (int i = 1; i < 145; ++i) {

        //printf("i: %d\n", i);
        if (i % 7 == 0) {
            printf("Week: %d\n", i / 7);
            
            market_shift(marketReport);
            strcat(news, marketReport);
            printf("News: \n%s", news);
            
            printf("State: \n");
            printState(marketState);
            printf("%s", marketState);

            marketState[0] = '\0';
            marketReport[0] = '\0';
            news[0] = '\0';

        }
        napms(100);
    }

    return 0;
}