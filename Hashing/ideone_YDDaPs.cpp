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

// dddeeeeeeeeeeepp deep


void consistency(string s, string t) {
	int n = s.size();
	int m = t.size();
	
	vector<int> f(26, 0), g(26, 0);
	for(int i=0; i<n; i++){
		f[s[i]-'a']++;
	}
	
	for(int i=0; i<m; i++){
		g[t[i]-'a']++;
	}
	
	int ans = INF;
	for(int i=0; i<26; i++){
		if(g[i] == 0) continue;
		
		//* if any s freq < t freq then t can't fit in s => return 0
		if(f[i] < g[i]){
			cout << 0 << endl;
			return;
		}
		f[i] = f[i]/g[i];
		
		ans = min(ans, f[i]);
	}
	
	cout << ans << endl;
	
}

void solve() {
    
	string s, t;
	cin >> s >> t;
    consistency(s, t) ;

}





int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}