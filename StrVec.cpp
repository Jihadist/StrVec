#include "pch.h"
#include "StrVec.h"


StrVec::StrVec(std::initializer_list<std::string> s):
	elements(nullptr), first_free(nullptr), cap(nullptr)
{
	for (auto& i : s)
	{
		chk_n_alloc();
		alloc.construct(first_free++, i);
	}
}

StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
	std::cout << "\nCopied\n";
}

StrVec & StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	std::cout << "\nOperator= used\n";
	return *this;
}

StrVec::~StrVec()
{
	free();
}


void StrVec::reserve(size_t new_cap)
{
	while (new_cap<=size())
	{
		reallocate();
	}
}

void StrVec::resize(size_t n)
{
	for (size_t i=0;i!=n;++n)
	{
		chk_n_alloc();
		alloc.construct(first_free++, nullptr);
	}
}

void StrVec::resize(size_t n, const std::string &s)
{
	for (size_t i = 0; i != n; ++n)
	{
		chk_n_alloc();
		alloc.construct(first_free++,s);
	}
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
	auto data = alloc.allocate(e - b);
	return { data,std::uninitialized_copy(b,e,data) };
}

void StrVec::free()
{
    if(elements)
    {
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

//void StrVec::free()
//{
//	if (elements)
//	{
//		std::for_each(elements, cap, [this](std::string &s) {alloc.destroy(&s); });
//    alloc.deallocate(elements, cap - elements);
//	}
//}

void StrVec::reallocate()
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

void StrVec::alloc_n_move(size_t new_cap)
{
	auto newdata = alloc.allocate(new_cap);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + new_cap;
}
