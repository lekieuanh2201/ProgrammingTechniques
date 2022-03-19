/*Bài tập 11: Tính tích hai đa thức
Cho 2 đa thức A(x) và B(x) tương ứng có bậc  N  và  M .
Hãy tính ma trận tích C(x) = A(x) * B(x) có bậc  N+M .*/

#include<iostream>
using namespace std;

int main(){
    int n, m;

    cin>>n;
    int *A = new int [n+1];
    for (int i=0; i<=n; i++){
        cin>>A[i];
    }

    cin>>m;
    int *B = new int [m+1];
    for (int i=0; i<=m; i++){
        cin>>B[i];
    }

    int bac_C = m+n;
    int *C = new int [bac_C+1];
    for (int i=0; i<=bac_C; i++){
        C[i]=0;
    }
    for (int i=0; i<=n; i++){
        for (int j=0; j<=m; j++){
            C[i+j] += A[i]*B[j];
        }
    }

    int x = C[0];
    for (int i=1; i<=bac_C; i++){
        x = x^C[i];
    }
    cout<<x;
    return 0;
}
