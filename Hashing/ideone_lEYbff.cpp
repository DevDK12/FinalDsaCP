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
// 5
// 0 0 0 0 0 
// 12
// 2 -3 6 0 4 -5 6 0 2 3 4 1
// 11
// 8 -3 1 -6 4 -4 7 -7 2 -2 0





vector<int> a;


int consistency1(int n){

	int total = 0;
	for(int i=0; i<n; i++) total += a[i];
	
	if(total % 4 != 0) return false;
	int x = total/4;
	
	unordered_map<int,int> prefixSum, suffixSum;
	
	int sum = 0;
	for(int i=n-1; i>=0; i--){
		sum += a[i];
		suffixSum[sum]++;
	}
		
	
	int ans = 0;
	int leftSum = 0;
	int rightSum = total;

	
	for(int i=0; i<=n-2; i++){
		suffixSum[rightSum]--;
		if(suffixSum[rightSum] == 0) suffixSum.erase(rightSum);
		
		leftSum += a[i];
		rightSum -= a[i];
		

		suffixSum[rightSum]--;

		
		if(leftSum == 2*x){
			ans += prefixSum[leftSum/2] * suffixSum[rightSum/2];
		}
		
		suffixSum[rightSum]++;
		prefixSum[leftSum]++;
	}
	
	return ans;
	
}





int consistency2(int n){

	int total = 0;
	for(int i=0; i<n; i++) total += a[i];
	
	if(total % 4 != 0) return 0;
	
	int x = total/4;
	
	vector<int> suffixWays(n, 0);
	int ct_x = 0;
	int sum = 0;

	for(int i=n-1; i>=0; i--){
		sum += a[i];
		
		if(sum == 2*x){
			suffixWays[i] += ct_x; 
		}		
		if(sum == x){
			ct_x++;
		}
	}
	

	sum = 0;
	ct_x = 0;
	int ans = 0;
	
	for(int i=0; i<=n-3; i++){
		sum += a[i];
		if(sum == 2*x)	ans += ct_x * suffixWays[i+1];
		
		if(sum == x) ct_x++;
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
    
    cout << consistency1(n) << " " << consistency2(n) << endl;
    
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