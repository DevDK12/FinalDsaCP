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

//  1
// 20
// 0 17 3 14 7 2 18 5 15 8 11 4 6 19 0 1 12 13 16 20
 

 
vector<int> a;

int consistency(int n){
	
	unordered_set<int> st;

    for(int i=0; i<n; i++){
        st.insert(a[i]);
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        if(st.count(a[i]-1)) continue;
        
        int j = a[i];
        while(st.count(j)){
            st.erase(j);
            j++;
        }
        ans = max(ans, j-a[i]);
    }

    return ans;
}
 
 
 
 
 









 
 
 
 
 
 
 
 
 
 
 
int practice(int n){
 
 
    return 0;
}
 
 
 
 
 
void solve() {
 
    int n;
    cin >> n;
    
    a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];
 
    cout << consistency(n) << endl;
 
 
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