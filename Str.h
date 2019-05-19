#pragma once
#include <stddef.h>
#include <string>
class Str
{
public:
	Str():elements(nullptr),first_free(nullptr),cap(nullptr){}
	Str(const char * s);
	~Str();
	Str(const Str&);
	Str &operator=(const Str&);
	void push_back(const char &);
	void reserve(size_t);
	void resize(size_t);
	void resize(size_t, const char &);

	size_t size() const { return first_free - cap; }
	size_t capacity() const { return cap - elements; }

	char *begin() const { return elements; }
	char *end() const { return first_free; }
private:
	void chk_n_alloc()
	{
		if (size() == capacity()) reallocate();
	}

	std::pair<char *, char *> alloc_n_copy
	(const char *, const char *);
	void free();
	void reallocate();
private:
	std::allocator<char> alloc;
	char * elements;
	char * first_free;
	char * cap;
};

