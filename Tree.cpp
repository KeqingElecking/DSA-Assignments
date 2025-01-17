#include <iostream>
#include <string.h>
using namespace std;
//Cây -> sử dụng để lưu cho các cấu trúc dữ liệu phân cấp
//các bài toán của cây: bổ sung phần tử, duyệt cây, tìm kiếm, sắp xếp

//duyệt cơ bản => đệ quy
//nếu là cây ko rỗng => thăm gốc -> cây con trái -> cây con phải (preorder)

struct node
{
    int data;
    node* left;
    node* right;
    node(int s)
    {
        data = s;
        left = NULL;
        right = NULL;
    }
};

node* insert(node* org, int s)
{
    if (org == nullptr){
        return new node(s);
    }
    if (s < org->data)
    {
        org->left = insert(org->left, s);
    }
    else
    {
        org->right = insert(org->right, s);
    }
    return org;
}

void scaning(node* org)
{
    if (org == nullptr) return;
    scaning(org->left);
    cout << org->data << endl;
    scaning(org->right);
}

int main()
{
    int n;
    cin >> n;
    node* root = nullptr;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        root = insert(root, s);
    }
    scaning(root);
}


