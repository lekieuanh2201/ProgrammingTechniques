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
int NamePos(char *ht)
{
    int i = strlen(ht) - 1;
    while (ht[i] == ' ' && i > -1)
        i--;
    while (ht[i] != ' ' && i > -1)
        i--;
    return i + 1;
}
void sapXepDanhSach(char ds[MAXSV][MAXLEN])
{
    int n = 0;
    while(strlen(ds[n]) != 0){
        n = n+1;
    }
    char tg[30];
    for (int i = 0; i < n - 1; i++)
    {
        int k = i;
        for (int j = i + 1; j < n; j++)
            if (strcmp(ds[k] + NamePos(ds[k]),
                       ds[j] + NamePos(ds[j])) > 0)
                k = j;
            else if (strcmp(ds[k] + NamePos(ds[k]),
                            ds[j] + NamePos(ds[j])) == 0)
                if (strcmp(ds[k], ds[j]) > 0)
                    k = j;
        if (k != i)
        {
            strcpy(tg, ds[i]);
            strcpy(ds[i], ds[k]);
            strcpy(ds[k], tg);
        }
    }
}
/*
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
*/
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
