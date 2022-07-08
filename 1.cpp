#include <iostream>
#include <iomanip>
#include "Card.h"
#include "DeckOfCards.h"
#include <stdlib.h>

using namespace std;

// Card.cpp
const std::string Card::faces[] = {"Ace", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
const std::string Card::suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

Card::Card()
{
    face = 0;
    suit = 0;
}

Card::Card(int suit, int face){
    this->face = face;
    this->suit = suit;
}

Card::~Card()
{
    //destructor
}

std::string Card::toString(){
    return Card::faces[face] + " of " + Card::suits[suit];
}

// DeckOfCards.cpp
// Default constructor
DeckOfCards::DeckOfCards()
{
    currentCard = 0;
    for (int suit = 0; suit < 4; suit++)
    {
        for (int face = 0; face < 13; face++)
        {
            deck[suit*13+face] = Card(suit, face);
        }
    }
}

// Shuffle cards
void DeckOfCards::shuffle()
{
    for (int i = 0; i < 52; i++)
    {
        int j = rand() % 52;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Deal card
Card DeckOfCards::dealCard()
{
    return deck[currentCard++];
}

// Check if there are more cards
bool DeckOfCards::moreCards()
{
    return currentCard < 52;
}

// main.cpp
int main(){
    DeckOfCards deck;
    deck.shuffle();

    int j = 0;
    while(deck.moreCards()){
        Card card = deck.dealCard();
        cout << card.toString() << endl;
    }

    if (++j % 4 == 0) {
        j = 0;
        cout << endl;
    }
    return 0;
}
