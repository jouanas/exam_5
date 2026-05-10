#include "bigint.hpp"
int main()
{
    bigint N(42);
    bigint b(1337);
    std::cout << "N = " << N << std::endl;
    std::cout<<"============================================"<<std::endl;
    std::cout<<"N << 3: "<< (N << 3) <<std::endl;
    std::cout<<"N <<= 3: "<< (N <<= 3) <<std::endl;
    std::cout<<"1337 >> 2 : "<<(b >> 2)<<std::endl;
    std::cout<<"1337 >>= 2 : "<<(b >>= 2)<<std::endl;
    std::cout<<"the result if + : "<< N + b << std::endl;


}