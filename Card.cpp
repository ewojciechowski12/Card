//
// Created by ethan on 4/16/2025.
//

#include "Card.h"
#include <iostream>

Card::Card() {
    value = 10;
    cardSuit = HEARTS;

}

Card::Card(enum Card::Suit suit, int value) {
    this->cardSuit = suit;
    this->value = value;
}

enum Card::Suit Card::getSuit() {
    return cardSuit;
}

int Card::getValue() {
    return value;
}

void Card::setSuit(enum Suit suit) {
    this->cardSuit = suit;
}

void Card::setValue(int value) {
    this->value = value;
}

void Card::printCard() {
    string Suits[] = {"Clubs","Diamonds","Hearts","Spades"};
    cout << value << " of " << Suits[cardSuit] << "\n";
}
