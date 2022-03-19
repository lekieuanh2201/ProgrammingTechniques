/*Bài tập 13: Đếm xâu con*/

#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#define LONGMAX 1000000000
#define LONGMIN -1000000000
using namespace std;

long long count_string(char *st, long n){
    map<long, long long> my_map;
    long maxi = LONGMIN;
    long mini = LONGMAX;
    my_map[0] = 1;
    long sum = 0;
    for (long i = 0; i < n; i++){
        if (st[i] == '1'){
            sum ++;
        }
        else{
            sum --;
        }
        mini = min(mini, sum);
        maxi = max(maxi, sum);
        my_map[sum] ++;
    }
    long long result = 0;
    for (long i = mini; i <= maxi; i++){
        result += (my_map[i] * (my_map[i] - 1)) / 2;
    }
    return result;
}
int main()
{
    char st[1000000];
    cin >> st;
    long n = strlen(st);
    cout << count_string(st, n);
    return 0;
}
