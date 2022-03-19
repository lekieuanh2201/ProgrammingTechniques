/*
Viết hàm đảo ngược một mảng các số nguyên theo hai cách: dùng chỉ số và dùng con trỏ.
Ví dụ mảng đầu vào là [9, -1, 4, 5, 7] thì kết quả là [7, 5, 4, -1, 9].
*/

#include<iostream>
using namespace std;

void reversearray(int arr[], int size){
    int l = 0, r = size - 1, tmp;
    /*****************# YOUR CODE HERE #*****************/
    for (int i=l; i<=r/2; i++){
        tmp = arr[i];
        arr[i] = arr[r-i];
        arr[r-i] = tmp;
    }
    /*****************# YOUR CODE HERE #*****************/
}
void ptr_reversearray(int *arr, int size){
    int l = 0, r = size - 1, tmp;
    /*****************# YOUR CODE HERE #*****************/
    for (int i=l; i<=r/2; i++){
        tmp = arr[i];
        arr[i] = arr[r-i];
        arr[r-i] = tmp;
    }
    /*****************# YOUR CODE HERE #*****************/
}

int main(){
    int arr[] = {9, 3, 5, 6, 2, 5};
    reversearray(arr, 6);
    for(int i = 0; i < 6; i++) cout << arr[i] << " ";
    int arr2[] = {4, -1, 5, 9};
    ptr_reversearray(arr2, 4);
    for(int i = 0; i < 4; i++) cout << arr2[i] << " ";

    return 0;
}
