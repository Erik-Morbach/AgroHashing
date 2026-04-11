#pragma once
#include "hashTable.hpp"
#include <array>
#include <vector>


template<typename T, size_t S>
class LinkedHashTable: public HashTable<T> {
private:
	std::array<T, S> values;
public:
	virtual void add(T value); 
	virtual void remove(T value); 
	virtual T search(T key); 
	virtual std::vector<T> listAll(); 
};