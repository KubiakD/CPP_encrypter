#include <iostream>
#include <string>
#include <cmath>
#include "encrypt.h"

using namespace std;

int main() {
    string message {};
    //string key {"qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM "};
    string key{};
    cout << "Enter your message: " << endl;
    getline(cin, message);
    cout << "Enter your key: " << endl;
    cin >> key;
    string encrypted_message = encrypt_with_key(message, key);
    //decrypt_message(encrypted_message, key);
    cout << encrypted_message << endl;
    return 0;
}