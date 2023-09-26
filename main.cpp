#include <iostream>
#include "Card.hpp"
#include "Dealer.hpp"
#include "Deck.hpp"
#include "Table.hpp"

int main(int argc, char** argv)
{
    Table table;

    table.addPlayer();
    table.addPlayer();
    table.dealCards();
    table.showHands();
    table.endHand();
    table.dealCards();
    table.showHands();
    table.showDiscardPile();

    return 0;
}