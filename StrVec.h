#pragma once
#include <string>
#include <stddef.h>
class StrVec
{
public:
	StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}
	StrVec(std::initializer_list<std::string> s) :
	elements(nullptr), first_free(nullptr), cap(nullptr) { for (auto &i : s) push_back(i); }
	StrVec(const StrVec&);
	StrVec &operator=(const StrVec&);
	~StrVec();
	
	void push_back(const std::string &);
	void reserve(size_t);
	void resize(size_t);
	void resize(size_t, const std::string &);
	
	size_t size() const { return first_free - cap; }
	size_t capacity() const { return cap - elements; }



	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }
private:
	void chk_n_alloc()
	{
		if (size() == capacity()) reallocate();
	}

	std::pair<std::string *, std::string *> alloc_n_copy
	(const std::string *, const std::string *);
	void free();
	void reallocate();
	void alloc_n_move(size_t new_cap);
private:
	std::allocator<std::string> alloc;
	std::string * elements;
	std::string * first_free;
	std::string * cap;

};

