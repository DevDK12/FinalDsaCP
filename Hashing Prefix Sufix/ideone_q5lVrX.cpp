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




vector<int> a;

//* prefix sum 

int consistency1(int n, int x, int y){
	
	int ans = INF;
	
	for(int k=0; k<y; k++){
		
		vector<int> prefix(n/y+2);
		
		for(int i=k, j=1; i<n; i+=y, j++){
			prefix[j] = prefix[j-1] + a[i];
			
			if(j-x < 0) continue;
			
			int sum = prefix[j] - prefix[j-x];
			
			ans = min(ans, sum);
		}
	}

    return ans;
}



//* SLiding window

int consistency2(int n, int x, int y){
	
	int ans = INF;
	
	for(int k=0; k<y; k++){
		
		int sum = 0;
		for(int i=k; i<n; i+=y){
			sum += a[i];
			
			if(i >= y*x){
				sum -= a[i-y*x];
			}
			
			if(i >= y*(x-1)){
				ans = min(ans, sum);
			}
		}
	}
	
	return ans;
}















int practice(int n, int x, int y){


}










void solve() {
    
    int n, x, y;
    cin>> n >> x >> y;
    
    a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    cout << consistency1(n, x, y) << " " <<  consistency2(n, x, y) << endl;
    
    // cout << practice(n, x, y) << endl;


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
