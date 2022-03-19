#include<iostream>
#include<math.h>
using namespace std;

struct fraction{
    int tuso;
    int mauso;
    fraction(int t, int m){
        tuso = t;
        mauso = m;
    }
};
void simplify(fraction &f){
    for (int i = 1; i <= min(f.tuso, f.mauso); i++){
        if ((f.tuso%i==0)&&(f.mauso%i==0)){
            f.tuso = f.tuso/i;
            f.mauso = f.mauso/i;
        }
    }
}
int LCM(int m1, int m2){
    for (int i = max(m1, m2); i <= m1*m2; i++){
        if((i%m1==0)&&(i%m2==0)){
            return i;
        }
    }
    return m1*m2;
}
fraction operator + (fraction f1, fraction f2){
    int MSC = LCM (f1.mauso, f2.mauso);
    int Tu = f1.tuso*(MSC/f1.mauso)+f2.tuso*(MSC/f2.mauso);
    struct fraction f = fraction(Tu, MSC);
    simplify(f);
    return f;
}
fraction operator - (fraction f1, fraction f2){
    int MSC = LCM (f1.mauso, f2.mauso);
    int Tu = f1.tuso*(MSC/f1.mauso)-f2.tuso*(MSC/f2.mauso);
    struct fraction f = fraction(Tu, MSC);
    simplify(f);
    return f;
}
fraction operator * (fraction f1, fraction f2){
    int Tu = f1.tuso*f2.tuso;
    int Mau = f1.mauso*f2.mauso;
    struct fraction f = fraction(Tu, Mau);
    simplify(f);
    return f;
}
fraction operator / (fraction f1, fraction f2){
    if(f2.tuso==0){
        cout<<"Khong the chia cho 0";
        return f2;
    }
    else{
        struct fraction ND = fraction(f2.mauso, f1.tuso);
        struct fraction f = f1*ND;
        simplify(f);
        return f;
    }
}
fraction &operator ++ (fraction &f){
    //Tien to
    f.tuso = f.tuso+f.mauso;
    simplify(f);
    return f;
}
fraction operator ++ (fraction &f, int){
    //Hau to
    struct fraction temp = f;
    f.tuso = f.tuso+f.mauso;
    return temp;
}
fraction &operator -- (fraction &f){
    //Tien to
    f.tuso = f.tuso-f.mauso;
    simplify(f);
    return f;
}
fraction operator -- (fraction &f, int){
    //Hau to
    struct fraction temp = f;
    f.tuso = f.tuso-f.mauso;
    return temp;
}
fraction operator += (fraction&f1, fraction f2){
    f1 = f1+f2;
    simplify(f1);
    return f1;
}
fraction operator -= (fraction&f1, fraction f2){
    f1 = f1-f2;
    simplify(f1);
    return f1;
}
fraction operator *= (fraction&f1, fraction f2){
    f1 = f1*f2;
    simplify(f1);
    return f1;
}
fraction operator /= (fraction&f1, fraction f2){
    f1 = f1/f2;
    simplify(f1);
    return f1;
}
void printFrac(fraction f){
    cout<<f.tuso<<"/"<<f.mauso<<endl;
}
int main(){
    int t1, m1, t2, m2;
    cout<<"Nhap tu so va mau so phan so f1:";
    cin>>t1;
    cin>>m1;
    cout<<"Nhap tu so va mau so phan so f2:";
    cin>>t2;
    cin>>m2;
    struct fraction f1=fraction(t1,m1);
    struct fraction f2=fraction(t2,m2);
    printFrac(f1);
    printFrac(f2);
    simplify(f1);
    simplify(f2);

    struct fraction f=f1+f2;
    cout<<"f=f1+f2=";
    printFrac(f);

    f = f1-f2;
    cout<<"f=f1-f2=";
    printFrac(f);

    f = f1*f2;
    cout<<"f=f1*f2=";
    printFrac(f);

    f = f1/f2;
    cout<<"f=f1/f2=";
    printFrac(f);

    f=++f1;
    cout<<"++f1 = ";
    printFrac(f);

    f=f1++;
    cout<<"f1++ = ";
    printFrac(f);

    f1+=f2;
    cout<<"f1+=f2; f1=";
    printFrac(f1);

    f1-=f2;
    cout<<"f1-=f2; f1=";
    printFrac(f1);

    f1*=f2;
    cout<<"f1*=f2; f1=";
    printFrac(f1);

    f1/=f2;
    cout<<"f1/=f2; f1=";
    printFrac(f1);

    return 0;
}
