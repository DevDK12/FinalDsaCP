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
// 7
// 1 2 3 4 -1 -2 -2
// 6
// 5 10 -5 -5 -10 -10





vector<int> a;

int consistency1(int n){
	
	int ans = 0;
	
	for(int i=0; i<=n-4; i++){
		for(int j=i+1; j<=n-3; j++){
			
			unordered_map<int,int> sufixMp;
			for(int k=n-1; k>=j+1; k--){
				sufixMp[a[k]]++;
			}
			
			for(int k=j+1; k<=n-2; k++){
				sufixMp[a[k]]--;
				if(sufixMp[a[k+1]] == 0) sufixMp.erase(a[k]);
				
				int sum = a[i] + a[j] + a[k];
				
				if(sufixMp.count(-sum)){
					ans += sufixMp[-sum];
				}
			}
		}
	}
	
	return ans;
}





int consistency2(int n){
	
	int ans = 0;
	
	sort(begin(a), end(a));
	
	for(int i=0; i<=n-4; i++){
		for(int j=i+1; j<=n-3; j++){
			
			int sum = a[i]+a[j];
			
			int t = -sum;
			
			int s = j+1, e = n-1;
			while(s<e){
				if(a[s] + a[e] == t){
					
					//* t = 8   [4 4 4 4 4 ] => 5C2 
					if(a[s] == a[e]){
						int ct = e-s+1;
						ans += (ct*(ct-1))/2;
						break;
					}
					
					int ct1 = 0;
					int x1 = a[s];
					while(s<=e && a[s] == x1){
						ct1++;
						s++;
					}
					
					int ct2 = 0;
					int x2 = a[e];
					while(s<=e && a[e] == x2){
						ct2++;
						e--;
					}
					
					ans += ct1 * ct2;
				}
				else if(a[s] + a[e] > t) e--;
				else s++;
			}
			
		}
	}
	
	return ans;
}





int consistency3(int n){
	
	int ans = 0;
	
	unordered_map<int,int> mp;
	for(int i=n-1; i>=2; i--){
		for(int j=i-1; j>=1; j--){
			mp[a[i]+a[j]]++;
		}
	}
	
	for(int j=1; j<=n-3; j++){
		
		for(int k=j+1; k<=n-1; k++){
			int sum = a[j]+a[k];
			
			mp[sum]--;
			if(mp[sum] == 0) mp.erase(sum);
		}
		
		for(int i=j-1; i>=0; i--){
			
			int sum = a[i]+a[j];
			if(mp.count(-sum))	ans += mp[-sum];
		}
	}

	
	return ans;
}
























int practice(int n){
	
	int ans = 0;
	



    return ans;
}





void solve() {
    
    int n;
    cin>> n;
    
    a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    cout << consistency1(n) << " " << consistency2(n) << " " << consistency3(n) << endl;
    
    // cout << " => " << practice(n) << endl;


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