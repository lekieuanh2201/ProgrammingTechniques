#include<iostream>
using namespace std;

//BT chia phan thuong
int part(int m, int n){
    if (m==0) return 1;
    else if (n==0) return 0;
    else if (m<n) return part(m,m);
    else return part(m, n-1)+part(m-n, n);
}
//BT nuoi tho
int numOfRabbits(int n){
    if (n<=12){
        if (n==1 || n==2) return 1;
        else return numOfRabbits(n-1)+numOfRabbits(n-2);
    }
    else if (n==13) return numOfRabbits(12)+numOfRabbits(11)-1;
    else if (n==14) return numOfRabbits(13)+numOfRabbits(12);
    else return numOfRabbits(n-1)+numOfRabbits(n-2)-numOfRabbits(n-12);
}
int sumInn(int n){
    if (n<=12) return 0;
    else{
        if (n==13) return 10;
        else if (n==14) return 0;
        else return sumInn(n-1)+sumInn(n-2);
    }
}
int sum(int n){
    int sum=0;
    if (n<=12) return 0;
    else {
        for(int i=13; i<=n; i++){
            sum += sumInn(i);
        }
        return sum;
    }
}
int main(){
    int n;
    cout<<"nhap n:";
    cin>>n;
    int fn=numOfRabbits(n);
    cout<<fn<<endl;
    int money = sum(n);
    cout<<"$"<<money;
    return 0;
}
