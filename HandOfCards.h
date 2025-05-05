//
// Created by ethan on 5/5/2025.
//

#ifndef HANDOFCARDS_H
#define HANDOFCARDS_H
#pragma once

#include "Card.h"
#include <vector>

using namespace std;



class HandOfCards {
public:
    HandOfCards(vector<Card>& someCards);
    int getNumberOfCardsBySuit(Card::Suit);
    //vector<Card> getCardsByValue(int value);
private:
    vector<vector<Card>> cardsBySuit;
    vector<vector<Card>> cardsByValue;
};



#endif //HANDOFCARDS_H
