#include "pch.h"
#include "String.h"

std::pair<char*, char*>
String::alloc_n_copy(const char *b, const char *e)
{
	auto str = alloc.allocate(e - b);
	return{ str, std::uninitialized_copy(b, e, str) };
}

void String::range_initializer(const char *first, const char *last)
{
	auto newstr = alloc_n_copy(first, last);
	elements = newstr.first;
	last = newstr.second;
}

String::String(const char *s)
{
	char *sl = const_cast<char*>(s);
	while (*sl)
		++sl;
	range_initializer(s, ++sl);
}

String::String(const String& rhs)
{
	range_initializer(rhs.elements, rhs.last);
	std::cout << "copy constructor" << std::endl;
}

void String::free()
{
	if (elements) {
		std::for_each(elements, last, [this](char &c) { alloc.destroy(&c); });
		alloc.deallocate(elements, last - elements);
	}
}

String::~String()
{
	free();
}

String& String::operator = (const String &rhs)
{
	auto newstr = alloc_n_copy(rhs.elements, rhs.last);
	free();
	elements = newstr.first;
	last = newstr.second;
	std::cout << "copy-assignment" << std::endl;
	return *this;
}