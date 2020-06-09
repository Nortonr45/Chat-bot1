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
#include <algorithm>

using namespace std;
class Chat_class
{
public:
	ifstream F;

public:
	int result(string s, string ss)// Функция сравнивает строки
	{
		string str1 = s;
		string str2 = ss;
		
		transform(str1.begin(), str1.end(), str1.begin(), tolower);
		transform(str2.begin(), str2.end(), str2.begin(), tolower);
		
		int pos = str2.find(str1);  //Ищем "friend" в str
		//cout << "v stroke " << str2 << " net stroki " << str1 << endl;

		return pos;
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
				if (result(a, stolica) > (-1)) { a2 = a1; 
				
				}
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

				if (result(a, stolica) > (-1)) {
					a2 = a1;  
				}
			}
		}
		in.close();     // закрываем файл
		//if (a2 == 300) { cout << "В нашем списке нет такой страны или столицы"; }
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

	string name_flag(int a2) //функция возвращает описание флага
	{
		int a1;
		a1 = 0;
		string a, b;


		ifstream in("\\flag.txt"); // окрываем файл для чтения
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
	bool list_coutry(string strana)
	{
		int words[12], count = 0, number[12], rezultat=0;
		for (int k = 194; k < 207; k++)
		{
			words[k] = result(name_starana(k), strana);
			if (words[k] > -1) { number[count] = k; count = count + 1; }
			//cout << "words[" << k << "] = " << words[k] << endl;

		}
		int t = 0, f, c=8;
		for (int k = 1; k < 194; k++)
		{
			t = 0, f=0;
			for ( f = 0; f <= count; f++)
			{
				if ((result(name_starana(number[f]), name_flag(k))) >-1)
				{
					t++;
				}
				
			}
			if (t == f) 
			{
				rezultat++;
				if (c == 8)
			     { 
				cout << "Вот список стран, у которых флаг с данными параметрами: "; 
				c++;
			     }
			    else { cout << ", "; } 
			    cout << name_starana(k); 
			  }
			
		}
		if (rezultat == 0) { cout << "К сожалению поиск не дал результатов."; }
		cout << endl << endl;
		return true;
	}

};


// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
