#include<iostream>
using namespace std;

typedef struct matrix{
    int r, c;
    float **M;
    matrix(int row, int col){
        r=row; c=col;
        M = new float *[r];
        for (int i = 0; i < r; i++){
            M[i] = new float [c];
        }
    }
}matrix;


matrix operator + (matrix a, matrix b){
    matrix c(a.r,a.c);
    for (int i = 0; i < c.r; i++){
        for (int j = 0; j < c.c;j++){
            c.M[i][j] = a.M[i][j] + b.M[i][j];
        }
    }
    return c;
}
matrix operator * (matrix a, matrix b){
    matrix c(a.r,b.c);
    for(int i = 0;i<a.r;i++){
        for(int j = 0;j<b.c;j++){
            c.M[i][j] = 0;
        }
    }
    if(a.c!=b.r){
        return c;
    }
    for(int i = 0;i<a.r;i++){
        for(int j = 0;j<a.c;j++){
            for(int k = 0;k<b.c;k++){
                c.M[i][k] += a.M[i][j]*b.M[j][k];
            }
        }
    }
    return c;
}
void input(matrix a){
    cout<<"Nhap ma tran:"<<endl;
    for (int i = 0; i < a.r; i++){
        for (int j = 0; j < a.c; j++){
            cin>>a.M[i][j];
        }
    }
}
void output(matrix a){
    cout<<"In ma tran:"<<endl;
    for (int i = 0; i < a.r; i++){
        for (int j = 0; j < a.c; j++){
            cout<<a.M[i][j]<<" ";
        }
        cout<<endl;
    }
}
void freeMatrix(matrix &a){
    for (int i = 0; i < a.r; i++){
        delete[] a.M[i];
    }
    delete[] a.M;
}
int main(){
    int r, c;
    cout<<"Nhap so hang va cot cua 2 ma tran:";
    cin>>r>>c;
    matrix A{r,c}; matrix B{r,c}; matrix C(r,c);
    input(A); input(B);
    C = A+B;
    output(C);
    freeMatrix(A); freeMatrix(B); freeMatrix(C);

    int r1, c1, r2, c2;
    cout<<"Nhap so hang va cot cua ma tran 1:";
    cin>>r1>>c1;
    matrix A1{r1,c1};
    input(A1);
    cout<<"Nhap so hang va cot cua ma tran 2:";
    cin>>r2>>c2;
    matrix B1{r2,c2};
    input(B1);
    matrix C1(r1,c2);
    C1 = A1*B1;
    output(C1);

    return 0;
}
