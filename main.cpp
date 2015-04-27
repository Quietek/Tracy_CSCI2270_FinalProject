using namespace std;
#include <iostream>
#include "Encryption.h"

int main(int argc, const char * argv[]) {
    string teststring = "hello world";
    Encryption enc = Encryption(10);
    string newstring = enc.encrypt(teststring);
    cout << newstring << endl;
    string key = enc.getkey();
    string oldstring = enc.decrypt(newstring, key)
    cout << oldstring << endl;
    return 0;
}
