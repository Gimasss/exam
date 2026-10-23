#pragma once

#include "searchable_bag.hpp"
#include "searchable_array_bag.hpp"


class set : public searchable_bag {
	private:
		searchable_bag &_bag;
		set();
		set &operator=(const set &other);

	public:
		set(searchable_bag &bag);
		set(const set &other);
		~set();

		void insert (int);
		void insert (int *, int);
		void print() const;
		void clear();

		bool has(int) const;

		const searchable_bag &get_bag() const;
};