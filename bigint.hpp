#pragma once

#include <iostream>
#include <vector>


class bigint
{
    private:
        std::vector<int> bigint_num;
    public:
        bigint(unsigned int);
        bigint(const bigint& other);
        ~bigint();
        void trim();
        void print(std::ostream& os);

        bigint operator<<(int shift_num) const;
        bigint operator>>(int shift_num) const;
        int 
    };
    
std::ostream& operator<<(std::ostream& os, const bigint& obj);
