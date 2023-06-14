///ДОЛЖНА БЫТЬ ПРОВЕРКА НА АНГЛИЙСКИЙ ЯЗЫК
#include "Header.h" 
// Функция шифрования
string _encrypt(string text, int k, int* perm) {
    string result = "";
    int n = text.length();
    int groups = n / k;
    if (n % k != 0) {
        groups++;
    }
    for (int i = 0; i < groups; i++) {
        int start = i * k;
        int end = min(start + k, n);
        string group = text.substr(start, end - start);
        if (group.length() < k) {
            group.append(k - group.length(), ' ');
        }
        for (int j = 0; j < k; j++) {
            result += group[perm[j] - 1];
        }
    }
    return result;
}

// Функция дешифрования
string _decrypt(string text, int k, int* perm) {
    string result = "";
    int n = text.length();
    int groups = n / k;
    for (int i = 0; i < groups; i++) {
        int start = i * k;
        int end = min(start + k, n);
        string group = text.substr(start, end - start);
        string decrypted_group = "";
        for (int j = 0; j < k; j++) {
            decrypted_group += group[find(perm, perm + k, j + 1) - perm];
        }
        result += decrypted_group;
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
void Write4(string text, string password, string password_) {
    int key = 0;
    int k = 4;
    int perm[] = { 3, 2, 4, 1 };
    string plaintext;
    cout << "Введите исходный текст: ";
    getline(cin, plaintext);
    bool mes = _isEnglish_(plaintext);
    if (mes) {
        write_to_file("source.txt", plaintext);
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
            text = _encrypt(text, k, perm);
            write_to_file("encoded.txt", text);
            cout << "-> Текст зашифрован и записан в encoded.txt" << endl;
        }
        // дешифрование  
        if (password == "123") {
            text = read_from_file("encoded.txt");
            text = _decrypt(text, k, perm);
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