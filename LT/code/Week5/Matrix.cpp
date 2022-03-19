#include <iostream>
#include <conio.h>
using namespace std;

//Nhan hai ma trận
void MultiplyMatrix(int **A,int **B,int **C,int M, int N, int P){
    for (int i=0; i<M; i++){
        for (int j=0; j<P; j++){
            C[i][j]=0;
        }
    }
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            for (int k = 0; k < P; k++){
                C[i][k] += A[i][j]*B[j][k];
            }
        }
    }
}
//Cấp phát vùng nhớ cho ma trận
void AllocMatrix(int **A,int M,int N){
    //A = new int* [M];
    for (int i=0; i<M; i++){
        A[i] = new int [N];
    }
    /*
    if (A == NULL)
        return 0;
    return 1;*/
}
//Giải phóng vùng nhớ
void FreeMatrix(int **A, int M){
    for (int i=0; i<M; i++){
        delete [] A[i];
    }
    delete [] A;
}

//Nhập các giá trị của ma trận
void InputMatrix(int**A,int M,int N)
{
    for(int I=0;I<M; I++){
        for(int J=0;J<N; J++){
            cout<<"["<<I<<"]["<<J<<"]=";
            cin>>A[I][J];
        }
    }
}
//Hiển thị ma trận
void DisplayMatrix(int **A,int M,int N)
{
    for(int I=0;I<M;++I)
    {
        for(int J=0;J<N;++J)
        {
            cout<<A[I][J]<<"\t";
        }
        cout<<endl;
    }
}


int main(){
    int M,N,P;


    cout<<"Nhap so dong cua ma tran A:";
    cin>>M;
    cout<<"Nhap so cot cua ma tran A va so dong cua ma tran B:";
    cin>>N;
    cout<<"Nhap so cot cua ma tran B:";
    cin>>P;
    int **A = new int*[M];
    int **B = new int*[N];
    int **C = new int*[M];

 	AllocMatrix(A, M, N);
 	AllocMatrix(B, N, P);
 	AllocMatrix(C, M, P);

    cout<<"Nhap ma tran thu 1"<<endl;
    InputMatrix(A,M,N);
    cout<<"Nhap ma tran thu 2"<<endl;
    InputMatrix(B,N,P);
    cout<<"Ma tran thu 1"<<endl;
    DisplayMatrix(A,M,N);
    cout<<"Ma tran thu 2"<<endl;
    DisplayMatrix(B,N,P);

    MultiplyMatrix(A, B, C, M, N, P);

    cout<<"Tich hai ma tran"<<endl;
    DisplayMatrix(C,M,P);
    FreeMatrix(A, M);//Giải phóng vùng nhớ A
    FreeMatrix(B, N);//Giải phóng vùng nhớ B
    FreeMatrix(C, M);//Giải phóng vùng nhớ C
    return 0;
}
