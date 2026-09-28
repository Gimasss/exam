#include "searchable_tree_bag.hpp"
//#include ""

searchable_tree_bag::searchable_tree_bag(): tree_bag()
{}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &other) : tree_bag(other) {}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &other)
{
	if (this != &other)
		tree_bag::operator=(other);
	return *this;
}

searchable_tree_bag::~searchable_tree_bag(){}

bool searchable_tree_bag::_helper(const struct tree_bag::node *leaf, int pollo) const {
	if (leaf == NULL)
		return false;
	if (leaf->value == pollo)
		return true;
	return (_helper(leaf->l, pollo) || _helper(leaf->r, pollo));
}

bool searchable_tree_bag::has(int pollo) const {
	return (_helper(tree, pollo));
}