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

// 7
// 8 3 6 1 7 2 5




vector<int> a;

int consistency1(int n){
	
	int ans = 0;
	
	for(int j=1; j<=n-2; j++){
		
		int ct1 = 0;
		int i = j-1;
		while(i>=0){
			if(a[i] > a[j]) ct1++;
			i--;
		}
			
		int ct2 = 0;
		int k = j+1;
		while(k<n){
			if(a[k] > a[j]) ct2++;
			k++;
		}
		
		ans += (ct1 * ct2);
	}
	
	return ans;

}



//* Followup : 

int consistency2(int n){
	
	int ans = 0;
	
	for(int j=1; j<=n-3; j++){
		for(int k=j+1; k<=n-2; k++){
			
			if(a[j] >= a[k]) continue;
				
			int ct1 = 0;
			int i = j-1;
			while(i>=0){
				if(a[i] > a[j]) ct1++;
				i--;
			}
			
			int ct2 = 0;
			int l = k+1;
			while(l<=n-1){
				if(a[l] < a[k]) ct2++;
				l++;
			}
			
			ans += ct1*ct2;
			
		}
	}
	
	return ans;
}




int consistency3(int n){
	
	int ans = 0;
	
	vector<int> pCountGreaterThan(n, 0);
	for(int j=1; j<=n-1; j++){
		int i = j-1;
		while(i>=0){
			if(a[i] > a[j]) pCountGreaterThan[j]++;
			i--;
		}
	}
	
	vector<int> sCountSmallerThan(n, 0);
	for(int k=0; k<=n-2; k++){
		int l = k+1;
		while(l<=n-1){
			if(a[l] < a[k]) sCountSmallerThan[k]++;
			l++;
		}
	}
	
	for(int j=1; j<=n-3; j++){
		for(int k=j+1; k<=n-2; k++){
			
			if(a[j] >= a[k]) continue;
				
			ans += pCountGreaterThan[j] * sCountSmallerThan[k];
			
		}
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
    
    cout << consistency1(n) << endl;
    cout << "Followup => " << consistency2(n) << " " << consistency3(n) << endl;


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