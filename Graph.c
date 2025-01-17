#include <stdio.h>
#include <stdlib.h>

struct node
{
    int checked;
    int data;
    int des;
    struct node* next;
};

struct edge
{
    int src, des;
};
struct graph
{
    int N;
    struct node* head[];
};
struct queue
{
    struct node* first;
    struct node* last;
};

struct graph* create(struct edge edges[], int num)
{
    struct graph* grp = (struct graph*)malloc(sizeof(struct graph)); //Khởi tạo vùng nhớ cho đồ thị
    grp->N = num;
    for (int i = 0 ; i < grp->N; i++) //Khởi tạo vùng nhớ trống cho từng pointer chỉ vào các đỉnh + khởi tạo data từng node
    {
        grp->head[i] = NULL;
        grp->head[i]->checked = 0;
        printf("Confirm value of node %d: ", i);
        scanf("%d", grp->head[i]->data);
    }
    for (int i = 0; i < grp->N; i++)
    {
        int src = edges[i].src;
        int des = edges[i].des;

        struct node* n_node = (struct node*)malloc(sizeof(struct node)); //Khởi tạo một node tạm để lưu thông tin liên kết từ một đỉnh đến đỉnh khác
        n_node->des = des; //Gán thông tin của đỉnh hiện tại
        n_node->next = grp->head[src]; //Trỏ vào địa chỉ của đỉnh hiện tại
        grp->head[src] = n_node; //Gán địa chỉ đỉnh kế tiếp

        n_node = (struct node*)malloc(sizeof(struct node)); //sử dụng lại biến tạm để lưu thông tin liên kết ngược (nếu như là liên kết có hướng thì bỏ qua bước này)
        //các bước thực hiện dưới giống hệt
        n_node->des = src;
        n_node->next = grp->head[des];
        grp->head[des] = n_node;
    }

    return grp;
}

void create_edge(struct edge edges[],int num)
{
    printf("Confirm edges");
    for (int i = 0; i < num; i++)
    {
        scanf("%d %d", &edges[i].src, &edges[i].des);
        printf("Edge between %d and %d created\n", edges[i].src, edges[i].des);
    }
}

struct queue* create_queue()
{
    struct queue* qq = (struct queue*)malloc(sizeof(struct queue));
    qq->first = qq->last = NULL;
    return qq;
}

void push(struct queue* qq, struct node* n_node)
{
    if (qq->last == NULL)
    {
        qq->first = qq->last = n_node;
        return;
    }
    qq->last->next = n_node;
    qq->last= n_node;
}

struct node* pop(struct queue* qq)
{
    if (qq->first == NULL) return NULL;
    struct node* temp = qq->first;
    struct node* callback = temp;
    qq->first = qq->first->next;
    if(qq->first = NULL) qq->last = NULL;
    free(temp);
    return callback;
}

struct node* peak(struct queue* qq)
{
    if (qq->first == NULL) return NULL;
    return qq->first;
}

void bfs_graph(struct graph* grp, struct node* start)
{

}

void dfs_graph(struct graph* grp, struct node* start)
{

}


