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
// 8
// 18 5 4 3 2 1 8 10
// 6
// 5 4 3 2 1 8



vector<int> a;

bool consistency1(int n){
	int count = 0;
	
	
	for(int j = 1; j<n-1; j++){
		int ct1 = 0;
		int i =j-1;
		while(i>=0){
			if(a[i] < a[j]) ct1++;
			i--;
		}
		
		int ct2 = 0;
		int k =j+1;
		
		while(k<n){
			if(a[j] < a[k]) ct2++;
			k++;
		}
		
		count += ct1 * ct2;
	}
	
	if(count == 0) return false;
	return true;

}




bool consistency2(int n){
	int count = 0;
	
	vector<int> prefixMin(n+1, INF);
	for(int i=0; i<n; i++){
		prefixMin[i+1] = min(prefixMin[i-1], a[i]);
	}
	
	vector<int> sufixMax(n+1, -INF);
	for(int i=n-1; i>=0; i--){
		sufixMax[i] = max(sufixMax[i+1], a[i]);
	}
	
	for(int j = 1; j<=n-2; j++){
		if(a[j] > prefixMin[j] && a[j] < sufixMax[j+1]) return true;;
		
	}
	
	return false;

}







bool consistency3(int n){
	int count = 0;
	
	vector<int> sufixMax(n+1, -INF);
	for(int i=n-1; i>=0; i--){
		sufixMax[i] = max(sufixMax[i+1], a[i]);
	}
	
	int mini = a[0];
	for(int j = 1; j<=n-2; j++){
		if(a[j] > mini && a[j] < sufixMax[j+1]) return true;;
		
		mini = min(mini, a[j]);
	}
	
	return false;
}
























bool practice(int n){


    return 0;
}





void solve() {
    
    int n;
    cin>> n;
    
    a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    cout << consistency1(n) << " " << consistency2(n) << endl;


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