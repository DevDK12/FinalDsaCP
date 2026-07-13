#include <bits/stdc++.h>
using namespace std;
#define int              long long int
#define double           long double
inline int power(int a, int b) {
    int x = 1;
    while (b) {
        if (b & 1) x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}


const int M = 1000000007;
const int N = 3e5+9;
const int INF = 2e9+1;
const int LINF = 2000000000000000001;

//_ ***************************** START Below *******************************

// 1
// 4
// 4 2 1 2


//* Alternatve way : 
//* freqMap = { 
//*      x -> c1
//* 	 y -> c2
//* 	... -> ...
//* }

//* Ans = (1 + 2 + 3 + ... c1-1)   +  (1 + 2+ ... c2-1)   +  ....
//* 	ans = c1(c1-1)/2 + c2(c2-1)/2 

//* This is what we do each time with =>  
//* 	ans += mp[val]	
//* 	map[val]++


vector<int> a;
void consistency(int n) {
	
	unordered_map<int,int> mp;
	int ans = 0;
	
	for(int i=1; i<=n; i++){
		int val = a[a[a[i]]];
		if(mp.count(val)){
			ans += mp[val];
		}
		
		mp[val]++;
	}
	
	cout << ans << endl;
	
}

void solve() {
    
    int n;
    cin >> n;
    a.resize(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];
    consistency(n) ;

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