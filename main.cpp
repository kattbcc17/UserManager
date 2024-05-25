#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class User {
   private:
    string username, password;

   public:
    User(string name, string pass) {
        username = name;
        password = pass;
    }

    string getUsername() { return username; }

    string getPassword() { return password; }
};

class UserManager {
   private:
    map<string, string> users;

   public:
    void RegisterUser() {
        string username, password;
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;

        if (users.find(username) != users.end()) {
            cout << "\t\t Username already exists. Please choose a different "
                    "username."
                 << endl;
        } else {
            users[username] = password;
            cout << "\t\t User Registered Successfully" << endl;
        }
    }

    void LoginUser() {
        string username, password;
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;

        if (users.find(username) != users.end()) {
            if (users[username] == password) {
                cout << "\t\t Login Successful" << endl;
            } else {
                cout << "\t\t Invalid Password" << endl;
            }
        } else {
            cout << "\t\t User not registered. Please register first." << endl;
        }
    }

    void ShowUserList() {
        cout << "\t\t User List:" << endl;
        for (auto const& user : users) {
            cout << "\t\t " << user.first << endl;
        }
    }

    void SearchUser() {
        string username;
        cout << "Enter Username to Search: ";
        cin >> username;

        if (users.find(username) != users.end()) {
            cout << "\t\t User Found" << endl;
            cout << "\t\t Welcome, " << username << "!" << endl;
            // Perform additional actions, such as displaying user-specific
            // information or options
        } else {
            cout << "\t\t User Not Found" << endl;
        }
    }

    void DeleteUser() {
        string username;
        cout << "Enter Username to Delete: ";
        cin >> username;

        if (users.find(username) != users.end()) {
            users.erase(username);
            cout << "\t\t User Deleted Successfully" << endl;
        } else {
            cout << "\t\t User Not Found" << endl;
        }
    }
};

int main() {
    UserManager usermanage;

    int op;
    while (true) {
        cout << "\n\n\t\t1. Register User" << endl;
        cout << "\t\t2. Login" << endl;
        cout << "\t\t3. Show User List " << endl;
        cout << "\t\t4. Search user " << endl;
        cout << "\t\t5. Delete User " << endl;
        cout << "\t\t6. Exit " << endl;
        cout << "\t\tEnter your choice:  ";
        cin >> op;

        switch (op) {
            case 1:
                usermanage.RegisterUser();
                break;
            case 2:
                usermanage.LoginUser();
                break;
            case 3:
                usermanage.ShowUserList();
                break;
            case 4:
                usermanage.SearchUser();
                break;
            case 5:
                usermanage.DeleteUser();
                break;
            case 6:
                return 0;
            default:
                cout << "\t\t Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}