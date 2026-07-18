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

// 12
// x y p z w b p x y z w b


vector<string> a;

int consistency(int n) {
	
	int x=0, y=0, z=0, w=0, b=0;
	
	map<vector<int>, int> mp = {{{0,0,0,0}, 1}};
	int ans = 0;
	for(int i=0; i<n; i++){
		if(a[i] == "x") x++; 
		if(a[i] == "y") y++; 
		if(a[i] == "z") z++; 
		if(a[i] == "w") w++; 
		if(a[i] == "b") b++; 

		vector<int> diff = {x-y, y-z, z-w, w-b };		
		if(mp.count(diff)){
			ans += mp[diff];
		}
		mp[diff]++;
		
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
