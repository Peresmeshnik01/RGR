/* НЕ РАБОТАЕТ ДЛЯ НЕСКОЛЬКИХ СЛОВ ПОЧЕМУ ТО :(*/
#include "Header.h" 
// Функция шифрования
string Fun(string plaintext, string key) {
    string ciphertext = "";

    // Создаем таблицу замены
    vector<vector<char>> table(26, vector<char>(26));
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            table[i][j] = 'A' + (i + j) % 26;
        }
    }

    string key_only_letters = "";
    for (char c : key) {
        if (isalpha(c)) {
            key_only_letters += toupper(c);
        }
    }

    int col = 0;

    // Шифруем каждый символ открытого текста
    for (char c : plaintext) {
        if (isalpha(c)) {
            c = toupper(c);
            int row = key_only_letters[col % key_only_letters.length()] - 'A';
            ciphertext += table[row][c - 'A'];
            col++;
        }
    }

    return ciphertext;
}

// Функция расшифровки
string Fun2(string ciphertext, string key) {
    string plaintext = "";

    // Создаем таблицу замены
    vector<vector<char>> table(26, vector<char>(26));
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            table[i][j] = 'A' + (i + j) % 26;
        }
    }

    string key_only_letters = "";
    for (char c : key) {
        if (isalpha(c)) {
            key_only_letters += toupper(c);
        }
    }

    int col = 0;

    // Расшифровываем каждый символ шифротекста
    for (char c : ciphertext) {
        if (isalpha(c)) {
            c = toupper(c);
            int row = key_only_letters[col % key_only_letters.length()] - 'A';
            for (int i = 0; i < 26; i++) {
                if (table[row][i] == c) {
                    plaintext += 'A' + i;
                    break;
                }
            }
            col++;
        }
    }

    return plaintext;
}
bool isEnglish(string str) {
    for (int i = 0; i < str.length(); i++) {
        int asciiCode = (int)str[i];
        if (asciiCode < 65 || (asciiCode > 90 && asciiCode < 97) || asciiCode>122) {
            return false;
        }
    }
    return true;
}
void Write2(string text, string password, string password_) {
    setlocale(LC_ALL, "RUS");
    string key;
    bool all_upper = true;
    cout << "Введите исходный текст на английском языке заглавными буквами:  ";
    getline(cin, text);
    for (char c : text) {
        if (islower(c)) {
            all_upper = false;
            cout << "Ошибка: строка содержит символы нижнего регистра.\n";
            break;
        }
    }
    bool mes = isEnglish(text);
    if (all_upper && mes) {
        cout << "Введите ключ (слово на английском языке): ";
        getline(cin, key);
        bool k = isEnglish(key);
        if (k) {
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
            if (password == "123") {

                text = read_from_file("source.txt");
                text = Fun(text, key);
                write_to_file("encoded.txt", text);
                cout << "-> Текст зашифрован и записан в encoded.txt" << endl;
            }
            // дешифрование  
            if (password == "123") {
                text = read_from_file("encoded.txt");
                text = Fun2(text, key);
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

        else if (!k) {
            cout << "Ключ содержит символы на русском языке";
        }

        else if (!mes) {
            cout << "Строка содержит символы на русском языке";
        }
    }
}