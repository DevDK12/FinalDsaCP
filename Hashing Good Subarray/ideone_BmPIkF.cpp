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

// 1
// 8 5
// 1 5 -5 8 8 8 10 15




vector<int> a;

int consistency(int n, int k){

	unordered_map<int,int> mp;
	int sum = 0;
	int lastSum = 0;
	
	int ans = -INF;
	
	for(int i=0; i<n; i++){
		int x = a[i];
		sum += x;
		if(i-1>=0) lastSum += a[i-1];
		
		int dif1 = x + k;
		int dif2 = x - k;
		
		if(mp.count(x+k) ){
			ans = max(ans, sum - mp[x+k]);	
		}
		if(mp.count(x-k) ){
			int pastSum = mp[dif2];
			ans = max(ans, sum - mp[x-k]);	
		}
		
		if(mp.count(x)){
			mp[x] = min(mp[x], lastSum);
		}
		else mp[x] = lastSum;
	}
	
	return ans;
}















int practice(int n, int k){


    return 0;
}





void solve() {
    
    int n, k;
    cin>> n >> k;
    
    a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    cout << consistency(n, k) << endl;


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