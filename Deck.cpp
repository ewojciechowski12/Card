//
// Created by ethan on 4/16/2025.
//

#include "Deck.h"

#include <algorithm>
#include <string>
#include <iostream>

//Constructor that initializes 4 suits with 13yes cards each (ace-king)
Deck::Deck() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 13; j++) {
            Card::Suit cardSuit = static_cast<Card::Suit>(i);
            Card card(cardSuit, j + 1);
            allCards.push_back(card);
        }
    }
}

//Method to shuffle deck
void Deck::shuffle() {
    for(int i = 0; i < 250; i++) {
        //assigns card to random spot
        swap(allCards.at(rand() % allCards.size()), allCards.at(rand() % allCards.size()));
    }
}

//Method to print all cards in a deck
void Deck::printAllCards() {
    string Suits[] = {"Clubs","Diamonds","Hearts","Spades"};
    for(Card card : allCards) {
        cout << card.getValue() << " of " << Suits[card.getSuit()] << "\n";
    }
}

bool Deck::getCards(int numRequestedCards, vector <Card>& cards) {
    //get cards from deck, add to vector (users hand)
    //temp vector to hold cards to remove from allCards
    vector <Card> cardsToRemove;
    if(allCards.size() < numRequestedCards) {
        return false;
    }else {
        for(int i = 0; i < numRequestedCards; i++) {
            cards.push_back(allCards[i]);
            cardsToRemove.push_back(allCards[i]);
        }
        //remove cards from deck that are now in users hand
        removeCards(cardsToRemove);
        return true;
    }
}

void Deck::addCardsBackToDeck(vector <Card>& cards) {
    //remove cards from passed vector, add back to deck
    vector <Card> cardsToRemove;
    for(int i = 0; i < cards.size(); i++) {
        allCards.push_back(cards[i]);
        cardsToRemove.push_back(cards[i]);
    }
    removeCards(cardsToRemove);
}

void Deck::removeCard(int num, int suit) {
    for(int i = 0; i < allCards.size(); i++) {
        if(allCards[i].getValue() == num && allCards[i].getSuit() == suit) {
            allCards.erase(allCards.begin() + i);
            return;
        }
    }
}

//Remove cards from deck
//use iterator instead of for loop index to avoid out of range error
void Deck::removeCards(vector<Card>& cardsToRemove) {
    for(auto it = allCards.begin(); it != allCards.end();) {
        if(shouldRemoveCard(*it, cardsToRemove)){
            it = allCards.erase(it); //return next valid iterator
        }else {
            it++;
        }
    }
}

//Helper function to check if card should be removed
bool Deck::shouldRemoveCard(Card& card,std::vector<Card>& cardsToRemove)
{
    for(Card cardToRemove : cardsToRemove) {
        if(card.getSuit() == cardToRemove.getSuit() && card.getValue() == cardToRemove.getValue()) {
            return true;
        }
    }
    return false; //No match found
}




