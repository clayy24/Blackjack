#pragma once
#include "Card.hpp"
#include "Player.hpp"
#include "Dealer.hpp"
#include "Deck.hpp"
#include <vector>
#include <string>

#define FLAG 4

class Table
{
public:
    void dealCards();
    void showHands();
    void endHand();
    void showDiscardPile();
    void runGame();
    void modifyBet();
    void cashOut();
    int endGame();
private:
    Deck deck = Deck();
    Player player = Player();
    Dealer dealer;
    std::vector<Card> discardPile;
};

void Table::dealCards()
{
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
}

void Table::showHands()
{
    dealer.showHand();
    player.showHand();

}

void Table::endHand()
{
    discardPile.push_back(player.removeCard());
    discardPile.push_back(dealer.removeCard());
}

void Table::showDiscardPile()
{
    std::cout << "Discard pile:\n";
    for(const Card& card : discardPile)
    {
        std::cout << card.toString() << "\n";
    }
    std::cout << std::endl;
}

void Table::runGame()
{
    int flag = 0;

    while(flag != FLAG)
    {
        std::cout << "Curent balance: $" << player.getBalance() << std::endl;
        std::cout << "Current bet amount: $" << player.getBetAmount() << std::endl;

        switch(prompt())
        {
            case 1:
                modifyBet();
                break;
            case 2:
                dealCards();
                break;
            case 3:
                cashOut();
                flag = endGame();
                break;
            case 4:
                flag = endGame();
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }


    }
}


void Table::modifyBet()
{
    int newBetAmount;

    std::cout << "Enter the amount you would like to bet: ";
    std::cin >> newBetAmount;

    while(newBetAmount > player.getBalance())
    {
        std::cout << "Error: cannot bet more than current balance.\n";
        std::cout << "Enter a new bet amount: ";

        std::cin >> newBetAmount;
    }

    player.setBetAmount(newBetAmount);
}

void Table::cashOut()
{
    std::cout << "You are cashing out with $" << player.getBalance() << "!";
}

int Table::endGame()
{
    std::cout << "Game over." << std::endl;
    return FLAG;
}

int prompt()
{
    int input;

    std::cout << "1. Modify bet\n";
    std::cout << "2: Deal cards\n";
    std::cout << "3: Cash out\n";
    std::cout << "4: Exit" << std::endl;

    std::cin >> input;

    return input;
}