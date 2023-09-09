#include <iostream>
#include "Card.hpp"
#include "Deck.hpp"

int main(int argc, char** argv)
{
    Deck deck = Deck();
    std::cout << deck.toString() << std::endl;

    deck.shuffle();
    std::cout << deck.toString() << std::endl;

    return 0;
}