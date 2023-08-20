#include <iostream>
#include "menu.h"
using std::cout;
using std::cin;
using std::endl;
char display_menu() {
	char choice;
	cout << "Select option" << endl;
	cout << "1 - Encrypt message with standard key" << endl;
	cout << "2 - Encrypt message with custom key" << endl;
	cout << "3 - Decrypt message" << endl;
	cout << "9 - Close program" << endl;
	cin >> choice;
	return choice;
}