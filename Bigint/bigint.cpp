#include "bigint.hpp"

bigint::bigint()
{
    bigint_num.push_back(0);
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


void bigint::pushToNumber(bigint& obj, unsigned int number)
{
    if (number == 0)
        obj.bigint_num.push_back(0);
    while (number)
    {
        obj.bigint_num.push_back(number%10);
        number /= 10;
    }
}

bigint::bigint(unsigned int number)
{
    pushToNumber(*this, number);
}

void bigint::print(std::ostream& os) const
{
    
    for (std::vector<int>::const_reverse_iterator i = bigint_num.rbegin(); i != bigint_num.rend(); i++)
    {
        // std::cout<<"index = [" << *i << "]" << std::endl;
        // std::cout<< std::endl;
        os<<*i;
    }
}

std::ostream& operator<<(std::ostream& os, const bigint& obj)
{
   obj.print(os);
    return os;
}

unsigned int bigint::ConvertToUnsignedInt(const bigint& obj) const
{
    int mult = 1;
     unsigned int result = 0;
    for (size_t i = 0; i < obj.bigint_num.size(); i++)
    {
        result +=  obj.bigint_num[i]*mult;
        mult *= 10;
    }
    return result; 
}

bigint bigint::operator>>(const bigint& obj) const
{
    bigint new_obj(*this);
    unsigned int shift_num = ConvertToUnsignedInt(obj);
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



bigint bigint::operator<<(const bigint& obj) const
{
    unsigned int shift_num = ConvertToUnsignedInt(obj);
    bigint new_obj(*this);
    new_obj.bigint_num.insert(new_obj.bigint_num.begin(), shift_num, 0);
    
    new_obj.trim();
    return new_obj;
}



bigint& bigint::operator>>=(const bigint& obj)
{
    unsigned int shift_num = ConvertToUnsignedInt(obj);
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



bigint& bigint::operator<<=(const bigint& obj)
{
    unsigned int shift_num = ConvertToUnsignedInt(obj);
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
    bigint result(*this);

    result += other;
    return result;
}


bigint& bigint::operator+=(const bigint& other)
{
    bigint tmp(*this);
    bigint tmp_other(other);
    int sum = 0;
    int carry = 0;

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
    this->bigint_num.clear();
    for (size_t i = 0 ; i <  tmp.bigint_num.size(); i++)
    {
        sum = (tmp.bigint_num[i] + tmp_other.bigint_num[i]) + carry;
        this->bigint_num.push_back(sum % 10);
        carry = sum/10;
    }
      if (carry)
        this->bigint_num.push_back(carry);
    return *this;
}

bool bigint::operator<(const bigint& other) const
{
    if (bigint_num.size() < other.bigint_num.size())
        return true;
    if (bigint_num.size() > other.bigint_num.size())
        return false;
    for (int i = bigint_num.size() - 1; i >= 0 ; i--)
    {
        if (bigint_num[i] < other.bigint_num[i]) return true;
        if (bigint_num[i] > other.bigint_num[i]) return false;
    }
    
    return false;
}

bool bigint::operator>(const bigint& other) const
{
    if (bigint_num.size() > other.bigint_num.size())
        return true;
    if (bigint_num.size() < other.bigint_num.size())
        return false;
    for (int i = bigint_num.size() - 1; i >= 0 ; i--)
    {
        if (bigint_num[i] < other.bigint_num[i]) return false;
        if (bigint_num[i] > other.bigint_num[i]) return true;
    }
    
    return false;
}

bool bigint::operator<=(const bigint& other) const
{
    if (*this < other) return true;
    if (*this > other) return false;

    return true;
}

bool bigint::operator>=(const bigint& other) const
{
    if (*this > other) return true;
    if (*this < other) return false;

    return true;
}

bool bigint::operator==(const bigint& other) const
{
    if (bigint_num.size() != other.bigint_num.size()) return false;
    for (size_t i = 0; i < bigint_num.size(); i++)
        if (bigint_num[i] != other.bigint_num[i]) return false;
    return true;
}

bool bigint::operator!=(const bigint& other) const
{
    if (bigint_num.size() != other.bigint_num.size()) return true;
    for (size_t i = 0; i < bigint_num.size(); i++)
        if (bigint_num[i] != other.bigint_num[i]) return true;
    return false;
}


bigint& bigint::operator++()
{
    
    return *this +=1;
}

bigint bigint::operator++(int)
{
    bigint result(*this);
    *this +=1;
    return result;
}