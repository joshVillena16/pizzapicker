#include "Actions.h"  // Parent

class DayActions : public Actions {
	public:
		
		void makePizza(GameStats* gameStats){
			gameStats->addPizza();
			changeTextColorToGreen();
			cout << "Made pizza today" << std::endl;
			changeTextColorToWhite();
		}
		
		void hireCook(GameStats* gameStats){
			gameStats->hireCook();
			changeTextColorToGreen();
			cout << "Hired cook today" << std::endl;
			changeTextColorToWhite();
		}
		
		void attractCustomer(GameStats* gameStats){
			gameStats->attractCustomer();
			changeTextColorToGreen();
			cout << "Attracted customer today" << std::endl; 
			changeTextColorToWhite();
		}
		
		void researchPizzaQuality(GameStats* gameStats){
			currentPizos = gameStats->noOfPizos;
			
			if(isCurrentPizoGreaterThanZero()){
				getPlayerDecisionForResearch();
				handleInputValidationForResearch();
				gameStats->researchPizzaQuality(pizoAllocated);
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			} else {
				cout << "You don't have any pizos" << std::endl; ;
			}
		}
		
		GameStats sellPizza(GameStats gameStats){
			if(pizzaInventoryStillHasStock(&gameStats.noOfPizzas)){
				gameStats.sellPizza();
				changeTextColorToGreen();
				cout << "Sold pizza today" << std::endl;
				cout << "Pizo Before:" << gameStats.noOfPizos-1 << std::endl;
				cout << "Pizo After:" << gameStats.noOfPizos << std::endl;
				changeTextColorToWhite();
			} else {
				changeTextColorToRed();
				cout << "There is no pizzas left to be sold" << std::endl;
				changeTextColorToWhite();
			}
			
			return gameStats;
		}
		
		void displayActionMenu(){
			cout << "Action Menu" << std::endl;
			cout << "1. Make a Pizza" << std::endl;
			cout << "2. Sell a Pizza" << std::endl;
			cout << "3. Hire a Cook" << std::endl;
			cout << "4. Attract a Customer" << std::endl;
			cout << "5. Research Pizza Quality" << std::endl;
			cout << "6. Skip x days" << std::endl;
			cout << "7. Exit game" << std::endl;
		}
		
		void displayGameStats(GameStats gameStats){
			cout << "Day " << gameStats.currentDay << std::endl;
			cout << "Pizza: " << gameStats.noOfPizzas << std::endl;
			cout << "Pizo: " << gameStats.noOfPizos << std::endl;
			cout << "Cooks: " << gameStats.noOfCooks << std::endl;
			cout << "No Of Customers: " << gameStats.noOfCustomers << std::endl;
			cout << "Pizza Price: " << gameStats.pizzaPrice << std::endl << std::endl;
			
			
			// dev tools
			gameStats.getSalariesOfCook();
			cout << "Market Value of Next Cook: " << gameStats.getMarketValueOfCook()  << std::endl << std::endl;;
		}
		
		void getUserInput(int* playerDecision){
			getPlayerDecision();
			*playerDecision = handleInputValidation(decision);
		}
		
		int handleInputValidation(int decision){
			while(inputIsNotNumericOrNegativeNumber(decision)){
				clearInput();
				clearScreen();
				cout << "Input invalid. Pick a valid action." << std::endl << std::endl;
				displayActionMenu();
				getPlayerDecision();
			}
			return decision; 
		}
		
		void handleInputValidationForResearch(){
			while(inputIsNotNumericOrNegativeNumberOrGreaterThanNoOfPizos()){
				clearInput();
				clearScreen();
				changeTextColorToRed();
				cout << "Amount entered is greater than Pizos own or less than zero." << std::endl;
				cout << "Pizos own: " << currentPizos << std::endl;
				changeTextColorToWhite();
				
				getPlayerDecisionForResearch();
			}
		}
		
		// Separated player decision from action menu for method single responsibility. (int)
		void getPlayerDecision(){
			cout << "Pick an action: " << std::endl;
			cin >> decision;
		
			decision;
		}
		
		// Separated player decision from action menu for method single responsibility. (float)
		void getPlayerDecisionForResearch(){
			cout << "How much would you like to spend on research? ";
			cin >> pizoAllocated;
		}
		
		void clearScreen(){
			// clear screen. This is bad practice, but this will do for now. 
			system("cls");
		}
		
	private: 
		int currentPizos;
		int decision;
		
		float pizoAllocated;
	
		bool inputIsNotNumericOrNegativeNumberOrGreaterThanNoOfPizos(){
			return (cin.fail() || pizoAllocated < 0 || pizoAllocated > currentPizos);
		}
		
		bool inputIsNotNumericOrNegativeNumber(int decision){
			return (cin.fail() || decision < 0);
		}
		
		bool isCurrentPizoGreaterThanZero(){
			return (currentPizos > 0);
		}
		
		void clearInput(){
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
};
