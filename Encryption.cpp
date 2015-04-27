#include "Encryption.h"
#include <random>
#include <iostream>
#include <queue>

Encryption::Encryption(int keylength, std::string temp)
{
    generatekey(keylength);
    setstring(temp);
}

Encryption::Encryption(std::string keystr, std::string temp, int base)
{
    manualkey(keystr);
    setstring(temp);
    setbase(base);
}
Encryption::~Encryption()
{
    
}

void Encryption::generatekey(int keylength)
{
    std::string temp = "";
    for (int i = 0; i < keylength; i++)
    {
        char c = rand() % 26 + 97;
        temp = temp + c;
    }
    key = temp;
}

void Encryption::manualkey(std::string str)
{
    key = str;
}

void Encryption::setstring(std::string temp)
{
    str = temp;
}
void Encryption::encryptshift()
{
    std::string temp = "";
    std::queue<char> Q;
    char c;
    for( int i = 0; i < str.length(); i++)
    {
        Q.push(str[i]);
    }
    while(!Q.empty())
    {
        c = Q.front();
        int keypos = Q.size() % key.size();
        c = c - key[keypos];
        temp = temp + c;
        Q.pop();
    }
    str = temp;
}

void Encryption::decryptshift(std::string keystr)
{
    std::string temp = "";
    std::queue<char> Q;
    char c;
    for( int i = 0; i < str.length(); i++)
    {
        Q.push(str[i]);
    }
    while(!Q.empty())
    {
        c = Q.front();
        int keypos = Q.size() % key.size();
        c = c + key[keypos];
        temp = temp + c;
        Q.pop();
    }
    str = temp;
}

std::string Encryption::getkey()
{
    return key;
}

std::string Encryption::getstring()
{
    return str;
}
