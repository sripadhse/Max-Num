#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
 
 
 
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 
	int t;
	cin>>t;
 
	int C[31][31]; 
 
 
    for (int i = 0; i <= 30; i++)  { 
        for (int j = 0; j <= min(i, 30); j++) { 
            if (j == 0 || j == i) 
                C[i][j] = 1; 
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j]; 
        } 
    }
 
 
	while(t--) {
 
		int n, l;
		scanf("%d %d", &n, &l);
		vector<int> a(n);
		vector<int> m(31, 0);
		map<ll, ll> v;
 
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			for(int j = 0; j < 31; j++) {
				if(((a[i])&(1 << j)) != 0)
					m[j] += 1;
			}
		}
 
		ll val;
		for(int i = 0; i < 31; i++) {
			if(m[i] == 0) continue;
			val = (1<<i);
			val *= m[i];
			v[val] += 1;
		}
 
 
		ll ans = 1;
		map<ll, ll> :: reverse_iterator rit = v.rbegin();
		for(; l > 0 && rit != v.rend(); rit++) {
			if(rit->second <= l) {
				l -= rit->second;
			} else {
				ans = C[rit->second][l];
				l = 0;
			}
 
		}
 
		if(l > 0) printf("-1\n");
		else printf("%lld\n", ans);
 
	}
 
	return 0;
}