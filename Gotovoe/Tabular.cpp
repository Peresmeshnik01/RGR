//норм
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
    int i = 0;

    // Шифруем каждое слово открытого текста
    while (i < plaintext.length()) {
        string word = "";
        while (i < plaintext.length() && isalpha(plaintext[i])) {
            word += plaintext[i];
            i++;
        }

        if (!word.empty()) {
            for (char& c : word) {
                c = toupper(c);
                int row = key_only_letters[col % key_only_letters.length()] - 'A';
                ciphertext += table[row][c - 'A'];
                col++;
            }
            ciphertext += " ";
        }
        i++;
    }

    // Удаляем последний пробел
    if (!ciphertext.empty()) {
        ciphertext.pop_back();
    }

    return ciphertext;
}
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
    for (int i = 0; i < ciphertext.length(); i++) {
        if (isalpha(ciphertext[i])) {
            ciphertext[i] = toupper(ciphertext[i]);
            int row = key_only_letters[col % key_only_letters.length()] - 'A';
            for (int j = 0; j < 26; j++) {
                if (table[row][j] == ciphertext[i]) {
                    plaintext += 'A' + j;
                    break;
                }
            }
            col++;
        }
        else {
            plaintext += ciphertext[i];
        }
    }

    return plaintext;
}
bool isEnglish(string str) {
    for (int i = 0; i < str.length(); i++) {
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z')) {
            continue;
        }
        if (str[i] < 'A' || str[i] > 'z' || (str[i] > 'Z' && str[i] < 'a')) {
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
