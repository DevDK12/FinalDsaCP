#include <bits/stdc++.h>
using namespace std;
#define int              long long int
#define double           long double
inline int power(int a, int b) {
    int x = 1;
    while (b) {
        if (b & 1) x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}


const int M = 1000000007;
const int N = 3e5+9;
const int INF = 2e9+1;
const int LINF = 2000000000000000001;

//_ ***************************** START Below *******************************

// LMCT

string a;

int consistency(int n) {
	
	
	int l = 0;
	int lc = 0;
	int lct = 0;
	
	for(int i=0; i<n; i++){
		if(a[i] == 'L') l++;
		else if(a[i] == 'C')	lc += l;
		else if(a[i] == 'T')	lct += lc;
	}
	
	int llct = lct + lc;
	
	int t = 0;
	int ct = 0;
	for(int i=n-1; i>=0; i--){
		if(a[i] == 'T') t++;
		else if(a[i] == 'C')	ct += t;
	}
	
	int lctt = lct + ct;

	
	int x = 0;
	l = 0;
	for(int i=0; i<n; i++){
		if(a[i] == 'L') l++;
		else if(a[i] == 'T') t--;
		
		x = max(x, l * t);
	}
	
	int lcct = lct + x;
	
	int ans = max({ lct, lctt, llct, lcct } );
	
	return ans;

}












void solve() {
    
	cin >> a;
	int n = a.size();
	
    cout << consistency(n) << endl ;

}





int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}