#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
// User class to store username and password
class User {
   private:
    string username, password;

   public:
    // Constructor to initialize the user with a username and password
    User(string name, string pass) {
        username = name;
        password = pass;
    }
    // Getter for usernama
    string getUsername() { return username; }
    // Getter for password
    string getPassword() { return password; }
};
// UserManager class to handle user management operations
class UserManager {
   private:
    map<string, string> users;  // Map to store users, with username as key and
                                // password as value

   public:
    // Method to register a new user
    void RegisterUser() {
        string username, password;
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
        // Check if the username already exists
        if (users.find(username) != users.end()) {
            cout << "\t\t Username already exists. Please choose a different "
                    "username."
                 << endl;
        } else {
            // Add the new user to the map
            users[username] = password;
            cout << "\t\t User Registered Successfully" << endl;
        }
    }
    // Method to log in a user
    void LoginUser() {
        string username, password;
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
        // Check if the username exists
        if (users.find(username) != users.end()) {
            // Check if the password is correct
            if (users[username] == password) {
                cout << "\t\t Login Successful" << endl;
            } else {
                cout << "\t\t Invalid Password" << endl;
            }
        } else {
            cout << "\t\t User not registered. Please register first." << endl;
        }
    }
    // Method to show the list of registered users
    void ShowUserList() {
        cout << "\t\t User List:" << endl;
        for (auto const& user : users) {
            cout << "\t\t " << user.first << endl;
        }
    }
    // Method to search for a specific user
    void SearchUser() {
        string username;
        cout << "Enter Username to Search: ";
        cin >> username;
        // Check if the user exists
        if (users.find(username) != users.end()) {
            cout << "\t\t User Found" << endl;
            cout << "\t\t Welcome, " << username << "!" << endl;
            // Perform additional actions, such as displaying user-specific
            // information or options
        } else {
            cout << "\t\t User Not Found" << endl;
        }
    }
    // Method to delete a user
    void DeleteUser() {
        string username;
        cout << "Enter Username to Delete: ";
        cin >> username;
        // Check if the user exists
        if (users.find(username) != users.end()) {
            // Remove the user from the map
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
        // Display the menu options
        cout << "\n\n\t\t1. Register User" << endl;
        cout << "\t\t2. Login" << endl;
        cout << "\t\t3. Show User List " << endl;
        cout << "\t\t4. Search user " << endl;
        cout << "\t\t5. Delete User " << endl;
        cout << "\t\t6. Exit " << endl;
        cout << "\t\tEnter your choice:  ";
        cin >> op;
        // Handle menu options
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
                return 0;  // Exit the program
            default:
                cout << "\t\t Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}