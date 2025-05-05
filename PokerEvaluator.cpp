//
// Created by ethan on 5/5/2025.
//

#include "PokerEvaluator.h"
#include "Deck.h"
#include <iostream>
#include "HandOfCards.h"
#include <algorithm>

PokerEvaluator::PokerEvaluator(int numCards) {

    //Only allow 5 or 7 card hands
    if(numCards !=5 && numCards !=7) {
        throw std::invalid_argument("Only 5 or 7 card hands are supported");
    } else {
        numCardsPerHand = numCards;
        numHandsToPlay = 100000;
    }
}

void PokerEvaluator::setNumberOfHandsToPlay(int hands) {
    numHandsToPlay = hands;
}

void PokerEvaluator::addCardToHand(int value, Card::Suit suit) {
    //Do not allow addition of cards to hand if hand size is 5
    if(numCardsPerHand == 5) {
        std::cerr << "Cannot add cars to a 5-card hand." << std::endl;
        return;
    }
    //Do not allow more than a 2 card addition to a hand (5 generated, 2 user defined)
    if(userDefinedCards.size() >= 2) {
        std::cerr << "Cannot add more tha n2 user-defined cards to a 7-card hand" << std::endl;
        return;
    }

    //Add Card to userDefined Cards
    userDefinedCards.push_back(Card(suit, value));
}

void PokerEvaluator::playAndDisplay() {
    //Create Fresh Deck
    Deck deck;
    deck.shuffle();

    //Draw Random cards from deck depending on how many are specified by user
    int numRandomCards = numCardsPerHand - userDefinedCards.size();
    vector<Card> hand;
    deck.getCards(numRandomCards, hand);

    //Combine random cards with user-defined cards
    for(Card card : userDefinedCards) {
        hand.push_back(card);
    }

    //Evaluate hand
    evaluateHand(hand);

    //Update Statistics

    //Display Results
}

void PokerEvaluator::evaluateHand(vector<Card>& hand) {

}

/*
//Check for flush
bool PokerEvaluator::isFlush(vector<Card>& userHand) {
    HandOfCards hand(userHand);
    int handSize = userHand.size();

    int numClubs = hand.getNumberOfCardsBySuit(Card::CLUBS);
    int numDiamonds = hand.getNumberOfCardsBySuit(Card::DIAMONDS);
    int numHearts = hand.getNumberOfCardsBySuit(Card::HEARTS);
    int numSpades = hand.getNumberOfCardsBySuit(Card::SPADES);

    if (numClubs == handSize) return true;
    if (numDiamonds == handSize) return true;
    if (numHearts == handSize) return true;
    if (numSpades == handSize) return true;

    return false;
}
*/

//Check for straight
bool PokerEvaluator::isStraight(vector<Card>& userHand) {
    //extract card values into vector of values
    vector<int> values;
    for(Card card : userHand) {
        values.push_back(card.getValue());
    }

    //sort values in ascending order
    sort(values);

    //remove duplicates from values using iterator instead of index
    removeDuplicates(values);

    //check standard straight
    for(int i =0; i < values.size() - 4; i++) {
        if(values[i+1] == values[i] + 1
            and values[i+2] == values[i] + 2
            and values[i+3] == values[i] + 3
            and values[i+4] == values[i] + 4) return true;
    }

    //Check for Ace-high straight
    vector<int> aceHighStraight = {1, 10, 11, 12, 13};
    if(containsAll(values, aceHighStraight)) {
        return true; //ace-high straight found
    }

    return false; //no straight found
}

//Helper Utility Function to sort values of cards of a given hand
void PokerEvaluator::sort(vector<int>& cardValues) {
    for(int i = 0; i < cardValues.size() - 1; i++) {
        for(int j = 0; j < cardValues.size() - i - 1; j++) {
            if(cardValues[j] > cardValues[j + 1]) {
                swap(cardValues[j], cardValues[j + 1]);
            }
        }
    }
}

//Helper Utility Function to removeDuplicate card values from vector
void PokerEvaluator::removeDuplicates(vector<int>& cardValues) {
    for(auto i = 0; i < cardValues.size() - 1;) {
        if(cardValues[i] == cardValues[i+1]) {
            cardValues.erase(cardValues.begin() + i + 1); // remove duplicate
        } else {
            i++; // move to next index if no duplicate removed
        }
    }
}

//Helper Utility Function to check if a vector contains all values from another list
bool PokerEvaluator::containsAll(vector<int>& vec, vector<int>& valuesToCheck) {
    for(int value : valuesToCheck) {
        if(find(vec.begin(), vec.end(), value) == vec.end()) {
            return false; //if any value is not found, return false
        }
    }
    return true;
}

bool PokerEvaluator::isStraightFlush(vector<Card>& hand) {
    if(isSameSuit(hand) && isStraight(hand)) {
        return true;
    }
    return false;
}

bool PokerEvaluator::isRoyalFlush(vector <Card>& hand) {
    vector<int> royalFlush = {1,10,11,12,13}; // ace, 10, jack, queen, king
    vector<int> cardValues;
    for(Card card : hand) {
        cardValues.push_back(card.getValue());
    }

    return containsAll(cardValues, royalFlush) && isSameSuit(hand);
}

//Helper function to validate if all cards in a hand are of the same suit
bool PokerEvaluator::isSameSuit(vector<Card>& hand) {
    Card::Suit firstSuit = hand[0].getSuit();

    for(Card card : hand) {
        if(card.getSuit() != firstSuit) {
            return false;
        }
    }
    return true;
}

//Function to check for Four of a Kind
bool PokerEvaluator::fourOfAKind(vector<Card>& hand) {
    // check each possible card value
    for (int value = 1; value <= 14; ++value) {
        int numSameCards = 0;

        for (Card card : hand) {
            if (card.getValue() == value) {
                numSameCards++;
            }
        }

        // If any value appears 4 times, it's Four of a Kind
        if (numSameCards == 4) {
            return true;
        }
    }

    return false;
}

