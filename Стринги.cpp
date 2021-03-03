#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int strLen(char str[]);

void to_upper(char str[]); // переводит строку в верхний регистр
void to_lower(char str[]); // в нижний
void capitalize(char str[]); // первую букву каджого слова в предложении делает заглавной и удаляет лишние пробелы

void to_upper_lol(char str[]);
void tolower(char str[]);
void capitalizsetwo(char str[]);
void shrink(char str[]);
void remove_symbol(char str[], char symbol);

bool is_palindrome(char str[]);
bool is_int_number(char str[]);
bool is_bin_number(char str[]);

bool is_int_numbertwo(char str[]);
bool is_bin_number(char str[]);

int  to_int_number(char str[]);
int  bin_to_dec(char str[]);

int to_int_numbertwo(char str[]);
int bin_to_dec(char str[]);

void ASCII();

int main()
{
	setlocale(LC_ALL, "Ru");
	system("Color 0A");
	system("CHCP 1251");
	system("CLS");

	const int n = 256;
	char str[n] = {};
	cout << "Введите строку: "; SetConsoleCP(1251); cin.getline(str, n); //SetConsoleCP(866);
	cout << "Размер массива: " << sizeof(str) << endl;
	cout << "Размер строки: " << strLen(str) << endl;
	cout << "Верхний регистр: "; to_upper(str); cout << str << endl;
	cout << "Нижний регистр: "; to_lower(str); cout << str << endl;
	cout << "to upper: "; to_upper_lol(str); cout << str << endl;
	cout << "tolower: "; tolower(str); cout << str << endl;
	cout << "shrink: "; shrink(str); cout << str << endl; //cout << str << endl;
	cout << "capitalize: "; capitalizsetwo(str); cout << str << endl;
	cout << "Палиндром?: "; cout << (is_palindrome(str) ? "Да" : "Нет") << endl;
	cout << "Целое?: "; cout << (is_int_number(str) ? "Да" : "Нет") << endl;
	cout << "Выводим целое: "; cout << to_int_number(str) << endl; //cout << str << endl;
	cout << "Двоичный?: "; cout << (is_bin_number(str) ? "Да" : "Нет");
}

int strLen(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		str[i] = toupper(str[i]);
		//cout << str[i];
	}
}

void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		str[i] = tolower(str[i]);
		//cout << str[i];
	}
}

void capitalize(char str[])
{
	char *sup;
	sup = strtok(str, " ");
	do
	{
		if (*sup == tolower(*sup))
			*sup = toupper(*sup);

		cout << sup << ' ';
		sup = strtok(NULL, " ");
	} while (sup);
}

void to_upper_lol(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я')
		{
			str[i] -= 32;
		}
	}
}

void tolower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'А' && str[i] <= 'Я')
		{
			str[i] += 32;
		}
	}
}

void capitalizsetwo(char str[])
{
	tolower(str);
	if (str[0] >= 'a'&&str[0] <= 'z' || str[0] >= 'а'&&str[0] <= 'я')str[0] -= 32;
	else if (str[0] == 'ё')str[0] -= 16;

	for (int i = 1; str[i]; i++)
	{
		if ((str[i] >= 'a'&&str[i] <= 'z' || str[i] >= 'а'&&str[i] <= 'я') && str[i - 1] == ' ')str[i] -= 32;
		else if (str[i] == 'ё' && str[i - 1] == ' ')str[i] -= 16;
	}
}

// Шринк через strtok

//void shrink(char str[])
//{
//	char *sup;
//	sup = strtok(str, " ");
//	do
//	{
//		cout << sup << ' ';
//		sup = strtok(NULL, " ");
//	} while (sup);
//}

void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i; str[j]; j++) // Сдвигает часть строки влево
			{
				str[j] = str[j + 1];
			}
		}
	}
}

bool is_palindrome(char str[])
{
	int size = strLen(str);
	char* buffer = new char[size + 1]{};
	//for (int i = 0; str[i]; i++)buffer[i] = str[i];
	strcpy(buffer, str); // String Copy | buffer - получатель, str - строка источник

	tolower(buffer);
	remove_symbol(buffer, ' ');
	size = strlen(buffer);
	// Определяем длину строки
	for (int i = 0; i < size / 2; i++)
	{
		if (buffer[i] != buffer[size - 1 - i])
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}

bool is_int_number(char str[])
{
	/*int size = strLen(str);
	char* buffer = new char[size + 1]{};
	strcpy(buffer, str);*/

	int size = strlen(str);

	for (int i = 0; i < size; i++)
	{
		if (!isdigit(str[i] & 0xff))
		{
			continue;
		}

		else if (isdigit(str[i]))
		{
			return true;
		}
	}
	return false;
}

int  to_int_number(char str[])
{
	//int size = strlen(str);

	//for (int i = 0; i < size; i++)
	//{
	//	/*if (!isdigit(str[i] & 0xff))
	//	{
	//		continue;
	//	}*/

	//	 if ()
	//	{
	//		int number;
	//		number = atoi(str);
	//		return number;
	//	}
	//}

	int size = strlen(str);

	int number;

	for (int i = 0; size; i++)
	{
		if (isdigit(str[i]) & 0xff)
		{
			number = atoi(str);
			return atoi(str);

		}
		else
		{
			cout << "nope";
			break;
		}
	}
	// ДА ЁПТ ЕСЛИ ВСТАВИТЬ В НАЧАЛО СТРОКИ БУКВУ А НЕ ЦИФРУ ТО НИФИГА
}

bool is_bin_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1')return false;
	}
	return true;
}

int bin_to_dec(char str[])
{
	int decimal = 0;
	int weight = 1; // Весовой коэффициент разряда
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ')continue;
		decimal;
	}
	return 0;
}

void ASCII()
{
	for (int i = 0; i < 256; i++)
	{
		cout << i << "\t" << (char)i << endl;
	}
}

void remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)str[j] = str[j + 1];
		}
	}
}

bool is_int_numbertwo(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))return false;
		if (str[i] == ' ' && str[i + 1] == ' ')return false;
		//else return true;
	}
	return true;
}


int to_int_numbertwo(char str[])
{
	if (!is_int_numbertwo(str))return 0; 

	int number = 0;

	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ')continue;
		number *= 10; // Сдвигаем число на разряд влево (освобождаем младший разряд)
		number += str[i] - 48;
	}
	return number;
}

