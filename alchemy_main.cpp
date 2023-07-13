#include <stdio.h>
#include <iostream>
#include <string>
#include <ncurses.h>
#include "state.h"
using namespace std;

WINDOW *create_win(int height, int width, int startY, int startX);
void initializeWindows(WINDOW *left, WINDOW *centre, WINDOW *right);
//void setMenu(int menuCode, WINDOW *right);
void morningMenu(WINDOW *right);
void productionMenu(WINDOW *right);
void salesMenu(WINDOW *right);
void drawInfo(WINDOW *left, int date, string news, gameState gState);
void drawProduction(WINDOW *centre);
void drawSales(WINDOW *centre);


int main(void) {

    WINDOW *left, *centre, *right;
    int startX, startY, width, height;
    int ch, date = 0;
    string news;

    initscr();

    height = LINES - 12;
    width = COLS;
    startX = 1;
    startY = 1;

    left = create_win(height, width * .3, startY, startX);
    centre = create_win(height, width * .5, startX, startY + width * .3);
    right = create_win(height, width * .2, startX, startY + width *.8);
    initializeWindows(left, centre, right);

    mvwprintw(centre, height - 3, 1, "Press any key to continue...");
    //mvwprintw(centre, 8, 1, "Press any key to continue...");
    wgetch(centre);

    wmove(centre, height - 3, 0);
    wclrtoeol(centre);
    morningMenu(right);
    gameState gState;

    while ( ch != 'x') {

        if (date % 7 == 0) {
            news += gState.mState.market_shift();
        }
        
        drawInfo(left, date, news, gState);
        news = "";

        productionMenu(right);
        drawProduction(centre);
        ch = wgetch(centre);

        switch(ch) {
            case 'x':
                continue;
            case 'c':
                mvwprintw(centre, height - 3, 1, "Continuing");
            default:
                mvwprintw(centre, 5, 1, "invalid command");
        }

        salesMenu(right);
        drawSales(centre);
        ch = wgetch(centre);

        switch(ch) {
            case 'x':
                continue;
            case 'c':
                mvwprintw(centre, height - 3, 1, "Continuing");
            default:
                mvwprintw(centre, 5, 1, "invalid command");
        }

        //ch = wgetch(centre);
        ++date;
    }

    wgetch(left);

    endwin();
    return 0;
}

WINDOW *create_win(int height, int width, int startY, int startX) {

    WINDOW *window;
    window = newwin(height, width, startY, startX);
    box(window, 0, 0);
    wrefresh(window);

    return window;
}

void initializeWindows(WINDOW *left, WINDOW *centre, WINDOW *right) {
    
    mvwprintw(left, 1, 1, "{SHOP NAME GOES HERE}");
    mvwprintw(left, 3, 1, "Date: ");
    mvwprintw(left, 5, 1, "Gold: ");
    mvwprintw(left, 8, 1, "News: ");

    //mvwprintw(centre, 1, 1, "THIS IS WERE YOU DO STUFF");
    
    mvwprintw(centre, 1, 1, "Congratulations!\n\tYou've inherited/swindled an alchemists shop from your grandfather/old mentor/aquaintance/some poor sucker.\nOr some other roleplaying premise for why your playing this game, I dunno, am I your supervisor?\nPut some work in you ingrate.\n\tAnyhoo, you've got this shop, but you know almost nothing about alchemy. The old alamanac lying around in the back has a few recipes, and the ingredient stores have a few old bits of things left to make your first potions.\nBeyond that you're on your own. Watch the market, and try to make potions people want to buy, and experiment to discover what ingredients make which potions.\nA'ight, go play the game.");
    mvwprintw(centre, 12, 1, "The game works in two modes. Production mode, where you experiment, learn things, and make new potions\nAnd Sales mode, where the market simulation takes over and decides how much you sold that day. Rinse and repeat\n");

    mvwprintw(right, 1, 1, "MENU");

    wrefresh(right);
    wrefresh(centre);
    wrefresh(left);

}

//Displays the menu for the morning/potion making phase of a game day
void morningMenu(WINDOW *right) {

    wclear(right);

    mvwprintw(right, 1, 1, "MENU");
    mvwprintw(right, 3, 1, "(x) Exit Game");
    //mvwprintw(right, 4, 1, "(i) Ingredient Stores");
    box(right, 0, 0);
    wrefresh(right);
}

void productionMenu(WINDOW *right) {

    wclear(right);

    mvwprintw(right, 1, 1, "PRODUCTION MENU");
    mvwprintw(right, 3, 1, "(x) Exit Game");
    mvwprintw(right, 4, 1, "(c) Continue");
    mvwprintw(right, 5, 1, "(b) Brew Potions");
    mvwprintw(right, 6, 1, "(l) The Lab");

    box(right, 0, 0);
    wrefresh(right);
}

void salesMenu(WINDOW *right) {

    wclear(right);

    mvwprintw(right, 1, 1, "Sales MENU");
    mvwprintw(right, 3, 1, "(x) Exit Game");
    mvwprintw(right, 4, 1, "(c) Continue");

    box(right, 0, 0);
    wrefresh(right);
}

void drawInfo(WINDOW *left, int date, string news, gameState gState) {

    wclear(left);

    const char *newsptr = news.c_str(); 

    //mvwprintw(left, 8, 1, "News: ");
    //mvwprintw(left, 9, 1, "%s", newsptr);
    //marketState = printState();
    //string stateReport = gState.mState.printState();
    //const char *msptr = stateReport.c_str();
    //mvwprintw(left, 12, 1, "State of the market: %s", msptr);

    mvwprintw(left, 1, 1, "{SHOP NAME GOES HERE}");
    mvwprintw(left, 3, 1, "Date: %d", date);
    mvwprintw(left, 5, 1, "Gold: ");
    mvwprintw(left, 8, 1, "News: %s\n\n\n", newsptr);

    box(left, 0, 0);
    wrefresh(left);
}

void drawProduction(WINDOW *centre) {

    wclear(centre);

    mvwprintw(centre, 1, 1, "Production view");

    box(centre, 0, 0);
    wrefresh(centre);
}

void drawSales(WINDOW *centre) {
    
    wclear(centre);

    mvwprintw(centre, 1, 1, "Sales view");

    box(centre, 0, 0);
    wrefresh(centre);
}

//setMenu       A function containing a switch statement. A simple number code indicates which menu to display

// void setMenu(int menuCode, WINDOW *right) {

//     cout << "setting menu\n";

//     switch(menuCode) {
//         case 0: 
//             morningMenu(right);
//             break;
      
//         default:
//             cout << "setMenu Error\n";
//     }
// }




// for (int i = 1; i < 78; ++i) {
    //     mvwprintw(left, 4, 1, "Week: %d, Day: %d", i / 7 + 1, i % 7 + 1);
    //     wrefresh(left);

    //     if (i % 7 == 0) {
            
    //         string news = "";
    //         news += mState.market_shift();
    //         const char *newsptr = news.c_str(); 

    //         mvwprintw(left, 8, 1, "News: ");
    //         mvwprintw(left, 9, 1, "%s", newsptr);
    //         //marketState = printState();
    //         string stateReport = mState.printState();
    //         const char *msptr = stateReport.c_str();
    //         mvwprintw(left, 12, 1, "State of the market: %s", msptr);

    //         wnoutrefresh(left);
    //         doupdate();
    //     }
    //     napms(200);
    // }