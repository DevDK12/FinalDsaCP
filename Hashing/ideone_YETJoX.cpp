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

int consistency(int n, int k){

	unordered_map<int,int> mp;
	int len = INF;
	for(int i=0; i<n; i++){
		if(mp.count(k-a[i])){
			len = min(len, i - mp[k-a[i]] + 1);
		}
		mp[a[i]] = i;
	}
	return len;
}



int followup(int n, int k){

	unordered_map<int,int> mp;
	int len = 0;
	for(int i=0; i<n; i++){
		if(mp.count(k-a[i])){
			len = max(len, i - mp[k-a[i]] + 1);
		}
		
		if(!mp.count(a[i])) mp[a[i]] = i;
	}
	return len;
}























int practice(int n, int k){


    return 0;
}





void solve() {
    
    int n, k;
    cin>> n >> k;
    
    a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    cout << consistency(n, k) << " " << followup(n, k) << endl;


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