#pragma once

//#ifndef HELPERS_H_
//#define HELPERS_H_

#include <iostream>
#define PUTS(x) (std::cout << x << std::endl)
#define PUT(x) (std::cout << x)

typedef std::string String;

// Is this bad?
extern String readString(); /*{
							String mystr;
							std::getline(std::cin, mystr);
							return mystr;
							}*/

#define GETS() (readString())	// just for the syntax highlighting hahaha



//#endif