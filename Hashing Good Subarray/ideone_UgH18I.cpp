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

// 8 15
// 10 5 2 7 1 9 8 7


vector<int> a;

int consistency(int n, int k) {
	
	unordered_map<int,int> mp = {{0, -1}};
	int sum = 0;
	int minLen = n;
	for(int i=0; i<n; i++){
		sum += a[i];
		if(mp.count(sum-k)){
			int l = mp[sum-k];
			int len = i-l;
			minLen = min(minLen, len);
		}
		mp[sum] = i;
	}
	
	int ans = 0;
	int s = 0, e = 0;
	sum = 0;
	while(e<n){
		sum += a[e];
		if(e-s+1<minLen){
			e++;
		}
		else{
			if(sum == k) ans++;
			sum -= a[s];
			s++;
			e++;
		}
	}
	
	return ans;
}















int practice(int n){


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
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}