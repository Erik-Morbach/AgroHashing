#pragma once

template<typename T>
struct Hashable {
	virtual unsigned long long int hash() const = 0;
};