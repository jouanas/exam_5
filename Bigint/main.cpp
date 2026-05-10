#include "bigint.hpp"
int main()
{
    bigint N(1337);
    bigint b(1337);
    bigint test(99);
    std::cout<< "test =>"<< (test += 1) << std::endl;
    std::cout << "N = " << N << std::endl;
    std::cout<<"============================================"<<std::endl;
    // std::cout<<"N << 3: "<< (N << 3) <<std::endl;
    // std::cout<<"N <<= 3: "<< (N <<= 3) <<std::endl;
    // std::cout<<"1337 >> 2 : "<<(b >> 2)<<std::endl;
    // std::cout<<"1337 >>= 2 : "<<(b >>= 2)<<std::endl;
    // std::cout<<"the result if + : "<< N + b << std::endl;
    // std::cout<<"the result if += : "<< (N += b) << std::endl;
    std::cout<< "N = "<<N<<std::endl;
    std::cout<< "B = "<<b<<std::endl;

    std::cout<<"the result of < : "<<std::boolalpha<< (b < N) << std::endl;
    std::cout<<"the result of > : "<<std::boolalpha<< (b > N) << std::endl; 
    std::cout<<"the result of <= : "<<std::boolalpha<< (b <= N) << std::endl; 
    std::cout<<"the result of >= : "<<std::boolalpha<< (b >= N) << std::endl; 
    std::cout<<"the result of == : "<<std::boolalpha<< (b == N) << std::endl; 
    std::cout<<"the result of != : "<<std::boolalpha<< (b != N) << std::endl; 
    std::cout<<"the result of b++ : "<<std::boolalpha << (b++) << std::endl; 
    std::cout<<"the result of ++b : "<<std::boolalpha << (++b) << std::endl; 











}
