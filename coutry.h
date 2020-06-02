// coutry.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <cstring>
#include <windows.h>
#include <iostream>

using namespace std;
class Chat_class
{
public:
	ifstream F;

public:
	boolean result(string s, string ss)// Функция сравнивает строки
	{
		return(s == ss);
	}
	//_____________________________________________________________________________________________________________

	int f_country(string stolica) //функция возвращает номер строки столицы
	{
		int a1, a2;
		a1 = 0; a2 = 300;
		string a;
		
		ifstream in("\\stolica.txt"); // окрываем файл для чтения
		if (in.is_open())
		  {
			while (getline(in, a))
			{
				a1 = a1 + 1;
				if (result(a, stolica)) { a2 = a1; }
			}
		  }
		in.close();     // закрываем файл
		if (a2 == 300) { a2 = f_starana(stolica); }
		return a2;
	}
	//___________________________________________________________________________________________________________


	int f_starana(string stolica) //функция возвращает номер строки страны
	{
		int a1, a2;
		a1 = 0;
		a2 = 300;
		string a;


		ifstream in("\\strana.txt"); // окрываем файл для чтения
		if (in.is_open())
		{
			while (getline(in, a))
			{
				a1 = a1 + 1;

				if (result(a, stolica)) { a2 = a1; }
			}
		}
		in.close();     // закрываем файл
		if (a2 == 300) { cout << "В нашем списке нет такой страны или столицы"; }
		return a2;
	}

	//___________________________________________________________________________________________________________
	string name_starana(int a2) //функция возвращает название страны по номеру строки
	{
		int a1;
		a1 = 0;
		string a, b;


		ifstream in("\\strana.txt"); // окрываем файл для чтения
		if (in.is_open())
		{
			while (getline(in, a))
			{
				a1 = a1 + 1;

				if (a1 == a2) { b = a; }
			}
		}
		in.close();     // закрываем файл
		return b;
	}
	//___________________________________________________________________________________________________________
	string name_stolica(int a2) //функция возвращает название столицы по номеру строки
	{
		int a1;
		a1 = 0;
		string a, b;


		ifstream in("\\stolica.txt"); // окрываем файл для чтения
		if (in.is_open())
		{
			while (getline(in, a))
			{
				a1 = a1 + 1;

				if (a1 == a2) { b = a; }
			}
		}
		in.close();     // закрываем файл
		return b;
	}


};


// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
