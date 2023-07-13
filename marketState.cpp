//#include <stdio.h>
//#include <stdlib.h>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include "state.h"
using namespace std;

// struct demand market_state[] = {		//Maintains the current demand fo all effects
//     "Health", 1.6,
//     "Mana", 1.5,
//     "Stamina", 1.4,
//     "Reflex", 1.2,
//     "Strength", 1.2,
//     "Intelligence", 1.2
//     };

marketState::marketState() {					//Maintains the current demand fo all effects
	market_state.push_back({"Health", 1.6,});		//Later, we'll initialize this from a data file
	market_state.push_back({"Mana", 1.5});
	market_state.push_back({"Stamina", 1.4});
	market_state.push_back({"Reflex", 1.2});
	market_state.push_back({"Strength", 1.2});
	market_state.push_back({"Intelligence", 1.2});
}

/**
 * 		changes the demand of a 1 - MAXCHANGED effects
 * 		effects are weighted, so that some are more likely to change than others
 **/
string marketState::market_shift() {

	srand(time(NULL));
    int numRoll = rand() % MAXCHANGED;

	string report = "";

    for (int i = 0; i <= numRoll; ++i) {

		int roll = rand() % 100;

        if (roll < 23) {				//Health
			//strcat(marketReport, report);
			report += changeDemand(0);
    	}
        else if (roll < 46) {			//Mana
			// changeDemand(1, report);
			// marketReport += report;
			report += changeDemand(1);		
    	}
    	else if (roll < 70) {			//Stamina
			report += changeDemand(2);			
    	}
    	else if (roll < 80) {			//Reflex
			report += changeDemand(3);	
    	}
    	else if (roll < 90) {			//Strength
			report += changeDemand(4);	
	    }
    	else {							//Intelligence
			report += changeDemand(5);
    	}
    }

	return report;
	//printf("market report before return: %s", marketReport);
}

/**
 * 		increments or decrements the demand of a particular effect
 **/
string marketState::changeDemand(int index) {

	int roll = rand() % 100;

	if (roll < (FUDGE - (market_state[index].demand * 100))) {
		roll = rand() % 5 + 1;
		market_state[index].demand += roll * INCREMENT;		//increase demand	
		//sprintf(report, "demand for %s potions has increased by: %.2f\n", market_state[index].effect, roll * INCREMENT);
		char numptr[12];
		sprintf(numptr, "%.2f", roll * INCREMENT);
		return "demand for " + market_state[index].effect + " potions has increased by: " + numptr + "\n";
	}
	else {
		roll = rand() % 5 + 1;
		market_state[index].demand -= roll * INCREMENT;		//decrease demand
		char numptr[12];
		sprintf(numptr, "%.2f", roll * INCREMENT);
		return "demand for " + market_state[index].effect + " potions has decreased by: " + numptr + "\n";
	}

	//printf("report before return: %s", report);
}

string marketState::printState() {

	string stateReport = "Market state: \n";
	
    for (int j = 0; j < 6; ++j) {
		//cout << "building market state (" + to_string(j) + "): " + stateReport;
		char numptr[12];
		sprintf(numptr, "%.2f", market_state[j].demand);
		stateReport += "demand " + market_state[j].effect + ": " + numptr + "\n";
    }

	return stateReport;
}




