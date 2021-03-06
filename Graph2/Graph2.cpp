// Graph2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "Basic.h"

void menu() {

	std::cout << "e - exit\n";
	std::cout << "h - help\n";
	std::cout << "1 - Basic\n";
}

void doBasic() {

	Basic::Node *f = 0;
	int len;

	std::cout << "Number of nodes... ";
	std::cin >> len;

	Basic::readGraph(f, len);
	Basic::printGraph(f);
	Basic::printGrades(f);
}

void choose(){

	char option;
	do {

		std::cout << "Option... ";
		std::cin >> option;
		switch (option) {

		case 'h': menu(); break;
		case '1': doBasic();  break;

		}

	} while (option != 'e');
}

int main()
{
	menu();
	choose();
	
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
