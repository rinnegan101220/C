#include<bits/stdc++.h> 
using namespace std;  
// Tra ve nCr% p. Trong chuong tr�nh dua tr�n �inh l� Lucas n�y, h�m n�y chi duoc goi cho n <p v� r <p. 
int nCrModpDP(int n, int r, int p) { 
    // Mang C se luu tru h�ng cuoi c�ng cua tam gi�c pascal o cuoi. V� muc cuoi c�ng cua h�ng cuoi c�ng l� nCr
    int C[r+1]; 
    memset(C, 0, sizeof(C)); 
    C[0] = 1; // H�ng tr�n c�ng cua Tam gi�c Pascal
    // Tam gi�c tu tr�n xuong duoi
    for (int i = 1; i <= n; i++) { 
        // �ien c�c muc cua h�ng hien tai bang c�ch su dung gi� tri h�ng truoc d�  
        for (int j = min(i, r); j > 0; j--) 
            // nCj = (n-1)Cj + (n-1)C(j-1); 
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
}  
// H�m dua tr�n dinh l� Lucas tra ve nCr% p
// H�m n�y hoat d�ng nhu chuyen doi th�p ph�n sang nhi ph�n
// H�m de quy. �au ti�n ch�ng ta t�nh c�c chu s� cu�i cua n v� r trong co so p, sau d� lap lai cho c�c chu so c�n lai
int nCrModpLucas(int n, int r, int p) { 
   if (r==0) 
      return 1; 
    // T�nh c�c chu so cuoi cua n v� r trong co so p 
   int ni = n%p, ri = r%p; 
   // T�nh ket qua cho c�c chu so cuoi duoc t�nh o tr�n v� cho c�c chu so c�n lai. Nh�n hai ket qua v� t�nh ket qua cua ph�p nh�n trong modulo p.
   return (nCrModpLucas(n/p, r/p, p) *  // C�c chu so cuoi cua n v� r 
           nCrModpDP(ni, ri, p)) % p;   // C�c chu so c�n lai
}  
int main(){
    int T;
    cin >> T;
    long long p=pow(10,9)+7;
    while (T--){
        int n,r;
        cin >> n >>r;
        cout << nCrModpLucas(n, r, p) << endl;
    }
    return 0;
}

