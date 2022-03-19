/*Bài tập 9: Lập lịch cho y tá*/

#include<iostream>
using namespace std;

int x[1000];
int n, k1, k2;

void print_sol(){
    for (int i = 1; i <= n; i++){
        cout << x[i];
    }
    cout << endl;
}
void TRY(int i, int j, int old_L){
    x[i] = j;
	int L = j ? ++old_L : 0;
    if (i == n ){
		if(L==0 || L>=k1){
            print_sol();
            return;
        }
		else return;
	}
    if(L < k1) TRY(i+1,1,L);
    else{
    	if (L + 1 > k2) TRY(i + 1, 0, L);
		else {
			TRY(i+1,0,L);
            TRY(i+1,1,L);
	    }
    }
}
int main(){
    cin >> n >> k1 >> k2;
    TRY(1, 0, 0);
    TRY(1, 1, 0);
    return 0;
}
