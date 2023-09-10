#pragma once
#include <string>


class Card
{
public:
    Card(std::string rank, std::string suit);
    std::string getSuit() const;
    std::string getRank() const;
    std::string toString() const;
private:
    std::string suit;
    std::string rank;
};

Card::Card(std::string rank, std::string suit) : rank(rank), suit(suit){}

std::string Card::getRank() const
{
    return rank;
}

std::string Card::getSuit() const
{
    return suit;
}

std::string Card::toString() const
{
    return rank + " of " + suit;
}
