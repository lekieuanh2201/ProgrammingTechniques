#include<iostream>
using namespace std;
double tinhS(int n){
    if(n==1) return 1.0/2;
    else return 1.0/(n*(n+1))+ tinhS(n-1);
}
int h(int n){
    if(n<3) return n;
    else return 2*h(n-1)*h(n-2);
}
int h2(int n){
    int sum=0;
    if(n)
    for (int i=3; i<n; i++){

    }
}
int main(){
    int n=5;
    cout << tinhS(n)<<endl;
    int x=5;
    cout << h(x);
    return 0;
}


