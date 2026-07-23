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

// 7 4
// 1 3 2 4 2 4 1



vector<int> a;

int consistency1(int n, int k){

    vector<int> mods(n+1);
    mods[0] = 1%k;


    int sum = 0;
    for(int i=0; i<n; i++){
        sum += a[i];

        int mod = (sum - i + k)%k;
        mods[i+1] = mod;

    }

    int m = mods.size();
    unordered_map<int,int> mp;
    int s = 0, e = 0;
    int ans = 0;

    while(e<m){
        mp[mods[e]]++;
        if(e-s+1 <= k-1){
            ans += mp[mods[e]]-1;
            e++;
        }
        else{
            while(s<=e && e-s+1>k ){
                mp[mods[s]]--;
                if(mp[mods[s]] == 0) mp.erase(mods[s]);
                s++;
            }
            ans += mp[mods[e]]-1;
            e++;
        }
    }


    return ans;
}







int consistency2(int n, int k){

	unordered_map<int,int> mp = {{1%k, 1}};
	vector<int> mods(n+1, 0);
	mods[0] = 1%k;
	
	int ans = 0;
	int sum = 0;
	
	for(int i=0; i<n; i++){
		sum += a[i];
		int mod = ((sum - i)%k + k) % k;
		
		mods[i+1] = mod;
		mp[mod]++;
		
		//* maintaining window of size k-1
		if(i+1 >= k){
			int lastMod = mods[i-k+1]; // 1 based indexing i-k => i-k+1
			mp[lastMod]--;
			if(mp[lastMod] == 0) mp.erase(lastMod);
		}
		
		ans += mp[mod]-1;
				
	}

    return ans;
}




int consistency3(int n, int k){

	unordered_map<int,int> mp = {{1%k, 1}};

	deque<int> dq = {1%k};
	
	int ans = 0;
	int sum = 0;
	
	for(int i=0; i<n; i++){
		sum += a[i];
		int mod = ((sum - i)%k + k) % k;
		
		dq.push_back(mod);
		mp[mod]++;
		
		//* maintaining window of size k-1
		if(i+1 >= k){
			int lastMod = dq.front();
			dq.pop_front();
			
			mp[lastMod]--;
			if(mp[lastMod] == 0) mp.erase(lastMod);
		}
		
		ans += mp[mod]-1;
				
	}

    return ans;
}














int practice(int n, int k){


}





void solve() {
    
    int n, k;
    cin>> n >> k;
    
    a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    cout << consistency1(n, k) << " " << consistency2(n,k) << " " << consistency3(n,k) << endl;
	// cout << practice(n, k) << endl;

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