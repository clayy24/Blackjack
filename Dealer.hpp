#pragma once
#include <iostream>
#include "Card.hpp"
#include <vector>

class Dealer
{
public:
    void addCard(const Card& card);
    Card removeCard();
    std::vector<Card> getHand();
    void showHand();
private:
    std::vector<Card> hand;
};


void Dealer::addCard(const Card& card)
{
    hand.push_back(card);
}

Card Dealer::removeCard()
{
    Card temp = hand.back();
    hand.pop_back();
    return temp;
}

std::vector<Card> Dealer::getHand()
{
    return hand;
}

void Dealer::showHand()
{
    std::cout << "Dealer's Hand:\n";
    for(const Card& card : hand)
    {
        std::cout << card.toString() << "\n";
    }
    std::cout << std::endl;
}