#include "Header.h"
int main()
{
    setlocale(LC_ALL, "RUS");
    string text, result, password, key, message;
    string password_ = "123";
    cout << "o----------------------�����----------------------o";
    cout << endl;
    while (password != password_)
    {
        cout << "----������� ������";
        cout << endl;
        getline(cin, password); // �������� ���� ������������

        // ���� ��������� ������ ��������, ������� ��������� �� ������
        if (password != password_)
        {
            cout << "-> �������� ������! ���������� �����." << endl;
            cout << endl;
        }
    }
    cout << "-> ���������� ������! ������ ��������." << endl;
    while (1) {
        int ch;
        cout << "  o-------------������� ����� �����-------------o";
        cout << endl;
        cout << "  |  1. ���� ������                             |" << endl;
        cout << "  |  2. ��������� ��������                      |" << endl;
        cout << "  |  3. ��������� ��������                      |" << endl;
        cout << "  |  4. �������� ��������������� �������������  |" << endl;
        cout << "  |  5. ���� �����                              |" << endl;
        cout << "  |  6. ���� ��������                           |" << endl;
        cout << "  |  7. ���� � �������������� �������� �����    |" << endl;
        cout << "  |  8. ���� ������������ '�������'             |" << endl;
        cout << "  |  9. �������� '����������� �������'          |" << endl;
        cout << "  |  0. ����� �� ��������� '�����'              |" << endl;
        cout << "  o---------------------------------------------o";
        cout << endl;
        cin >> ch;
        getline(cin, text);
        switch (ch)
        {
        case 1:
            cout << "���� ������" << endl;
            cout << endl;
            Write1(text, password, password_);
            break;
        case 2:
            cout << "��������� ��������" << endl;
            cout << endl;
            Write2(text, password, password_);
            break;
        case 3:
            cout << "��������� ��������:" << endl;
            cout << endl;
            Write3(text, password, password_);
            break;
        case 4:
            cout << "�������� ��������������� �������������" << endl;
            cout << endl;
            Write4(text, password, password_);
            break;
        case 5:
            cout << "���� �����" << endl;
            cout << endl;
            Write5(text, password, password_);
            break;
        case 6:
            cout << "���� ��������" << endl;
            cout << endl;
            Write6(text, password, password_);
            break;
        case 7:
            cout << "���� � �������������� �������� �����" << endl;
            cout << endl;
            Write7(text, password, password_);
            break;
        case 8:
            cout << "���� ������������ '�������'" << endl;
            cout << endl;
            Write8(text, password, password_);
            break;
        case 9:
            cout << "�������� '����������� �������'" << endl;
            cout << endl;
            Write9(text, password, password_);
            break;
        case 0:
            cout << "------------/ >  >     bye";
            cout << endl;
            cout << "-----------| 0  0|";
            cout << endl;
            cout << "----------/  =__x)=";
            cout << endl;
            cout << "---------/      |";
            cout << endl;
            cout << "--------/   | | |";
            return 0;
        default:
            break;
        }
    }
}