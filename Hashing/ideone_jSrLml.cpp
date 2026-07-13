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

// 12
// ab ab ba ba ee ee ee ff ff ff gg gg

vector<string> a;
void consistency(int n) {
	
	unordered_map<string, int> mp, aa;
	int ans = 0;
	
	for(auto& w : a){
		string rev(w);
		swap(rev[0], rev[1]);
		
		if(w[0] == w[1]){
			aa[w]++;
			continue;
		}
		
		if(mp.count(rev)){
			mp[rev]--;
			if(mp[rev]==0) mp.erase(rev);
			ans += 2;
		}
		else{
			mp[w]++;
		}
	}
	
	int odd = 0;
	for(auto& it : aa){
		int ct = it.second;
		if(ct & 1){
			odd++;
			ans += ct-1;
		}
		else ans += ct;
	}
	
	if(odd) ans++;
	
	cout << 2*ans << endl;


}

void solve() {
    
    int n;
    cin >> n;
    a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];

    consistency(n) ;

}





int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}