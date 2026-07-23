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


// 6 4
// abcaab
// 1 1
// 2 5
// 3 6
// 1 6


string a;
vector<vector<int>> qr;

vector<int> consistency(int n, int q){
	
	vector<vector<int>> f(n+1, vector<int>(26, 0));
	
	for(int i=0; i<n; i++){
		
		for(int j=0; j<26; j++){
			f[i+1][j] = f[i][j];
		}
		
		f[i+1][a[i] - 'a']++;
	}
	
	vector<int> ans;
	
	for(auto& qq : qr){
		int L = qq[0];
		int R = qq[1];
			
		int val = 0;
		for(int j=0; j<26; j++){
			
			int ct = f[R][j] - f[L-1][j];
			
			val += (ct * (ct+1))/2;
		}
		ans.push_back(val);
		
	}
	
	return ans;

}














// string a;
// vector<vector<int>> qr;

vector<int> practice(int n, int q){
	
}





void solve() {
    
    int n, q;
    cin>> n >> q;
    	
    cin >> a;
    
    qr.resize(q);
    for(int i=0; i<q; i++) {
    	int x, y;
    	cin >> x >> y;
    	qr[i] = {x,y};
    }
    
    auto ans = consistency(n, q);
    for(auto& t : ans) cout << t << " "; cout << endl;
    
    // auto ans2 = practice(n, q);
    // for(auto& p : ans2) cout << p << " "; cout << endl;
    // cout << endl;


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