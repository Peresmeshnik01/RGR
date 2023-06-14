#pragma once
#include <string>
#include <algorithm> 
#include <iostream>
#include <string>  
#include <math.h>   
#include <locale>
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <Windows.h>
using namespace std;

string get_password();
void write_to_file(string filename, string text);
string read_from_file(string filename);

string encrypt_(string message, int key);//шифр Цезаря
string decrypt_(string message, int key);
void Write1(string text, string password, string password_);

string Fun(string plaintext, string key);//Табличная
string Fun2(string ciphertext, string key);//Табличная
bool isEnglish(string str);
void Write2(string text, string password, string password_);

string e(string text);//матричная шифровка
string d(string text);
void Write3(string text, string password, string password_);


string _encrypt(string text, int k, int* perm);//зафиксированная перестановка
string _decrypt(string text, int k, int* perm);//зафиксированная перестановка
bool _isEnglish_(string str);
void Write4(string text, string password, string password_);

string atbash(string text);//атбаш
string atbash_rus(string text);//атбаш
void Write5(string text, string password, string password_);

void createVigenereTable(int tableArr[26][26]);
string cipherEncryption(const string& text, const string& mappedKey);
int itrCount(int key, int msg);
string cipherDecryption(const string& text, const string& mappedKey);
void Write6(string text, string password, string password_);

void createNewAlphabet(char* newAlphabet);//кодовое слово
string encode_text(string text, char* ALPHABET_ENCODED);//кодовое слово
string decode_text(string text, char* ALPHABET_ENCODED);//кодовое слово
void Write7(string text, string password, string password_);

string Encr(const string& text, int rails);//Скитала
string Decr(const string& text, int rails);//Скитала
void Write8(string text, string password, string password_);

string encodeText(const string& text);//тарабарская грамота
string decodeText(const string& encodedText);//тарабарская грамота
bool isRussianText(const string& text);
void Write9(string text, string password, string password_);