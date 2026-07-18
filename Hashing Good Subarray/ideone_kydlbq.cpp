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

// 9 3
// 1 1 -1 4 -1 0 -1 2 -1  




vector<int> a;

vector<int> consistency(int n, int k) {
	
	unordered_map<int,int> mp = {{0, -1}};
	int sum = 0;
	int maxLen = 0;
	
	for(int i=0; i<n; i++){
		
		sum += a[i];
		if(mp.count(sum-k)){
			maxLen = max(maxLen, i-mp[sum-k]);
		}
		
		if(!mp.count(sum)) mp[sum] = i;
	}
	
	int e=0, s=0;
	sum = 0;
	while(e<n){
		sum += a[e];
		if(e-s+1<maxLen) e++;
		else{
			if(sum == k){
				return {s+1, e+1};
			}
			sum -= a[s];
			e++;
			s++;
		}
	}
	
	return {};
}

















vector<int> practice(int n, int k){


}




void solve() {
    
	int n, k;
	cin >> n >> k;
	
	a.resize(n);
	for(int i=0; i<n; i++) cin >> a[i];
	
    auto ans = consistency(n, k) ;
    if(ans.size() == 0){
    	cout << "-1" << endl;
    	return;
    }
    for(auto& t : ans) cout << t << " "; cout << endl;

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