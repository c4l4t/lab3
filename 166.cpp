#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <stdio.h>
#include <cctype>

using namespace std;

int palindrom(char* a);
void menu();
void kount(char* a);
void task2(ifstream& TEXT);
void task3(ifstream& TEXT);
int count_SP(char LINE[255]);
void sorter(char LINES[3][255]);

int main()
{
	setlocale(LC_ALL, "Russian");

	int choose = 10;

	menu();
	while (choose != 0) {
		cout << "Задание № ";
		cin >> choose;

		if (choose == 1) {
			cout << "Считает количество символов в строке." << endl;
			cin.clear();
			cin.ignore();
			int i, n = 0;
			char* s = new char[100];
			cout << "Введите строку: ";
			cin.getline(s, 255);
			for (i = 0; s[i] != '\0'; i++) n++;
			cout << "Количество символов в строке: " << n << endl;
			cout << endl;
		}
		if (choose == 2) {
			cout << "Составляет предложения из заранее подготовленных слов." << endl;
			cout << "Порядок слов: article, существительное, глагол, предлог, article и существительное. " << endl;
			cin.clear();
			cin.ignore();
			int arts, nos, ves, pres;
			char* art[100];
			{
				ifstream fin("z2.txt");
				if (!fin) {
					cout << "ошибка открытия файла" << endl;
					exit;
				}
				char* s = new char[100];
				int size = 0;
				int n;
				while (!fin.eof())
				{
					fin.getline(s, 100, '\n');
					char seps[] = " ,;"; // Строка разделителей
					char* token; // указатель на новой слово
					token = strtok(s, seps);// находим первое слово
					n = 0; //n - количество слов
					while (token != NULL) {
						art[size] = token; size++;
						token = strtok(NULL, seps); n++;// выделяем следующее слово
					}
				}
				//for (int i = 0; i < n; i++) cout << art[i] << " "
				arts = n;
				cout << endl;
			}
			char* no[100];// = { "boy", "girl", "cat", "city", "car" };
			{
				ifstream fin("z2.2.txt");
				if (!fin) {
					cout << "ошибка открытия файла" << endl;
					exit;
				}
				char* s = new char[100];
				int size = 0;
				int n;
				while (!fin.eof())
				{
					fin.getline(s, 100, '\n');
					char seps[] = " ,;"; // Строка разделителей
					char* token; // указатель на новой слово
					token = strtok(s, seps);// находим первое слово
					n = 0; //n - количество слов
					while (token != NULL) {
						no[size] = token; size++;
						token = strtok(NULL, seps); n++;// выделяем следующее слово
					}
				}
				//for (int i = 0; i < n; i++) cout << no[i] << " ";
				nos = n;
			}
			char* ve[100];// = { "drove", "worked", "ran", "walked", "write" };
			{
				ifstream fin("z2.3.txt");
				if (!fin) {
					cout << "ошибка открытия файла" << endl;
					exit;
				}
				char* s = new char[100];
				int size = 0;
				int n;
				while (!fin.eof())
				{
					fin.getline(s, 100, '\n');
					char seps[] = " ,;"; // Строка разделителей
					char* token; // указатель на новой слово
					token = strtok(s, seps);// находим первое слово
					n = 0; //n - количество слов
					while (token != NULL) {
						ve[size] = token; size++;
						token = strtok(NULL, seps); n++;// выделяем следующее слово
					}
				}
				//for (int i = 0; i < n; i++) cout << ve[i] << " ";
				ves = n;
			}
			char* pre[100];// = { "to", "from", "over", "under", "in" };
			//int pres = sizeof(pre) / sizeof(pre[0]);
			{
				ifstream fin("z2.4.txt");
				if (!fin) {
					cout << "ошибка открытия файла" << endl;
					exit;
				}
				char* s = new char[100];
				int size = 0;
				int n;
				while (!fin.eof())
				{
					fin.getline(s, 100, '\n');
					char seps[] = " ,;"; // Строка разделителей
					char* token; // указатель на новой слово
					token = strtok(s, seps);// находим первое слово
					n = 0; //n - количество слов
					while (token != NULL) {
						pre[size] = token; size++;
						token = strtok(NULL, seps); n++;// выделяем следующее слово
					}
				}
				//for (int i = 0; i < n; i++) cout << pre[i] << " ";
				pres = n;
			}
			int N;
			cout << "Количество предложений = ";
			cin >> N;
			for (int i = 0; i < N; i++)
			{
				const int max_N = 256;
				char offer[max_N];
				sprintf(offer, "%s %s %s %s %s %s.", art[rand() % arts], no[rand() % nos], ve[rand() % ves], pre[rand() % pres], art[rand() % arts], no[rand() % nos]);
				offer[0] = toupper(offer[0]);
				cout << offer << endl;
			}
			cout << endl;
		}
		if (choose == 3) {
			cout << "Определяет является ли строка палиндромом." << endl;
			cin.clear();
			cin.ignore();
			char* s = new char[100];
			cout << "При использовании Русского языка, программа будет выдовать не верные результаты," << endl;
			cout << "поэтому рекомендуется использовать латинский алфовит." << endl;
			cout << "Введите строку - ";
			cin.getline(s, 255);
			if (palindrom(s)) cout << "Строка является Палиндромом!" << endl;
			else cout << "Строка не является Палиндромом!" << endl;
		}
		if (choose == 4) {
			cout << "Считает количество слов , а также количество предложений." << endl;
			cin.clear();
			cin.ignore();
			char* s = new char[100];
			cout << "Введите строку: ";
			cin.getline(s, 255);
			kount(s);
		}
		if (choose == 5) {
			cout << "Конкатенация строк: " << endl;
			cin.clear();
			cin.ignore();
			int i, n = 0;
			char* s = new char[100];
			char* z = new char[100];
			cout << "Введите строку№ 1: ";			
			cin.getline(s, 255);
			cout << "Введите строку№ 2: ";
			cin.getline(z, 255);
			for (i = 0; s[i] != '\0'; i++) n++;
			for (i = 0; z[i] != '\0'; i++) n++;
			cout << s <<" "<< z << endl;
			cout << endl;

		}
		if (choose == 6) {
			ifstream TEXT;
			TEXT.open("text.txt");
			task2(TEXT);
			TEXT.close();
		}
		if (choose == 7) {
			ifstream TEXT;
			TEXT.open("text.txt");
			task3(TEXT);
			TEXT.close();
		}

	}
}
void menu()
{
	cout << "1 - Задание 1" << endl;
	cout << "2 - Задание 2" << endl;
	cout << "3 - Задание 3" << endl;
	cout << "4 - Задание 4" << endl;
	cout << "5 - 3 вариант- 1 задание" << endl;
	cout << "6 - 3 вариант- 2 задание" << endl;
	cout << "7 - 3 вариант- 3 задание" << endl;
	cout << "0 - EXIT" << endl;
}

