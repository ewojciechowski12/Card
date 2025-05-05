#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "HandOfCards.h"
#include "PokerEvaluator.h"

using namespace std;

int main()
{
    srand(time(0));

    //Create, print, shuffle and reprint deck of cards
    Deck deck;
    deck.printAllCards();
    deck.shuffle();
    cout << "\n";
    deck.printAllCards();

    //Create a hand of cards and print
    cout << "\n\nMy Hand: " << endl;
    vector <Card> myHand;
    if(deck.getCards(5, myHand) == true) {
        for(Card c : myHand) {
            c.printCard();
        }
    }

    //Test Hand of Cards class and methods
    HandOfCards hand(myHand);
    int numClubs = hand.getNumberOfCardsBySuit(Card::CLUBS);
    int numDiamonds = hand.getNumberOfCardsBySuit(Card::DIAMONDS);
    int numHearts = hand.getNumberOfCardsBySuit(Card::HEARTS);
    int numSpades = hand.getNumberOfCardsBySuit(Card::SPADES);

    cout << "\n\nNumber of Clubs: " << numClubs << endl;
    cout << "\n\nNumber of Diamonds: " << numDiamonds << endl;
    cout << "\n\nNumber of Hearts: " << numHearts << endl;
    cout << "\n\nNumber of Spades: " << numSpades << endl;

    return 0;
}
