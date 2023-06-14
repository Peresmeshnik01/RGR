#include "Header.h"
int main()
{
    setlocale(LC_ALL, "RUS");
    string text, result, password, key, message;
    string password_ = "123";
    cout << "o----------------------КОДЕК----------------------o";
    cout << endl;
    while (password != password_)
    {
        cout << "----Введите пароль";
        cout << endl;
        getline(cin, password); // Получаем ввод пользователя

        // Если введенный пароль неверный, выводим сообщение об ошибке
        if (password != password_)
        {
            cout << "-> Неверный пароль! Попробуйте снова." << endl;
            cout << endl;
        }
    }
    cout << "-> Правильный пароль! Доступ разрешен." << endl;
    while (1) {
        int ch;
        cout << "  o-------------Введите номер шифра-------------o";
        cout << endl;
        cout << "  |  1. Шифр Цезаря                             |" << endl;
        cout << "  |  2. Табличная шифровка                      |" << endl;
        cout << "  |  3. Матричная шифровка                      |" << endl;
        cout << "  |  4. Шифровка зафиксированной перестановкой  |" << endl;
        cout << "  |  5. Шифр Атбаш                              |" << endl;
        cout << "  |  6. Шифр Виженера                           |" << endl;
        cout << "  |  7. Шифр с использованием кодового слова    |" << endl;
        cout << "  |  8. Шифр перестановки 'Скитала'             |" << endl;
        cout << "  |  9. Шифровка 'Тарабарская грамота'          |" << endl;
        cout << "  |  0. Выход из программы 'Кодек'              |" << endl;
        cout << "  o---------------------------------------------o";
        cout << endl;
        cin >> ch;
        getline(cin, text);
        switch (ch)
        {
        case 1:
            cout << "Шифр Цезаря" << endl;
            cout << endl;
            Write1(text, password, password_);
            break;
        case 2:
            cout << "Табличная шифровка" << endl;
            cout << endl;
            Write2(text, password, password_);
            break;
        case 3:
            cout << "Матричная шифровка:" << endl;
            cout << endl;
            Write3(text, password, password_);
            break;
        case 4:
            cout << "Шифровка зафиксированной перестановкой" << endl;
            cout << endl;
            Write4(text, password, password_);
            break;
        case 5:
            cout << "Шифр Атбаш" << endl;
            cout << endl;
            Write5(text, password, password_);
            break;
        case 6:
            cout << "Шифр Виженера" << endl;
            cout << endl;
            Write6(text, password, password_);
            break;
        case 7:
            cout << "Шифр с использованием кодового слова" << endl;
            cout << endl;
            Write7(text, password, password_);
            break;
        case 8:
            cout << "Шифр перестановки 'Скитала'" << endl;
            cout << endl;
            Write8(text, password, password_);
            break;
        case 9:
            cout << "Шифровка 'Тарабарская грамота'" << endl;
            cout << endl;
            Write9(text, password, password_);
            break;
        case 0:
            cout << "------------/ >  >     bye";
            cout << endl;
            cout << "-----------| 0  0|";
            cout << endl;
            cout << "----------/  =__x)=";
            cout << endl;
            cout << "---------/      |";
            cout << endl;
            cout << "--------/   | | |";
            return 0;
        default:
            break;
        }
    }
}