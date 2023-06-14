/*ЕСТЬ ВЫБОР ЯЗЫКА, ЕСЛИ ВЫБРАН РУССКИЙ СДЕЛАТЬ ПРОВЕРКУ НА РУССКИЙ ЯЗЫК,
ЕСЛИ НЕ ПРАВИЛЬНО ЗАПРАШИВАТЬ ПОВТОРНЫЙ ВВОД ТЕКСТА И ТАК ЖЕ СДЕЛАТЬ ПРИВЫБОРЕ АНГЛИЙСКОГО*/
#include "Header.h" 

string atbash(string text) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) { // uppercase
                result += (char)('Z' - (text[i] - 'A'));
            }
            else { // lowercase
                result += (char)('z' - (text[i] - 'a'));
            }
        }
        else { // not a letter
            result += text[i];
        }
    }
    return result;
}
string atbash_rus(string text) {
    string result = "";
    string a = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    string b = a;
    reverse(b.begin(), b.end());
    string A = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    string B = A;
    reverse(B.begin(), B.end());
    for (int i = 0; i < text.length(); i++) {
        if (a.find(text[i]) != string::npos) { //если символ существует в строке "а" 
            int index = a.find(text[i]); //ищем его индекс 
            text[i] = b[index]; //находим символ на зеркальной стороне 
        }
        else if (A.find(text[i]) != string::npos) { //для символов в верхнем регистре 
            int index = A.find(text[i]);
            text[i] = B[index];
        }
        result += text[i]; //собираем результат 
    }
    return result;
}
void Write5(string text, string password, string password_) {
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int language;
    cout << "1.Английский\n2.Русский\nВыберите(1,2): ";
    cin >> language;
    cin.ignore();
    cout << "Введите текст: ";
    getline(cin, text);
    write_to_file("source.txt", text);
    cout << "Введите пароль: ";
    getline(cin, password);
    while (password != password_)
    {
        cout << "Введите пароль: ";
        getline(cin, password); // Получаем ввод пользователя

        // Если введенный пароль неверный, выводим сообщение об ошибке
        if (password != password_)
        {
            cout << "Неверный пароль! Попробуйте снова." << endl;
        }
    }
    if (language == 1) {
        if (password == "123") {
            text = read_from_file("source.txt");
            text = atbash(text);
            write_to_file("encoded.txt", text);
            cout << "-> Текст зашифрован и записан в encoded.txt" << endl;
        }
        // дешифрование  
        if (password == "123") {
            text = read_from_file("encoded.txt");
            text = atbash(text);
            write_to_file("decoded.txt", text);
            cout << "-> Текст расшифрован и записан decoded.txt" << endl;
        }
        cout << "Файл source.txt:" << endl;
        cout << endl;
        cout << read_from_file("source.txt") << endl;
        cout << endl;
        cout << "Файл encoded.txt:" << endl;
        cout << endl;
        cout << read_from_file("encoded.txt") << endl;
        cout << endl;
        cout << "Файл decoded.txt:" << endl;
        cout << endl;
        cout << read_from_file("decoded.txt") << endl;
        cout << endl;
    }
    if (language == 2) {
        if (password == "123") {
            text = read_from_file("source.txt");
            text = atbash_rus(text);
            write_to_file("encoded.txt", text);
            cout << "-> Текст зашифрован и записан в encoded.txt" << endl;
        }
        // дешифрование  
        if (password == "123") {
            text = read_from_file("encoded.txt");
            text = atbash_rus(text);
            write_to_file("decoded.txt", text);
            cout << "-> Текст зашифрован и записан decoded.txt" << endl;
        }
        cout << "Файл source.txt:" << endl;
        cout << endl;
        cout << read_from_file("source.txt") << endl;
        cout << endl;
        cout << "Файл encoded.txt:" << endl;
        cout << endl;
        cout << read_from_file("encoded.txt") << endl;
        cout << endl;
        cout << "Файл decoded.txt:" << endl;
        cout << endl;
        cout << read_from_file("decoded.txt") << endl;
        cout << endl;
    }
}