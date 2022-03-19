/*Bài tập 12: Map Sort
Hôm nay, cô giáo giao cho An một câu hỏi hóc búa. Cô cho một danh sách với mỗi phần tử có dạng <key, value>
và yêu cầu An sắp xếp danh sách đó giảm dần theo giá trị value.
Nếu 2 phần tử có value giống nhau thì sắp xếp giảm dần theo key.
Hãy viết một chương trình sử dụng hàm nặc danh để giúp An làm bài tập.*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <sstream>

using namespace std;

int main(){
    vector<pair<int, int>> M;
    int key, value;
    string line;
    while(getline(cin,line)){
        string arr[2];
        int i = 0;
        stringstream ssin(line);
        while (ssin.good() && i < 2){
            ssin >> arr[i];
            ++i;
        }
        key = stoi(arr[0]);
        value = stoi(arr[1]);
        M.push_back(make_pair(key, value));
    }
    sort(M.begin(), M.end(), [](pair<int, int> M1, pair<int, int> M2)->bool{
        if(M1.second != M2.second){
            return M1.second > M2.second;
        }
        else{
            return M1.first > M2.first;
        }
    });
    for (auto& it : M) {
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}
