#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <stdio.h>
#include <string>

class Encryption
{
    public:
        Encryption(int keylength);
        virtual ~Encryption();
        void generatekey(int keylength);
        void manualkey(std::string str);
        std::string encrypt(std::string str);
        std::string decrypt(std::string str, std::string key);
        std::string getkey();
        
        void encryptrandom(std::string key);
        void decryptrandom(std::string key);
        void setbase(int temp);
        void getbase();
    protected:
    private:
        std::string key;
        
        
        
        int base;
};



#endif
