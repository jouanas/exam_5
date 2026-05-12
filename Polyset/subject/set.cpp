#include "set.hpp"

set::set(/* args */)
{
     Bag = nullptr;
}

set::~set()
{
}


set::set(searchable_bag& Bag)
{
    this->Bag = &Bag;
}


set::set(const set& other)
{
    Bag = other.Bag;
}


set& set::operator=(const set& other)
{
    if (this != &other)
        Bag = other.Bag;
    return *this;
}


void set::insert(int value)
{
    if (!Bag->has(value))
        Bag->insert(value);
}

void set::insert(int *array, int size)
{
    for (int i = 0; i < size; i++)
        insert(array[i]);
}

bool set::has(int value) const
{
     return Bag->has(value);
}

void set::print() const
{
    Bag->print();
}


void set::clear()
{
    Bag->clear();
}


searchable_bag& set::get_bag() const
{
    return *Bag;
}