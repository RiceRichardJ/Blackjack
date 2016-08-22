#pragma once

#include "Deck.h"

typedef std::vector<Card> CardVec;

class Blackjack {
public:
	Blackjack();
	~Blackjack();
	Deck d;
	CardVec dealerHand;
	CardVec playerHand;

	void play();
	void shuffleAndDeal(Deck& d, CardVec& dHand, CardVec& pHand);
	void hit(Deck& d, CardVec& hand);
	void printHand(CardVec& hand);
	void printHiddenHand(CardVec& hand);
	bool checkWin(CardVec& dealerHand, CardVec& playerHand);
	void endGame(CardVec& dHand, CardVec& pHand);
	int blackjackValue(CardVec& cards);
};