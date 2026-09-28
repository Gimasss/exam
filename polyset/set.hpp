#pragma once

#include "searchable_bag.hpp"
#include "searchable_array_bag.hpp"


class set : public searchable_bag {
	private:
		searchable_bag &_bag;

	public:
		set(searchable_bag &bag);
		set(set &other);
		set &operator=(const set &other) = delete;
		~set();

		void insert (int);
		void insert (int *, int);
		void print() const;
		void clear();

		bool has(int) const;

		const searchable_bag &get_bag();
};