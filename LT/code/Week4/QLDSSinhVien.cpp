#include<iostream>
#include<cstring>
using namespace std;

#define MAXSV 101
#define MAXLEN 30

void boSungDanhSach(char DS[MAXSV][MAXLEN]){
    int i = 0;
    while(strlen(DS[i]) != 0){
        i = i+1;
    }
    while(i<100){
        cout<<"Nhap ho va ten sinh vien: ";
        fflush(stdin);
        gets(DS[i]);
        if (strlen(DS[i]) == 0){
            break;
        }
        i=i+1;
    }
}

void sapXepDanhSach(char DS[MAXSV][MAXLEN]){
    int l = 0;
    while(strlen(DS[l]) != 0){
        l = l+1;
    }
    char tmp[30];
    for(int i=1;i<l;i++){
        for(int j=1;j<l;j++){
            if(strcmp(DS[j-1], DS[j])>0){
                strcpy(tmp, DS[j-1]);
                strcpy(DS[j-1], DS[j]);
                strcpy(DS[j], tmp);
            }
        }
    }
}

void inDanhSach(char DS[MAXSV][MAXLEN]){
    int i = 0;
    while(strlen(DS[i]) != 0){
        cout << i+1 <<":"<< DS[i] << endl;
        i = i+1;
    }
}
int main(){
    char ds[MAXSV][MAXLEN];
    char c;
    do{
        cout<<"--Nhap 1 de bo sung danh sach"<<endl;
        cout<<"--Nhap 2 de sap xep danh sach"<<endl;
        cout<<"--Nhap 3 de in ra danh sach"<<endl;
        cout<<"--Nhap # de ket thuc"<< endl;
        cin >> c;

        if (c == '1'){
            boSungDanhSach(ds);
        }
        if (c == '2'){
            sapXepDanhSach(ds);
        }
        if (c == '3'){
            inDanhSach(ds);
        }
        if (c == '#'){
            break;
        }
    }while(1);
    return 0;
}
