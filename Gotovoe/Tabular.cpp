/* �� �������� ��� ���������� ���� ������ �� :(*/
#include "Header.h" 
// ������� ����������
string Fun(string plaintext, string key) {
    string ciphertext = "";

    // ������� ������� ������
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

    // ������� ������ ������ ��������� ������
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

// ������� �����������
string Fun2(string ciphertext, string key) {
    string plaintext = "";

    // ������� ������� ������
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

    // �������������� ������ ������ �����������
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
    cout << "������� �������� ����� �� ���������� ����� ���������� �������:  ";
    getline(cin, text);
    for (char c : text) {
        if (islower(c)) {
            all_upper = false;
            cout << "������: ������ �������� ������� ������� ��������.\n";
            break;
        }
    }
    bool mes = isEnglish(text);
    if (all_upper && mes) {
        cout << "������� ���� (����� �� ���������� �����): ";
        getline(cin, key);
        bool k = isEnglish(key);
        if (k) {
            write_to_file("source.txt", text);
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
                text = Fun(text, key);
                write_to_file("encoded.txt", text);
                cout << "-> ����� ���������� � ������� � encoded.txt" << endl;
            }
            // ������������  
            if (password == "123") {
                text = read_from_file("encoded.txt");
                text = Fun2(text, key);
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

        else if (!k) {
            cout << "���� �������� ������� �� ������� �����";
        }

        else if (!mes) {
            cout << "������ �������� ������� �� ������� �����";
        }
    }
}