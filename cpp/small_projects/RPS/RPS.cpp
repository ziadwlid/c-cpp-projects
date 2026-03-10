#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class RPS
{
private:
    int input{};
    string choices[3];
    void intro_game()
    {
        cout << "WELCOME TO 'Rock Scissor Paper' Game :)\n";
        cout << "Make your decision from this list:\n";
    }
    int get_player_choice()
    {
        while (true)
        {
            cout << "\n1: Rock\n2: Scissor\n3: Paper\n-1: Exit Game\nYour choice: ";
            cin >> input;
            if (input == -1)
            {
                return -1;
            }
            if (input >= 1 && input <= 3)
            {
                return input - 1;
            }
            cout << "\n***********Invalid input. Please try again.***********\n";
        }
    }
    int get_computer_choice()
    {
        return rand() % 3;
    }
    void decide_winner(int player, int computer)
    {
        cout << "\nYou choose: " << choices[player] << endl;
        cout << "\nComputer choose: " << choices[computer] << endl;
        if (player == computer)
        {
            cout << "\n----------It's a Draw!\n";
        }
        else if ((player == 0 && computer == 1) ||
                 (player == 1 && computer == 2) ||
                 (player == 2 && computer == 0))
        {
            cout << "\n--------You Win! \n";
        }
        else
        {
            cout << "\n--------Computer Wins!\n";
        }
    }

public:
    RPS()
    {
        choices[0] = "Rock";
        choices[1] = "Scissor";
        choices[2] = "Paper";
    }
    void game() {
        intro_game();

        while (true) {
            int player_choice = get_player_choice();

            if (player_choice == -1) {
                cout << "\nThank you for playing! :)\n";
                break;
            }

            int computer_choice = get_computer_choice();

            decide_winner(player_choice, computer_choice);
        }
    }
};

int main()
{
    RPS game;
    game.game();
    return 0;
}