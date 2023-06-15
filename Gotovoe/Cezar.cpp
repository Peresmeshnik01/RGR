//норм
#include "Header.h" 
string encrypt_(string message, int key) {
    setlocale(LC_ALL, "RUS");
    string result = "";
    for (int i = 0; i < message.length(); i++) {
        if (isalpha(message[i])) {
            if (message[i] >= 'a' && message[i] <= 'z') {
                char ch = (message[i] + key - 'a') % 26 + 'a';
                result += ch;
            }
            else {
                char ch = (message[i] + key - 'A') % 26 + 'A';
                result += ch;
            }
        }
    }
    return result;
}
bool _isEnglish_(string str) {
    for (int i = 0; i < str.length(); i++) {
        int asciiCode = (int)str[i];
        if (asciiCode < 65 || (asciiCode > 90 && asciiCode < 97) || asciiCode>122) {
            return false;
        }
    }
    return true;
}

string decrypt_(string message, int key) {
    string result = "";
    for (int i = 0; i < message.length(); i++) {
        char ch = message[i];
        if (isalpha(ch)) {
            if (islower(ch)) {
                ch -= key;
                if (ch < 'a') {
                    ch += 26;
                }
            }
            else {
                ch -= key;
                if (ch < 'A') {
                    ch += 26;
                }
            }
        }
        result += ch;
    }
    return result;
}
void Write1(string text, string password, string password_) {
    setlocale(LC_ALL, "RUS");
    int key = 0;
    
    cout << "Введите исходный текст (на английском языке) : ";
    getline(cin, text);
    bool en_text = _isEnglish_(text);
    while (!en_text) {
        cout << "Введите строку еще раз (на английском языке): ";
        getline(cin, text);
        en_text = _isEnglish_(text);
    }
    write_to_file("source.txt", text);
    cout << "-> Файл был записан в encoded.txt";
    cout << endl;
    cout << "Пароль: ";
    getline(cin, password);
    while (password != password_)
    {
        cout << "Пароль: ";
        getline(cin, password); // Получаем ввод пользователя

        // Если введенный пароль неверный, выводим сообщение об ошибке
        if (password != password_)
        {
            cout << "Неверный пароль! Попробуйте ещё раз." << endl;
        }
    }
    if (password == "123") {
        cout << "Key: ";
        cin >> key;
        text = read_from_file("source.txt");
        text = encrypt_(text, key);
        write_to_file("encoded.txt", text);
        cout << "-> Файл зашифрован и записан в encoded.txt" << endl;
    }
    // дешифрование  
    if (password == "123") {
        text = read_from_file("encoded.txt");
        text = decrypt_(text, key);
        write_to_file("decoded.txt", text);
        cout << "-> Файл расшифрован и записан в decoded.txt" << endl;
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
