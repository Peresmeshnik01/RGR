//ТУТ ВСЁ НОРМ
#include "Header.h"

string encodeText(const string& text) {
    const string russianAlphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя.,-:…+= ";
    const string encodedAlphabet = "АЩШЧЦЕЁХФИЙТСРПОНМЛКУЗЖДГВБЪЫЪЭЮЯащшчцеёхфийтсрпонмлкузждгвбъыьэюя.,-:…+= ";
    string encodedText;
    for (char c : text) {
        size_t index = russianAlphabet.find(tolower(c));
        if (index != string::npos) {
            encodedText += encodedAlphabet[index];
        }
        else {
            encodedText += c;
        }
    }
    return encodedText;
}

string decodeText(const string& encodedText) {
    const string russianAlphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя.,-:…+= ";
    const string encodedAlphabet = "АЩШЧЦЕЁХФИЙТСРПОНМЛКУЗЖДГВБЪЫЪЭЮЯащшчцеёхфийтсрпонмлкузждгвбъыьэюя.,-:…+= ";
    string decodedText;
    for (char c : encodedText) {
        size_t index = encodedAlphabet.find(c);
        if (index != string::npos) {
            decodedText += russianAlphabet[index];
        }
        else {
            decodedText += c;
        }
    }
    return decodedText;
}

bool isRussianText(const string& text) {
    const string russianAlphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя.,-:…+= ";
    const string encodedAlphabet = "АЩШЧЦЕЁХФИЙТСРПОНМЛКУЗЖДГВБЪЫЪЭЮЯащшчцеёхфийтсрпонмлкузждгвбъыьэюя.,-:…+= ";
    for (char c : text) {
        if (russianAlphabet.find(tolower(c)) == string::npos) {
            return false;
        }
    }
    return true;
}


void Write9(string text, string password, string password_) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string inputText;
    while (true) {
        cout << "Введите исходный текст: " << endl;
        getline(cin, inputText);
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
        if (isRussianText(inputText)) {
            break;
        }
        else {
            cout << "Ошибка: используйте русский язык." << endl;
        }
    }

    ofstream inputFile("source.txt");
    if (inputFile.is_open()) {
        inputFile << inputText;
        inputFile.close();
        cout << "\n" << "Исходный текст записан в файл 'input.txt'" << "\n\n";
    }
    else {
        cout << "Ошибка при открытии файла 'input.txt'" << endl;
        
    }

    string encodedText = encodeText(inputText);
    cout << "Закодированный текст: " << "\n" << encodedText << endl;
    cout << "\n";
    string decodedText = decodeText(encodedText);
    cout << "Декодированный текст: " << "\n" << decodedText << endl;

    ofstream encodedFile("encoded.txt");
    if (encodedFile.is_open()) {
        encodedFile << encodedText;
        encodedFile.close();
        cout << "\n" << "Закодированный текст записан в файл 'encoded_text.txt'" << endl;
    }
    else {
        cout << "Ошибка при открытии файла 'encoded.txt'" << endl;
       
    }

    ofstream decodedFile("decoded.txt");
    if (decodedFile.is_open()) {
        decodedFile << decodedText;
        decodedFile.close();
        cout << "Декодированный текст записан в файл 'decoded.txt'" << endl;
    }
    else {
        cout << "Ошибка при открытии файла 'decoded_text.txt'" << endl;
    }
}
