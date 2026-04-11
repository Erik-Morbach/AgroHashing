#include "linkedHashTable.hpp"
#include "hashable.hpp"

template<typename T, size_t S>
size_t LinkedHashTable<T,S>::transform(const T &value) const{
	Hashable<T> h = static_cast<Hashable<T>>(value);
	return h.hash() % S;
}

template<typename T, size_t S>
void LinkedHashTable<T,S>::add(T value) {
	size_t index = transform(value);
	values[index].push_front(value);
}

template<typename T, size_t S>
void LinkedHashTable<T,S>::remove(T value) {
	size_t index = transform(value);
	auto &list = values[index];
	auto it = list.find(value);
	if(it != list.end()) {
		list.erase(it);
	}
}
template<typename T, size_t S>
T LinkedHashTable<T,S>::search(T value) const {
	size_t index = transform(value);
	auto &list = values[index];
	auto it = list.find(value);
	if(it == list.end()){
		return value
	}
	return *it;
}
template<typename T, size_t S>
std::vector<T> LinkedHashTable<T,S>::listAll() const {
	std::vector<T> ans;
	for(size_t i=0;i<S;i++) {
		for(auto val: values[i]) {
			if(!val) continue;
			ans.push_back(val.get());
		}
	}
	return ans;
}