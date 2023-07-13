#include <vector>
#include <string>

#define		FUDGE		200		//Used to weight the change in demand towards decrease when it's already high, and vice versa
#define		INCREMENT	.05		//The smallest increment by which demand can change
#define 	MAXCHANGED	2		//The max number of changes in market demand per shift
#define     REPORTBUFF  55      //The predicted max length of a report string returned my changedDemand

// void market_shift(char* marketReport);
// void changeDemand(int index, char* report);
// void printState(char* state);

using namespace std;

struct effect {					//Pairs effect names with a demand value
    string effect;
    float demand;
};

class marketState {
	public:
		string market_shift();
		string changeDemand(int index);
		string printState();
		marketState();
	private:
		std::vector<effect> market_state;
};

class gameState {
    public:
        marketState mState;
        //playerInventory pInven;
        //playerAlmanac pAlm;
        //MasterIngredientList mIList;
        //MasterAlmanac mAlm;
        gameState();		
};