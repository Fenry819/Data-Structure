#include<stdio.h>
#include<conio.h>
int set1[10], set2[10], set3[20], n, m, max;
void insert(int[], int, int);
void display(int[], int);
void intersection(int[], int[]);
void setunion(int[], int[]);
int main() {
    int i, element;
    clrscr();
    printf("\nNo of elements in first set: ");
    scanf("%d", &n);
    printf("\nNo of elements in second set: ");
    scanf("%d", &m);
    max = m + n;
    printf("\nEnter first set: ");
    for (i = 0; i < n; i++) {
	scanf("%d", &element);
	insert(set1, i, element);
    }
    printf("\nEnter second set: ");
    for (i = 0; i < m; i++) {
	scanf("%d", &element);
	insert(set2, i, element);
    }
    printf("\nThe sets are: ");
    display(set1, n);
    display(set2, m);
    printf("\nThe intersection of these sets is: ");
    intersection(set1, set2);
    printf("\nThe union of these sets is: ");
    setunion(set1, set2);
    return 0;
}

void insert(int data[], int count, int element) {
    data[count] = element;
}

void display(int set[], int num) {
    int i;
    printf("\n");
    for (i = 0; i < num; i++) {
	printf("%d\t", set[i]);
    }
}

void intersection(int s1[], int s2[]) {
    int i, j, x = -1;
    for (i = 0; i < n; i++) {
	for (j = 0; j < m; j++) {
	    if (s1[i] == s2[j])
		insert(set3, ++x, s1[i]);
	}
    }
    if(x==-1)
    {
     printf("No elements");
    }
    display(set3, ++x);
}

void setunion(int s1[], int s2[]) {
    int i, j, x = -1, flag = 0;
    for (i = 0; i < n; i++) {
	insert(set3, ++x, s1[i]);
    }
    for (i = 0; i < m; i++) {
	flag = 0;
	for (j = 0; j < n; j++) {
	    if (s2[i] == s1[j]) {
		flag = 1;
		break;
	    }
	}
	if (flag == 0) {
	    insert(set3, ++x, s2[i]);
	}
    }
    display(set3, ++x);
    getch();
}
