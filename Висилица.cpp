#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int total_game = 0;

//* Приветствие и правила игры
void info()
{
    const char T = '\t';
    string info;
    cout << "\n\n\n";
    cout << T << "________________________________________________________" << endl;
    cout << T << T << "-----------------------------------" << endl;
    cout << T << "------------ ДОБРО ПОЖАЛОВАТЬ В ВИСИЛИЦУ! --------------" << endl;
    cout << T << T << "-----------------------------------" << endl;
    cout << T << "________________________________________________________" << endl;
    cout << "\n\n\n\t Если вы хотите ознакомиться с правилами игры напишите \"info\" or или \"инфо\"" << endl;

    cin >> info;

    //* Знакомство с правилами
    if (info == "info" || info == "инфо")
    {
        cout << "hello wordl!";
        cout << "Hello world!";
        cout << "Правила игры \"Виселица\" довольно просты:" << endl;
        cout << "Цель игры: Угадать слово, которое загадал другой игрок, за ограниченное количество попыток." << endl;
        cout << "Количество попыток: Обычно у игрока есть ограниченное количество попыток, чтобы угадать слово.\n Обычно это представлено в виде изображения виселицы. Когда игрок совершает неправильную попытку, к рисунку добавляется новый элемент." << endl;
        cout << "Как угадывать: Игрок предлагает буквы, которые, как он думает, могут входить в загаданное слово.\n Если буква есть в слове, она отображается на своем месте (или местах). Если буквы нет в слове, то к рисунку виселицы добавляется новый элемент." << endl;
        cout << "Победа или поражение: Игрок побеждает, если угадывает слово до того, как количество попыток закончится. Игрок проигрывает, если рисунок виселицы полностью нарисован до того, как он угадает слово." << endl;
        cout << "Конец игры: Игра заканчивается, когда игрок угадывает слово или количество попыток исчерпано." << endl;
        cout << "Продолжение игры: После завершения игры игрок может начать новую игру с новым словом или выйти из игры." << endl;
        cout << "\n\n\tНу теперь когда вы ознакомились с правила можно и начать игру!\n\n";
    }
}

//* Игра
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void game()
{
    bool is_game = false; //? Проверка все ли слова ввел пользователь
    int attempts = 6;     //? Попытки

    vector<string> english_word = {
        "apple", "house", "sun", "winter", "spring", "summer", "autumn", "sea", "mountain", "tree",
        "bird", "flower", "sky", "star", "moon", "river", "lake", "rain", "wind", "snow",
        "dog", "cat", "fish", "elephant", "giraffe", "tiger", "lion", "wolf", "bear", "fox", "pike"};

    string rand_word = english_word[rand() % 31], atte_str;
    int rand_word_size = rand_word.size();

    cout << "\n\n\tИтак загаданно слово состоящие из " << rand_word_size << " букв, у вас есть 6 попыток чтобы отгадать слово" << endl;
    cout << "\n\t\t\t";
    for (int i = 0; i < rand_word_size; ++i)
    {
        cout << "_  ";
        atte_str += '_';
    }
    cout << '\n';

    vector<string> hangmanParts = {
        "  __________________",
        "  |  |",
        "  |",
        "  |",
        "  |",
        "  |",
        "  |",
        "  |",
        "  |",
        "  |",
        "  |",
        "  |",
        "  |",
        "  |",
        "__|__"};

    //* Цикл игры
    do
    {
        bool flag = false;
        char attem_chr;
        cout << "\n\nВаше предположение: ";
        cin >> attem_chr;

        for (int i = 0; i < rand_word.size(); i++)
        {
            if (attem_chr == rand_word[i])
            {
                atte_str[i] = attem_chr;
                flag = true;
            }
        }

        if (!flag)
        {
            attempts -= 1;
            switch (attempts)
            {
            case 5:
                hangmanParts[1] = "  |           O";
                break;
            case 4:
                hangmanParts[2] = "  |           |";
                break;
            case 3:
                hangmanParts[3] = "  |          /|\\";
                break;
            case 2:
                hangmanParts[4] = "  |           |";
                break;
            default:
                hangmanParts[5] = "  |          / \\";
                break;
            }

            for (int i = 0; i < hangmanParts.size(); i++)
            {
                cout << hangmanParts[i] << endl;
            }
            cout << "\nК сожалению, это не та буква, у вас осталось: " << attempts << " попыток\n\n";
        }

        int total = 0;
        for (int i = 0; i < atte_str.size(); i++)
        {
            if (atte_str[i] != '_')
            {
                total += 1;
            }
            cout << atte_str[i] << "  ";
        }

        if (total == atte_str.size())
        {
            total_game += 100;
            cout << "Вы заработали +100 очков ";
            cout << "У вас " << total_game << " очков!";
            is_game = true;
            cout << "\nВы выиграли! Ура!" << endl;
            return;
        }
    } while (!is_game && attempts != 0);

    cout << "\n\n\n\tК сожалению, вы проиграли :(" << endl;
    cout << "\tБыло загадано слово:  " << rand_word << endl;
    total_game -= 100;
    cout << "Вы потеряли -100 очков \n";
    cout << "Ваш баланс: " << total_game << " очков!";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    info();
    cout << "Вот всевозможные варианты ответов: "
         << "\n\tapple, house, sun, winter, spring, summer, autumn, sea, mountain,\n\t tree, bird, flower, sky, star, moon, river, lake,\n\t rain, wind, snow, dog, cat, fish, elephant,\n\t giraffe, tiger, lion, wolf, bear, fox, pike";

    while (true)
    {
        game();
        cout << "\n\n\n\nХотите сыграть еще раз? Если вы уйдете то счет обнулится(y/n)";
        char game_repl;
        cin >> game_repl;
        if (game_repl != 'y')
        {
            return 0;
        }
        cout << "\n\n\tОтлично! \n";
    }
}
