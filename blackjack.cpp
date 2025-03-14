#include <iostream>
#include <windows.h> 
#include <cstdlib>
#include <ctime>

using namespace std;

string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

void getCard(string &cardName, int &handTotal, int &aceCount) {
    int rankIndex = rand() % 13; 
    int suitIndex = rand() % 4; 

    cardName = ranks[rankIndex] + " of " + suits[suitIndex];

    int cardValue;
    if (rankIndex >= 9) {
        cardValue = 10;  
    } else if (rankIndex == 12) {
        cardValue = 11;  
        aceCount++;
    } else {
        cardValue = rankIndex + 2; 
    }

    handTotal += cardValue;

    // Adjust for Ace if total exceeds 21
    while (handTotal > 21 && aceCount > 0) {
        handTotal -= 10; // Convert an Ace from 11 to 1
        aceCount--;
    }
}

// Function to check for Blackjack
bool isBlackjack(int totalCards, int totalValue) {
    return (totalCards == 2 && totalValue == 21);
}

int main() {
    srand(time(0));  // Random seed

    cout << "Welcome to Blackjack!\n";

    string playerCards[10], dealerCards[10]; // Store card names
    int playerTotal = 0, dealerTotal = 0;
    int playerCardCount = 0, dealerCardCount = 0;
    int playerAces = 0, dealerAces = 0; // Track Aces for adjusting values
    char choice;

    // Initial dealing (2 cards each)
    getCard(playerCards[playerCardCount], playerTotal, playerAces);
    playerCardCount++;
    getCard(playerCards[playerCardCount], playerTotal, playerAces);
    playerCardCount++;
    
    getCard(dealerCards[dealerCardCount], dealerTotal, dealerAces);
    dealerCardCount++;
    getCard(dealerCards[dealerCardCount], dealerTotal, dealerAces);
    dealerCardCount++;

    // Display player's hand
    cout << "\nYour cards: ";
    Sleep(1000);
    for (int i = 0; i < playerCardCount; i++) {
        cout << playerCards[i] << ", ";
    }
    Sleep(2000);
    cout << "\nYour total: " << playerTotal << endl;

    Sleep(2000);
    cout << "Dealer's first card: " << dealerCards[0] << endl;
    cout<<"Dealer's Total : "<<dealerTotal<<endl;

    // Check for Blackjack
    if (isBlackjack(playerCardCount, playerTotal)) {
        cout << "Blackjack! You win instantly!\n";
        return 0;
    }

    // Player's turn
    while (playerTotal < 21) {
        cout <<endl<< "Do you want to (H)it or (S)tand? : ";
        cin >> choice;

        if (choice == 'H' || choice == 'h') {
            getCard(playerCards[playerCardCount], playerTotal, playerAces);
            playerCardCount++;
            Sleep(700);
            
			cout<<"You drew : "<<playerCards[playerCardCount - 1];
			Sleep(2000);
			
            cout << "\nYour cards: ";
            for (int i = 0; i < playerCardCount; i++) {
                cout << playerCards[i] << ", ";
            }
            cout << "\nYour total: " << playerTotal << endl;
        } else {
            break;
        }
    }

    // Check if player busted
    if (playerTotal > 21) {
        cout << "You busted! Dealer wins.\n";
        return 0;
    }
	
    // Dealer's turn
    cout << "\nDealer's turn...\n";
    Sleep(500);
    cout << "Dealer's full hand: ";
    Sleep(500);
    for (int i = 0; i < dealerCardCount; i++) {
        cout << dealerCards[i] << ", ";
    }
    cout << "\nDealer's total: " << dealerTotal << endl;
	
    while (dealerTotal < 17) {
        getCard(dealerCards[dealerCardCount], dealerTotal, dealerAces);
        dealerCardCount++;
		Sleep(2000);
        cout << "Dealer drew: " << dealerCards[dealerCardCount - 1] << endl;
        Sleep(500);
		cout << "Dealer's total: " << dealerTotal << endl<<endl;
    }

    // Determine winner
    if (dealerTotal > 21) {
        Sleep(2000);
		cout<<"You win!\n";
		cout<<"Dealer Busted!!";
	} else if (playerTotal > dealerTotal) {
		Sleep(2000);
		cout<<"You win!\n";
    } else if (dealerTotal == playerTotal) {
    	Sleep(2000);
        cout << "It's a tie!\n";
    } else {
    	Sleep(2000);
        cout << "Dealer wins!\n";
    }

    return 0;
}

