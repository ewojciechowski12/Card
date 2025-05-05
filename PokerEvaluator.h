//
// Created by ethan on 5/5/2025.
//

#ifndef POKEREVALUATOR_H
#define POKEREVALUATOR_H
#pragma once

#include "Card.h"
#include <vector>


class PokerEvaluator {
public:
    PokerEvaluator(int numCards);

    void setNumberOfHandsToPlay(int hands);
    void addCardToHand(int value, Card::Suit suit);
    void playAndDisplay();

    //make private after testing
    bool isStraight(std::vector<Card>& hand);
    bool isFlush(std::vector<Card>& hand);
    bool isStraightFlush(std::vector<Card>& hand);

private:
    int numCardsPerHand;
    int numHandsToPlay;
    std::vector<Card> userDefinedCards;

    void evaluateHand(std::vector<Card>& hand);
    void displayResults();




    void sort(vector<int>& cardValues);
    void removeDuplicates(vector<int>& cardValues);
    bool containsAll(vector<int>& vec, vector<int>& valuesToCheck);
    bool isSameSuit(vector<Card>& hand);
};



#endif //POKEREVALUATOR_H
