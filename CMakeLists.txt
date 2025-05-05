cmake_minimum_required(VERSION 3.29)
project(Card)

set(CMAKE_CXX_STANDARD 20)

add_executable(Card main.cpp
        Card.cpp
        Card.h
        Deck.cpp
        Deck.h
        HandOfCards.cpp
        HandOfCards.h
        PokerEvaluator.cpp
        PokerEvaluator.h)
