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


// 9 4
// 1 5 0 3 4 1 2 2 3



vector<int> a;
int consistency(int n, int k) {
	
	int ans = 0;
	unordered_map<int,int> freq;
	for(int i=0; i<n; i++){
		if(freq.count(k-a[i])){
			ans += freq[k-a[i]];
		}
		freq[a[i]]++;
	}

	return ans;
}















int practice(int n, int k) {
	
	int ans = 0;

	
	return ans;	
}

void solve() {
    
    int n, k;
    cin >> n >> k;
    a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    cout << consistency(n, k) << endl ;

    // cout << consistency(n, k) << " -> " << practice(n, k) << endl ;
}





int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
