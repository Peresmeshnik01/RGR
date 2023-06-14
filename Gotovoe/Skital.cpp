//��� �Ѩ ����
#include "Header.h"


string Encr(const string& text, int rails) {
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

// ������� ��� ������������ ������� �������  
string Decr(const string& text, int rails) {
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
void Write8(string text, string password, string password_) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int rails = 0;
    cout << "������� �����: ";
    getline(cin, text);
    write_to_file("source.txt", text);
    cout << "������� ���������� ����� �������: ";
    cin >> rails;
    cin.ignore();

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
        text = Encr(text, rails);
        write_to_file("encoded.txt", text);
        cout << "-> ����� ���������� � ������� � encoded.txt" << endl;
    }
    // ������������  
    if (password == "123") {
        text = read_from_file("encoded.txt");
        text = Decr(text, rails);
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