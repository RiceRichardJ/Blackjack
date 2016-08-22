#pragma once

#include <string>

//#define DECKLIB_EXPORTS
#ifdef DECKLIB_EXPORTS
#define DECKLIB_API __declspec(dllexport) 
#else
#define DECKLIB_API __declspec(dllimport) 
#endif

class Card {
public:
	DECKLIB_API Card();
	DECKLIB_API Card(int, char);
	DECKLIB_API ~Card();
	int value;
	char suit;
	DECKLIB_API std::string valueName();
	DECKLIB_API std::string suitName();
	DECKLIB_API std::string toString();
	DECKLIB_API friend std::ostream& operator<<(std::ostream&, Card&);
};