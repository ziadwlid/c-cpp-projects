#include <iostream>
#include <vector>
using namespace std;
class program
{
private:
    vector<pair<string, string>> data;
    void intro_program()
    {
        cout << "----------------------\n"
             << "Hello to the login page :)\n";
    }
    void choise()
    {
        cout << "Choose if you want to "
             << "\n 1 -> Login to page"
             << "\n 2 -> Greate account"
             << "\n 3 -> End the program \n";
    }
    int great_account()
    {
        cout << "----Greate account----\n";
        string *username = new string;
        string *password = new string;
        cout << "Enter your username:  ";
        cin >> *username;
        cout << "Enter your password:  ";
        cin >> *password;

        data.push_back(make_pair(*username, *password));
        return 2;
    }

    int login_accout()
    {
        bool found1 = false, found2 = false;

        cout << "----Login account----\n";
        string username{}, password{};

        cout << "Enter your username:  ";
        cin >> username;

        for (auto &u : data)
        {
            if (u.first == username)
            {
                found1 = true;
                cout << "Your username is : " << u.first << "\n";
                break;
            }
        }

        if (!found1)
        {
            cout << "Invalid username please rewrite it :( \n";
            return 0;
        }

        cout << "Enter your password:  ";
        cin >> password;

        for (auto &u : data)
        {
            if (u.first == username && u.second == password)
            {
                found2 = true;
                cout << "Your password is : " << u.second << "\n";
                break;
            }
        }

        if (!found2)
        {
            cout << "Invalid password please rewrite it :( \n";
            return 0;
        }

        cout << "Successful login :) \n";
        return 1;
    }

    void operation()
    {
        intro_program();

        while (true)
        {
            choise();
            int input{};
            cin >> input;
            if (input < 3 && input > 3)
            {
                cout << "INVALID choise! please choose correct number\n";
                cin >> input;
            }
            if (input == 3)
            {
                cout << "---- Thank you :) ----\n";
                break;
            }
            if (input == 1)
            {
                login_accout();
            }
            if (input == 2)
            {
                great_account();
            }
        }
    }

public:
    program() {};
    void reg()
    {
        operation();
    }
};
int main()
{
    program prg1;
    prg1.reg();
    return 0;
}