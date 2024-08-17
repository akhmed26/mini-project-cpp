#include <iostream>
#include <string>

using namespace std;

void history(string name, string work, string lesson, string nik, string enemy, string weap, string citi, string data);
string askText(string txt);

int main()
{
    cout << "\tДобро Пожаловать в Map_lub\n\n";
    cout << "Здесь вы можете сочинить историю отвечая на вопросы\n\n";
    cout << "Вопросы буду идти по очереди\n\n";

    string name = askText("Пожалуйста назовите свое имя: ");
    string work = askText("Назовите свою любимую деятельность: ");
    string lesson = askText("Назовите ваш любимый предмет: ");
    string nikename = askText("Назовите вашу кличку: ");
    string enemy = askText("Назовите вашего заклятого врага: ");
    string weapon = askText("Введите оружие которым вы бы хотели сражаться");
    string citi = askText("Назовите локацию которую на которой хотели бы быть");
    string data = askText("Назовите дату боя: ");
    history(name, work, lesson, nikename, enemy, weapon, citi, data);
}

string askText(string text)
{
    string txt;
    cout << text;
    cin >> txt;
    return txt;
}

void history(string name, string work, string lesson, string nik, string enemy, string weap, string citi, string data)
{
    cout << "\n\n\tИтак вот ваша история\n\n";
    cout << "\tЖил давным давно человек по имени '" << name << "' по прозвещу '" << nik << "'" << endl;
    cout << "\tОн был очень любил предмет " << lesson << " и эти знания помогли ему одолеть его заклятого врага " << endl;
    cout << "\tЕго основная деятельность: " << work << " а его любимое оружие в свободное время когда он не занимался работой: " << weap << endl;
    cout << "\tИ у него был заклятый враг по имени '" << enemy << "'" << endl;
    cout << "\tВ " << data << "Прошел бой между " << nik << " и " << enemy << " На локации: " << citi << endl;
    cout << "\tВ итоге победил " << nik << endl;
    cout << "\tМораль следующяя, isik = большой пись писик(одобренно алишкой, и максом)" << endl;
}
