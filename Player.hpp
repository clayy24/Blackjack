#pragma once
#include "Card.hpp"
#include <iostream>
#include <vector>

class Player
{
public:
    Player(int balance, std::string name);
    Player();
    void addCard(const Card& card);
    Card removeCard();
    std::vector<Card> getHand() const;
    int getBetAmount() const;
    int getBalance() const;
    int getHandsPlayed() const;
    int getHandsWon() const;
    int getHandsLost() const;
    std::string getName() const;
    void setBetAmount(int betAmount);
    void incrementHandsPlayed();
    void incrementHandsWon();
    void incrementHandsLost();
    void showHand() const;
private:
    std::vector<Card> hand;
    std::string name;
    int betAmount;
    int balance;
    int handsPlayed = 0;
    int handsWon = 0;
    int handsLost = 0;
};

Player::Player(int balance, std::string name) : balance(balance), name(name) {}

Player::Player()
{
    name = "";
    betAmount = 50;
    balance = 500;
}

void Player::addCard(const Card& card)
{
    hand.push_back(card);
}

Card Player::removeCard()
{
    Card temp = hand.back();
    hand.pop_back();
    return temp;
}

std::vector<Card> Player::getHand() const
{
    return hand;
}

int Player::getBetAmount() const
{
    return betAmount;
}

int Player::getBalance() const
{
    return balance;
}

int Player::getHandsPlayed() const
{
    return handsPlayed;
}

int Player::getHandsWon() const
{
    return handsWon;
}

int Player::getHandsLost() const
{
    return handsLost;
}

std::string Player::getName() const
{
    return name;
}

void Player::setBetAmount(int betAmount)
{
    this->betAmount = betAmount;
}

void Player::incrementHandsPlayed()
{
    handsPlayed++;
}

void Player::incrementHandsWon()
{
    handsWon++;
}

void Player::incrementHandsLost()
{
    handsLost++;
}

void Player::showHand() const
{
    std::cout << name << "'s Hand: " << std::endl;
    
    for(const Card& card : hand)
    {
        std::cout << card.toString() << std::endl;
    }
    std::cout << std::endl;
}
