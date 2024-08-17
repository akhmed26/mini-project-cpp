#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char X = 'X';
char O = 'O';
char TIE = 'T';
char NO_WIN = 'N';
char SPACE = ' ';
const unsigned int b_num = 9; // Исправлено значение на 9

// TODO: Функция приветствия
void Hello();

// TODO: Функция вывода доски на экран
void cout_Board(const vector<char> &board);

// TODO: Функция, которая возвращает противоположный символ (X -> O или O -> X)
char oppositely(char X_O);

// TODO: Функция выбора, кем будет играть пользователь (X или O)
char Onego();

// TODO: Функция для определения победителя
char winner(const vector<char> &board);

// TODO: Функция для проверки корректности ввода числа
int isnum();

// TODO: Инлайн-функция для проверки, является ли клетка пустой
inline bool isnoSpace(int move, const vector<char> &board);

// TODO: Функция для выполнения хода пользователя
int humanMove(const vector<char> &board);

// TODO: Функция для выполнения хода компьютера
int compMove(vector<char> board, char comp, char human);

// TODO: Функция для вывода результата игры
void Victory(char victoty, char human, char comp);

int main()
{
    vector<char> board(b_num, SPACE);

    Hello();
    char human = Onego();
    char comp = oppositely(human);
    char moved = X;
    while (winner(board) == NO_WIN)
    {
        int move;
        if (moved == human)
        {
            move = humanMove(board);
            board[move] = human;
        }
        else
        {
            move = compMove(board, comp, human);
            board[move] = comp;
        }
        cout_Board(board);
        cout << "\n\n\n";
        moved = oppositely(moved);
    }
    Victory(winner(board), human, comp);
}

void Hello()
{
    cout << "\n\tДобро пожаловать в Крестики-Нолики!\n\n";
    cout << "\tВ этой игре вы будете сражаться против ИИ\n\n";
    cout << "Сделайте свой ход, введя число от 1 до 9 вкл. Число\n";
    cout << "соответствует желаемой позиции на доске, как показано ниже:\n\n";

    cout << "		1 | 2 | 3\n";
    cout << "		---------\n";
    cout << "		4 | 5 | 6\n";
    cout << "		---------\n";
    cout << "		7 | 8 | 9\n\n";

    cout << "Приготовьтесь, человек. Битва начинается.\n\n";
}

char Onego()
{
    string s;
    cout << "\nХотите играть за X первым?(x/любая клавиша): ";
    cin >> s;
    if (s == "x")
    {
        return X;
    }
    return O;
}

char oppositely(char X_O)
{
    if (X_O == 'X')
    {
        return O;
    }
    return X;
}

void cout_Board(const vector<char> &board)
{
    cout << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "---------\n";
    cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "---------\n";
    cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

char winner(const vector<char> &board)
{
    const int WINNING_ROWS[8][3] = {{0, 1, 2},
                                    {3, 4, 5},
                                    {6, 7, 8},
                                    {0, 3, 6},
                                    {1, 4, 7},
                                    {2, 5, 8},
                                    {0, 4, 8},
                                    {2, 4, 6}};

    for (int i = 0; i < 8; ++i)
    {
        if (board[WINNING_ROWS[i][0]] != SPACE &&
            board[WINNING_ROWS[i][0]] == board[WINNING_ROWS[i][1]] &&
            board[WINNING_ROWS[i][1]] == board[WINNING_ROWS[i][2]])
        {
            return board[WINNING_ROWS[i][0]];
        }
    }

    if (count(board.begin(), board.end(), SPACE) == 0)
    {
        return TIE;
    }
    return NO_WIN;
}

int isnum()
{
    int s;
    while (true)
    {
        cout << "\nКуда вы желаете пойти? (1-9): ";
        cin >> s;

        // Проверка на корректность ввода
        if (cin.fail()) // Если введено не число
        {
            cin.clear();                                         // Очистка ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Пропуск оставшегося ввода
            cout << "Нужно ввести число от 1 до 9.\n";
        }
        else if (s >= 1 && s <= 9)
        {
            return s;
        }
        else
        {
            cout << "Нужно выбрать от 1 до 9 включительно и чтобы эта клетка была свободна.\n";
        }
    }
}
inline bool isnoSpace(int move, const vector<char> &board)
{
    return (board[move] == SPACE);
}

int humanMove(const vector<char> &board)
{
    while (true)
    {
        int move = isnum() - 1;
        if (board[move] == SPACE)
        {
            return move;
        }
        cout << "\nГлупый человек, эта клетка занята\n";
    }
}

int compMove(vector<char> board, char comp, char human)
{
    unsigned int move = 0;
    bool flag = false;
    while (!flag && move < board.size())
    {
        if (isnoSpace(move, board))
        {
            board[move] = comp;
            flag = (winner(board) == comp);
            board[move] = SPACE;
        }

        if (!flag)
        {
            ++move;
        }
    }

    if (!flag)
    {
        move = 0;

        while (!flag && move < board.size())
        {
            if (isnoSpace(move, board))
            {
                board[move] = human;
                flag = (winner(board) == human);
                board[move] = SPACE;
            }

            if (!flag)
            {
                ++move;
            }
        }
    }

    if (!flag)
    {
        move = 0;
        unsigned short int i = 0;
        const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};

        while (!flag && i < board.size())
        {
            move = BEST_MOVES[i];
            if (isnoSpace(move, board))
            {
                flag = true;
            }
            ++i;
        }
    }

    cout << "\tБОТ: Я займу клетку номер " << move + 1 << endl; // Исправлено: move + 1
    return move;
}

void Victory(char victoty, char human, char comp)
{
    if (victoty == human)
    {
        cout << "\nПобедил пользователь\n";
    }
    else if (victoty == comp)
    {
        cout << "\nПобедил бот\n";
    }
    else
    {
        cout << "Ничья\n";
    }
}