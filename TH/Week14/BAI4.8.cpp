/*Bai tap 8: Viet cac ham thuc hien cac phep giao va hop cua 2 tap hop mo duoc bieu dien bang map*/

#include<iostream>
#include<map>

using namespace std;

template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b){
    /*YOUR CODE HERE*/
    map<T, double> temp = a;
    for (const auto &item : b){
        if (temp.count(item.first)){
            temp[item.first] = max(temp[item.first], item.second);
        }
        else temp.insert(item);
    }
    return temp;
    /****************/
}
template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b){
    /*YOUR CODE HERE*/
    map<T, double> temp;
    for(const auto itema : a){
        for(const auto itemb : b){
            if(itema.first == itemb.first){
                temp.insert({itema.first, min(itema.second, itemb.second)});
                break;
            }
        }
    }
    return temp;
    /****************/
}
template<class T>
void print_fuzzy_set(const map<T, double> &a){
    cout<<"{ ";
    for(const auto &x:a){
        std::cout<<"("<<x.first<<", "<<x.second<<") ";
    }
    cout<<"}";
    std::cout<<std::endl;
}
int main(){
    std::map<int, double> a = {{1, 0.2},{2,0.5},{3,1},{4,0.6},{5,0.7}};
    std::map<int, double> b = {{1, 0.5},{2,0.4},{4,0.9},{5,0.4},{6,1}};
    std::cout<<"A = ";print_fuzzy_set(a);
    std::cout<<"B = ";print_fuzzy_set(b);
    std::map<int, double> c = fuzzy_set_union(a, b);
    std::map<int, double> d = fuzzy_set_intersection(a, b);
    std::cout<<"Union: ";print_fuzzy_set(c);
    std::cout<<"Intersection: ";print_fuzzy_set(d);
}
