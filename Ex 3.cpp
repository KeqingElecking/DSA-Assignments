#include <stdio.h>
#include <string.h>
struct NGAY{
    int ngay; 
    int thang; 
    int nam;
};
struct SinhVien{
    char maSV[8];
    char hoten[50];
    int Gioitinh;
    NGAY ngaysinh;
    char diachi[100];
    char lop[12];
    char khoa[7];
};
struct Thongtin{
    SinhVien data;
    Thongtin *next;
};
struct Danhsach{
    Thongtin *first;
    Thongtin *last;
};
void NhapSV(SinhVien x){
    gets(x.maSV);
    fflush(stdin);
    gets(x.hoten);
    fflush(stdin);
    scanf("%d%d%d%d", x.Gioitinh, x.ngaysinh.ngay, x.ngaysinh.thang, x.ngaysinh.nam);
    gets(x.diachi);
    fflush(stdin);
    gets(x.lop);
    fflush(stdin);
    gets(x.khoa);
    fflush(stdin);
}
void NhapDS(Danhsach *ds, int total)
{
    ds->first = ds->last = NULL;
    int i = 0;
    while(i < total){
        Thongtin* p = new Thongtin;
        NhapSV(p->data);
        p->next = ds->first;
        ds->first = p;
        i++;
    }
}
bool sosanh(char sv1[], char sv2[])
{
    if(sizeof(sv1)>sizeof(sv2)) return true;
    else if (sizeof(sv1)<sizeof(sv2)) return false;
    else
    {
        int i = 0;
        while (i < sizeof(sv1) - 1)
        {
            if(sv1[i] > sv2[i]) return true;
            else if (sv1[i] > sv2[i]) return false;
        }
        return true;
    }
}
void sort(Danhsach *sv, int total)
{
    Thongtin* i = sv->first;
    Thongtin* j = sv->last;

}
int main()
{
    int total;
    scanf("%d", &total);
    Danhsach* sv;
    sv = NULL;
    NhapDS(sv, total);

}
