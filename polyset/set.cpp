#include "set.hpp"

set::set(searchable_bag &bag): _bag(bag) {
}

set::set(set &other): _bag(other) {
}

set::~set() {}

void set::insert (int val){
	if (!has(val))
		_bag.insert(val);
}

void set::insert (int *values, int size){
	for (int i = 0; i < size; i++)
		insert(values[i]);
}

void set::print() const {
	_bag.print();
}

void set::clear() {
	_bag.clear();
}

bool set::has(int val) const {
	return _bag.has(val);
}

const searchable_bag &set::get_bag() {
	return _bag;
}