#include "Encryption.h"
#include <random>
#include <iostream>
#include <queue>

Encryption::Encryption(int keylength, std::string temp)
{
    generatekey(keylength);
    setstring(temp);
    int tempint = rand() % 999 + 1;
    base = tempint;
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
void Encryption::encryptshift(std::string keystr)
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
        int keypos = Q.size() % keystr.size();
        c = c - key[keypos];
        while (c < 0)
        {
            c = c + 127;
        }
        while (c > 127)
        {
            c = c - 127;
        }
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
        int keypos = Q.size() % keystr.size();
        c = c + key[keypos];
        while (c > 127)
        {
            c = c - 127;
        }
        while (c < 0)
        {
            c = c + 127;
        }
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

void Encryption::encryptrandom(std::string key)
{
    
}

void Encryption::decryptrandom(std::string key)
{
    
}

void Encryption::setbase(int baseint)
{
    base = baseint;
}

int Encryption::getbase()
{
    return base;
}

void Encryption::encrypt()
{
    int scramble = 13%(base*0.2) + 97;
    int placerand = 13%(base*0.7) + 13 + 97;
    std::string scrambleNote = std::to_string(scramble);
    std::string placeRandNote = std::to_string(placerand);
    std::string temp;
    for(int i = 0; i<key.size(); i++){
        temp = "";
        if(key[i] == scrambleNote){
            for(int j = i+1; j<key.size(); j++){
                i++;
                temp = temp + key[j]
            }
            encryptshift(temp);
        }
        if(key[i] == paceRandNote){
            if(i+1 < key.size()){
                encryptrandom(key[i+1]);
            }
        }
    }
}

void Encryption::decrypt()
{
    int scramble = 13%(base*0.2) + 97;
    int placerand = 13%(base*0.7) + 13 + 97;
    std::string scrambleNote = std::to_string(scramble);
    std::string placeRandNote = std::to_string(placerand);
    std::string temp;
    for(int i = 0; i<key.size(); i++){
        temp = "";
        if(key[i] == scrambleNote){
            for(int j = i+1; j<key.size(); j++){
                i++;
                temp = temp + key[j]
            }
            decryptshift(temp);
        }
        if(key[i] == paceRandNote){
            if(i+1 < key.size()){
                decryptrandom(key[i+1]);
            }
        }
    }
}
