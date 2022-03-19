/*
Viết chương trình in ra tất cả các dãy con của một dãy cho trước
*/

#include<iostream>
using namespace std;

void nhapDaySo (int *arr, int n){
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
}

void inDayCon (int *arr, int n){
    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            for (int k=i; k<=j; k++){
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int *arr = new int [n];
    nhapDaySo(arr,n);
    inDayCon(arr,n);
    delete []arr;
    return 0;
}
