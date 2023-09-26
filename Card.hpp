#pragma once
#include <string>


class Card
{
public:
    Card(std::string rank, std::string suit);
    std::string getSuit() const;
    std::string getRank() const;
    std::string toString() const;
    int getValue() const;
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

int Card::getValue() const
{
    if (rank == "Jack" || rank == "Queen" || rank == "King") {
            return 10;
        } else if (rank == "Ace") {
            return 11; // Aces are initially worth 11, can be adjusted later
        } else {
            // For numbered cards (2-10), return their face value
            return std::stoi(rank);
        }
}
