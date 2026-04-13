#pragma once
#include "hashTable.hpp"
#include "hashable.hpp"
#include <array>
#include <vector>
#include <memory>
#include <iostream>

template<typename T, size_t S>
class OpenHashTable : public HashTable<T> {
private:
	enum class State { EMPTY, OCCUPIED, DELETED };
	struct Slot {
		std::shared_ptr<T> value;
		State state = State::EMPTY;
	};
	std::array<Slot, S> slots;
	size_t collisionCount = 0;

	size_t primaryIndex(const T& value) const {
		const Hashable<T>& h = static_cast<const Hashable<T>&>(value);
		size_t index = h.hash() % S;
		std::cout << value.getId() << " was transformed into " << index << std::endl;
		return index;
	}

public:
	virtual void add(T value);
	virtual bool remove(T value);
	virtual std::shared_ptr<T> search(T key) const;
	virtual std::vector<std::shared_ptr<T>> listAll() const;
	virtual size_t getCollisions() const { return collisionCount; }
};

template<typename T, size_t S>
void OpenHashTable<T, S>::add(T value) {
	size_t start = primaryIndex(value);
	for (size_t step = 0; step < S; step++) {
		size_t i = (start + step) % S;
		if (slots[i].state == State::EMPTY || slots[i].state == State::DELETED) {
			if (step > 0) collisionCount++;
			slots[i].value = std::make_shared<T>(value);
			slots[i].state = State::OCCUPIED;
			return;
		}
	}
	std::cout << "Table is full, could not insert " << value.getId() << std::endl;
}

template<typename T, size_t S>
bool OpenHashTable<T, S>::remove(T value) {
	size_t start = primaryIndex(value);
	for (size_t step = 0; step < S; step++) {
		size_t i = (start + step) % S;
		if (slots[i].state == State::EMPTY) return false;
		if (slots[i].state == State::OCCUPIED && *slots[i].value == value) {
			slots[i].state = State::DELETED;
			return true;
		}
	}
	return false;
}

template<typename T, size_t S>
std::shared_ptr<T> OpenHashTable<T, S>::search(T value) const {
	size_t start = primaryIndex(value);
	for (size_t step = 0; step < S; step++) {
		size_t i = (start + step) % S;
		if (slots[i].state == State::EMPTY) return nullptr;
		if (slots[i].state == State::OCCUPIED && *slots[i].value == value)
			return slots[i].value;
	}
	return nullptr;
}

template<typename T, size_t S>
std::vector<std::shared_ptr<T>> OpenHashTable<T, S>::listAll() const {
	std::vector<std::shared_ptr<T>> result;
	for (size_t i = 0; i < S; i++) {
		if (slots[i].state == State::OCCUPIED)
			result.push_back(slots[i].value);
	}
	return result;
}
