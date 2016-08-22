#include <iostream>
#include <vector>
#include "stdafx.h"
#include "Blackjack.h"
#include "Helpers.h"

// Extern Helper.h
String readString() {
	String mystr;
	std::getline(std::cin, mystr);
	return mystr;
}

Blackjack::Blackjack() { }
Blackjack::~Blackjack() { }

///// Main Game Loop ////
void Blackjack::play() {
	// Shuffle, Deal, Show Initial Hands
	PUTS("\n#####BLACKJACK#####");
	shuffleAndDeal(d, dealerHand, playerHand);
	PUTS("\nDEALER'S HAND: ");
	printHiddenHand(dealerHand);
	PUTS("\nYOUR HAND: ");
	printHand(playerHand);

	// Did anyone get dealt a blackjack??
	if (checkWin(dealerHand, playerHand)) {
		PUTS("\nDealer shows his hand:");
		printHand(dealerHand);
		return;
	}

	// Player's Turn: Hit or Stand Loop
	while (true) {
		PUTS("\nYOUR TURN:");
		PUT("Hit or Stand? [H/S]: ");
		String ans = GETS();
		if (ans == "H" || ans == "h") {
			PUTS("HIT.");
			hit(d, playerHand);
			if (checkWin(dealerHand, playerHand)) { return; }
		}
		else if (ans == "S" || ans == "s") {
			PUTS("STAND.");
			break;
		}
		else {
			PUTS("Invalid input, try again.");
		}
	}

	// Dealer's Turn: Hit until higher score than player.
	PUTS("\nDEALER'S TURN:");
	PUTS("\nDealer shows his hand:");
	printHand(dealerHand);
	while (blackjackValue(dealerHand) < blackjackValue(playerHand)) {
		PUTS("\nDealer hits:");
		hit(d, dealerHand);
		if (checkWin(dealerHand, playerHand)) { return; }
	}

	// Game over. Player with greater hand under 21 wins.
	endGame(dealerHand, playerHand);
	PUTS("");
}


// Shuffle and deal the cards from Deck to hands.
void Blackjack::shuffleAndDeal(Deck& d, CardVec& dHand, CardVec& pHand) {
	PUTS("The dealer shuffles and deals the cards.");
	d.shuffle();
	d.deal(dHand, 2);
	d.deal(pHand, 2);
}


// Hit: Deal one card from Deck to "hand"
void Blackjack::hit(Deck& d, CardVec& hand) {
	d.deal(hand, 1);
	printHand(hand);
}


// Print Hand
void Blackjack::printHand(CardVec& hand) {
	for (int i = 0; i < hand.size(); i++) {
		PUTS(hand[i]);
	}
	PUT("VALUE: ");
	PUTS(blackjackValue(hand));
}


// Print Hidden Hand: Dealer only shows one card.
void Blackjack::printHiddenHand(CardVec& hand) {
	PUTS(hand[0]);
	for (int i = 1; i < hand.size(); i++) { PUTS("[???]"); }
	PUT("VALUE: ");
	CardVec firstCard = { hand[0] };
	PUT(blackjackValue(firstCard));  PUTS("?");
}


// Checks for wins by 21.
bool Blackjack::checkWin(CardVec& dealerHand, CardVec& playerHand) {
	int dealerScore = blackjackValue(dealerHand);
	int playerScore = blackjackValue(playerHand);
	if (dealerScore < 21 && playerScore < 21) {
		return false;
	}
	if (playerScore == 21) {
		PUTS("\nYOU WIN!");
		return true;
	}
	else if (dealerScore == 21) {
		PUTS("\nYOU LOSE!");
		return true;
	}
	else if (playerScore > 21) {
		PUTS("\nYOU LOSE!");
		return true;
	}
	else if (dealerScore > 21) {
		PUTS("\nYOU WIN!");
		return true;
	}
	printHand(dealerHand);
	printHand(playerHand);
	return false;
}


// Checks for wins by greater score.
// "checkWin()" must be run before "endGame()" incase of wins thru 21.
void Blackjack::endGame(CardVec& dHand, CardVec& pHand) {
	int dealerScore = blackjackValue(dHand);
	int playerScore = blackjackValue(pHand);
	if (dealerScore == playerScore) {
		PUTS("\nTIE GAME!");
	}
	else if (dealerScore > playerScore) {
		PUTS("\nYOU LOSE!");
	}
	else {
		PUTS("\nYOU WIN!");
	}
}


// Calculate value of hand setting Ace as High or Low
// to try and keep value under 21.
// Blackjack face cards are worth 10 instead of 11-13.
int Blackjack::blackjackValue(CardVec& cards) {
	int sum = 0;

	// Create copy so we can remove as we count.
	std::vector<Card> copy(cards);

	// Sum non-ace cards first.
	for (int i = 0; i < copy.size(); i++) {
		if (copy[i].value != 1) {
			if (copy[i].value > 10) {
				sum += 10;
			}
			else {
				sum += copy[i].value;
			}
			copy.erase(copy.begin() + i);
			i--;
		}
	}

	// Add with Ace High or Low
	for (int i = 0; i < copy.size(); i++) {
		if (sum + 11 <= 21) {
			sum += 11;
		}
		else {
			sum += 1;
		}
		copy.erase(copy.begin() + i);
		i--;
	}
	return sum;
}
