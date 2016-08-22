// BlackjackGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Blackjack.h"
#include "Helpers.h"

int _tmain(int argc, _TCHAR* argv[]) {
	while (true) {
		Blackjack bj;
		bj.play();
		PUT("\nPlay Again? [y/n]: ");
		if (GETS() != "y") {
			break;
		}
	}
	return 0;
}

