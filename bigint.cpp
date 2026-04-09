#include "bigint.hpp"

bigint::bigint(const bigint& other)
{
    for (std::vector<int>::const_iterator i = other.bigint_num.begin(); i != other.bigint_num.end(); ++i)
    {
        bigint_num.push_back(*i);
    } 
}
void bigint::trim()
{
    int i = bigint_num.size();
    while (i > 1 && bigint_num[i] == 0)
    {
        bigint_num.pop_back();
        i--;
    }
}


bigint::bigint(unsigned int number)
{
    // i have to remove the 000 first
    while (number)
    {

        // std::cout<<number%10<<std::endl;
        bigint_num.push_back(number%10);

        number /= 10;
    }
    // trim();
    // for (std::vector<int>::iterator i = bigint_num.begin(); i != bigint_num.end(); ++i)
    // {
    //     std::cout<<*i<<std::endl;
    // }
    
}

void bigint::print(std::ostream& os)
{
    
    for (std::vector<int>::const_reverse_iterator i = bigint_num.rbegin(); i != bigint_num.rend(); i++)
    {
        trim();
        os<<*i;
    }
}

std::ostream& operator<<(std::ostream& os, const bigint& obj)
{
   bigint& non_cast = const_cast<bigint&>(obj);
   non_cast.print(os);
    return os;
}


bigint bigint::operator>>(int shift_num) const
{

}


bigint bigint::operator<<(int shift_num) const
{
    bigint new_obj(*this);
    for (size_t i = 0; i < new_obj.bigint_num.size(); i++)
    {
        
    }
    

}

bigint::~bigint()
{
}




