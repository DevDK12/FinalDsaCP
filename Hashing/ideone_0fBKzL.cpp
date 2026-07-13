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


// 4 9
// 2 7 11 15 

vector<int> a;

vector<int> consistency(int n, int k){
	
	unordered_map<int, int> mp;
	for(int i=0; i<n; i++){
		if(mp.count(k-a[i])){
			int j = mp[k-a[i]];
			
			return {j, i};
		}
		mp[a[i]] = i;
	}
	return {-1, -1};
}















vector<int> practice(int n, int k){


}





void solve() {
    
    int n, k;
    cin>> n >> k;
    
    a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    auto ans = consistency(n, k);
    
    cout << ans[0] << " " << ans[1] << endl;


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