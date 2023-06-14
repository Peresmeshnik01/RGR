//����� �������� �� ���������� �����, � �� ������� ����� (��� �� ���������� � � ��������� �������)
#include "Header.h"

void createVigenereTable(int tableArr[26][26]) {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            int temp;
            if ((i + 65) + j > 90) {
                temp = ((i + 65) + j) - 26;
                tableArr[i][j] = temp;
            }
            else {
                temp = (i + 65) + j;
                tableArr[i][j] = temp;
            }
        }
    }
}

string cipherEncryption(const string& text, const string& mappedKey) {
    int tableArr[26][26];
    createVigenereTable(tableArr);
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == 32 && mappedKey[i] == 32) {
            result += " ";
        }
        else {
            int x = (int)text[i] - 65;
            int y = (int)mappedKey[i] - 65;
            result += (char)tableArr[x][y];
        }
    }

    return result;
}

int itrCount(int key, int msg) {
    int counter = 0;
    string result = "";

    for (int i = 0; i < 26; i++) {
        if (key + i > 90) {
            result += (char)(key + (i - 26));
        }
        else {
            result += (char)(key + i);
        }
    }

    for (int i = 0; i < result.length(); i++) {
        if (result[i] == msg) {
            break;
        }
        else {
            counter++;
        }
    }
    return counter;
}

string cipherDecryption(const string& text, const string& mappedKey) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == 32 && mappedKey[i] == 32) {
            result += " ";
        }
        else {
            int temp = itrCount((int)mappedKey[i], (int)text[i]);
            result += (char)(65 + temp);
        }
    }

    return result;
}

void Write6(string text, string password, string password_) {
    while (password != password_) {
        cout << "������� ������: ";
        getline(cin, password);

        if (password != password_) {
            cout << "�������� ������! ���������� �����." << endl;
        }
    }

    if (password == "123") {

        string mappedKey;

        string msg;
        cout << "������� ����� �� ����������: ";
        getline(cin, msg);

        for (int i = 0; i < msg.length(); i++) {
            msg[i] = toupper(msg[i]);
        }

        string key;
        cout << "������� ���� (���������� ����� ���������� �������): ";
        getline(cin, key);

        for (int i = 0; i < key.length(); i++) {
            key[i] = toupper(key[i]);
        }

        string keyMap = "";
        for (int i = 0, j = 0; i < msg.length(); i++) {
            if (msg[i] == 32) {
                keyMap += 32;
            }
            else {
                if (j < key.length()) {
                    keyMap += key[j];
                    j++;
                }
                else {
                    j = 0;
                    keyMap += key[j];
                    j++;
                }
            }
        }
        text = msg;
        write_to_file("source.txt", text);
        mappedKey = keyMap;

        if (password == "123") {
            text = read_from_file("source.txt");
            text = cipherEncryption(text, mappedKey);
            write_to_file("encoded.txt", text);
            cout << "-> ����� ���������� � ������� � encoded.txt" << endl;
        }
        // ������������  
        if (password == "123") {
            text = read_from_file("encoded.txt");
            text = cipherDecryption(text, mappedKey);
            write_to_file("decoded.txt", text);
            cout << "-> ����� ���������� � ������� decoded.txt" << endl;
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
}