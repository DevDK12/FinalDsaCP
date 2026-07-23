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
// 1st Mar 1974
// 22nd Jan 2013
// 7th Apr 1904


vector<string> a;

vector<string> consistency(int n){
	
	unordered_map<string, string> mp = {
		{"Jan" , "01"},	
		{"Feb" , "02"},	
		{"Mar" , "03"},	
		{"Apr" , "04"},	
		{"May" , "05"},	
		{"Jun" , "06"},	
		{"Jul" , "07"},	
		{"Aug" , "08"},	
		{"Sep" , "09"},	
		{"Oct" , "10"},	
		{"Nov" , "11"},	
		{"Dec" , "12"},	
	};
	

	
	vector<string> ans;
	
	for(auto& w : a){
		

		stringstream ss(w);
		string temp;
		
		string final = "";
	
		int i = 0;
		while(ss >> temp){
			if(i==0){
				temp.pop_back();
				temp.pop_back();
				
				if(temp.size() == 1) temp = "0" + temp;
				final = temp + final;
			}
			else if(i==1){
				final = mp[temp] + "-" + final;
			}
			else{
				final = temp + "-" + final;
			}
			
			i++;
		}
		ans.push_back(final);
	}
	
	return ans;

}















vector<string> practice(int n){


}





void solve() {
    
    int n;
    cin >> n;
    
    cin.ignore();
    
    a.resize(n);
    for(int i=0; i<n; i++) getline(cin, a[i]);
    
    auto ans = consistency(n);
	for(auto& t : ans) cout << t << " "; cout << endl;

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