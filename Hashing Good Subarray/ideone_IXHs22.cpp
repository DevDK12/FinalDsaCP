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


// 9 3
// 1 1 -1 4 -1 0 -1 2 -1  



vector<int> a;

int consistency(int n, int k) {
    int sum = 0;
    unordered_map<int,int> mp = {{0, -1}};
    int maxLen = 0;
    
    for(int R=0; R<n; R++){
        sum += a[R];
        if(mp.count(sum-k)){
            int L = mp[sum-k];
            int len = R-L;
            maxLen = max(maxLen, len);
        }
        if(!mp.count(sum)) mp[sum] = R;
    }
    
    return maxLen;
}















int practice(int n, int k){


    return 0;
}





void solve() {
    
    int n, k;
    cin >> n >> k;
    
    a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    cout << consistency(n, k) << endl ;

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