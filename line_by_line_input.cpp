#include <iostream>//���������� ���������� �����-������ 
using namespace std;//���������� ����������� ������������ ���� 
int main() {//�������� �������(���� ���������) 
    const int size = 3;//������ ������ ������� 
    int A[size][size], i, j, n = 0;//��������� ������, ��������� ��� ����� � �������� � ����������, � ������� �������� �������� ������ ��� ������ �� ������� 
    //��������� ������ � ���������� 
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            cin >> A[i][j];
        cout << "\n";
    i = 0, j = 0;
    do {
        n++;//����������� �������� ������ �� 1 
        for (int k = 0; k < size; k++)//������� n ��������� �� ������� 
            cout << A[i][j++] << ' '; //����� � �����������
        cout << "\n";
        if (n == size)//���� ����� ����� ����������� ������� 
            break;//����� 
    } while (n);
    cout << "\n";
    i = 0, j = 0;
        for (int l = 0; l < (size * size); l++)
            cout << A[i][j++] << ' '; //���������� ����� ��������� �������
}