int palindrom(char* a)

{
	char* b = new char[100];
	int n = strlen(a);
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (isalpha(a[i])) {
			b[k++] = tolower(a[i]);
		}
	}
	b[k] = '\0';
	bool t = 1;
	for (int i = 0, j = strlen(b) - 1; i < j; i++, j--)
	{
		if ((b[i]) != b[j])
		{
			t = 0;
		}
	}
	return t;
}

void kount(char* a)

{
	int i;
	char* b = new char[100];
	strcpy(b, a);
	char seps[] = " ,.;!?";
	char seps1[] = ".!?";
	char* token;
	token = strtok(b, seps);
	int n = 1, m = 0;
	while (token != NULL) {
		token = strtok(NULL, seps); n++;
	}
	n--;
	cout << "Количество слов: " << n << endl;
	for (i = 0; i < strlen(a); i++)
	{
		if (a[i] == '.' || a[i] == '!' || a[i] == '?') m++;
	}
	cout << "Количество предложений: " << m << endl;
}


void task2(ifstream& TEXT) {
	char line[255];
	char* word;
	char delim[] = " !?.,\n";
	TEXT.getline(line, 255, NULL);
	word = strtok(line, delim);
	while (word != NULL) {
		if (strlen(word) > 9) cout << word << endl;
		word = strtok(NULL, delim);
	}
}

void task3(ifstream& TEXT) {
	char LINES[3][255];
	char temp[255] = " ";
	TEXT.getline(LINES[0], 255, '\n');
	TEXT.getline(LINES[1], 255, '\n');
	TEXT.getline(LINES[2], 255, '\n');
	int count1 = count_SP(LINES[0]);
	int count2 = count_SP(LINES[1]);
	int count3 = count_SP(LINES[2]);
	for (int i = 0; i < 3; i++) {
		cout << LINES[i] << endl;
	}
	cout << "\nРезультат сортировки:\n" << endl;
	sorter(LINES);
	for (int i = 0; i < 3; i++) {
		cout << LINES[i] << endl;
	}
}

int count_SP(char LINE[255]) {
	int count = 0;
	for (int i = 0; i < strlen(LINE); i++) {
		if (LINE[i] == ' ') count++;
	}
	return count;
}

void sorter(char LINES[3][255]) {
	char temp[255];
	for (int i = 1; i <= 3; i++) {
		for (int j = i - 1; j > 0; j--) {
			if (count_SP(LINES[j]) > count_SP(LINES[j - 1])) {
				memcpy(temp, LINES[j], 255);
				memcpy(LINES[j], LINES[j - 1], 255);
				memcpy(LINES[j - 1], temp, 255);
			}
		}
	}
}