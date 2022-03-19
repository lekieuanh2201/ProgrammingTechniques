//Xây dựng các hàm cấp phát và giải phóng bộ nhớ động cho mảng 3 chiều dùng *** và ****

#include<iostream>
using namespace std;

void allocM(float ****M, int r, int c, int d){
    *M = new float** [r];
    for (int i = 0; i < r; i++){
        *M[i] = new float* [c];
        for (int j = 0; j < c; j++){
            *M[i][j] = new float [d];
        }
    }
}
void freeM(float ****M, int r, int c, int d){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            delete [] M[i][j];
        }
        delete [] M[i];
    }
    delete [] M;
}
