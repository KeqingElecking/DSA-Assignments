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
    fflush(stdin);
    gets(x.maSV);
    fflush(stdin);
    gets(x.hoten);
    fflush(stdin);
    scanf("%d%d%d%d", &x.Gioitinh, &x.ngaysinh.ngay, &x.ngaysinh.thang, &x.ngaysinh.nam);
    fflush(stdin);
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
        if (ds->first = 0) ds->first = ds->last = p;
        else
        {
            p->next = ds->first;
            ds->first = p;
            i++;
        }

    }
}
void Delete(Danhsach *ds, int place)
{
    Thongtin* p = ds->first;
    for (int i = 0; i < place - 1; ++i)
    {
        p = p->next;
    }
    Thongtin* del = p->next;
    Thongtin* apd = del->next;
    p->next = apd;
    delete del;
}
bool sosanh(char sv1[], char sv2[])
{
    if (sv2 = 0) return false;
    if(sizeof(sv1)<sizeof(sv2)) return true;
    else if (sizeof(sv1)>sizeof(sv2)) return false;
    else
    {
        int i = 0;
        while (i < sizeof(sv1) - 1)
        {
            if(sv1[i] < sv2[i]) return true;
            else if (sv1[i] > sv2[i]) return false;
        }
        return true;
    }
}
void sort(Danhsach *sv, int total)
{
    Thongtin* p = 0;
    while (sv->first != 0)
    {
        Thongtin* i = sv->first;
        Thongtin** max = &sv->first;
        while(i != 0)
        {
            if (sosanh(i->data.hoten, (*max)->data.hoten)) max = &i->next;
            i = i->next;
        }
        Thongtin* del = *max;
        *max = del->next;
        del->next = p;
        p = del;
    }
}
void append(Danhsach* sv, SinhVien &x)
{
    Thongtin* p = new Thongtin;
    p->data = x;
    p->next = 0;
    if (sv->first == nullptr || sosanh(x.hoten, sv->first->data.hoten) < 0)
    {
        p->next = sv->first;
        sv->first = p;
        return;
    }
    Thongtin* ptr = sv->first;
    while (ptr->next != nullptr && sosanh(ptr->next->data.hoten, x.hoten) < 0)
    {
        ptr = ptr->next;
    }
    p->next = ptr->next;
    ptr->next = p;
}
void Samedob(Danhsach* sv, int total)
{
    
}
int main()
{
    int total;
    scanf("%d", &total);
    Danhsach sv;
    Danhsach* psv = &sv;
    NhapDS(psv, total);
    psv = &sv;
    sort(&sv, total);
    SinhVien x;
    NhapSV(x);
    append(psv, x);
    
}
