#include "Header.h" 
#include <locale>
using namespace std;
string get_password() {
    setlocale(LC_ALL, "RUS");
    string password;
    cout << "Введите пароль: ";
    cin >> password;
    return password;
}

void write_to_file(string filename, string text) {
    setlocale(LC_ALL, "RUS");
    ofstream file(filename);
    file << text;
    file.close();

}

string read_from_file(string filename) {
    ifstream file(filename);
    string text((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
    file.close();
    return text;
}
