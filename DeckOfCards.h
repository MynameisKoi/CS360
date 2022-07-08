// DeckOfCards.h
// DeckOfCards class definition.

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include "Card.h"

class DeckOfCards{
    private:
        Card deck[52];
        int currentCard;
    public:
        DeckOfCards();
        void shuffle();
        Card dealCard();
        bool moreCards();
};

#endif // DECKOFCARDS_H
