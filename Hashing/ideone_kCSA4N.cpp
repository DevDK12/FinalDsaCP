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

// 10
// -100 -100 -70 -60 -60 110 120 130 130 160 




vector<int> a;

vector<vector<int>> consistency1(int n){

	sort(begin(a), end(a));
	
    vector<vector<int>> ans;

    for (int i = 0; i <= n - 3; i++) {
        if (i > 0 && a[i] == a[i - 1]) continue;    
        
        unordered_map<int, int> mp;
        for (int k=n-1; k>=i+2; k--) {
            mp[a[k]]++;
        }   
        
        for (int j = i+1; j<=n-2; j++) {
            if (j>=i+2 && a[j] == a[j - 1]){
            	
            	//* sync map to clear next
                mp[a[j+1]]--;
                if (mp[a[j+1]] == 0) mp.erase(a[j+1]);
                continue;
            }   
            int sum = a[i] + a[j];

            if (mp.count(-sum)) {
                ans.push_back({a[i], a[j], -sum});
            }

			//* sync map to clear next
            mp[a[j+1]]--;
            if (mp[a[j+1]] == 0) mp.erase(a[j+1]);
        }
    }   
    
    
    return ans;

}



vector<vector<int>> consistency2(int n){

	sort(begin(a), end(a));
	
    vector<vector<int>> ans;

	for(int i=0; i<=n-3; i++){
		if(i-1>=0 && a[i] == a[i-1]) continue;
		
		int sum = -a[i];
		
		int s = i+1;
		int e = n-1;

		while(s<e){
			if(a[s]+a[e] == sum){
				
				ans.push_back({a[i], a[s], a[e]});
				
				int left = a[s];
				while(s<e && a[s] == left)	s++;
				
				int right = a[e];
				while(e>s && a[e] == right) e--;
				
			}
			else if(a[s] + a[e] < sum){
				s++;
			}
			else{
				e--;
			}
		}
		
	}
   
    
    return ans;

}























vector<vector<int>> practice(int n){


}





void solve() {
    
    int n;
    cin>> n;
    
    a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    auto ans = consistency2(n);
    
    for(auto t : ans){
    	cout << t[0] << " " << t[1] << " " << t[2] << endl;
    }


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