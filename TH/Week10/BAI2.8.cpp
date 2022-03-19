/*Bài tập 8: Sắp xếp
Viết hàm so sánh cho thuật toán sắp xếp.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int val1, val2;
    cin >> val1 >> val2;
    vector< vector<int> > a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };

    //# sắp xếp các vector trong a theo tổng các phần tử giảm dần
    /*# YOUR CODE HERE #*/
    sort(a.begin(), a.end(), [](vector<int> &b, vector<int> &c){
        int sumb = accumulate(b.begin(), b.end(), 0);
        int sumc = accumulate(c.begin(), c.end(), 0);
        return sumb>sumc;
    });
    /*****************/

    for (const auto &v : a) {
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
