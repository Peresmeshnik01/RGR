//��� �Ѩ ����
#include "Header.h"

string encodeText(const string& text) {
    const string russianAlphabet = "�����Ũ����������������������������������������������������������.,-:�+= ";
    const string encodedAlphabet = "�����Ũ����������������������������������������������������������.,-:�+= ";
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
    const string russianAlphabet = "�����Ũ����������������������������������������������������������.,-:�+= ";
    const string encodedAlphabet = "�����Ũ����������������������������������������������������������.,-:�+= ";
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
    const string russianAlphabet = "�����Ũ����������������������������������������������������������.,-:�+= ";
    const string encodedAlphabet = "�����Ũ����������������������������������������������������������.,-:�+= ";
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
        cout << "������� �������� �����: " << endl;
        getline(cin, inputText);
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
        if (isRussianText(inputText)) {
            break;
        }
        else {
            cout << "������: ����������� ������� ����." << endl;
        }
    }

    ofstream inputFile("source.txt");
    if (inputFile.is_open()) {
        inputFile << inputText;
        inputFile.close();
        cout << "\n" << "�������� ����� ������� � ���� 'input.txt'" << "\n\n";
    }
    else {
        cout << "������ ��� �������� ����� 'input.txt'" << endl;
        
    }

    string encodedText = encodeText(inputText);
    cout << "�������������� �����: " << "\n" << encodedText << endl;
    cout << "\n";
    string decodedText = decodeText(encodedText);
    cout << "�������������� �����: " << "\n" << decodedText << endl;

    ofstream encodedFile("encoded.txt");
    if (encodedFile.is_open()) {
        encodedFile << encodedText;
        encodedFile.close();
        cout << "\n" << "�������������� ����� ������� � ���� 'encoded_text.txt'" << endl;
    }
    else {
        cout << "������ ��� �������� ����� 'encoded.txt'" << endl;
       
    }

    ofstream decodedFile("decoded.txt");
    if (decodedFile.is_open()) {
        decodedFile << decodedText;
        decodedFile.close();
        cout << "�������������� ����� ������� � ���� 'decoded.txt'" << endl;
    }
    else {
        cout << "������ ��� �������� ����� 'decoded_text.txt'" << endl;
    }
}