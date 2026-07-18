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
// 8 
// 1 -2 5 2 6 10 4 7





vector<int> a;

//* variant 2 : No condition (i.e i == j == k allowed )

int bruteforce(int n){
	int ans = -INF;
	
	for(int i = 0; i < n; i++) {
	    for(int j = 0; j < n; j++) {
	        for(int k = 0; k < n; k++) {
	            int curr = abs(a[i] - a[j] - a[k]) + abs(i - j - k);
	            ans = max(ans, curr);
	        }
	    }
	}
	return ans;
}



int consistency(int n){
	
	int max1 = -INF;
	int max2 = -INF;
	
	int min1 = INF;
	int min2 = INF;
	
	for(int i=0; i<n; i++){
		int add = a[i] + i;
		int dif = a[i] - i;
		
		max1 = max(max1, add);
		min1 = min(min1, add);
		
		max2 = max(max2, dif);
		min2 = min(min2, dif);
		
	}
	
	int ans = max( {max1 - 2*min1, max2 - 2*min2, 2*max1 - min1, 2*max2 - min2 });
	

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
    
    cout << bruteforce(n) << " " << consistency(n) << endl;


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