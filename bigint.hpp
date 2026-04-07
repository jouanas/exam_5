#pragma once

#include <iostream>
#include <vector>


class bigint
{
    private:
        std::vector<int> bigint_num;
    public:
        bigint(int);
        ~bigint();
        void trim();
        void print(std::ostream& os)const;
    };
    
std::ostream& operator<<(std::ostream& os, const bigint& obj);
