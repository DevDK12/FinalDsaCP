#include <bits/stdc++.h>
using namespace std;
#define int              long long int
#define double           long double
#define print(a)         for(auto x : a) cout << x << " "; cout << endl


const int M = 1e9+7;
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

// 3
// 3 14 15



const int MOD = 998244353;

vector<int> a;

int consistency(int n){
	
	vector<int> prefix(n+1);
	for(int i=0; i<n; i++){
		prefix[i+1] = (prefix[i] + a[i])%MOD;
	}
	
	int ans = 0;
	for(int i=n-1; i>=0; i--){
		
		int x = a[i];
		int psum = prefix[i];
		
		//* psum = psum * 10^digits
		while(x>0){
			psum = (psum * 10)%MOD;
			x /= 10;
		}
		
		psum = (psum + (i*a[i])%MOD )%MOD;
		
		ans = (ans + psum)%MOD;
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
    
    cout << consistency(n) << endl;


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