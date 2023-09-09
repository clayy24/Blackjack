#include <iostream>
#include "Card.hpp"
#include "Deck.hpp"

int main(int argc, char** argv)
{
    Card card = Card("Ace", "Hearts");
    Card card2 = Card("King", "Spades");

    Deck deck = Deck();
    std::cout << deck.toString() << std::endl;

    deck.shuffle();

    return 0;
}