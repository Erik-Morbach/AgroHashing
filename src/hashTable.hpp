#pragma once
#include <vector>

template<typename T>
struct HashTable {
	virtual void add(T value);
	virtual void remove(T value);
	virtual T search(T key) const;
	virtual std::vector<T> listAll() const;
};