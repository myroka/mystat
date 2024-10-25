#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Password
{
public:

    int Entrance()
    {
        string login = "login.txt";
        string password = "&&";

        fstream log;
        fstream pass;

        log.open(login, fstream::in | fstream::out | fstream::app);
        pass.open(password, fstream::in | fstream::out | fstream::app);

        if (!log.is_open() && !pass.is_open())
        {
            cout << "Ошибка!" << endl;
        }
        else
        {
            string log_cheker;
            string pass_cheker;

            while (!log.eof()) 
            {
                log_cheker = "";
                log >> log_cheker; 
            }
            while (!pass.eof()) 
            {
                pass_cheker = "";
                pass >> pass_cheker; 
            }

            string login_correct;
            string pass_correct;

            cout << "Введите свой логин: "; cin >> login_correct;
            cout << endl;
            cout << "Введите свой пароль: "; cin >> pass_correct;

            if (login_correct != log_cheker && pass_correct != pass_cheker)
            {
                cout << "Пароль или логин введен не правильно!" << endl;
            }
            else
            {
                cout << "Данные введены верно!" << endl;
            }
            return 0;
        }
    }
    int Sign_up()
    {
        string login = "login.txt";
        string password = "password.txt";

        fstream log;
        fstream pass;

        log.open(login, fstream::in | fstream::out | fstream::app);
        pass.open(password, fstream::in | fstream::out | fstream::app);

        if (!log.is_open() && !pass.is_open())
        {
            cout << "Ошибка!" << endl;
        }
        else
        {
            string log_cheker;
            string pass_cheker;
            cout << "Введите свой логин: "; cin >> log_cheker;
            cout << endl;
            cout << "Введите свой пароль: "; cin >> pass_cheker;

            log << log_cheker;
            pass << pass_cheker;

            cout << "Регистрация прошла успешно!" << endl;

            DisplayRating();

            
            ShowMenu();

            return 0;

        }
    }

    void DisplayRating()
    {
        
        cout << "\nТаблица лидеров:\n";
        cout << "1. Дем'яненко Олег Костянтинович\n";
        cout << "2. Савадого Мішель Елізе\n";
        cout << "3. Клименко Артем Сергійович\n";
        cout << "4. Гунько Мирослав Ярославович\n";
        cout << "5. Павлиш Нікіта Євгенійович\n";
        cout << "6. Чернов Данило Геннадійович\n";
        cout << "7. Яковлев Ігор Олександрович\n";
        cout << "8. Скрипковський Михайло Ярославович\n";
        cout << "9. Торопов Андрій Русланович\n";
        cout << "10. Пушкова Ангеліна Геннадіївна\n";
    }

    void ShowMenu()
    {
        
        int choice;
        cout << "\nМеню:\n";
        cout << "1. Домашнее задание\n";
        cout << "2. Отзывы\n";
        cout << "Выберите пункт: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Переход во вкладку 'Домашнее задание'\n";
            break;
        case 2:
            cout << "Переход во вкладку 'Отзывы'\n";
            break;
        default:
            cout << "Неверный выбор\n";
            break;
        }
    }
};



class menu
{
public:

    int RunMenu()
    {
        int punkt;
        cout << "Добро пожаловать!" << endl;
        cout << "1.Вход" << endl;
        cout << "2.Регистрация" << endl;
        cin >> punkt;

        if (punkt != 1 && punkt != 2)
        {
            cout << "Выбран неверный пункт меню!" << endl;
        }
        if (punkt == 1)
        {
            system("cls");
            Password pass;
            pass.Entrance();
        }
        if (punkt == 2)
        {
            system("cls");
            Password pass;
            pass.Sign_up();
        }
        return 0;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");

    menu Menu;

    Menu.RunMenu();

    return 0;
}

