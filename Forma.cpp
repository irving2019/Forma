#include <iostream>
#include <fstream>
#include <locale.h>
using namespace std;

string login;
string password;
string logreg;
string passreg;
int choise;

void saveDataToFile(string login, string password)
{
    ofstream file;
    file.open("userdata.txt");
    file << login << " " << password << endl;
    file.close();
}

bool readDataFromFile(string& login, string& password)
{
    ifstream file;
    file.open("userdata.txt");
    if (!file) {
        return false; // Если файл не существует или не может быть открыт, возвращаем false
    }
    file >> login >> password;
    file.close();
    return true;
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");

    cout << "1. Вход" << endl;
    cout << "2. Регистрация" << endl;

    cin >> choise;

    if (choise == 1)
    {
        cout << "Введите Логин:" << endl;

        cin >> login;

        cout << "Введите пароль:" << endl;

        cin >> password;
    }

    else if (choise == 2)
    {
        cout << "Придумайте логин:" << endl;

        cin >> logreg;

        cout << "Придумайте пароль:" << endl;

        cin >> passreg;

        saveDataToFile(logreg, passreg);
    }

    if (choise == 1) // Проверяем данные пользователя
    {
        
        string savedLogin, savedPassword;
        if (readDataFromFile(savedLogin, savedPassword) && login == savedLogin && password == savedPassword)
        {
            cout << "Добро пожаловать в систему";
        }
        else
        {
            cout << "Ошибка, неверный логин или пароль!";
        }
    }

    return 0;
}
