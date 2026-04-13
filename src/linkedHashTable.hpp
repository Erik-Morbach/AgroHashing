#pragma once
#include "hashTable.hpp"
#include "hashable.hpp"
#include <array>
#include <list>
#include <vector>
#include <iostream>


template<typename T, size_t S>
class LinkedHashTable: public HashTable<T> {
private:
	std::array<std::list<std::shared_ptr<T>>, S> values;
	size_t collisionCount = 0;
	size_t transform(const T &value) const;
public:
	virtual void add(T value);
	virtual bool remove(T value);
	virtual std::shared_ptr<T> search(T key) const;
	virtual std::vector<std::shared_ptr<T>> listAll() const;
	virtual size_t getCollisions() const { return collisionCount; }
};
template<typename T, size_t S>
size_t LinkedHashTable<T,S>::transform(const T &value) const{
	const Hashable<T> &h = static_cast<const Hashable<T>&>(value);
	std::cout << value.getId() << " was transformed into " << h.hash() % S << std::endl;
	return h.hash() % S;
}

template<typename T, size_t S>
void LinkedHashTable<T,S>::add(T value) {
	size_t index = transform(value);
	if (!values[index].empty()) collisionCount++;
	values[index].push_front(std::make_shared<T>(value));
}

template<typename T, size_t S>
bool LinkedHashTable<T,S>::remove(T value) {
	size_t index = transform(value);
	auto &list = values[index];
	auto it = list.begin();
	while(it != list.end()) {
		auto w = *it;
		if(w and *w.get()==value) {
			list.erase(it);
			return true;
		}
		it++;
	}
	return false;
}
template<typename T, size_t S>
std::shared_ptr<T> LinkedHashTable<T,S>::search(T value) const {
	size_t index = transform(value);
	for(auto &w: values[index]) {
		if(!w) continue;
		if(*w.get()==value)
		 return w;
	}
	return nullptr;
}
template<typename T, size_t S>
std::vector<std::shared_ptr<T>> LinkedHashTable<T,S>::listAll() const {
	std::vector<std::shared_ptr<T>> ans;
	for(size_t i=0;i<S;i++) {
		for(auto val: values[i]) {
			if(!val) continue;
			ans.push_back(val);
		}
	}
	return ans;
}