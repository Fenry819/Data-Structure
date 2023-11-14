#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node {
    int d;
    int c;
    struct node *p;
    struct node *l;
    struct node *r;
};

struct node *root = NULL;

struct node *bst(struct node *trav, struct node *temp) {
    if (trav == NULL)
        return temp;
    if (temp->d < trav->d) {
        trav->l = bst(trav->l, temp);
        trav->l->p = trav;
    } else if (temp->d > trav->d) {
        trav->r = bst(trav->r, temp);
        trav->r->p = trav;
    }
    return trav;
}


void rRotate(struct node *temp) {
    struct node *l = temp->l;
    temp->l = l->r;
    if (temp->l)
        temp->l->p = temp;
    l->p = temp->p;
    if (!temp->p)
        root = l;
    else if (temp == temp->p->l)
        temp->p->l = l;
    else
        temp->p->r = l;
    l->r = temp;
    temp->p = l;
}

void lRotate(struct node *temp) {
    struct node *r = temp->r;
    temp->r = r->l;
    if (temp->r)
        temp->r->p = temp;
    r->p = temp->p;
    if (!temp->p)
        root = r;
    else if (temp == temp->p->l)
        temp->p->l = r;
    else
        temp->p->r = r;
    r->l = temp;
    temp->p = r;
}

void fixup(struct node *root, struct node *pt) {
    struct node *p_pt = NULL;
    struct node *grand_p_pt = NULL;
    int t;

    while ((pt != root) && (pt->c != 0) && (pt->p->c == 1)) {
        p_pt = pt->p;
        grand_p_pt = pt->p->p;

        if (p_pt == grand_p_pt->l) {
            struct node *uncle_pt = grand_p_pt->r;
            if (uncle_pt != NULL && uncle_pt->c == 1) {
                grand_p_pt->c = 1;
                p_pt->c = 0;
                uncle_pt->c = 0;
                pt = grand_p_pt;
            } else {
                if (pt == p_pt->r) {
                    pt = p_pt;
                    lRotate(pt);
                    p_pt = pt->p;
                }
                rRotate(grand_p_pt);
                t = p_pt->c;
                p_pt->c = grand_p_pt->c;
                grand_p_pt->c = t;
                pt = p_pt;
            }
        } else {
            struct node *uncle_pt = grand_p_pt->l;
            if (uncle_pt != NULL && uncle_pt->c == 1) {
                grand_p_pt->c = 1;
                p_pt->c = 0;
                uncle_pt->c = 0;
                pt = grand_p_pt;
            } else {
                if (pt == p_pt->l) {
                    pt = p_pt;
                    rRotate(pt);
                    p_pt = pt->p;
                }
                lRotate(grand_p_pt);
                t = p_pt->c;
                p_pt->c = grand_p_pt->c;
                grand_p_pt->c = t;
                pt = p_pt;
            }
        }
    }

    root->c = 0;
}


void inorder(struct node *trav) {
    if (trav == NULL)
	return;
    inorder(trav->l);
    printf("%d", trav->d);
    if (trav->c == 0)
	printf(" black\t");
    else
	printf(" red\t");
    inorder(trav->r);
}

int main() {
    int n = 7;
    int a[7] = {7, 6, 5, 4, 3, 2, 1};
    int i;
    clrscr();

    for (i = 0; i < n; i++) {
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->r = NULL;
	temp->l = NULL;
	temp->p = NULL;
	temp->d = a[i];
	temp->c = 1;
	root = bst(root, temp);
	fixup(root, temp);
    }

    printf("Inorder traversal of the created tree:\n");
    inorder(root);
    getch();
    return 0;
}
