
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char hoten[30];
    int masv;
    float d1, d2, d3;
} Data;

typedef struct tagNode {
    Data infor;
    struct tagNode *link;
} Node;

typedef struct {
    Node *pHead;
    Node *pTail;
    int spt;
} LList;
void initList(LList *L)
{
    L->pHead = NULL;
    L->pTail = NULL;
    L->spt = 0;
}
int emptyList(LList L)
{
    return (L.spt == 0);
}
void nhap(Data *x)
{
    printf("Nhap ma sinh vien: ");
    scanf("%d", &x->masv);

    if(x->masv > 0) {
        printf("Nhap ho ten: ");
        scanf(" %29[^\n]", x->hoten);

        printf("Nhap diem mon 1: ");
        scanf("%f", &x->d1);

        printf("Nhap diem mon 2: ");
        scanf("%f", &x->d2);

        printf("Nhap diem mon 3: ");
        scanf("%f", &x->d3);
    }
}
void in(Data x)
{
    printf("Ten: %s | Ma: %d | Diem 1: %.2f | Diem 2: %.2f | Diem 3: %.2f\n",
           x.hoten, x.masv, x.d1, x.d2, x.d3);
}
void insert_Head(LList *L, Data x)
{
    Node *pp;
    pp = (Node*)malloc(sizeof(Node));

    if(pp == NULL) return;

    pp->infor = x;
    pp->link = NULL;

    if(emptyList(*L)) {
        L->pHead = pp;
        L->pTail = pp;
    }
    else {
        pp->link = L->pHead;
        L->pHead = pp;
    }

    L->spt++;
}
void insert_Tail(LList *L, Data x)
{
    Node *pp;
    pp = (Node*)malloc(sizeof(Node));

    if(pp == NULL) return;

    pp->infor = x;
    pp->link = NULL;

    if(emptyList(*L)) {
        L->pHead = pp;
        L->pTail = pp;
    }
    else {
        L->pTail->link = pp;
        L->pTail = pp;
    }

    L->spt++;
}
void insert_After(LList *L, int ma, Data x)
{
    Node *p = L->pHead;

    while(p != NULL && p->infor.masv != ma) {
        p = p->link;
    }

    if(p == NULL) {
        printf("Khong tim thay sinh vien!\n");
        return;
    }

    Node *pp = (Node*)malloc(sizeof(Node));

    if(pp == NULL) return;

    pp->infor = x;
    pp->link = p->link;
    p->link = pp;

    if(p == L->pTail) {
        L->pTail = pp;
    }

    L->spt++;
}
void processList(LList L)
{
    Node *pp = L.pHead;

    if(emptyList(L)) {
        printf("Danh sach rong!\n");
        return;
    }

    while(pp != NULL) {
        in(pp->infor);
        pp = pp->link;
    }
}
void freeList(LList *L)
{
    Node *p;

    while(L->pHead != NULL) {
        p = L->pHead;
        L->pHead = L->pHead->link;
        free(p);
    }

    L->pTail = NULL;
    L->spt = 0;
}

int main()
{
    LList L;
    int kt = 0;
    Data x;

    initList(&L);

    do {
        printf("\n===== CHUONG TRINH DSLK DON SV =====\n");
        printf("1: Them nut vao dau danh sach\n");
        printf("2: Them nut vao cuoi danh sach\n");
        printf("3: Them nut sau mot nut khac\n");
        printf("9: Duyet danh sach\n");
        printf("0: Thoat\n");
        printf("Moi ban chon: ");

        int chon;
        scanf("%d", &chon);

        switch(chon) {

            case 1:
                nhap(&x);

                if(x.masv > 0)
                    insert_Head(&L, x);

                break;

            case 2:
                nhap(&x);

                if(x.masv > 0)
                    insert_Tail(&L, x);

                break;

            case 3: {
                int ma;

                printf("Nhap ma sinh vien muon them phia sau: ");
                scanf("%d", &ma);

                nhap(&x);

                if(x.masv > 0)
                    insert_After(&L, ma, x);

                break;
            }

            case 9:
                processList(L);
                break;

            case 0:
                printf("Bye bye!\n");
                kt = 1;
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }

    } while(kt == 0);

    freeList(&L);

    return 0;
}
