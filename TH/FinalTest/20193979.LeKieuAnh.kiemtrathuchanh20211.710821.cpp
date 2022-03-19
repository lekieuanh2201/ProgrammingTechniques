/* De 1_5_LeKieuAnh_IT3040*/

#include<iostream>
#include<vector>
using namespace std;

typedef struct monHoc{
    string maMH;
    int soTinChiMH;
    double diemQT;
    double diemCK;
    double trongSoCK;
    double diemMH;
    int ketQuaMH;
}monHoc;
typedef struct sinhVien{
    //string maSv;
    string hoTen;
    string gioiTinh;
    int soMonHoc;
    vector<monHoc> dsMH;
    double CPA;
    string xepLoai;
}sinhVien;

vector<sinhVien> dssv;
void nhapThongTin(sinhVien sv, int i){
    cout<<"Nhap thong tin cua sinh vien "<<i+1<<" :"<<endl;
    cout<<"Nhap ten SV: ";
    getline(cin,sv.hoTen);
    fflush(stdin);
    cout<<"Nhap goi tinh: ";
    getline(cin,sv.gioiTinh);
    fflush(stdin);
    cout<<"Nhap so mon hoc: ";
    cin>>sv.soMonHoc;
    fflush(stdin);
    for(int j=0; j<sv.soMonHoc; j++){
        monHoc MH;
        cout<<"Nhap mon hoc thu "<<j+1<<endl;
        cout<<"     Nhap Ma MH: ";
        getline(cin,MH.maMH);
        fflush(stdin);
        cout<<"     Nhap so tin chi: ";
        cin>>MH.soTinChiMH;
        fflush(stdin);
        cout<<"     Nhap trong so CK:>0,<1: ";
        cin>>MH.trongSoCK;
        fflush(stdin);
        cout<<"     Nhap diem QT: ";
        cin>>MH.diemQT;
        fflush(stdin);
        cout<<"     Nhap diem CK: ";
        cin>>MH.diemCK;
        fflush(stdin);
        MH.diemMH = MH.diemCK*MH.trongSoCK+MH.diemQT*(1-MH.trongSoCK);
        if (MH.diemMH>5) MH.ketQuaMH = 1;
        else MH.ketQuaMH = 0;
        sv.dsMH.push_back(MH);
    }
    double diem = 0.0;
    int soTC=0;
    for(monHoc mh: sv.dsMH){
        diem += mh.diemMH*mh.soTinChiMH;
        soTC+=mh.soTinChiMH;
    }
    sv.CPA = diem/soTC;
    if(sv.CPA >= 9.0) sv.xepLoai = "A+";
    else if (sv.CPA>=8.5) sv.xepLoai = "A";
    else if (sv.CPA>=7.5) sv.xepLoai = "B+";
    else if (sv.CPA>=6.5) sv.xepLoai = "B";
    else if (sv.CPA>=5) sv.xepLoai = "C";
    else if (sv.CPA>=4) sv.xepLoai = "D";
    else sv.xepLoai = "F";
    dssv.push_back(sv);
}

void xuatDSSV(vector<sinhVien> ds){
    for(sinhVien sv: ds){
        cout<<"\tTensinhvien: "<<sv.hoTen<<endl;
        cout<<"\tGioi tinh: "<<sv.gioiTinh<<endl;
        cout<<"\tSo monHoc: "<<sv.soMonHoc<<endl;
        cout<<"\tKet qua hoc tap cac mon:"<<endl;
        cout<<"\tMamonHoc\tSotinchi\ttrong so\tdiemQT\tDiem CK\t\tDiem MH\t\tKetQua MH"<<endl;
        for(monHoc mh: sv.dsMH){
            if(mh.ketQuaMH==1){
               cout<<"\t"<<mh.maMH<<"\t\t"<<mh.soTinChiMH<<"\t\t"<<mh.trongSoCK<<"\t\t"<<mh.diemQT<<"\t\t"<<mh.diemCK<<"\t\t"<<mh.diemMH<<"\t\tqua mon"<<endl;
            }
            else{
                cout<<"\t"<<mh.maMH<<"\t\t"<<mh.soTinChiMH<<"\t\t"<<mh.trongSoCK<<"\t\t"<<mh.diemQT<<"\t\t"<<mh.diemCK<<"\t\t"<<mh.diemMH<<"\t\thoc lai"<<endl;
            }
        }
        cout<<"\tDiemCPA: "<<sv.CPA<<endl;
        cout<<"\tXep loai: "<<sv.xepLoai<<endl<<endl;
    }
}

int main(){
    int phimChucNang;
    char tiepTuc;
    bool check = true;
    while(check == true){
        cout<<"Le Kieu Anh - 20193979 - Ma lop TH: 710821"<<endl;
        cout<<"**    CHUONG TRINH QUAN LY SINH VIEN  **"<<endl;
        cout<<"**1.  Nhap cac SINH VIEN              **"<<endl;
        cout<<"**2.  In THONG TIN SV, KET QUA,..     **"<<endl;
        cout<<"**0.  Thoat                           **"<<endl;
        cout<<"****************************************"<<endl;
        cout<<"**       Nhap lua chon cua ban        **"<<endl;
        cin>>phimChucNang;
        fflush(stdin);
        switch(phimChucNang){
        case 1:{
            cout<<"Ban da chon nhap ds SINH VIEN!"<<endl;
            int soSV;
            cout<<"Nhap so luong sinh vien: ";
            cin>>soSV;
            fflush(stdin);
            for(int i=0; i<soSV; i++){
                sinhVien sv;
                nhapThongTin(sv,i);
            }
            cout<<"Ban da nhap thanh cong!"<<endl;
            cout<<"Bam phim bat ky de tiep tuc!"<<endl;
            cin>>tiepTuc;
            fflush(stdin);
            break;
        }
        case 2:{
            cout<<"Ban da chon xuat DS SINH VIEN !"<<endl;
            xuatDSSV(dssv);
            cout<<"Bam phim bat ky de tiep tuc!"<<endl;
            cin>>tiepTuc;
            fflush(stdin);
            break;
        }
        case 0:{
            cout<<"Ban da chon thoat chuong trinh!"<<endl;
            check = false;
            break;
        }
        default:{
            cout<<"Vui long chon dung phim chuc nang!"<<endl;
            break;
        }
        }
    }

}

