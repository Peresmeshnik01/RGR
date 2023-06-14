//��� �Ѩ ����
#include "Header.h"
#include <algorithm> 
void createNewAlphabet(char* newAlphabet) {
    const int ALPHABET_SIZE = 26;
    char originalAlphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char word[ALPHABET_SIZE + 1];
    bool validInput = false;
    while (!validInput) {
        cout << "������� ���� (����� �� ���������� ����� ���������� �������): ";
        cin >> word;
        validInput = true;
        int wordLength = strlen(word);
        for (int i = 0; i < wordLength; i++) {
            if (!isupper(word[i])) { // ���������, ��� ������ �������� ��������� ������ 
                validInput = false;
                break;
            }
        }
        if (!validInput) {
            std::cout << "������: ������� ������ ��������� ����� ����������� ��������" << std::endl;
        }
    }

    // ��������� ����� �� ����� � ����� ������� 
    int wordLength = strlen(word);
    for (int i = 0; i < wordLength; i++) {
        newAlphabet[i] = word[i];
    }

    // ��������� ��������� ����� �� ��������� �������� 
    int j = wordLength;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        char letter = originalAlphabet[i];
        if (strchr(word, letter) == nullptr) { // ���������, ��� ����� �� ���� ��������� ����� 
            newAlphabet[j] = letter;
            j++;
        }
    }
    newAlphabet[ALPHABET_SIZE] = '\0';
}


string encode_text(string text, char* ALPHABET_ENCODED) {
    string text_encoded; // ������ ��� �������� ��������������� ������ 
    string encoded_text;
    char ALPHABET_DECODED[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (auto c : text) {
        auto it = std::find(std::begin(ALPHABET_DECODED), std::end(ALPHABET_DECODED), std::toupper(c));
        if (it != std::end(ALPHABET_DECODED)) {
            int index = std::distance(std::begin(ALPHABET_DECODED), it);
            text_encoded += std::toupper(ALPHABET_ENCODED[index]);
        }
        else {
            text_encoded += c;
        }
        encoded_text += text_encoded + "\n";

    }
    return text_encoded;
}

string decode_text(string text, char* ALPHABET_ENCODED) {
    const int ALPHABET_SIZE = 26;
    string decoded_text;
    char ALPHABET_DECODED[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < text.size(); i++) {
        char c = text[i];
        bool found = false;
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            if (toupper(c) == ALPHABET_ENCODED[j]) {
                decoded_text += toupper(ALPHABET_DECODED[j]);
                found = true;
                break;
            }
        }
        if (!found) {
            decoded_text += c;
        }
    }
    return decoded_text;
}
void Write7(string text, string password, string password_) {
    const int ALPHABET_SIZE = 26;
    setlocale(LC_ALL, "RUS");
    cout << "������� �����: ";
    getline(cin, text);
    write_to_file("source.txt", text);
    char newAlphabet[ALPHABET_SIZE + 1];
    char ALPHABET_ENCODED[ALPHABET_SIZE + 1];
    createNewAlphabet(newAlphabet);
    cout << "������� ������: ";
    getline(cin, password);
    while (password != password_)
    {
        cout << "������� ������: ";
        getline(cin, password); // �������� ���� ������������

        // ���� ��������� ������ ��������, ������� ��������� �� ������
        if (password != password_)
        {
            cout << "�������� ������! ���������� �����." << endl;
        }
    }
    if (password == "123") {
        text = read_from_file("source.txt");
        text = encode_text(text, ALPHABET_ENCODED);
        write_to_file("encoded.txt", text);
        cout << "-> ����� ���������� � ������� � encoded.txt" << endl;
    }
    // ������������  
    if (password == "123") {
        text = read_from_file("encoded.txt");
        text = decode_text(text, ALPHABET_ENCODED);
        write_to_file("decoded.txt", text);
        cout << "-> ����� ����������� � ������� decoded.txt" << endl;
    }
    cout << "���� source.txt:" << endl;
    cout << endl;
    cout << read_from_file("source.txt") << endl;
    cout << endl;
    cout << "���� encoded.txt:" << endl;
    cout << endl;
    cout << read_from_file("encoded.txt") << endl;
    cout << endl;
    cout << "���� decoded.txt:" << endl;
    cout << endl;
    cout << read_from_file("decoded.txt") << endl;
    cout << endl;
}