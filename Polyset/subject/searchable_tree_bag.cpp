#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag(/* args */)
{
}

searchable_tree_bag::~searchable_tree_bag()
{
}


bool searchable_tree_bag::has(int value) const
{
    node *current = tree;
    while (current != nullptr)
    {
        if (value == current->value)
                return true;
        else if (value > current->value)
            current = current->r;
        else if (value < current->value)
            current = current->l;
    }
    
    return false;
}

searchable_tree_bag:: searchable_tree_bag (const searchable_tree_bag& other):bag(other),tree_bag(other) ,searchable_bag(other)
{

}


searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& other)
{
    if (this != &other)
        tree_bag::operator=(other);
    
    return *this;
}