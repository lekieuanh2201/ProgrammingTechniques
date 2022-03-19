#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct SV{
    string classCode;
    string fullName;
    double score;
} SV;
void themSV(SV sv){
    FILE * fp;
    fp = fopen ("qlsv.txt","a");
    fprintf(fp, "%6s%30s%10f\n", sv.classCode, sv.fullName, sv.score);
    fclose(fp);
}
bool compareName(SV sv1, SV sv2) {
	if (sv1.fullName < sv2.fullName)
		return true;
	else if (sv1.fullName > sv2.fullName)
		return false;
    return false;
}
void sapXep(vector<SV> dssv){
    sort(dssv.begin(), dssv.end(), compareName);
}
void inDSSV(string maLop){
    FILE * fp;
    SV sv;
    vector<SV> dssv;
    fp = fopen("qlsv.txt", "r");
    while (fscanf(fp, "%6s%30s%10f\n", &sv.classCode, &sv.fullName, &sv.score) != EOF){
        if (maLop.compare(sv.classCode) == 0){
            dssv.push_back(sv);
        }
    }
    fclose(fp);
    sapXep(dssv);
    cout<<"Ho va ten\t\t Diem so"<<endl;
    for (SV sv:dssv){
        cout<<sv.fullName<<"\t\t"<<sv.score<<endl;
    }
}
void capNhatDiem(SV sv3){
    FILE * fp;
    SV sv;
    vector<SV> dssv;
    fp = fopen("qlsv.txt", "r");
    while (fscanf(fp, "%6s%30s%10f\n", &sv.classCode, &sv.fullName, &sv.score) != EOF){
        if (sv3.classCode.compare(sv.classCode) != 0){
            dssv.push_back(sv);
        }
        else{
            if(sv3.fullName.compare(sv.fullName) != 0){
                dssv.push_back(sv);
            }
        }
    }
    dssv.push_back(sv3);
    FILE *f;
    f = fopen("qlsv.txt","w");
    for (SV sinhVien : dssv){
        fprintf(f, "%6s%30s%10f\n", sinhVien.classCode, sinhVien.fullName, sinhVien.score);
    }
    fclose(f);
}
int main(){
    bool stop = false;
    while(stop == false){
        cout<<"CHUONG TRINH QUAN LY SINH VIEN"<<endl<<endl;
        cout<<"Chon 1 trong cac chuc nang sau"<<endl;
        cout<<"     1. Bo sung sinh vien"<<endl;
        cout<<"     2. In danh sach sinh vien cua 1 lop"<<endl;
        cout<<"     3. Cao nhat diem"<<endl;
        int function;
        cin>>function;
        fflush (stdin);
        if(function == 1){
            cout<<"CHUC NANG BO SUNG SINH VIEN"<<endl;
            SV sv1;
            cout<<"Nhap ma lop: ";
            getline(cin, sv1.classCode);
            cout<<"Nhap ten sinh vien: ";
            getline(cin, sv1.fullName);
            cout<<"Nhap diem sinh vien (chua co diem: nhap 0): ";
            cin>>sv1.score;
            themSV(sv1);
        }
        else if(function == 2){
            cout<<"CHUC NANG IN DANH SACH SINH VIEN"<<endl;
            cout<<"Nhap ma lop ";
            string maLop2;
            getline(cin, maLop2);
            inDSSV(maLop2);
        }
        else if(function == 3){
            cout<<"CHUC NANG CAP NHAT DIEM"<<endl;
            SV sv3;
            cout<<"Nhap ma lop: ";
            getline(cin, sv3.classCode);
            cout<<"Nhap ten sinh vien: ";
            getline(cin, sv3.fullName);
            cout<<"Nhap diem moi: ";
            double diem;
            cin>>sv3.score;
            capNhatDiem(sv3);
        }
        else {
            cout<<"Cam on ban da su dung chuong trinh";
            stop = true;
            break;
        }
    }
    return 0;
}
