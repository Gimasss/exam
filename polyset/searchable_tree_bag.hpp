#pragma once

#include <iostream>
#include "tree_bag.hpp"
#include "searchable_bag.hpp"

//estendo teeeeee bag --- adding features to the father class as a son

class searchable_tree_bag : public tree_bag, public searchable_bag {

	private:
		bool _helper(const struct tree_bag::node *leaf, int pollo) const;
	public :
		searchable_tree_bag();
		searchable_tree_bag(const searchable_tree_bag &other);
		searchable_tree_bag &operator=(const searchable_tree_bag &other);
		~searchable_tree_bag();

		bool has(int) const;


};