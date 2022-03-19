/*Bài tập 1: Tính dãy Lucas
Dãy Lucas được định nghĩa bởi  Ln=Ln−1+Ln−2  và bắt đầu bởi  L0=2 ,  L1=1 .
Viết hàm tính số Lucas thứ  n .*/

#include<iostream>
using namespace std;

int lucas(int n) {
    /*****************# YOUR CODE HERE #*****************/
    if(n == 0) return 2;
    else if(n == 1) return 1;
    else return lucas(n-1)+lucas(n-2);
}
int main(){
    int n;
    cin>>n;
    cout<<"Ln="<<lucas(n);
    return 0;
}
