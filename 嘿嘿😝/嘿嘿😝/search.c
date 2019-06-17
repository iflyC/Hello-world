//
//  search.c
//  嘿嘿😝
//
//  Created by iflyC on 2018/12/10.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#include "search.h"
#include <stdlib.h>
void search_test(void)
{
    int *a = (int *)malloc(sizeof(int) * 50);
    for(int i = 0; i < 50; i++)
    {
        a[i] = i;
    }
    for(int i = 0; i < 50; i++)
    {
        int result = binary_search(a, 0, 49, i);
        printf("%d\n",result);
    }
    // 随便修改了一下
}
// 递归查找
int binary_search_recursive(int a[],int low,int high,int key)
{
    int ret = -1;
    if(low <= high)
    {
        int mid = (low + high)/2.0;
        if(key == a[mid])
        {
            ret = mid;
        }else if (key < a[mid])
        {
            ret = binary_search_recursive(a, low, mid-1, key);
        }else if (key > a[mid])
        {
            ret = binary_search_recursive(a, mid+1, high, key);
        }
    }
    return ret;
}
// 循环查找
int binary_search_while(int a[], int low ,int high, int key)
{
    int ret = -1;
    int mid = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if(a[mid] == key)
        {
            ret = mid;
            break;
        }else if (key < a[mid]){
            high = mid - 1;
        }else if (key > a[mid]){
            low = mid + 1;
        }
    }
    return ret;
}
// 差值查找
int binary_search_offset(int a[], int low ,int high, int key)
{
    int ret = -1;
    while (low <= high && key <= a[high] && key >= a[low])
    {
        float fx = 1.0 * (key - a[low])/(a[high] - a[low]);
        int  mid = low + fx * (high - low);
        if(a[mid] == key)
        {
            ret = mid;
            break;
        }else if (key < a[mid]){
            high = mid - 1;
        }else if (key > a[mid]){
            low = mid + 1;
        }
    }
    return ret;
}


