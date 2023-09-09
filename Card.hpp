#pragma once
#include <string>


class Card
{
public:
    Card(const std::string rank, const std::string suit);
    std::string getSuit() const;
    std::string getRank() const;
    std::string toString() const;
private:
    const std::string suit;
    const std::string rank;
};

Card::Card(std::string rank, std::string suit) :  rank(rank), suit(suit){};

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
