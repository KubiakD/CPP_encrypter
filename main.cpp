#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string alphabet {"abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

string encrypt_message(string &message, string &key) {
  string encrypted_message{};
  for (char c: message) {
    size_t current_letter_index { alphabet.find(c) };
    encrypted_message += key.at(current_letter_index);
  }
  cout << "Encrypted message is: " << encrypted_message << endl;
  return encrypted_message;
}

string decrypt_message(string &message, string &key) {
  string decrypted_message{};
  for (char c: message) {
    size_t current_letter_index { key.find(c) };
    decrypted_message += alphabet.at(current_letter_index);
  }
  cout << "Decrypted message is: " << decrypted_message << endl;
  return decrypted_message;
}

string encrypt_with_key(string& message, string& key) {
    size_t key_length = key.length();
    size_t message_length = message.length();
    size_t counter = floor(message_length/key_length);
    size_t remainder = message_length % (key_length * counter);

    string modified_key{};
    for (size_t i{ 0 }; i < counter; i++)
        modified_key.append(key);
    modified_key += key.substr(0, remainder);

    for (size_t i{ 0 }; i < message_length; i++) {
        size_t key_index = alphabet.find(modified_key.at(i));
        size_t message_index = alphabet.find(message.at(i));
        size_t index_sum = key_index + message_index;
        size_t alphabet_index{index_sum>alphabet.length()?index_sum-alphabet.length():index_sum};
        message.at(i) = alphabet.at(alphabet_index);
    }
    return message;
}

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