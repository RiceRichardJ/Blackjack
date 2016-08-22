#include "stdafx.h"
#include "Card.h"

Card::Card() {}
Card::~Card() {}

Card::Card(int v, char s) {
	value = v;
	suit = s;
}

std::string Card::suitName() {
	if (suit == 'C') { return "Clubs"; }
	if (suit == 'D') { return "Diamonds"; }
	if (suit == 'H') { return "Hearts"; }
	if (suit == 'S') { return "Spades"; }
	return "";
}

std::string Card::valueName() {
	if (value == 1) { return "Ace"; }
	if (value == 11) { return "Jack"; }
	if (value == 12) { return "Queen"; }
	if (value == 13) { return "King"; }
	return std::to_string(value);
}

std::string Card::toString() {
	return valueName() + " of " + suitName();
}

// Courtesy Stackoverflow: http://stackoverflow.com/questions/1549930/c-equivalent-of-java-tostring
std::ostream& operator<<(std::ostream &strm, Card &c) {
	return strm << "[" << c.toString() << "]";
}
