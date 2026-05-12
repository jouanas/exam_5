#pragma once


#include <iostream>
#include "array_bag.hpp"
#include "searchable_bag.hpp"


class searchable_array_bag : public array_bag , public searchable_bag 
{
private:
    
public:
    searchable_array_bag(/* args */);
    ~searchable_array_bag();
    searchable_array_bag(const searchable_array_bag& other);
    searchable_array_bag& operator=(const searchable_array_bag& other);
	virtual bool has(int) const ;
    searchable_bag* clone();


};

