//
//  Recursive.c
//  嘿嘿😝
//
//  Created by iflyC on 2018/9/27.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#include "Recursive.h"
void reverse(char *str)
{
    if(*str != '\0')
    {
        reverse(str+1);
        printf("%c",*str);
    }
}
int strlen_R(char *str)
{
    if(str == NULL)
    {
        return -1;
    }
    else if(*str == '\0')
    {
        return 0;
    }else{
        return strlen_R(str + 1) + 1;
    }


}
int feibonaqi(int n)
{
    int ret = 0;
    if(n > 1)
    {
        ret = feibonaqi(n - 1) + feibonaqi(n - 2);
    }else if (n == 1)
    {
        ret = 1;
    }else if (n == 0)
    {
        ret = 1;
    }
    return ret;
}



void hannuota_Test(int n, char a,char b, char c)
{
    if(n <= 0) return;
    if(n == 1)
    {
        printf("%c->%c\n",a,c);
    }else{
        hannuota_Test(n - 1, a, c, b);
        printf("%c->%c\n",a,c);
        hannuota_Test(n - 1, b, a, c);
    }
}
void hannuota(int n, char a, char b, char c)
{
    // 移动 n (n>1)个盘子的三个步骤
    // 1. a 借助 c 移动(n-1)个盘子到 b
    // 2. a直接移动第n个盘子到c
    // 3. b 借助 a 讲（n-1）盘子移动到c
    if(n > 0)
    {
        if(n == 1)
        {
            printf("%c->%c\n",a,c);
        }else{
            hannuota(n - 1, a, c, b);
            printf("%c->%c\n",a,c);
            hannuota(n - 1, b, a, c);
        }
    }
}
void permutation(char s[],int b, int e)
{
    if(b >= 0 && b <= e)
    {
        if(b == e)
        {
            printf("%s\n",s);
        }else{

            for(int i = b; i <= e; i++)
            {
                char t = s[b];
                s[b] = s[i];
                s[i] = t;
                permutation(s, b+1, e);
                t = s[b];
                s[b] = s[i];
                s[i] = t;
            }
        }
    }
}
#define N 8
char table[N+2][N+2];
struct Pos{
    int ios;
    int jos;
};
struct Pos pos[3] = {{-1,-1},{-1,0},{-1,1}};
static int counter = 0;
int check(int i ,int j)
{
    int ret = 1;
    for(int index =0; index < 3; index++)
    {
        int ni = i;
        int nj = j;
        while (ret && table[ni][nj] != '#') {
            ni = ni + pos[index].ios;
            nj = nj + pos[index].jos;
            ret = ret && table[ni][nj] != '*';
        }
    }
    return ret;
}

void initBoard(void)
{
    for(int i = 0; i < N +2; i++)
    {
        for(int j = 0; j < N+2; j++)
        {
            table[i][j] = ' ';
        }
    }
    for(int i = 0; i < N+2; i++)
    {
        table[0][i] = '#';
        table[N+1][i] = '#';
        table[i][0] = '#';
        table[i][N+1] = '#';

    }
}
void displayBoard(void)
{
    for(int i = 0; i < N +2; i++)
    {
        for(int j = 0; j < N+2; j++)
        {
            printf("%c ",table[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void find(int i)
{
    if(i > 8)
    {
        counter++;
        printf("solution%d:\n",counter);
        displayBoard();
    }else{
        for(int j = 1; j < N+1; j++)
        {
            if(check(i, j))
            {
                table[i][j] = '*';
                find(i+1);
                table[i][j] = ' ';
            }

        }
    }
}

void eightQueen(int n)
{
    initBoard();
    //displayBoard();
    find(1);
}

