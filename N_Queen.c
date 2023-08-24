#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)

int n;    // n x n �������� ũ�� n 
int* col;    // �� �ະ�� ���� ��(column) ��ġ 

void printQueens()
{
    int i;
    printf(" ");
    for (i = 1; i <= n; i++)
        printf("(%d, %d)\n ", i, col[i]);
    exit(1);
}

int promising(int i)    // �������� üũ 
{
    int k = 1;
    while (k < i)
    {
        if (col[i] == col[k] || abs(col[i] - col[k]) == abs(i - k))    // �����¿�, �밢�� �� �ִ� �� 
            return 0;
        k++;
    }
    return 1;
}


void queens(int i)
{
    int j;

    if (promising(i))    // �����ϴٸ�  
    {
        if (i == n)    // ������ ����� ������ �����ٸ� 
        {
            printQueens();    // ���� ��ġ ��� 
            return;
        }
        else    // ���� ������ �ʾҴٸ� 
        {
            for (j = 1; j <= n; j++)    // ��� �� Ž�� 
            {
                col[i + 1] = j;
                queens(i + 1);
            }
        }
    }

}


int main()
{
    printf("Input N: ");
    scanf("%d", &n);
    col = (int*)malloc(sizeof(int) * (n + 1));
    queens(0);
    printf("No solution");    // �ذ���� ���� ��� 

    return 0;
}
