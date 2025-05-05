//
// Created by ethan on 4/16/2025.
//
#pragma once

#ifndef CARD_H
#define CARD_H
#include <string>

using namespace std;

class Card {
public:
    enum Suit {
        CLUBS = 0,
        DIAMONDS,
        HEARTS,
        SPADES
    };
    Card();
    Card(enum Card::Suit suite, int value);
    enum Suit getSuit();
    void setSuit(enum Suit suit);
    int getValue();
    void setValue(int value);
    void printCard();

private:
    enum Suit cardSuit;
    int value;
};



#endif //CARD_H
