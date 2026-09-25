#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Check whether username already exists
bool userExists(string username)
{
    ifstream file("users.txt");

    string storedUsername, storedPassword, storedEmail, storedMobile;

    while (file >> storedUsername >> storedPassword >> storedEmail >> storedMobile)
    {
        if (storedUsername == username)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// Registration Function
void registerUser()
{
    string username, password, confirmPassword;
    string email, mobile;

    cout << "\n================================\n";
    cout << "        USER REGISTRATION\n";
    cout << "================================\n";

    // Username
    cout << "Enter username: ";
    cin >> username;

    if (username.length() < 3)
    {
        cout << "Error: Username must contain at least 3 characters.\n";
        return;
    }

    // Check duplicate username
    if (userExists(username))
    {
        cout << "Error: Username already exists!\n";
        cout << "Please choose another username.\n";
        return;
    }

    // Email
    cout << "Enter email: ";
    cin >> email;

    if (email.find('@') == string::npos)
    {
        cout << "Error: Please enter a valid email address.\n";
        return;
    }

    // Mobile
    cout << "Enter mobile number: ";
    cin >> mobile;

    if (mobile.length() != 10)
    {
        cout << "Error: Mobile number must contain 10 digits.\n";
        return;
    }

    // Password
    cout << "Create password: ";
    cin >> password;

    if (password.length() < 6)
    {
        cout << "Error: Password must contain at least 6 characters.\n";
        return;
    }

    // Confirm password
    cout << "Confirm password: ";
    cin >> confirmPassword;

    if (password != confirmPassword)
    {
        cout << "Error: Passwords do not match!\n";
        return;
    }

    // Store user information
    ofstream file("users.txt", ios::app);

    if (!file)
    {
        cout << "Error: Unable to create users.txt file.\n";
        return;
    }

    file << username << " "
         << password << " "
         << email << " "
         << mobile << endl;

    file.close();

    cout << "\n================================\n";
    cout << "Registration Successful!\n";
    cout << "Welcome, " << username << "!\n";
    cout << "================================\n";
}

// Login Function
void loginUser()
{
    string username, password;

    string storedUsername;
    string storedPassword;
    string storedEmail;
    string storedMobile;

    cout << "\n================================\n";
    cout << "             LOGIN\n";
    cout << "================================\n";

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");

    if (!file)
    {
        cout << "Error: No registered users found.\n";
        return;
    }

    while (file >> storedUsername
                >> storedPassword
                >> storedEmail
                >> storedMobile)
    {
        if (username == storedUsername &&
            password == storedPassword)
        {
            file.close();

            cout << "\n================================\n";
            cout << "Login Successful!\n";
            cout << "Welcome, " << username << "!\n";
            cout << "================================\n";

            return;
        }
    }

    file.close();

    cout << "\nError: Invalid username or password.\n";
}

// Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << "     LOGIN & REGISTRATION SYSTEM\n";
        cout << "====================================\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "\nThank you for using the system!\n";
                break;

            default:
                cout << "\nInvalid choice! Please select 1, 2 or 3.\n";
        }

    } while (choice != 3);

 
    return 0;
}