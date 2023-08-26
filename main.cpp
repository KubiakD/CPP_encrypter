#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include "encrypt.h"
#include "menu.h"

using namespace std;

int main() {
    char user_choice;
    do
    {
        user_choice = display_menu();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    switch (user_choice) 
    {
    case '1':
    {
        string message = get_message();
        string encrypted_message = encrypt_message(message);
        cout << encrypted_message << endl;
        break;
    }
    case '2':
    {
        string message = get_message();
        string key = get_key();
        string encrypted_message = encrypt_with_key(message, key);
        cout << encrypted_message << endl;
        break;
    }
    case '3':
    {
        string decrypted_message = decrypt_message();
        cout << decrypted_message << endl;
        break;
    }
    case '9':
        cout << "See you again!" << endl;
        break;
    default:
        cout << "Wrong input!" << endl;
        break;
    }
    } while (user_choice != '9');
    return 0;
}