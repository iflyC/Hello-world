//
//  MySort.c
//  嘿嘿😝
//
//  Created by iflyC on 2018/11/16.
//  Copyright © 2018年 iflyC. All rights reserved.
//

//
//  MySort.h
//  嘿嘿😝
//
//  Created by iflyC on 2018/11/16.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
void swap(int array[], int i, int j)
{
    int t = array[i];
    array[i] = array[j];
    array[j] = t;
}
void printArray(int array[],int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}
// 选择排序
void selectionSort(int array[],int length) // O(n*n)
{
    for(int i = 0; i < length; i++)
    {
        int k = i;
        for(int j = i; j < length; j++)
        {
            if(array[k] < array[j])
            {
                k = j;
            }
        }
        swap(array, i, k);
    }
}
// 插入排序
void insertionSort(int array[],int length)
{
    for(int i = 1; i < length; i++)
    {
        int k = i;
        int temp = array[i];
        for(int j = i-1; j >= 0 && temp > array[j]; j--)
        {
            array[j+1] = array[j];
            k = j;
        }
        array[k] = temp;
    }
}
// 冒泡排序
void bubbleSort(int array[],int length)
{
    int exchange = 1;
    for(int i = 0; i < length && exchange; i++)
    {
        exchange = 0;
        for(int j = length-1; j > i; j--)
        {
            if(array[j] > array[j-1])
            {
                swap(array, j, j-1);
                exchange = 1;
            }
        }
    }
}
// 希尔排序
void shellSort(int array[], int length)
{
    int gap = length;
    do {
        gap = gap / 3 + 1;

        for(int i = gap; i < length; i += gap)
        {
            int k = i;
            int temp = array[i];
            for(int j = i - gap; j>=0 && temp > array[j]; j -= gap)
            {
                array[j + gap] = array[j];
                k = j;
            }
            array[k] = temp;
        }

    } while (gap > 1);
}
// 快速排序
int partion(int array[],int low, int high)
{
    int pv = array[low];

    while (low < high) {

        while (low < high && array[high] >= pv) {
            high--;
        }
        swap(array, high, low);

        while (low < high && array[low] <= pv) {
            low++;
        }
        swap(array, high, low);
    }
    return low;
}
void qSort(int array[], int low, int high)
{
    if(low < high)
    {
        int mid = partion(array, low, high);
        qSort(array, low, mid - 1 );
        qSort(array, mid+1, high);
    }
}

void quickSort(int array[],int length)
{
    qSort(array, 0, length - 1);
}
// 归并排序
void merge(int *src,int *dsc, int low ,int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;// 此处犯错了

    while (i <= mid && j <= high)
    {
        if(src[i] < src[j]) {
            dsc[k++] = src[i++];
        }else
        {
            dsc[k++] = src[j++];
        }
    }
    while (i <= mid) {
        dsc[k++] = src[i++];
    }

    while (j <= high) {
        dsc[k++] = src[j++];
    }

}
void mSort(int *src, int *dsc, int low, int high ,int length)
{
    if(low == high)
    {
        dsc[low] = src[low];
    }else{

        int mid = (low + high) / 2;
        int *space = (int *)malloc(sizeof(int) * length);
        if(space != NULL)
        {
            mSort(src,space, low, mid,length);
            mSort(src, space, mid+1, high,length);
            merge(space, dsc,low, mid, high);
        }
        free(space);
    }
}
void mergeSort(int *array, int length)
{
    mSort(array,array, 0, length - 1,length);
}

void sortTest(void)
{
    int array1[10] = {21,32,20,8,12,54,23,43,12,67};
    //printArray(array1, 10);
    shellSort(array1, 10);
    printArray(array1, 10);

    int array2[10] = {21,32,20,8,12,54,23,43,12,67};
    //printArray(array2, 10);
    bubbleSort(array2, 10);
    printArray(array2, 10);

    int array3[10] = {21,32,20,8,12,54,23,43,12,67};
    //printArray(array3, 10);
    insertionSort(array3, 10);
    printArray(array3, 10);

    int array4[10] = {21,32,20,8,12,54,23,43,12,67};
    //printArray(array4, 10);
    selectionSort(array4, 10);
    printArray(array4, 10);

    int array5[10] = {21,32,20,8,12,54,23,43,12,67};
    //printArray(array4, 10);
    quickSort(array5, 10);
    printArray(array5, 10);

    int array6[10] = {21,32,20,8,12,54,23,43,12,67};
    //printArray(array4, 10);
    mergeSort(array6, 10);
    printArray(array6, 10);
}

