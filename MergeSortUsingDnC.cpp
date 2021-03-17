#include<iostream>
#include <chrono>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
using namespace std::chrono;;

//Merge Sort

void mergeA(int arr[], int low, int mid, int high)
{
    int l1 = mid - low + 1;
    int l2 = high - mid;
	int lf[l1];
	int rf[l2];
	for (int i = 0; i < l1; i++)
		lf[i] = arr[low + i];
	for (int j = 0; j < l2; j++)
		rf[j] = arr[mid + 1 + j];
	int l = 0, r = 0, index = low;
	while (l < l1 && r < l2)
	{
		if (lf[l] <= rf[r]) {
			arr[index] = lf[l];
			l++;
		}
		else {
			arr[index] = rf[r];
			r++;
		}
		index++;
	}
	while (l < l1) {
		arr[index] = lf[l];
		index++;
		l++;
	}
	while (r < l2) {
		arr[index] = rf[r];
		index++;
		r++;
	}
}

void mergeSort(int arr[], int low, int high)
{
	if (high > low)
	{
		int mid = low + (high-low)/2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		mergeA(arr, low, mid, high);
	}
}

// MOM Merge Sort

int partitionMOM(int* arr, int low, int high, int x) {
	int i;
	for (i = low; i < high; i++)
		if (arr[i] == x)
			break;
	swap(arr[i], arr[high]);
	i = low;
	for (int j = low; j <= high - 1; j++) {
		if (arr[j] <= x) {
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[high]);
	return i;
}

int medianMOM(int* arr, int n) {
	sort(arr, arr + n);
	return arr[n / 2];
}

int kSmallest(int* arr, int low, int high, int k) {
	if (k > 0 && k <= high - low + 1) {
		int n = high - low + 1;
		int i, * median = new int[(n / 5) + 1];
		for (i = 0; i < n / 5; i++)
			median[i] = medianMOM(arr + low + i * 5, 5);
		if (i * 5 < n) {
			median[i] = medianMOM(arr + low + i * 5, n % 5);
			i++;
		}
		int medofMed = (i == 1) ? median[i - 1] : kSmallest(median, 0, i - 1, i / 2);

		int pos = partitionMOM(arr, low, high, medofMed);

		if (pos - low == k - 1)
			return arr[pos];
		if (pos - low > k - 1)
			return kSmallest(arr, low, pos - 1, k);
		return kSmallest(arr, pos + 1, high, k - pos + low - 1);
	}
	return INT_MAX;
}

void MOMmergeSort(int arr[], int low, int high)
{
	if (high > low)
	{
	    int n = high - low + 1;
		int mom = kSmallest(arr,low,high,n/2);
		mergeSort(arr, low, mom);
		mergeSort(arr, mom + 1, high);
		mergeA(arr, low, mom, high);
	}
}


void printArray(int* arr, int len) {
	cout << "Array elements after sorting - \n";
	for (int i = 0; i < len; i++) cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = { 1000, 10, 7, 8, 9, 30, 900, 1, 5, 6, 20 };
	int sec[1005];
	for (int i = 0; i < 1005; i++) sec[i] = rand() % 1000;
	int len = sizeof(arr) / sizeof(arr[0]);
	int len2 = sizeof(sec) / sizeof(sec[0]);
	auto start = high_resolution_clock::now();
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	int c;
	cout << "Select your Choice - \n";
	do {
		cout << "\n1)MergeSort  \n2)Median of Medians \n3)Exit\n";
		cin >> c;
		switch (c) {

		case 1:
			start = high_resolution_clock::now();
			mergeSort(sec, 0, len2 - 1);
			stop = high_resolution_clock::now();
			duration = duration_cast<microseconds>(stop - start);
			printArray(sec, len2);
			cout << "Time taken by function: " << duration.count() << " microseconds";
			break;


		case 2:
			start = high_resolution_clock::now();
			MOMmergeSort(arr, 0, len - 1);
			stop = high_resolution_clock::now();
			duration = duration_cast<microseconds>(stop - start);
			printArray(arr, len);
			cout<<"Median of Median is: "<<kSmallest(arr,0,len-1,len/2)+1<<" \n";
			cout << "Time taken by function: " << duration.count() << " microseconds";
			break;

		case 3:
			c = 0;
			break;
		}
	} while (c != 0);
}
