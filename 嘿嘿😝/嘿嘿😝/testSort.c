//
//  testSort.c
//  嘿嘿😝
//
//  Created by iflyC on 2019/3/7.
//  Copyright © 2019年 iflyC. All rights reserved.
//

#include "testSort.h"
void testSwap(int array[], int i, int j)
{
    int t = array[i];
    array[i] = array[j];
    array[j] = t;
}

void testBubbleSort(int *a, int length)
{
    int exchange = 1;
    for(int i = 0; i < length && exchange; i++)
    {
        exchange = 0;
        for(int j = length - 1; j > i; j--)
        {
            if(a[j] > a[j-1])
            {
                testSwap(a, j, j-1);
                exchange = 1;
            }
        }
    }
}
void testInsertionSort(int *a, int length)
{
    for(int i = 1; i < length; i++)
    {
        int k = i;
        int temp = a[i];
        for(int j = i - 1; j >= 0 && a[j] > temp; j--)
        {
            a[j+1] = a[j];
            k = j;
        }
        a[k] = temp;
    }
}
void testShellSort(int *a, int length)
{
    int gap = length;

    do {
        gap = gap / 3 + 1;

        for(int i = gap; i < length; i+=gap)
        {
            int k = i;
            int temp = a[i];
            for(int j = i - gap; j >= 0 && a[j] > temp; j-=gap)
            {
                a[j+ gap] = a[j];
                k = j;
            }
            a[k] = temp;
        }

    } while (gap > 0);
}
int testPartion(int *a, int low, int high)
{
    int ret = low;
    int pv = a[low];
    while ( low < high) {
        while (low < high && a[high] > pv) {
            high--;
        }
        testSwap(a, low, high);
        while (low < high && a[low] <= pv) {
            low++;
        }
        testSwap(a, low, high);
    }
    return ret;
}
void qSort(int *a, int low, int high)
{
    if(low < high)
    {
        int mid = testPartion(a, low, high);
        qSort(a, low, mid - 1);
        qSort(a, mid + 1, high);
    }
}
void qtestQuickSort(int *a, int length)
{
    qSort(a, 0, length - 1);
}
int binary_search(int *a, int low, int high, int key)
{
    int ret = -1;
    int mid = (low + high) / 2;
    if(key == a[mid])
    {
        ret = mid;
    }else if(key < a[mid]){
        ret = binary_search(a, low, mid - 1, key);
    }else if (key > a[mid])
    {
        ret = binary_search(a, mid + 1, high, key);
    }
    return ret;
}
int binary_searchex(int *a, int low, int high, int key)
{
    int ret = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if(key == a[mid])
        {
            ret = mid;
            break;
        }else if(key < a[mid])
        {
            high = mid - 1;
        }else if(key > a[mid])
        {
            low = mid + 1;
        }
    }
    return  ret;
}





