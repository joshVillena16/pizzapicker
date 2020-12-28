#include <iostream>
#include<stdlib.h>
#include <limits>
#include <list>
#include "Gamestats.h"
#include "DayActions.h"
#include "NightActions.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Forward declarations to adapt top-down style.
bool gameWillContinue(int playerDecision);

int main(int argc, char** argv) {
	//std::cout << "hello world" << std::endl;
	
	int playerDecision = 0;
	
	// Create gamestats object 
	GameStats gameStats;
	
	// Create dayActions object
	DayActions dayActions;
	
	// Create nigtActions object
	NightActions nightActions;
	
	do{
		dayActions.displayGameStats(gameStats);
		dayActions.displayActionMenu();
		dayActions.getUserInput(&playerDecision);
		
		switch(playerDecision){
			case 1:	dayActions.makePizza(&gameStats);
					break;
			case 2: gameStats = dayActions.sellPizza(gameStats); break;
			case 3: dayActions.hireCook(&gameStats);
					break;
			case 4: dayActions.attractCustomer(&gameStats);
					break;
			case 5: dayActions.researchPizzaQuality(&gameStats); break;
			case 6: break;
		}
		
		// pause to see action result. 
		if(playerDecision != 7){
			system("pause");
			dayActions.clearScreen();
		} else{
			break;
		}
		
		
		// night phase	
		nightActions.beginNightPhase(gameStats);
		
		// end day actions
		gameStats.currentDay++;
		
	}while(gameWillContinue(playerDecision));
	return 0;
}

bool gameWillContinue(int playerDecision){
	return playerDecision != 7;
}


		
