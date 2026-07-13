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
// 0 1 -1
// -1 1 0
// 0 0 1
// -1 1 1






vector<int> a, b, c, d;

//* Hashing + 2 Ptr    =>     O(n^3)
int consistency1(int n){
	
	sort(begin(c), end(c));
    sort(begin(d), end(d));
    
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int sum = a[i]+b[j];
            
            int ct = 0;
            int s = 0, e = n-1;
            
            while(s<n && e>=0){
                if(c[s] + d[e] == -sum ){
                    int x = c[s];
                    int f1 = 0;
                    while(s<n && c[s] == x){
                        f1++;
                        s++;
                    }
                    
                    int y = d[e];
                    int f2 = 0;
                    while(e>=0 && d[e] == y){
                        f2++;
                        e--;
                    }
                    
                    ct += f1*f2;
                }
                else if(c[s] + d[e] > -sum){
                    e--;
                }
                else{
                    s++;
                }
            }
            ans += ct;
        }
    }
    
    return ans;
}



//* Optimization : 
//* Fetch all possible sum in map : SC = O(n^2)
//* 	max distinct sum in map == O(n^2) , TC == O(n^2 * n) == O(n^3)

int consistency2(int n){
	
	sort(begin(c), end(c));
	sort(begin(d), end(d));
	
	unordered_map<int,int> mp;
	for(int i=0; i<n; i++){
	    for(int j=0; j<n; j++){
	        int sum = a[i]+b[j];
	        mp[sum]++;
	    }
	}
	
	int ans = 0;
	for(auto& t : mp){
	    int sum = t.first;
	    int f = t.second;
	    int ct = 0;
	    int s = 0, e = n-1;
	    while(s<n && e>=0){
	        if(c[s] + d[e] == -sum ){
	        	
	            int x = c[s];
	            int f1 = 0;
	            while(s<n && c[s] == x){
	                f1++;
	                s++;
	            }
	            
	            int y = d[e];
	            int f2 = 0;
	            while(e>=0 && d[e] == y){
	                f2++;
	                e--;
	            }
	            
	            ct += f1*f2;
	        }
	        else if(c[s] + d[e] > -sum){
	            e--;
	        }
	        else{
	            s++;
	        }
	    }
	    ans += f*ct;
	}
	return ans;
}



//* Hashmap

int consistency3(int n){

    unordered_map<int,int> mp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int sum = a[i]+b[j];
            mp[sum]++;
        }
    }
    
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int sum = c[i]+d[j];
            
            if(mp.count(-sum)) ans += mp[-sum];
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
    b.resize(n);
    c.resize(n);
    d.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    for(int i=0; i<n; i++) cin >> c[i];
    for(int i=0; i<n; i++) cin >> d[i];
    
    cout << consistency1(n) <<  " " << consistency2(n) << " " << consistency3(n) << endl;


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