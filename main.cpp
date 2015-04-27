using namespace std;
#include <iostream>
#include "Encryption.h"

int main(int argc, const char * argv[]) {
    string teststring = "hello world";
    Encryption enc = Encryption(10, teststring);
    string key = enc.getkey();
    enc.encryptshift(key);
    cout << enc.getstring()<< endl;
    enc.decryptshift(key);
    cout << enc.getstring()<< endl;
    return 0;
}
