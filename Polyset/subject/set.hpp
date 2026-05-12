#pragma once 

#include "searchable_bag.hpp"

class set
{
private:
    searchable_bag* Bag;
public:
    set(/* args */);
    set(searchable_bag& bag);
    set(const set& other);
    set& operator=(const set& other);
    ~set();
    void insert(int);
    void insert(int *array, int size);
    bool  has(int value) const;
    void print()const;
    void clear();
    searchable_bag& get_bag() const;
};