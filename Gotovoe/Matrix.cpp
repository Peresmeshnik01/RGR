/*ТУТ ВСЁ НОРМ*/
#include "Header.h"
string e(string text) {
    int u = text.length();
    int m;
    m = ceil(sqrt(u));
    int k = 0;
    string result1 = "";
    string result = "";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (k < u) {
                result1 += text[k];
                k++;
            }
            else {
                result1 += ' ';
            }
        }
    }
    char A[1000][1000];
    int i, j, n = 0;

    for (int arr = 0; arr < sqrt(result1.length()); arr++)
    {
        for (int idx = 0; idx < sqrt(result1.length()); idx++)
        {
            A[arr][idx] = result1[idx + (arr * sqrt(result1.length()))];
        }
    }
    if (m % 2 == 1) {
        i = sqrt(result1.length()) / 2, j = sqrt(result1.length()) / 2;
        do {
            n++;
            for (int k = 0; k < n; k++)
                result.push_back(A[i][j--]);

            if (n == sqrt(result1.length()))
                break;
            for (int k = 0; k < n; k++)
                result.push_back(A[i++][j]);
            n++;
            for (int k = 0; k < n; k++)
                result.push_back(A[i][j++]);
            for (int k = 0; k < n; k++)
                result.push_back(A[i--][j]);
        } while (n);
    }
    else {
        i = sqrt(result1.length()) / 2, j = (sqrt(result1.length()) / 2) - 1;
        do {
            n++;
            for (int k = 0; k < n; k++)
                result.push_back(A[i][j++]);
            for (int k = 0; k < n; k++)
                result.push_back(A[i--][j]);
            n++;

            for (int k = 0; k < n; k++)
                result.push_back(A[i][j--]);

            if (n == sqrt(result1.length()))
                break;
            for (int k = 0; k < n; k++)
                result.push_back(A[i++][j]);
        } while (n);
    }
    return result;
}
string d(string text) {
    reverse(text.begin(), text.end());
    int u = text.length();
    int m;
    m = ceil(sqrt(u));
    char** A = new char* [m];
    for (int i = 0; i < m; i++)
        A[i] = new char[m];
    int top = 0, bottom = m - 1, left = 0, right = m - 1;
    int n = 0;
    while (n < text.length()) {
        for (int i = left; i <= right && n < text.length(); i++) {
            A[top][i] = text[n++];
        }
        top++;
        for (int i = top; i <= bottom && n < text.length(); i++) {
            A[i][right] = text[n++];
        }
        right--;
        for (int i = right; i >= left && n < text.length(); i--) {
            A[bottom][i] = text[n++];
        }
        bottom--;
        for (int i = bottom; i >= top && n < text.length(); i--) {
            A[i][left] = text[n++];
        }
        left++;
    }

    string result = "";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            result += A[i][j];
        }
    }
    return result;
}
void Write3(string text, string password, string password_) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Введите исходный текст: ";
    getline(cin, text);

    write_to_file("source.txt", text);



    cout << "-> Файл был записан в encoded.txt" << endl;
    cout << "Пароль: ";
    getline(cin, password);
    while (password != password_)
    {
        cout << "Пароль: ";
        getline(cin, password); // Получаем ввод пользователя

        // Если введенный пароль неверный, выводим сообщение об ошибке
        if (password != password_)
        {
            cout << "Неверный пароль! Попробуйте ещё раз." << endl;
        }
    }
    if (password == "123") {
        text = read_from_file("source.txt");
        text = e(text);
        write_to_file("encoded.txt", text);
        cout << "-> Файл зашифрован и записан в encoded.txt" << endl;
    }
    // дешифрование  
    if (password == "123") {
        text = read_from_file("encoded.txt");
        text = d(text);
        write_to_file("decoded.txt", text);
        cout << "-> Файл расшифрован и записан в decoded.txt" << endl;
    }
    cout << "Файл source.txt:" << endl;
    cout << endl;
    cout << read_from_file("source.txt") << endl;
    cout << endl;
    cout << "Файл encoded.txt:" << endl;
    cout << endl;
    cout << read_from_file("encoded.txt") << endl;
    cout << endl;
    cout << "Файл decoded.txt:" << endl;
    cout << endl;
    cout << read_from_file("decoded.txt") << endl;
    cout << endl;
}
