#include "bigint.hpp"

void bigint::trim()
{
    int i = bigint_num.size() - 1;
    while (i == 0)
    {
        bigint_num.pop_back();
        i--;
    }
}


bigint::bigint(int number)
{
    std::cout<<"==================="<<number<<std::endl;
    while (number)
    {

        std::cout<<number%10<<std::endl;
        bigint_num.push_back(number%10);

        number /= 10;
    }
    // trim();
    // for (std::vector<int>::iterator i = bigint_num.begin(); i != bigint_num.end(); ++i)
    // {
    //     std::cout<<*i<<std::endl;
    // }
    
}

void bigint::print(std::ostream& os)const
{
    
    for (std::vector<int>::const_reverse_iterator i = bigint_num.rbegin(); i != bigint_num.rend(); i++)
    {
        os<<*i;
    }
}

std::ostream& operator<<(std::ostream& os, const bigint& obj)
{
    obj.print(os);
    return os;
}


bigint::~bigint()
{
}


