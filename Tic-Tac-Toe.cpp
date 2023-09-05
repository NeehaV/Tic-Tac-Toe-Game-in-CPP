#include <iostream>
#include <ctime>

void showBoard(char *board);
bool checkSpace(char *board);
void playerMove(char *board);
void computerMove(char *board);
char checkResult(char *board);

int main()
{

    char player = 'X';
    char computer = 'O';
    char play;
    std::cout << "****************************" << '\n';
    std::cout << "******TIC-TAC-TOE GAME******" << '\n';
    std::cout << "****************************" << '\n';
    do
    {
        play = ' ';
        char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
        char result = ' ';
        showBoard(board);
        do
        {
            playerMove(board);
            result = checkResult(board);

            if (result == ' ')
            {
                computerMove(board);
                showBoard(board);
                result = checkResult(board);
            }

        } while (result == ' ');

        switch (result)
        {
        case 'X':
            std::cout << "******You have WON the game******";
            std::cout << "Result: " << '\n';
            showBoard(board);
            break;
        case 'O':
            std::cout << "******Computer has WON the game******";
            std::cout << "Result: " << '\n';
            showBoard(board);
            break;
        case 'T':
            std::cout << "*****It's a TIE game*****";
            std::cout << "Result: " << '\n';
            showBoard(board);
            break;
        default:
            std::cout << "An error occured!";
        }

        std::cout << '\n'
                  << "Do you want to play again?(Y/N): ";
        std::cin >> play;
        play = toupper(play);

    } while (play != 'N');

    return 0;
}

void showBoard(char *board)
{
    std::cout << '\n';
    std::cout << "1     |2     |3     " << '\n';
    std::cout << "   " << board[0] << "  |   " << board[1] << "  |  " << board[2] << '\n';
    std::cout << "------|------|-----" << '\n';
    std::cout << "4     |5     |6     " << '\n';
    std::cout << "    " << board[3] << " |   " << board[4] << "  |  " << board[5] << '\n';
    std::cout << "------|------|-----" << '\n';
    std::cout << "7     |8     |9     " << '\n';
    std::cout << "   " << board[6] << "  |   " << board[7] << "  |  " << board[8] << '\n';
}

bool checkSpace(char *board)
{
    int space = 0;
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == ' ')
        {
            space++;
        }
    }
    if (space == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void playerMove(char *board)
{
    int boxNumber;
    std::cout << '\n'
              << "***Your Turn***" << '\n';
    std::cout << "Enter your box number(1 to 9): ";
    std::cin >> boxNumber;
    board[boxNumber - 1] = 'X';
}

void computerMove(char *board)
{
    bool status = true;
    int computerBoxNumber;
    std::cout << '\n'
              << "***Computer's turn:...... ***";

    srand(time(NULL));
    while (status)
    {
        computerBoxNumber = rand() % 9; // generate random numbers between 0 to 8

        if (board[computerBoxNumber] == ' ')
        {
            board[computerBoxNumber] = 'O';
            status = false;
        }
    }
}

char checkResult(char *board)
{
    char winner;
    bool space = checkSpace(board);

    if ((board[0] == board[1]) && (board[0] == board[2]))
    {
        winner = board[0];
    }
    else if ((board[3] == board[4]) && (board[3] == board[5]))
    {
        winner = board[3];
    }
    else if ((board[6] == board[7]) && (board[6] == board[8]))
    {
        winner = board[6];
    }
    else if ((board[0] == board[3]) && (board[0] == board[6]))
    {
        winner = board[0];
    }
    else if ((board[1] == board[4]) && (board[1] == board[7]))
    {
        winner = board[1];
    }
    else if ((board[2] == board[5]) && (board[2] == board[8]))
    {
        winner = board[2];
    }
    else if ((board[0] == board[4]) && (board[0] == board[8]))
    {
        winner = board[0];
    }
    else if ((board[2] == board[4]) && (board[2] == board[6]))
    {
        winner = board[2];
    }
    else if (!space)
    {
        winner = 'T';
    }
    else
    {
        winner = ' ';
    }

    return winner;
}