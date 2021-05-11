#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono

void merge(int arr[], int start, int mid, int end)
{
    int len1 = mid - start + 1;
    int len2 = end - mid;
    int leftArr[len1], rightArr[len2];
    
    for (int i = 0; i < len1; i++)
    leftArr[i] = arr[start + i];
    
    for (int j = 0; j < len2; j++)
    rightArr[j] = arr[mid + 1 + j];
    
    int i, j, k;
    i = 0;
    j = 0;
    k = start;
    
    while (i < len1 && j < len2)
    {
        if (leftArr[i] <= rightArr[j])
            {
                arr[k] = leftArr[i];
                i++;
            } 
        else 
            {
                arr[k] = rightArr[j];
                j++;
            }
        k++;
    }
    
    while (i < len1)
    {
        arr[k] = leftArr[i];i++;
        k++;
    }
    
    while (j < len2)
    { arr[k] = rightArr[j];j++;
        k++;
    }
}


void mergeSort(int arr[], int start, int end)
{
    if (start < end)
     {
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
        
     }
}

void display(int arr[], int size)
{
        
    for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    
    int arr[1000] ;
    int n;

    cout<"\nEnter the value of n "
    cin>>n;
    
    for (int i=0; i<n; i++)
        arr[i] = (rand()%1000);
        
    auto startL = high_resolution_clock::now();
    mergeSort(arr, 0, n - 1);
    auto stopL = high_resolution_clock::now();
    auto durationL = duration_cast<microseconds>(stopL - startL);
    
    cout << "Time Required for Unsorted Array: " << durationL.count() << "microseconds" << endl;
    
    int arr1[100];
    for (int i =0; i<n; i++)
        arr1[i] = arr[i];auto start = high_resolution_clock::now();
        
    mergeSort(arr1, 0, n - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    cout << "\nTime Required for Sorted Array: " << duration.count() << "microseconds" << endl;
    cout << endl;
}
