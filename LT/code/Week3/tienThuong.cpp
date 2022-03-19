#include <iostream>

int main(){
    long long n;
    std::cout<<"Nhap doanh so:"<<std::endl;
    std::cin>>n;
    std::cout <<"Tien thuong: "<<(long long)((n<=500000000)?0:(
                                            (n<=1000000000)?(n*0.03):(
                                            (n<=2000000000)?(n*0.07):(n*0.1))));
}
