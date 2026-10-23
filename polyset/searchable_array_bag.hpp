#pragma once

#include <iostream>
#include "array_bag.hpp"
#include "searchable_bag.hpp"

//estendo array bag --- adding features to the father class as a son

class searchable_array_bag : public array_bag, public searchable_bag { //AGGIUNTO VIRTUAL

	public :
		searchable_array_bag();
		searchable_array_bag(const searchable_array_bag &other);
		searchable_array_bag &operator=(const searchable_array_bag &other);
		~searchable_array_bag();

		bool has(int) const;

};