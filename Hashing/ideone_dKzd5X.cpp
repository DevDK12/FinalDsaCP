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

// 2 2
// cdab dcba
// abcd abcd




vector<string> a;
vector<string> b;

vector<string> consistency(int n){
	
	vector<string> ans(n, "No");
	
	for(int i=0; i<n; i++){
		auto x = a[i];
		auto y = b[i];
		
		if(x.size() != y.size()) continue;
		int k = x.size();
		
		vector<int> even(26, 0), odd(26, 0);
		
		for(int j=0; j<k; j+=2)	even[x[j]-'a']++;
		for(int j=0; j<k; j+=2)	even[y[j]-'a']--;
		
		for(int j=1; j<k; j+=2)	odd[x[j]-'a']++;
		for(int j=1; j<k; j+=2)	odd[y[j]-'a']--;
		
		bool isValid = true;
		for(int j=0; j<26; j++){
			if(even[j] > 0) isValid = false;
			if(odd[j] > 0) isValid = false;
		}
		
		if(isValid) ans[i] = "Yes";
	}
	
	return ans;
}















vector<string> practice(int n){


}





void solve() {
    
    int m, n;
    cin>> m >> n;
    
    a.resize(m);
    for(int i=0; i<m; i++) cin >> a[i];
    
    b.resize(n);
    for(int i=0; i<n; i++) cin >> b[i];
    
    auto ans = consistency(n);
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