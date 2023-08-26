#include <iostream>
#include "encrypt.h"
#include <string>
using namespace std;
std::string alphabet {"abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

std::string get_message()
{
    std::string message {};
    cout << "Enter your message: " << endl;
    getline(cin, message);
    return message;
}

std::string get_key()
{
    std::string key {};
    cout << "Enter your key: " << endl;
    getline(cin, key);
    return key;
}

std::string encrypt_message(std::string& message) {
    string key{ "qwertyuiopasdfghjklzxcvbnm QWERTYUIOPASDFGHJKLZXCVBNM"};
    std::string encrypted_message{};
    for (char c : message) {
        size_t current_letter_index{ alphabet.find(c) };
        encrypted_message += key.at(current_letter_index);
    }
    cout << "Encrypted message is: " << encrypted_message << endl;
    return encrypted_message;
}

std::string decrypt_message(std::string& message, std::string& key) {
    std::string decrypted_message{};
    for (char c : message) {
        size_t current_letter_index{ key.find(c) };
        decrypted_message += alphabet.at(current_letter_index);
    }
    cout << "Decrypted message is: " << decrypted_message << endl;
    return decrypted_message;
}

std::string encrypt_with_key(std::string& message, std::string& key) {
    size_t key_length = key.length();
    size_t message_length = message.length();
    size_t counter = floor(message_length / key_length);
    size_t remainder = message_length % (key_length * counter);

    std::string modified_key{};
    for (size_t i{ 0 }; i < counter; i++)
        modified_key.append(key);
    modified_key += key.substr(0, remainder);

    for (size_t i{ 0 }; i < message_length; i++) {
        size_t key_index = alphabet.find(modified_key.at(i));
        size_t message_index = alphabet.find(message.at(i));
        size_t index_sum = key_index + message_index;
        size_t alphabet_index{ index_sum > alphabet.length() ? index_sum - alphabet.length() : index_sum };
        message.at(i) = alphabet.at(alphabet_index);
    }
    return message;
}