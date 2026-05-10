#include "bigint.hpp"

bigint::bigint()
{
}


bigint::bigint(const bigint& other)
{
    bigint_num = other.bigint_num;
}


void bigint::trim()
{
    int i = bigint_num.size() - 1;
    while (i > 0 && bigint_num[i] == 0)
    {
        bigint_num.pop_back();
        
        i--;
    }
}




bigint::bigint(unsigned int number)
{
    if (number == 0)
        bigint_num.push_back(0);
    while (number)
    {
        bigint_num.push_back(number%10);
        number /= 10;
    }


    // trim();
    // for (std::vector<int>::iterator i = bigint_num.begin(); i != bigint_num.end(); ++i)
    // {
    //     std::cout<<*i<<std::endl;
    // }
 
}

void bigint::print(std::ostream& os) const
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


bigint bigint::operator>>(unsigned int shift_num) const
{
    bigint new_obj(*this);
    if (shift_num >= new_obj.bigint_num.size())
    {
        new_obj.bigint_num.clear();
        new_obj.bigint_num.push_back(0);
    }
    else
        new_obj.bigint_num.erase(new_obj.bigint_num.begin(), new_obj.bigint_num.begin() + shift_num);
    new_obj.trim();
    return new_obj;
}



bigint bigint::operator<<(unsigned int shift_num) const
{
    bigint new_obj(*this);
    new_obj.bigint_num.insert(new_obj.bigint_num.begin(), shift_num, 0);
    
    new_obj.trim();
    return new_obj;
}


bigint& bigint::operator>>=(unsigned int shift_num)
{
    if (shift_num >= bigint_num.size())
    {
        bigint_num.clear();
        bigint_num.push_back(0);
    }
    else
        bigint_num.erase(bigint_num.begin(), bigint_num.begin() + shift_num);
    trim();
    return *this;
}



bigint& bigint::operator<<=(unsigned int shift_num){
    bigint_num.insert(bigint_num.begin(), shift_num, 0);
    
    trim();
    return *this;
}



bigint::~bigint()
{

}



bigint& bigint::operator=(const bigint& other)
{
    if (this != &other)
    {
        bigint_num = other.bigint_num;
    }

    return *this;
}


bigint bigint::operator+(const bigint& other) const
{
    bigint tmp(*this);
    bigint tmp_other(other);
    bigint obj;

    if (tmp.bigint_num.size() >= tmp_other.bigint_num.size())
    {
        while (tmp_other.bigint_num.size() < tmp.bigint_num.size())
        tmp_other.bigint_num.push_back(0);
    }
    else
    {
        while (tmp.bigint_num.size() < tmp_other.bigint_num.size())
            tmp.bigint_num.push_back(0);
    }

    for (size_t i = 0 ; i <  tmp.bigint_num.size(); i++)
        obj.bigint_num.push_back( tmp.bigint_num[i] + tmp_other.bigint_num[i]);
    return obj;
}

// bool bigint::operator<(const bigint& other) const
// {

// }

// bool bigint::operator>(const bigint& other) const
// {

// }

// bool bigint::operator<=(const bigint& other) const
// {

// }

// bool bigint::operator>=(const bigint& other) const
// {

// }

// bool bigint::operator==(const bigint& other) const
// {

// }

// bool bigint::operator!=(const bigint& other) const
// {

// }

// bigint& bigint::operator+=(const bigint& other)
// {

// }

// bigint& bigint::operator++()
// {

// }

// bigint bigint::operator++(int)
// {

// }