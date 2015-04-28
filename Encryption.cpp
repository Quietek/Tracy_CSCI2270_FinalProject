#include "Encryption.h"
#include <random>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

Encryption::Encryption(int keylength, std::string temp)
{
    setstring(temp);
    int tempint = rand() % 999 + 1;
    base = tempint;
    generatekey(keylength);
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
    if (keylength < 20)
    {
        keylength += 20;
    }
    std::string temp = "";
    int scrambleTemp = base;
    if(scrambleTemp == 0){
        scrambleTemp = 1;
    }
    int scramble = (scrambleTemp) % 13 + 97;
    char d = scramble;
    temp = temp + d;
    for (int i = 0; i < keylength - 1; i++)
    {
        if(i == keylength/2 || i == (keylength + 1)/2 )
        {
            int placerandtemp = base*3;
            if(placerandtemp == 0 || placerandtemp == scrambleTemp)
            {
                placerandtemp++;
                while(placerandtemp == scrambleTemp)
                {
                    placerandtemp++;
                }
            }
            int placerand = (placerandtemp) % 13 + 13 + 97;
            char e = placerand;
            temp = temp + e;
        }
        else
        {
            char c = rand() % 26 + 97;
            temp = temp + c;
        }
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
        int offset = int(keystr[keypos]);
        c = encryptshiftchar(c, offset);
        temp = temp + c;
        Q.pop();
    }
    str = temp;
}

char Encryption::encryptshiftchar(char c, int offset)
{
    c = c + offset;
    while (c > 126)
    {
        c = c - 126 + 33;
    }
    while (c < 0)
    {
        c = 34 + (127 - (c*-1));
    }
    return c;
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
        int offset = int(keystr[keypos]);
        c = decryptshiftchar(c, offset);
        temp = temp + c;
        Q.pop();
    }
    str = temp;
}

char Encryption::decryptshiftchar(char c, int offset)
{
    c = c - offset;
    while(c > 126)
    {
        c = c - 126 + 32;
    }
    while (c < 32)
    {
        c = 127 - (32 - c);
    }
    return c;
}

std::string Encryption::getkey()
{
    return key;
}

std::string Encryption::getstring()
{
    return str;
}

void Encryption::encryptrandom(std::string keystr)
{
    int distance = (keystr[0]-97)*.3;
    distance = distance % 3;
    if(distance == 0)
    {
        distance++;
    }
    for(int i = 0; i < str.length(); i+=distance)
    {
        char c = (rand()%(25)+97);
        std::string temp = "";
        temp = temp + c;
        if(str.length() >= i+distance){
            str.insert(distance+i, temp);
            i++;
        }
        
    }
}

void Encryption::decryptrandom(std::string keystr)
{
    int distance = (keystr[0]-97)*.3;
    distance = distance % 3;
    if(distance == 0)
    {
        distance++;
    }
    for(int i = 0; i < str.length(); i += distance)
    {
        if(i+distance < str.length()){
            str.erase(str.begin()+i+distance);
        }
    }
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
    int scrambleTemp = base;
    if(scrambleTemp == 0){
        scrambleTemp = 1;
    }
    int placerandtemp = base*3;
    if(placerandtemp == 0 || placerandtemp == scrambleTemp){
        placerandtemp++;
        while(placerandtemp == scrambleTemp){
            placerandtemp++;
        }
    }
    int scramble = (scrambleTemp) % 13 + 97;
    int placerand = (placerandtemp) % 13 + 13 + 97;
    char c = scramble;
    char d = placerand;
    std::string temp;
    for(int i = 0; i<key.size(); i++){
        temp = "";
        if(key[i] == c){
            for(int j = i+1; j<key.size() && j<10; j++){
                i++;
                temp = temp + key[j];
            }
            if(temp != ""){
                encryptshift(temp);
            }
        }
        if(key[i] == d){
            if(i+1 < key.size()){
                temp = key[i + 1];
                encryptrandom(temp);
            }
        }
    }
}

void Encryption::decrypt()
{
    std::vector<std::string> reversa;
    int scrambleTemp = base;
    if(scrambleTemp == 0){
        scrambleTemp = 1;
    }
    int placerandtemp = base*3;
    if(placerandtemp == 0 || placerandtemp == scrambleTemp){
        placerandtemp++;
        while(placerandtemp == scrambleTemp){
            placerandtemp++;
        }
    }
    int scramble = (scrambleTemp) % 13 + 97;
    int placerand = (placerandtemp) %13 + 13 + 97;
    char c = scramble;
    char d = placerand;
    std::string temp;
    for(int i = 0; i<key.size(); i++){
        temp = "";
        if(key[i] == c){
            temp = temp + key[i];
            for(int j = i+1; j<key.size() && j<10; j++){
                i++;
                temp = temp + key[j];
            }
            reversa.push_back(temp);
            
        }
        if(key[i] == d){
            temp = "";
            temp = temp + key[i];
            if(i+1 < key.size()){
                temp = temp + key[i+1];
                reversa.push_back(temp);
            }
            
        }
    }
    char determinate;
    for(long i = reversa.size()-1; i >= 0; i--){
        temp = reversa[i];
        determinate = temp[0];
        temp = temp.substr(1);
        if (temp != "")
        {
            if(determinate == c){
                decryptshift(temp);
            }else if(determinate == d){
                decryptrandom(temp);
            }
        }
    }
}
