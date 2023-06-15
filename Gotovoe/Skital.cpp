//норм
#include "Header.h"


string Encr(const string& text, int rails) {
    int length = text.length();
    int numRails = min(rails, length);
    int cycle = 2 * numRails - 2;
    string ciphertext;

    for (int i = 0; i < numRails; i++) {
        for (int j = i; j < length; j += cycle) {
            ciphertext += text[j];
            int k = j + cycle - 2 * i;
            if (i != 0 && i != numRails - 1 && k < length)
                ciphertext += text[k];
        }
    }

    return ciphertext;
}

// Функция для дешифрования методом Скитала  
string Decr(const string& text, int rails) {
    int length = text.length();
    int numRails = min(rails, length);
    int cycle = 2 * numRails - 2;
    string plaintext(length, ' ');

    int pos = 0;
    for (int i = 0; i < numRails; i++) {
        for (int j = i; j < length; j += cycle) {
            plaintext[j] = text[pos++];
            int k = j + cycle - 2 * i;
            if (i != 0 && i != numRails - 1 && k < length)
                plaintext[k] = text[pos++];
        }
    }

    return plaintext;
}
void Write8(string text, string password, string password_) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int rails = 0;
    cout << "Введите текст: ";
    getline(cin, text);
    write_to_file("source.txt", text);
    cout << "Введите количество ребер скитала: ";
    cin >> rails;
    cin.ignore();

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
    if (password == "123") {

        text = read_from_file("source.txt");
        text = Encr(text, rails);
        write_to_file("encoded.txt", text);
        cout << "-> Текст зашифрован и записан в encoded.txt" << endl;
    }
    // дешифрование  
    if (password == "123") {
        text = read_from_file("encoded.txt");
        text = Decr(text, rails);
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
