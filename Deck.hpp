#pragma once
#include "Card.hpp"
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>

class Deck
{
public:
    Deck();
    void shuffle();
    std::string toString();
private:
    std::vector<Card> cards;
    const std::vector<std::string> suits = {"Hearts", "Clubs", "Diamonds", "Spades"};
    const std::vector<std::string> ranks = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
};

Deck::Deck()
{
    for(const std::string& suit : suits)
    {
        for(const std::string& rank : ranks)
        {
            cards.push_back(Card(rank, suit));
        }
    }
}

void Deck::shuffle()
{
    std::cout << "Shuffling the deck..." << std::endl;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
}

std::string Deck::toString()
{
    std::string out = "";
    for( Card& card : cards)
    {
        out += card.toString() + '\n';
    }

    return out;
}