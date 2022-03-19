//Bài tập 5: Tính tổ hợp
#include <iostream>
using namespace std;

int binom(int n, int k) {
    if (k > n) return 0;
    if (k == 0) return 1;
    return binom(n-1, k) + binom(n-1, k-1);
}

int binom2(int n, int k){

    //# Khử đệ quy
    /*# YOUR CODE HERE #*/
    int gtn=1, gtk=1, gtn_k=1;
    for(int i=1; i<=n; i++){
        gtn*=i;
    }
    for(int i=1; i<=n-k; i++){
        gtn_k*=i;
    }
    for(int i=1; i<=k; i++){
        gtk*=i;
    }
    return gtn/(gtk*gtn_k);
    /*****************/
}

int main() {
    int m;
    cin >> m;
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom(n, k));
        printf("\n");
    }
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom2(n, k));
        printf("\n");
    }
    return 0;
}
