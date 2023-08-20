#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <string>

std::string encrypt_message(std::string& message, std::string& key);
std::string decrypt_message(std::string& message, std::string& key);
std::string encrypt_with_key(std::string& message, std::string& key);
std::string get_message();
std::string get_key();

#endif
