#pragma once
#include "hashTable.hpp"
#include <array>
#include <list>
#include <vector>


template<typename T, size_t S>
class LinkedHashTable: public HashTable<T> {
private:
	std::array<std::list<std::shared_ptr<T>>, S> values;
	size_t transform(const T &value) const;
public:
	virtual void add(T value); 
	virtual void remove(T value); 
	virtual T search(T key) const; 
	virtual std::vector<T> listAll() const; 
};