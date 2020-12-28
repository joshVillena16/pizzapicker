#ifndef ACTIONS_H
#define ACTIONS_H

#include <windows.h>   // WinApi header

class Actions {
	public:
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		void changeTextColorToRed(){
			SetConsoleTextAttribute(hConsole, 12);
		}
		
		void changeTextColorToLightBlue(){
			SetConsoleTextAttribute(hConsole, 11);
		}
		
		void changeTextColorToWhite(){
			SetConsoleTextAttribute(hConsole, 7);
		}
		
		void changeTextColorToGreen(){
			SetConsoleTextAttribute(hConsole, 2);
		}
		
		bool pizzaInventoryStillHasStock(int* nPizza){
			return (*nPizza > 0);
		}
};

#endif /* ACTIONS_H */
