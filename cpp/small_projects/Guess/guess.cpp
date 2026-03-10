#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class game
{
private:
    int input{};
    int money{};

    void game_intro()
    {
        cout << "----------------------------\n"
             << "Welcome to the guessing game\n"
             << "----------------------------\n";
    }

    void choises()
    {
        cout << "Choose: \n"
             << "1 -> to the game :)\n"
             << "2 -> end the game :(\n"
             << "----------------------------\n";
    }

    int computer_guess(int val)
    {
        if (val == 1)
            return rand() % 10 + 1;
        else if (val == 2)
            return rand() % 11 + 10;
        else if (val == 3)
            return rand() % 11 + 20;
        else if (val == 4)
            return rand() % 11 + 30;
        else if (val == 5)
            return rand() % 11 + 40;

        return -1;
    }

    int opr1()
    {
        cout << "level one: choose from 1 to 10\n";
        cin >> input;
        if (input < 1 || input > 10)
            cout << "Invalid input\n";
        return input;
    }

    int opr2()
    {
        cout << "level two: choose from 10 to 20\n";
        cin >> input;
        if (input < 10 || input > 20)
            cout << "Invalid input\n";
        return input;
    }

    int opr3()
    {
        cout << "level three: choose from 20 to 30\n";
        cin >> input;
        if (input < 20 || input > 30)
            cout << "Invalid input\n";
        return input;
    }

    int opr4()
    {
        cout << "level four: choose from 30 to 40\n";
        cin >> input;
        if (input < 30 || input > 40)
            cout << "Invalid input\n";
        return input;
    }

    int opr5()
    {
        cout << "level five: choose from 40 to 50\n";
        cin >> input;
        if (input < 40 || input > 50)
            cout << "Invalid input\n";
        return input;
    }

    void operations()
    {
        game_intro();

        int level = 1;

        while (true)
        {
            choises();
            cin >> input;

            if (input == 2)
            {
                cout << "You leave with: " << money << "\n";
                break;
            }

            int player_choice{};
            int computer_choice = computer_guess(level);

            if (level == 1)
                player_choice = opr1();
            else if (level == 2)
                player_choice = opr2();
            else if (level == 3)
                player_choice = opr3();
            else if (level == 4)
                player_choice = opr4();
            else if (level == 5)
                player_choice = opr5();

            if (player_choice == computer_choice)
            {
                cout << "Correct! You move to next level!\n";

                if (level == 1)
                    money += 500;
                else if (level == 2)
                    money += 1000;
                else if (level == 3)
                    money += 10000;
                else if (level == 4)
                    money += 100000;
                else if (level == 5)
                    money += 500000;

                cout << "Your account now: " << money << "\n";

                if (level < 5)
                    level++;
                else
                    cout << "You are already at the highest level!\n";
            }
            else
            {
                cout << "Wrong guess! Try again at the same level: \n";
            }
        }
    }

public:
    game() {}
    void the_game()
    {
        operations();
    }
};

int main()
{
    srand(time(0)); // seed once
    game gam1;
    gam1.the_game();
    return 0;
}