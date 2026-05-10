

#pragma once

#include <iostream>
#include <vector>
#include <cstdio>



class bigint
{
    private:
        std::vector<int> bigint_num;
    public:
        bigint();
        bigint(unsigned int);
        bigint(const bigint& other);
        bigint& operator=(const bigint& other);
        ~bigint();
        void trim();
        void print(std::ostream& os) const;

        bigint operator<<(unsigned int shift_num) const;
        bigint operator>>(unsigned int shift_num) const;
        bigint& operator>>=(unsigned int shift_num);
        bigint& operator<<=(unsigned int shift_num);
        bigint operator+(const bigint& other) const;
        bigint& operator+=(const bigint& other);
        bigint& operator++();
        bigint operator++(int);
        bool operator<(const bigint& other) const;
        bool operator<=(const bigint& other) const;
        bool operator>(const bigint& other) const;
        bool operator>=(const bigint& other) const;
        bool operator==(const bigint& other) const;
        bool operator!=(const bigint& other) const;


};
    
std::ostream& operator<<(std::ostream& os, const bigint& obj);
