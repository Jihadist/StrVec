#pragma once
#include <stddef.h>
#include <string>

class String
{
public:
	String() : String("") { }
	String(const char *);
	String(const String&);
	String& operator=(const String&);
	~String();

	const char *c_str() const { return elements; }
	size_t size() const { return last - elements; }
	size_t length() const { return last - elements - 1; }

	char * end() const { return last; }
	char * first() const { return elements; }

private:
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
	void range_initializer(const char*, const char*);
	void free();

private:
	char *elements;
	char *last;
	std::allocator<char> alloc;
};
