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
 
// 1
// 6
// 1 3 5 4 2 6
// 3 4 5 2 1 6


vector<int> a;
vector<int> b;

vector<int> consistency(int n) {
 
	unordered_map<int,int> freq;
	vector<int> prefix(n, 0);
 
	for(int i=0; i<n; i++){
		if(i-1>=0)	prefix[i] = prefix[i-1];
		if(a[i] == b[i]){
			prefix[i]++;
		}
		else{
 
			if(freq.count(a[i]) ){
				prefix[i]+=1;
			}
			if( freq.count(b[i]) ){
				prefix[i]+=1;
			}
		}
		freq[a[i]]++;
		freq[b[i]]++;
 
	}
 
    
    return prefix;
}
 
 
 
 
 









 
 
 
 
 
 
 
 
 
 
 
vector<int> practice(int n){
 
 
}
 
 
 
 
 
void solve() {
 
    int n;
    cin >> n;
    
    a.resize(n);
    b.resize(n);
    
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    
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