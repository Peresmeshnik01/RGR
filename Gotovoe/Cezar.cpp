/*���� �������� �� ���������� ����, �� ���� ������ ����� �� ������ ����� ����� ����������� ����� �٨ ���*/
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
        else {
            // cout << "������! ��������� ������ �������� ������ �� ���� ����������� ��������." << endl;
            cout << "Error, only eng alphabet" << endl;
            exit(1);
        }
    }
    return result;
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
    cout << "������� �������� ����� : ";
    getline(cin, text);
    write_to_file("source.txt", text);
    cout << "-> ���� ��� ������� � encoded.txt";
    cout << endl;
    cout << "������: ";
    getline(cin, password);
    while (password != password_)
    {
        cout << "������: ";
        getline(cin, password); // �������� ���� ������������

        // ���� ��������� ������ ��������, ������� ��������� �� ������
        if (password != password_)
        {
            cout << "�������� ������! ���������� ��� ���." << endl;
        }
    }
    if (password == "123") {
        cout << "Key: ";
        cin >> key;
        text = read_from_file("source.txt");
        text = encrypt_(text, key);
        write_to_file("encoded.txt", text);
        cout << "-> ���� ���������� � ������� � encoded.txt" << endl;
    }
    // ������������  
    if (password == "123") {
        text = read_from_file("encoded.txt");
        text = decrypt_(text, key);
        write_to_file("decoded.txt", text);
        cout << "-> ���� ����������� � ������� � decoded.txt" << endl;
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