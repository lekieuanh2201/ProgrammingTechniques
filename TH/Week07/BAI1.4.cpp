/*
Viết hàm countEven(int*, int) nhận một mảng số nguyên và kích thước của mảng,
trả về số lượng số chẵn trong mảng.
*/
#include<iostream>
using namespace std;

int counteven(int* arr, int size){
    int count = 0;
    /*****************# YOUR CODE HERE #*****************/

    for (int i=0; i<size; i++){
        if (*(arr+i) %2==0) count+=1;
    }
    /*****************# YOUR CODE HERE #*****************/

    return count;
}
 int main(){
    int arr[] = {1, 5, 4, 8, 10, 6, 7, 2};
    cout << counteven(arr, 8);
    return 0;
 }
