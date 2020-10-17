#include <iostream>
using namespace std;
long long maxx(int num1, int num2){
	if (num1>num2){
		return num1;
	}
	else
		return num2;
}
long long minn(int num1, int num2){
	if(num1<num2){
		return num1;
	}
	else
		return num2;
}
long long maxSubarrayProduct(long long arr[],long long n) { 
	long long max_ending_here = 1; 
	long long min_ending_here = 1; 
	long long max_so_far = 1; 
	long long flag = 0; 
	/* C�c gi� tri sau l� duoc duy tr� sau lan lap thu i:
	max lu�n l� 1 hoac mot so duong
	min lu�n l� 1 hoac mot so �m */
	for (int i = 0; i < n; i++) { 
		/* Neu l� duong, cap nhat max.
		Chi cap nhat min neu min l� am */
		if (arr[i] > 0) { 
			max_ending_here = max_ending_here * arr[i]; 
			min_ending_here = minn(min_ending_here * arr[i], 1); 
			flag = 1; 
		} 
		/* Neu phan tu n�y l� 0, th� gtri toi da kh�ng the ket th�c o d�y, 
		tao ca max v� min 0.Gia su: output lu�n >=1 */
		else if (arr[i] == 0) { 
			max_ending_here = 1; 
			min_ending_here = 1; 
		} 	
		/* Neu phan tu �m.
		max c� the l� 1 hoac duong. min c� the l� 1 hoac �m.
		min* Array [i], min tiep theo se l� 1 neu truoc d� max l� 1,
		neu kh�ng min tiep theo se l� truoc max * mang [i] */
		else { 
			int temp = max_ending_here; 
			max_ending_here = maxx(min_ending_here * arr[i], 1); 
			min_ending_here = temp * arr[i]; 
		} 
		if (max_so_far < max_ending_here) 
			max_so_far = max_ending_here; 
	} 
	if (flag == 0 && max_so_far == 1) 
		return 0; 
	return max_so_far; 
}  
void nhap(long long arr[],long long n){
	for(int i=0;i<n;i++)
		cin>>arr[i];
}
int main() { 
	int t; cin>>t;
	while(t--){
		long long n; cin>>n;
		long long arr[n]; 
		nhap(arr,n);
		cout << maxSubarrayProduct(arr, n)<<endl; 
	}
	return 0; 
} 
