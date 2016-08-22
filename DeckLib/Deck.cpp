#include "stdafx.h"
#include "Deck.h"
#include "Helpers.h"
#include <algorithm>
#include <random>

Deck::Deck() {
	for (int i = 0; i < 13; i++) {
		Card cc(i + 1, 'C'), cd(i + 1, 'D'), ch(i + 1, 'H'), cs(i + 1, 'S');
		cards.push_back(cc);
		cards.push_back(cd);
		cards.push_back(ch);
		cards.push_back(cs);
	}
}

Deck::~Deck() {}

void Deck::printAll() {
	for (unsigned int i = 0; i < cards.size(); i++) {
		PUTS(cards[i].toString());
	}
}

// Courtesy: http://en.cppreference.com/w/cpp/algorithm/random_shuffle
void Deck::shuffle() {
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(cards.begin(), cards.end(), g);
}

bool Deck::deal(std::vector<Card>& hand, int count) {
	if (cards.size() == 0) {
		PUTS("Deck empty!");
		return false;
	}
	for (int i = 0; i < count; i++) {
		hand.push_back(cards.back());
		cards.pop_back();
	}
	return true;
}