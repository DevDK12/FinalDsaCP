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
// 2
// 0 1
// 3
// 0 1 0
// 9
// 0 1 1 1 1 1 0 0 0
// 8
// 0 0 1 0 0 0 1 1




vector<int> a;

int consistency(int n) {
	
	int ones = 0;
	int zeroes = 0;
	
	unordered_map<int, int> mp = {{0, -1}};
	
	int ans = 0;
	
	for(int i=0; i<n; i++){
		if(a[i] == 0) zeroes++;
		else ones++;
		
		int dif = zeroes - ones;
		
		if(mp.count(dif)){
			int l = mp[dif];
			int len = i-l;
			ans = max(ans, len);
		}
		else mp[dif] = i;
		
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
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}