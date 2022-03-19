/*
Viết chương trình nhập vào 2 ma trận vuông cùng kích thước n*n, trong đó n nhập từ bàn phím.
Sau đó tính tổng và tích của hai ma trận đó và đưa kết quả ra màn hình.
Yêu cầu sử dụng cấp phát động để cấp phát bộ nhớ cho các ma trận.
*/

#include<iostream>
using namespace std;

void allocMT (int ***mt, int n){
    *mt = new int*[n];
    for (int i=0; i<n; i++){
        (*mt)[i] = new int [n];
    }
}
void freeMT (int **mt, int n){
    for (int i=0; i<n; i++){
        delete []mt[i];
    }
    delete []mt;
}
void input(int **mt, int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>mt[i][j];
        }
    }
}
void output (int **mt, int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<<mt[i][j]<<" ";
        }
        cout<<endl;
    }
}
void add(int **mt1, int **mt2, int **mt3, int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            mt3[i][j]=mt1[i][j]+mt2[i][j];
        }
    }
}
void multiply(int **mt1, int**mt2, int**mt3, int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            mt3[i][j] = 0;
            for (int k=0; k<n; k++){
                mt3[i][j] += mt1[i][k]*mt2[k][j];
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    int **mt1, **mt2, **mt3;
    allocMT(&mt1,n);
    allocMT(&mt2,n);
    allocMT(&mt3,n);
    input(mt1,n);
    input(mt2,n);
    add(mt1,mt2,mt3,n);
    output(mt3,n);
    multiply(mt1,mt2,mt3,n);
    output(mt3,n);
    freeMT(mt1,n);
    freeMT(mt2,n);
    freeMT(mt3,n);
    return 0;
}
