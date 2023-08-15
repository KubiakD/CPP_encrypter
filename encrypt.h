#ifndef _ENCRYPT_H
#define _ENCRYPT_H
string alphabet {"abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
string encrypt_with_key(string& message, string& key);
string decrypt_message(string& message, string& key);
string encrypt_message(string& message, string& key);


#endif