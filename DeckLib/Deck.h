#pragma once

#include <vector>
#include "Card.h"

//#define DECKLIB_EXPORTS
#ifdef DECKLIB_EXPORTS
#define DECKLIB_API __declspec(dllexport) 
#else
#define DECKLIB_API __declspec(dllimport) 
#endif

class Deck {
public:
	DECKLIB_API Deck();
	DECKLIB_API ~Deck();
	std::vector<Card> cards;
	DECKLIB_API void printAll();
	DECKLIB_API void shuffle();
	DECKLIB_API bool deal(std::vector<Card>&, int);
};

