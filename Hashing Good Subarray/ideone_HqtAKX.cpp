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
// 6
// 1 8 10 8 -5 8
// 9
// 2 8 -20 8 10 -4 2 8 10





vector<int> a;

int consistency(int n){
	

	int sum = 0;
	int lastSum = 0;
	
	unordered_map<int,int> mp;
	
	int ans = -INF;
	
	for(int i=0; i<n; i++){
		sum += a[i];
		if(i-1>=0) lastSum += a[i-1];
		
		if(mp.count(a[i])){
			ans = max(ans, sum - mp[a[i]]);
			
			mp[a[i]] = min(mp[a[i]], lastSum);
		}
		else {
			mp[a[i]] = lastSum;
		}
		
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
    
    cout << consistency(n) << endl;
    
    // cout << consistency(n) << " " << practice(n) << endl;


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