#include <cmath>
using namespace std;

class GameStats{
	private:
		int marketValueOfCook;
		
	public:
		int currentDay;
		int noOfPizzas;
		int noOfCustomers;
		int noOfCooks;
		
		float noOfPizos;
		float pizzaPrice;
		
		GameStats(){
			currentDay = 20;
			noOfPizzas = 2;
			noOfPizos = 1.0f;
			noOfCooks = 5;
			noOfCustomers = 8;
			pizzaPrice = 1.0f;
			marketValueOfCook = noOfCooks + 1;
		}
		
		// Pizza Related
		void addPizza(){
			noOfPizzas++;
		}
		
		void addPizza(int generatedPizzas){
			noOfPizzas += generatedPizzas;
		}
		
		void sellPizza(){
			noOfPizzas--;
			increasePizosByAmount(pizzaPrice);
		}
		
		// Cook Related
		hireCook(){
			marketValueOfCook++;
			noOfCooks++;
		}
		getNoOfCooks(){
			return noOfCooks;
		}
		
		// Cook Dev Related Utility
		getMarketValueOfCook(){
			marketValueOfCook = noOfCooks + 1;
			return marketValueOfCook;
		}
		getSalariesOfCook(){		
			for(int x = 0; x < noOfCooks; x++){
				cout << "Cook Salary: " << x+1 << std::endl;
			}
		}
		
		// Pizo Related
		void increasePizosByAmount(float amount){
			noOfPizos += amount;
		}
		
		// Customer Related
		attractCustomer(){
			noOfCustomers++;
		}
		
		// Pizza Quality Related
		researchPizzaQuality(float pizoAmountSpent){
			cout << "Pizza price before research: " << pizzaPrice << std::endl;
			cout << "Amount to be spent on research: " << pizoAmountSpent << std::endl;
			cout << "Square root of amount spent: " << sqrt(pizoAmountSpent) << std::endl;
			pizzaPrice += sqrt(pizoAmountSpent);
			noOfPizos -= pizoAmountSpent;
			cout << "Pizza price after research: " << pizzaPrice << std::endl;
		}
};
