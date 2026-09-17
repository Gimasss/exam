#include "set.hpp"

set::set(searchable_bag &bag): bag(bag) {
}

set::set(set &other): bag(other) {
}

set::~set() {}

void set::insert (int val){
	if (!has(val))
		bag.insert(val);
}

void set::insert (int *values, int size){
	for (int i = 0; i < size; i++)
		insert(values[i]);
}

void set::print() const {
	bag.print();
};
void set::clear() {
	bag.clear();
}

bool set::has(int pollo) const {
	return bag.has(pollo);
}

searchable_bag &set::get_bag()
{
	return bag;
}