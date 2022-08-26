#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t, str, intl, exp, ans;
    cin >> t;
    while(t--){
        cin >> str >> intl >> exp;
        ll si = 0;
        ll ei = exp;
        ll mid, ans = -1;
        while(si <= ei){
            mid = (si+ei)/2;
            if(str+mid > intl+exp-mid){
                ans = mid;
                ei = mid-1;
            }
            else si = mid+1;
        }
        if(ans == -1) cout << 0 << endl;
        else cout << exp-ans+1 << endl;
    }
}
