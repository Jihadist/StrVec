// Классы, управляющие динамической памятью.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include "pch.h"
#include "StrVec.h"
#include  "Str.h"
#include  "String.h"
#include <iostream>
#include <vector>

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
    vec_test();

}
