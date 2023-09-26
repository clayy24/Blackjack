#pragma once
#include "Card.hpp"
#include "Player.hpp"
#include "Dealer.hpp"
#include "Deck.hpp"
#include <vector>
#include <string>

#define FLAG 5

class Table
{
public:
    void addPlayer();
    void dealCards();
    void showHands();
    void endHand();
    void showDiscardPile();
    void runGame();
    void placeBet();
private:
    Deck deck = Deck();
    std::vector<Player> players;
    Dealer dealer;
    std::vector<Card> discardPile;
};

void Table::addPlayer()
{
    std::string name;
    int bal;

    std::cout << "Enter player name: ";
    std::cin >> name;
    std::cout << "Enter player balance: ";
    std::cin >> bal;
    std::cout << "\n";
    Player player = Player(bal, name);
    players.push_back(player);
}

void Table::dealCards()
{
    for(int i = 0; i < 2; i++)
    {
        for(Player& player : players)
        {
            player.addCard(deck.dealCard());
        }
        dealer.addCard(deck.dealCard());
    }
}

void Table::showHands()
{
    dealer.showHand();
    for(const Player& player : players)
    {
        player.showHand();
    }
}

void Table::endHand()
{
    for(int i = 0; i < 2; i++)
    {
        for(Player& player : players)
        {
            discardPile.push_back(player.removeCard());
        }
        discardPile.push_back(dealer.removeCard());
    }
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
        switch(prompt())
        {
            case 1:
                addPlayer();
                break;
            case 2:
                placeBet();
                break;
                
        }


    }
}

void Table::placeBet()
{
    
}

int prompt()
{
    int input;

    std::cout << "1: Add player\n";
    std::cout << "2. Place bet\n";
    std::cout << "3: Deal cards\n";
    std::cout << "4: Cash out\n";
    std::cout << "5: Exit" << std::endl;

    std::cin >> input;

    return input;
}