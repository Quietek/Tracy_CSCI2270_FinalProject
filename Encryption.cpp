#include "Encryption.h"
#include <rand>

Encryption::Encryption(int keylength)
{
    generatekey(keylength);
}

Encryption::~Encryption()
{
    
}

void Encryption::generatekey(int keylength)
{
    std::string temp = "";
    for (int i = 0; i < keylength; i++)
    {
        int intchar = rand() % 26 + 97;
        std::string temp = temp + intchar;
    }
    key = temp;
}

void Encryption::manualkey(std::string str)
{
    key = str;
}

std::string Encryption::encrypt(std::string str)
{
    int length = str.length();
    std::string encstr = "";
    for (int i = 0; i < length; i++)
    {
        int keypos = i % key.length();
        char c = str[i] - key[keypos];
        encstr += c;
    }
    return encstr;
}

std::string Encryption::decrypt(std::string str, std::string keystr)
{
    int length = str.length();
    std::string decstr = "";
    for (int i = 0; i < length; i++)
    {
        int keypos = i % keystr.length();
        char c = str[i] + keystr[keypos];
        decstr += c;
    }
    return decstr;
    
}

std::string Encryption::getkey()
{
    return key;
}