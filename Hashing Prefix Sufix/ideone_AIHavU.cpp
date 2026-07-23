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

// 3
// 3
// abc ade abc
// 3
// abc ade bbc
// 5
// aabc aade aabca abc acd



vector<string> a;

vector<int> consistency(int n){
	
	unordered_map<int, unordered_map<char,int> > mp;
	vector<int> ans(n);
	
	for(int i=n-1; i>=0; i--){
		string word = a[i];
		
		for(int j=0; j<word.size(); j++){
			char ch = word[j];
			
			ans[i] += mp[j][ch];
			mp[j][ch]++;
		}
		
	}
	
	return ans;
}















vector<int> practice(int n){


    
}





void solve() {
    
    int n;
    cin>> n;
    
    a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    auto ans = consistency(n);
    
    for(auto& t : ans) cout << t << " "; cout << endl;


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