#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <stdio.h>
#include <string>

class Encryption
{
public:
    Encryption(int keylength, std::string temp);
    Encryption(std::string keystr, std::string temp, int base);
    virtual ~Encryption();
    void generatekey(int keylength);
    void manualkey(std::string str);
    void setstring(std::string str);
    void encrypt();
    void encrypt(std::string keystr);
    void decrypt();
    void decrypt(std::string keystr);
    void encryptshift(std::string keystr);
    void decryptshift(std::string keystr);
    std::string getkey();
    std::string getstring();
    
    char encryptshiftchar(char c, int offset);
    char decryptshiftchar(char c, int offset);
    
    void encryptrandom(std::string key);
    void decryptrandom(std::string key);
    void setbase(int temp);
    int getbase();
protected:
private:
    std::string key;
    std::string str;
    int base;
};

#endif
