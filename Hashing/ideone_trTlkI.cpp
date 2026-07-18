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




vector<int> a;

int consistency1(int n){
	
	int ans = 0;
	int maxDifSoFar = a[0] - a[1];
	
	int maxi = a[0];
	
	for(int k=2; k<n; k++){
		
		ans = max(ans, maxDifSoFar * a[k]);
		
		maxi = max(maxi, a[k-1]);
		maxDifSoFar = max(maxDifSoFar, maxi - a[k] );
		
	}	
	
	
	return ans;
}







//* Pivot j : prefix && sufix 

int consistency2(int n){
	
	int ans = 0;
	vector<int> sufixMaxi(n+1);
	for(int i=n-1; i>=0; i--){
		sufixMaxi[i] = max(sufixMaxi[i+1], a[i]);
	}
	
	int maxi = a[0];
	
	for(int j=1; j<=n-2; j++){
		
		int rightMaxi = sufixMaxi[j+1];
		
		int val = (maxi - a[j]) * rightMaxi;
		
		maxi = max(maxi, a[j]);
		
		ans = max(ans, val);
		
	}	
	
	
	return ans;
}



























int practice(int n){


    return 0;
}





void solve() {
    
    int n;
    cin>> n;
    
    a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    cout << consistency1(n) << " " << consistency2(n) << endl;


}





int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}