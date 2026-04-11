#pragma once
#include <vector>

template<typename T>
struct HashTable {
	virtual void add(T value);
	virtual void remove(T value);
	virtual T search(T key);
	virtual std::vector<T> listAll();
};