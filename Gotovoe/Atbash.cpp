/*���� ����� �����, ���� ������ ������� ������� �������� �� ������� ����,
���� �� ��������� ����������� ��������� ���� ������ � ��� �� ������� ��������� �����������*/
#include "Header.h" 

string atbash(string text) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) { // uppercase
                result += (char)('Z' - (text[i] - 'A'));
            }
            else { // lowercase
                result += (char)('z' - (text[i] - 'a'));
            }
        }
        else { // not a letter
            result += text[i];
        }
    }
    return result;
}
string atbash_rus(string text) {
    string result = "";
    string a = "��������������������������������";
    string b = a;
    reverse(b.begin(), b.end());
    string A = "�����Ũ��������������������������";
    string B = A;
    reverse(B.begin(), B.end());
    for (int i = 0; i < text.length(); i++) {
        if (a.find(text[i]) != string::npos) { //���� ������ ���������� � ������ "�" 
            int index = a.find(text[i]); //���� ��� ������ 
            text[i] = b[index]; //������� ������ �� ���������� ������� 
        }
        else if (A.find(text[i]) != string::npos) { //��� �������� � ������� �������� 
            int index = A.find(text[i]);
            text[i] = B[index];
        }
        result += text[i]; //�������� ��������� 
    }
    return result;
}
void Write5(string text, string password, string password_) {
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int language;
    cout << "1.����������\n2.�������\n��������(1,2): ";
    cin >> language;
    cin.ignore();
    cout << "������� �����: ";
    getline(cin, text);
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
    if (language == 1) {
        if (password == "123") {
            text = read_from_file("source.txt");
            text = atbash(text);
            write_to_file("encoded.txt", text);
            cout << "-> ����� ���������� � ������� � encoded.txt" << endl;
        }
        // ������������  
        if (password == "123") {
            text = read_from_file("encoded.txt");
            text = atbash(text);
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
    if (language == 2) {
        if (password == "123") {
            text = read_from_file("source.txt");
            text = atbash_rus(text);
            write_to_file("encoded.txt", text);
            cout << "-> ����� ���������� � ������� � encoded.txt" << endl;
        }
        // ������������  
        if (password == "123") {
            text = read_from_file("encoded.txt");
            text = atbash_rus(text);
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