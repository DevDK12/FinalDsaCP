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
// 8
// 18 3 4 3 2 5 8 10
// 6
// 5 4 3 2 1 8





vector<int> a;

bool consistency(int n){
	int count = 0;
	
	unordered_map<int,int> prefixMap, sufixMap;
	
	for(int i=n-1; i>=1; i--){
		sufixMap[a[i]]++;
	}
	prefixMap[a[0]]++;
	
	for(int j = 1; j<=n-2; j++){
		sufixMap[a[j]]--;
		if(sufixMap[a[j]] == 0) sufixMap.erase(a[j]);
		
		if(prefixMap.count(a[j]-1) && sufixMap.count(a[j]+1)) return true;
		
		prefixMap[a[j]]++;
	}
	
	return false;
}




















bool practice(int n){


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