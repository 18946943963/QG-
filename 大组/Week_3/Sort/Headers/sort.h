#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>

void InsertSort(int* arr, int n);
void merge(int arr[], int start, int mid, int end);
void MergeSort(int arr[], int start, int end);
void Quick_Sort(int *arr, int begin, int end);
void CountSort(int* arr, int n);
int maxBit(int data[],int n);
void radixsort(int data[],int n);

#endif
