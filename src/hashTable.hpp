#pragma once
#include <vector>
#include <memory>

template<typename T>
struct HashTable {
	virtual void add(T value) = 0;
	virtual bool remove(T value) = 0;
	virtual std::shared_ptr<T> search(T key) const = 0;
	virtual std::vector<std::shared_ptr<T>> listAll() const = 0;
	virtual size_t getCollisions() const { return 0; }
};
