#include <iostream>  
#include <string> 
#include <math.h> 
using namespace std;
int main() {
    string str = "abcdefghijklmnopqrstuvwxy";
    char A[1000][1000];
    int i, j, n = 0;
    //��������� � ��������� ������� ������� �� ����������� 
    for (int arr = 0; arr < str.length(); arr++)
    {
        for (int idx = 0; idx < str.length(); idx++)
        {
            A[arr][idx] = str[idx + (arr * str.length())];
        }
    }
    i = 0, j = 0;
    do {
        n++;//����������� �������� ������ �� 1 
        for (int k = 0; k < sqrt(str.length()); k++)//������� n ��������� �� ������� 
            cout << A[i][j++] << ' '; //����� � ���� �������
        cout << "\n";
        if (n == sqrt(str.length()))//���� ����� ����� ����������� ������� 
            break;//����� 
    } while (n);
    cout << "\n";
    i = 0, j = 0;
    for (int l = 0; l < str.length(); l++)
        cout << A[i][j++] << ' '; //���������� ����� ��������� �������
}