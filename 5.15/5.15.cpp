#include <iostream>   
#include <fstream>   
#include <algorithm>   
#include <string>   
#include <math.h>    
#include <clocale> 
#include <Windows.h> 
using namespace std;

string encrypt(const string& text, int rails) {
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
string decrypt(const string& text, int rails) {
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
string get_password() {
    string password;
    cout << "Введите пароль: ";
    cin >> password;
    return password;
}

void write_to_file(string filename, string text) {
    ofstream file(filename);
    file << text;
    file.close();
    cout << "Текст записан в файл " << filename << endl;
}

string read_from_file(string filename) {
    ifstream file(filename);
    string text((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
    file.close();
    return text;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string text, password;
    char answer;
    int rails;
    cout << "Введите исходный текст: ";
    getline(cin, text);
    cout << "Введите количество ребер скитала: ";
    cin >> rails;

    write_to_file("source.txt", text);

    password = get_password();

    // шифрование   
    if (password == "secret") {
        text = read_from_file("source.txt");
        text = encrypt(text, rails);
        write_to_file("encoded.txt", text);
        cout << "Текст зашифрован и записан в encoded.txt" << endl;
    }
    else {
        cout << "Неверный пароль, шифрование невозможно" << endl;
    }
    password = get_password();
    // дешифрование   
    if (password == "secret") {
        text = read_from_file("encoded.txt");
        text = decrypt(text, rails);
        write_to_file("decoded.txt", text);
        cout << "Текст расшифрован и записан в decoded.txt" << endl;
    }
    else {
        cout << "Неверный пароль, дешифрование невозможно" << endl;
    }
    cout << "Нажмите 'p', чтобы распечатать файлы: ";
    cin >> answer;
    if (answer == 'p' || answer == 'P') {
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
    }
    return 0;
}
