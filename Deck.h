//
// Created by ethan on 4/16/2025.
//
#pragma once

#ifndef DECK_H
#define DECK_H
#include <vector>
#include <string>
#include "Card.h"

using namespace std;

class Deck {
public:
    Deck();
    void shuffle();
    void printAllCards();

    bool getCards(int numRequestedCards, vector <Card>& cards);
    void addCardsBackToDeck(vector <Card>& cards);
    void removeCard(int num, int suit);
private:
    vector <Card> allCards;
    void removeCards(vector<Card>& cards);
    bool shouldRemoveCard(Card& card,std::vector<Card>& cardsToRemove);
};



#endif //DECK_H

