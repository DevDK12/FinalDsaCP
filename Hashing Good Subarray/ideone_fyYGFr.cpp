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

// 5
// 9
// -3 -3 -3 0 -3 -3 -3 0 0
// 5
// 9 3 3 3 9
// 6
// 4 5 3 3 3 9
// 5
// 1 2 3 4 5
// 6
// -4 4 0 0 -8 -4





vector<int> a;

//* Search {P[R], A[R+1]} in past map of {P[L]+A[L] , A[L] }
int consistency1(int n) {
	
	map<pair<int,int>,int> mp;
	
	int ans = 0;
	int sum = 0;
	for(int i=0; i<n-1; i++){
		sum += a[i];
		
		if(mp.count({sum , a[i+1]})){
			ans += mp[{sum, a[i+1]}];
		}
		
		mp[{sum+a[i], a[i]}]++;
	}
	
	return ans;

}



//* Search {P[R]-A[R+1]}, A[R+1]  in past map of {P[L], A[L] }

int consistency2(int n) {
	
	map<pair<int,int>,int> mp;
	
	int ans = 0;
	int sum = 0;
	for(int i=0; i<n-1; i++){
		sum += a[i];
		
		if(mp.count({sum-a[i+1], a[i+1]})){
			ans += mp[{sum-a[i+1], a[i+1]}];
		}
		
		mp[{sum, a[i]}]++;
	}
	
	return ans;

}


//* Search {P[R]-2*A[R], A[R]} in past map of {P[L] , A[L] }
int consistency3(int n) {
	
	map<pair<int,int>,int> mp;
	
	int ans = 0;
	int sum = 0;
	int lastSum = 0;
	
	for(int i=0; i<n; i++){
		sum += a[i];
		if(i-1>=0) lastSum += a[i-1];
		
		
		if(mp.count( {sum - 2*a[i] , a[i]} )  ){
			ans += mp[{sum-2*a[i], a[i]}];
		}
		
		if(i-1>=0)	mp[{lastSum, a[i-1]}]++;
	}
	
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
    
    cout << consistency1(n) << " " << consistency2(n) << " " << consistency3(n) << endl;


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