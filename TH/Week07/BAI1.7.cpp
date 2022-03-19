/*
Viết chương trình nhập vào một mảng các số nguyên với số lượng các phần tử nhập từ bàn phím.
Sau đó sắp xếp mảng theo thứ tự tăng dần. Hiển thị danh sách mảng trước và sau khi sắp xếp.
Yêu cầu chỉ sử dụng con trỏ để truy cập mảng, không truy cập theo index mảng.
*/

#include <stdio.h>

int *a;
int n, tmp;

int main(){
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    //#Allocate memory
    /*****************# YOUR CODE HERE #*****************/

    a = new int [n];

    /*****************# YOUR CODE HERE #*****************/
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);

    printf("The input array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    //#Sort array
    /*****************# YOUR CODE HERE #*****************/
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if(*(a+i) > *(a+j)){
                tmp = *(a+i);
                *(a+i) = *(a+j);
                *(a+j) = tmp;
            }
        }
    }
    /*****************# YOUR CODE HERE #*****************/

    printf("The sorted array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");

    delete [] a;
    return 0;
}
