// Card.h
// Card class definition.

#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card{
    private:
        int face, suit;
    public:
        static const std::string faces[];
        static const std::string suits[];
    Card();
    Card(int suit, int face);
    virtual ~Card();
    std::string toString();
};

#endif // CARD_H
