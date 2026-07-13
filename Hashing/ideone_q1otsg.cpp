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
// 4
// 51 71 17 42
// 3
// 42 33 60
// 3
// 51 32 43 




vector<int> a;

int digitSum(int x){
	int sum = 0;
	while(x){
		sum += x%10;
		x /= 10;
	}
	return sum;
}

int consistency(int n) {
	
	unordered_map<int,int>mp;
	
	int ans = -1;
	for(int i=0; i<n; i++){
		int sum = digitSum(a[i]);
		
		if(mp.count(sum)){
			ans = max(ans, a[i] + mp[sum]);
		}
		mp[sum] = max(mp[sum], a[i]);
	}
	

	return ans;

}










int practice(int n){
	
	
	return 0;
}



void solve() {
    
    int n;
    cin >> n;
    
    a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];

    cout << consistency(n) << endl ;

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