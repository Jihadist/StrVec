#include "pch.h"
#include "Str.h"


Str::Str(const char * s)
{
	char *sl = const_cast<char*>(s);
	while (*sl)
		++sl;
	auto newstr = alloc_n_copy(s, ++sl);
	elements = newstr.first;
	first_free = newstr.second;
}

Str::~Str()
{
	free();
}

Str::Str(const Str &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

Str & Str::operator=(const Str &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
	// TODO: вставьте здесь оператор return
}

void Str::push_back(const char &s)
{
	chk_n_alloc();

	alloc.construct(first_free++, s);
}

void Str::reserve(size_t new_cap)
{
	while (new_cap <= size())
	{
		reallocate();
	}
}

void Str::resize(size_t n)
{
	for (size_t i = 0; i != n; ++n)
	{
		chk_n_alloc();
		push_back(NULL);
	}
}

void Str::resize(size_t n, const char &s)
{
	for (size_t i = 0; i != n; ++n)
	{
		chk_n_alloc();
		push_back(s);
	}
}

std::pair<char*, char*> Str::alloc_n_copy(const char *b, const char *e)
{
	auto data = alloc.allocate(e - b);
	return { data,std::uninitialized_copy(b,e,data) };
}

void Str::free()
{
	if (elements)
	{
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

void Str::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + capacity();
}
