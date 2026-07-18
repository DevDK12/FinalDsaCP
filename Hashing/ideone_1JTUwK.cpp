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

// 4
// 4 1
// 1 1 1 2
// 8 1
// 1 1 1 2 2 2 1 2
// 2 0
// 1 2
// 10 0
// 1 1 2 2 3 3 3 3 3 3


vector<int> a;

int consistency(int n, int k){
	
	unordered_map<int,int> mp;
	
	for(int i=0; i<n; i++){
		mp[a[i]]++;
	}
	
	int ans = 0;
	
	for(auto& t : mp){
		int x = t.first;
		int ct = t.second;
		
		if(k==0){
			if(ct >= 2) ans++;
		}
		else{
			if(mp.count(x+k)){
				ans++;
			}
		}
	}

    return ans;
}















int practice(int n, int k){


}





void solve() {
    
    int n, k;
    cin>> n >> k;
    
    a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    cout << consistency(n, k) << endl;
    
    // cout << consistency(n, k) << " " << practice(n, k) << endl;


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