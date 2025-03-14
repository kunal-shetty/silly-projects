#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<ctime>

using namespace std;

string display1 = " _____  _____  _____ \n";
string display2 = "|     ||     ||     |\n";
string display3 = "|  ?  ||  ?  ||  ?  |\n";
string display4 = "|_____||_____||_____|\n";

char items[] = {'A','B','C','D','E','F','G'};
char selectedChar;

void animateSlots(){
    for(int i = 0; i < 15; i++){
        display3[3] = items[rand() % 7];
        display3[10] = items[rand() % 7];
        display3[17] = items[rand() % 7];
        
        system("cls");
		
        cout<<display1<<display2<<display3<<display4;
        Sleep(100); 
    }
}

bool slotsWin(){
	animateSlots();
	
    selectedChar = items[rand() % 7];
    display3[3] = selectedChar;
    selectedChar = items[rand() % 7];
    display3[10] = selectedChar;
    selectedChar = items[rand() % 7];
    display3[17] = selectedChar;

    system("cls");
    cout<<display1<<display2<<display3<<display4<<endl;

    return ((display3[3]==display3[10]) && (display3[10]==display3[17]));
}

int main() {
    srand(time(0)); 
    int money, betMoney;
    cout<<"Welcome to Slots!!!!\n\n";
    cout<<"Enter your starting balance: ";
    cin>>money;

    while(money > 0){
        cout<<"Enter money to bet (or 0 to exit): ";
        cin>>betMoney;

        if(betMoney == 0){
            cout<<"Thanks for playing! Final balance: $"<<money<<endl;
            break;
        }
        if(betMoney > money){
            cout<<"You don't have enough money! Try again.\n";
            continue;
        }
        if(slotsWin()){
            cout<<"Congrats! You won!! "<<(10 * betMoney)<<"!\n";
            money += 10 * betMoney;
        } 
		else
            cout<<"You lost! Try again.\n";
            money -= betMoney;
        }

        cout<<"New Balance: $"<<money<<"\n";

        if(money <= 0){
            cout<<"You're out of money! Game over.\n";
            break;
        }
    }
    return 0;
}

