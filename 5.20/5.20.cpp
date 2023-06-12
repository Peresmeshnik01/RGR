#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

std::string encodeText(string& text) {
    std::string encodedText;
    for (char c : text) {
        switch (c) {
        case 'А': case 'а': encodedText += 'А'; break;
        case 'Б': case 'б': encodedText += 'Щ'; break;
        case 'В': case 'в': encodedText += 'Ш'; break;
        case 'Г': case 'г': encodedText += 'Ч'; break;
        case 'Д': case 'д': encodedText += 'Ц'; break;
        case 'Е': case 'е': encodedText += 'Е'; break;
        case 'Ж': case 'ж': encodedText += 'Х'; break;
        case 'З': case 'з': encodedText += 'Ф'; break;
        case 'И': case 'и': encodedText += 'И'; break;
        case 'Й': case 'й': encodedText += 'Й'; break;
        case 'К': case 'к': encodedText += 'Т'; break;
        case 'Л': case 'л': encodedText += 'С'; break;
        case 'М': case 'м': encodedText += 'Р'; break;
        case 'Н': case 'н': encodedText += 'П'; break;
        case 'О': case 'о': encodedText += 'О'; break;
        case 'П': case 'п': encodedText += 'Н'; break;
        case 'Р': case 'р': encodedText += 'М'; break;
        case 'С': case 'с': encodedText += 'Л'; break;
        case 'Т': case 'т': encodedText += 'К'; break;
        case 'У': case 'у': encodedText += 'У'; break;
        case 'Ф': case 'ф': encodedText += 'З'; break;
        case 'Х': case 'х': encodedText += 'Ж'; break;
        case 'Ц': case 'ц': encodedText += 'Д'; break;
        case 'Ч': case 'ч': encodedText += 'Г'; break;
        case 'Ш': case 'ш': encodedText += 'В'; break;
        case 'Щ': case 'щ': encodedText += 'Б'; break;
        case 'Ъ': case 'ъ': encodedText += 'Ъ'; break;
        case 'Ы': case 'ы': encodedText += 'Ы'; break;
        case 'Ь': case 'ь': encodedText += 'Ь'; break;
        case 'Э': case 'э': encodedText += 'Э'; break;
        case 'Ю': case 'ю': encodedText += 'Ю'; break;
        case 'Я': case 'я': encodedText += 'Я'; break;
        default: encodedText += c; break;
        }
    }
    return encodedText;
}

std::string decodeText(string& encodedText) {
    std::string decodedText;
    for (char c : encodedText) {
        switch (c) {
        case 'Ш': decodedText += 'В'; break;
        case 'П': decodedText += 'Н'; break;
        case 'М': decodedText += 'Р'; break;
        case 'Л': decodedText += 'С'; break;
        case 'Н': decodedText += 'П'; break;
        case 'К': decodedText += 'Т'; break;
        case 'Й': decodedText += 'Й'; break;
        case 'З': decodedText += 'Ф'; break;
        case 'Ж': decodedText += 'Х'; break;
        case 'Е': decodedText += 'Е'; break;
        case 'И': decodedText += 'И'; break;
        case 'Д': decodedText += 'Ц'; break;
        case 'Г': decodedText += 'Ч'; break;
        case 'В': decodedText += 'Ш'; break;
        case 'Б': decodedText += 'Щ'; break;
        case 'А': decodedText += 'А'; break;
        case 'Щ': decodedText += 'Б'; break;
        case 'С': decodedText += 'Л'; break;
        case 'Р': decodedText += 'М'; break;
        case 'Ф': decodedText += 'З'; break;
        case 'У': decodedText += 'У'; break;
        case 'Т': decodedText += 'К'; break;
        case 'Ц': decodedText += 'Д'; break;
        case 'Х': decodedText += 'Ж'; break;
        case 'Ч': decodedText += 'Г'; break;
        case 'Ъ': decodedText += 'Ъ'; break;
        case 'Ы': decodedText += 'Ы'; break;
        case 'Ь': decodedText += 'Ь'; break;
        case 'Э': decodedText += 'Э'; break;
        case 'Ю': decodedText += 'Ю'; break;
        case 'Я': decodedText += 'Я'; break;        
        default: decodedText += c; break;
        }
    }
    return decodedText;
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string inputText;    
    cout << "Введите исходный текст: ";
    getline(cin, inputText);

    for (char c : inputText) {
        if (c < -127 || c > 65) {
            std::cerr << "Ошибка: используйте русский язык." << std::endl;
            return 1;
        }
    }
    
    std::ofstream inputFile("input.txt");
    if (inputFile.is_open()) {
        inputFile << inputText;
        inputFile.close();
        std::cout << "Исходный текст записан в файл 'input.txt'" << std::endl;
    }
    else {
        std::cerr << "Ошибка при открытии файла 'input.txt'" << std::endl;
        return 1;
    }

    std::string encodedText = encodeText(inputText);
    std::cout << "Закодированный текст: " << encodedText << std::endl;

    std::string decodedText = decodeText(encodedText);
    std::cout << "Декодированный текст: " << decodedText << std::endl;

    std::ofstream encodedFile("encoded_text.txt");
    if (encodedFile.is_open()) {
        encodedFile << encodedText;
        encodedFile.close();
        std::cout << "Закодированный текст записан в файл 'encoded_text.txt'" << std::endl;
    }
    else {
        std::cerr << "Ошибка при открытии файла 'encoded_text.txt'" << std::endl;
        return 1;
    }

    std::ofstream decodedFile("decoded_text.txt");
    if (decodedFile.is_open()) {
        decodedFile << decodedText;
        decodedFile.close();
        std::cout << "Декодированный текст записан в файл 'decoded_text.txt'" << std::endl;
    }
    else {
        std::cerr << "Ошибка при открытии файла 'decoded_text.txt'" << std::endl;
        return 1;
    }

    return 0;
}

