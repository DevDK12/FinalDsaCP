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

// 2
// 12
// 2 -3 6 0 4 -5 6 0 2 1 -8 10
// 3
// 0 0 0




vector<int> a;

int consistency1(int n){
	
	int total = 0;
	for(int i=0; i<n; i++){
		total += a[i];
	}
	if(total % 3 != 0) return 0;
	
	int x = total/3;
	
	int ans = 0;
	int sum = 0;
	
	for(int i=0; i<=n-3; i++){
		sum += a[i];
		
		if(sum != x) continue;
		
		int sum2 = 0;
		for(int j=i+1; j<=n-2; j++){
			sum2 += a[j];
			if(sum2 == x) ans++;
		}
	}
	
	return ans;
}



int consistency2(int n){
	
	int total = 0;
	for(int i=0; i<n; i++) total += a[i];
	
	if(total % 3 != 0) return false;
	int x = total/3;
	
	
	unordered_map<int,int> prefixSum;
	
	int ans = 0;
	int sum = 0;
	
	for(int i=0; i<=n-2; i++){
		sum += a[i];
		
		if( !(sum & 1) && sum == 2*x ){
			ans += prefixSum[sum/2];
		}
		prefixSum[sum]++;
	}
	
	return ans;
	
}






int consistency3(int n){
	
	int total = 0;
	for(int i=0; i<n; i++){
		total += a[i];
	}
	if(total % 3 != 0) return 0;
	
	int x = total/3;
	
	int ans = 0;
	
	int count_x = 0;
	int sum = 0;
	
	for(int i=0; i<=n-2; i++){
		sum += a[i];
		
		if(sum == 2*x) ans += count_x;
		if(sum == x) count_x++;
	}
	
    return ans;
	
}

























int practice(int n){
	

}





void solve() {
    
    int n;
    cin>> n;
    
    a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    cout << consistency1(n) << " " << consistency2(n) << " " << consistency3(n) << endl;
	
	// cout << practice(n) << endl;

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