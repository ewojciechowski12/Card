//
// Created by ethan on 5/5/2025.
//

#include "HandOfCards.h"

HandOfCards::HandOfCards(vector<Card>& someCards)
    : cardsBySuit(4), cardsByValue(14)
{
    //Take in a hand of cards and put into respective vector
    for(Card card : someCards) {
        //Push Back By Suit
        Card::Suit cardSuit = card.getSuit();
        cardsBySuit[cardSuit].push_back(card);

        //Push Back By Value
        int value = card.getValue();
        cardsByValue[value].push_back(card);
    }
}

int HandOfCards::getNumberOfCardsBySuit(Card::Suit suit) {
    int numOfCards = 0;
    for(Card card : cardsBySuit[suit]) {
        if(card.getSuit() == suit) {
            numOfCards++;
        }
    }
    return numOfCards;
}
