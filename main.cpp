using namespace std;
#include <iostream>
#include "Encryption.h"
#include <string>


Encryption prompt()
{
    int input, input2, length;
    string str, str2, str3;
    cout << "Use existing base and key? (1. Yes, 2. No)" << endl;
    cin >> input;
    cin.ignore(256, '\n');
    Encryption enc;
    if (input == 1)
    {
        cout << "Input base" << endl;
        cin >> input2;
        cin.ignore(256, '\n');
        cout << "Input key" << endl;
        getline(cin, str);
        cout << "Input string to modify" << endl;
        getline(cin, str2);
        enc = Encryption(str, str2, input2);
        return enc;
    } else if (input == 2)
    {
        cout << "How long would you like the key to be?" << endl;
        cin >> length;
        cin.ignore(256, '\n');
        cout << "What is the string?" << endl;
        getline(cin, str3);
        enc = Encryption(length, str3);
    }
    return enc;
}

void displayMenu()
{
    cout << "======Main Menu======" << endl;
    cout << "1. Get string in current state" << endl;
    cout << "2. Set new string" << endl;
    cout << "3. Get key in current state" << endl;
    cout << "4. Set new key" << endl;
    cout << "5. Get base in current state" << endl;
    cout << "6. Set new base" << endl;
    cout << "7. Encrypt string" << endl;
    cout << "8. Decrypt string" << endl;
    cout << "9. Quit" << endl;
}

int main(int argc, const char * argv[]) {
    int input, base;
    string keystr, str0;
    bool appIsRunning = true;
    Encryption enc = prompt();
    while(appIsRunning)
    {
        displayMenu();
        cin >> input;
        cin.ignore(256, '\n');
        switch (input)
        {
            case 1:
                cout << enc.getstring() << endl;
                break;
            case 2:
                cout << "Input new string" << endl;
                getline(cin, str0);
                enc.setstring(str0);
                str0 = "";
                break;
            case 3:
                cout << enc.getkey() << endl;
                break;
            case 4:
                cout << "Input new key" << endl;
                getline(cin, keystr);
                keystr = "";
                break;
            case 5:
                cout << enc.getbase() << endl;
                break;
            case 6:
                cout << "Input new base" << endl;
                cin >> base;
                cin.ignore(256, '\n');
                break;
            case 7:
                cout << "Encrypting string" << endl;
                enc.encrypt();
                cout << enc.getstring() << endl;
                break;
            case 8:
                cout << "Decrypting string" << endl;
                enc.decrypt();
                cout << enc.getstring() << endl;
                break;
            case 9: 
                cout << "Goodbye!" << endl;
                appIsRunning = false;
                break;
            default:
                cout << "Invalid Input" << endl;
                cin.clear();
                cin.ignore(10000,'\n');
                break;
        }
    }
    return 0;
}
