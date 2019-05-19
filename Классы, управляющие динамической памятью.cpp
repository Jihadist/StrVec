﻿// Классы, управляющие динамической памятью.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "StrVec.h"
#include  "Str.h"
#include  "String.h"

void vec_test()
{
	std::string s1 = "abc";
	std::string s2 = "def";
	StrVec vec2{ s1,s2 };
	for (auto i : vec2)
		std::cout << i;
	std::cout << std::endl << vec2.size() << " " << vec2.capacity();

	std::cout << std::endl;
}
int f()
{
	std::vector<Str> vec;
	vec.push_back("a");
	vec.push_back("a");
	vec.push_back("a");
	vec.push_back("a");
	vec.push_back("a");
	vec.push_back("a");
	std::cout << "hello world";
	vec.push_back("a");
	vec.push_back("a");
	vec.push_back("a");
	for (auto &i : vec)
		std::cout << i.begin();
	return 1;
}

int main()
{
	String s("asdffdsasd");
	auto ss = s;
	auto sss(s);
	s.operator=(s);
	s = s;
	s = ss;
	std::cout << ss.first() << ss.end();
	
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
