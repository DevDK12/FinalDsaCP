#include <bits/stdc++.h>
using namespace std;
#define int              long long int
#define double           long double
#define print(a)         for(auto x : a) cout << x << " "; cout << endl


const int M = 1000000007;
const int N = 3e5+9;
const int INF = 2e9+1;
const int LINF = 2000000000000000001;

inline int power(int a, int b, int mod=M) {
    int x = 1;
    a %= mod;
    while (b) {
        if (b & 1) x = (x * a) % mod; 
        a = (a * a) % mod;
        b >>= 1;
    }
    return x;
}


//_ ***************************** START Below *******************************

// 2
// 15
// 1 2 4 5 3 2 7 8 2 9 1 0 3 4 2 
// 4
// 1 2 1 0



vector<int> a;

//* Piviot j (in i<j>k)

int consistency1(int n){
	
	int ans = 0;
	for(int j=1; j<=n-2; j++){
		int i = j-1;
		while(i>=0 && a[i] < a[i+1]) i--;
		int ct1 = j-i;
		
		int k = j+1;
		while(j<n && a[k] < a[k-1]) k++;
		int ct2 = k-j;
		
		
		ans += (ct1-1)*(ct2-1);
		
	}
	
	return ans;

}








int consistency2(int n){
	
	int ans = 0;
	
	//* prefix Longest increasing subarray ending at i
	vector<int> pLIS(n, 1);
	
	//* Suffix Longest decreasing subarray starting  at i
	vector<int> sLIS(n, 1);
	
	for(int i=1; i<n; i++){
		if(a[i] > a[i-1]){
			pLIS[i] = pLIS[i-1] + 1;
		}
	}
	
	for(int i=n-2; i>=0; i--){
		if(a[i] > a[i+1]){
			sLIS[i] = sLIS[i+1] + 1;
		}
	}
	
	for(int j=1; j<=n-2; j++){
		ans += (pLIS[j]-1) * (sLIS[j]-1);
	}
	
	return ans;

}






















int practice(int n){
	

}





void solve() {
    
    int n;
    cin>> n;
    
    a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    cout << consistency1(n) << " " << consistency2(n) << endl;
	// cout << practice(n) << endl;

}





int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}