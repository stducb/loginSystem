#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isLoggedIn(const string& username, const string& password)
{
    ifstream read("Accounts\\" + username + ".txt");
    if (!read.is_open()) {
        return false;
    }

    string un, pw;
    getline(read, un);
    getline(read, pw);

    return (un == username && pw == password);
}

void registerUser()
{
    string username, password;

    cout << "Select a username: ";
    cin >> username;
    cout << "Select a password: ";
    cin >> password;

    ofstream file("Accounts\\" + username + ".txt");
    if (!file) {
        cerr << "Error creating user file." << endl;
        return;
    }

    file << username << endl << password;
    file.close();

    cout << "Registration successful!" << endl;
}

int main()
{
    int choice;

    cout << "1: Register\n2: Login\nYour choice: ";
    cin >> choice;

    if (choice == 1) {
        registerUser();
    }
    else if (choice == 2) {
        string username, password;

        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        bool status = isLoggedIn(username, password);

        if (!status) {
            cout << "False Login!" << endl;
        }
        else {
            cout << "Successfully logged in!" << endl;
        }
    }

    return 0;
}
