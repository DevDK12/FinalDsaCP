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

// 1
// 11010101


string a;

int consistency(int n){
    
    vector<int> s01(n);
    vector<int> s10(n);
    
    for(int i=n-2; i>=0; i--){
        s01[i] += s01[i+1];
        s10[i] += s10[i+1];
        
        if(a[i] == '0' && a[i+1] == '1'){
            s01[i]++;
        }
        else if(a[i] == '1' && a[i+1] == '0'){
            s10[i]++;
        }
    }
    
    int p01 = 0;
    int p10 = 0;
    
    int ans = 0;
    
    for(int i=0; i<n; i++){
        if(i-1>=0 && a[i-1] == '0' && a[i] == '1') p01++;
        else if(i-1>=0 && a[i-1] == '1' && a[i] == '0') p10++;
        
        int c01 = p01 + s01[i];
        int c10 = p10 + s10[i];
        
        if(a[i] == '0'){
            if(i-1>=0 && a[i-1] == '1'){
                c10--;    
            }
            else if(i-1>=0 && a[i-1] == '0'){
                c01++;
            }
            
            if(i+1<n && a[i+1] == '0'){
                c10++;
            }
            else if(i+1<n && a[i+1] == '1'){
                c01--;
            }
            
        }
        else if(a[i] == '1'){
            if(i-1>=0 && a[i-1] == '1'){
                c10++;    
            }
            else if(i-1>=0 && a[i-1] == '0'){
                c01--;
            }
            
            if(i+1<n && a[i+1] == '0'){
                c10--;
            }
            else if(i+1<n && a[i+1] == '1'){
                c01++;
            }
        }
        
        if(c01 == c10) ans++;
        
    }
    
    return ans;
}















int practice(int n){


    return 0;
}





void solve() {
    
    int n;
    cin >> a;
    n = a.size();    

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