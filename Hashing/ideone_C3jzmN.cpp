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
// 4 2
// 1 3 2 0
// 4 4
// 1 4 -1 2
// 15 10
// -12 -10 -4 -5 -5 -1 2 3 5 5 5 5 8 10 13






vector<int> a;

int consistency(int n, int k){

    if(k&1) return 0;

    int val = k/2;

    int ct1 = 0; //* count of ele == +-k/2
    int ct2 = 0; //* count of ele in (-k/2 , k/2 )

    for(int i=0; i<n; i++){
        if( abs(a[i]) == val ) ct1++;
        if( abs(a[i])  < val ) ct2++;
    }

    int ans = ct1*ct2 + ct1*(ct1-1)/2;

    return ans;

}















int practice(int n, int k){


    return 0;
}





void solve() {
    
    int n, k;
    cin>> n >> k;
    
    a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    cout << consistency(n, k) << endl;


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