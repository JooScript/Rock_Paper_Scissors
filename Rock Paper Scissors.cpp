#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

short ReadValidateShortInRange(string Message, short From, short To)
{
    short Number;

    do
    {
        cout << Message;
        cin >> Number;
    } while (!(Number >= From && Number <= To));

    return Number;
}

bool ReadTrueOrFalse(string Message)
{
    bool TrueOrFalse = 1;
    short Num = ReadValidateShortInRange(Message, 0, 1);
    switch (Num)
    {
    case 1:
        return 1;
        break;
    default:
        return 0;
        break;
    }
}

void ClearScreen()
{
    system("clear"); // For linux
}

enum enGame
{
    Rock = 1,
    Paper = 2,
    Scissors = 3
};

struct stCounter
{
    short WinCount = 0, LossCount = 0, FairCount = 0;
};

enGame UserReadGame(string Message)
{
    return (enGame)ReadValidateShortInRange(Message, 1, 3);
}

enGame ReadComputerGame()
{
    return (enGame)RandomNumber(1, 3);
}

string ShowRockOrPaperOrScissors(enGame Game)
{
    switch (Game)
    {
    case enGame::Rock:
        return "Rock";
    case enGame::Paper:
        return "Paper";
    case enGame::Scissors:
        return "Scissors";
    default:
        return "Enter valid number 1 0r 2 0r 3";
        break;
    }
}

enum enWinLossFair
{
    Win = 1,
    Fair = 2,
    Loss = 3
};

enWinLossFair GameRules(enGame User, enGame Computer)
{
    if (User == Computer)
    {
        return enWinLossFair::Fair;
    }

    switch (User)
    {
    case enGame::Paper:
        if (Computer == enGame::Rock)
        {
            return enWinLossFair::Win;
        }
        else if (Computer == enGame::Scissors)
        {
            return enWinLossFair::Loss;
        }
    case enGame::Rock:
        if (Computer == enGame::Paper)
        {
            return enWinLossFair::Loss;
        }
        else if (Computer == enGame::Scissors)
        {
            return enWinLossFair::Win;
        }
    case enGame::Scissors:
        if (Computer == enGame::Paper)
        {
            return enWinLossFair::Win;
        }
        else if (Computer == enGame::Rock)
        {
            return enWinLossFair::Loss;
        }
    default:
        return enWinLossFair::Fair;
    }
}

string PrintWinner(enGame User, enGame Computer)
{
    switch (GameRules(User, Computer))
    {
    case enWinLossFair::Win:
        return "[Player]";
    case enWinLossFair::Loss:
        return "[Computer]";
    case enWinLossFair::Fair:
        return "[No winner]";
    default:
        return "Biiiiiiiig eroooooooor";
    }
}

short ReadRounds(short &Rounds)
{
    Rounds = ReadValidateShortInRange("How many rounds 1 to 10 ", 1, 10);

    return Rounds;
}

string FinalWinner(stCounter Counter)
{
    if (Counter.WinCount > Counter.LossCount)
    {
        return "Player";
    }
    else if (Counter.WinCount < Counter.LossCount)
    {
        return "Computer";
    }
    else
    {
        return "No winner";
    }
}

void GamePlay(int Rounds, stCounter &Counter, enGame User, enGame Computer)
{
    int i = 0;
    for (int i = 1; i <= Rounds; i++)
    {
        cout << "\nRound [ " << i << " ] begins:\n";
        User = UserReadGame("Your choice: [1]: Rock, [2]: Paper, [3]: Scissors ");
        Computer = ReadComputerGame();
        cout << "\n__________Round [" << i << "]__________\n";
        cout << "Player choice :" << ShowRockOrPaperOrScissors(User) << "\n";
        cout << "Computer choice :" << ShowRockOrPaperOrScissors(Computer) << "\n";
        cout << "Round winner :" << PrintWinner(User, Computer);
        cout << "\n_____________________________\n";

        switch (GameRules(User, Computer))
        {
        case enWinLossFair::Win:
            Counter.WinCount++;
            break;
        case enWinLossFair::Loss:
            Counter.LossCount++;
            break;
        case enWinLossFair::Fair:
            Counter.FairCount++;
            break;
        default:
            break;
        }
    }
}

void GameOverCard(int Rounds, stCounter Counter)
{
    cout << "\n***************************************\n";
    cout << "\t+++Game Over+++\t";
    cout << "\n***************************************\n";
    cout << "____________[Game Results]__________\n";
    cout << "Game rounds :" << Rounds;
    cout << "\nPlayer win times : " << Counter.WinCount;
    cout << "\nComputer win times : " << Counter.LossCount;
    cout << "\nDraw times : " << Counter.FairCount;
    cout << "\nFinal winner : " << FinalWinner(Counter);
    cout << "\n____________________________________\n";
}

int main()
{
    srand((unsigned)time(NULL));
    bool Again;

    do
    {
        short Rounds;
        ReadRounds(Rounds);
        enGame User, Computer;
        stCounter Counter;
        GamePlay(Rounds, Counter, User, Computer);
        GameOverCard(Rounds, Counter);
        Again = ReadTrueOrFalse("Are you want to play again ? 1:Yes,0:No ");
        if (Again)
        {
            ClearScreen();
        }
    } while (Again);
    cout << "\n\n";
    return 0;
}
