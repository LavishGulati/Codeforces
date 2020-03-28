#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
#define f first
#define s second
#define mp make_pair

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t, n, x, ans, a, b;
    cin >> t;
    while(t--){
        cin >> n >> x;
        pll *input = new pll[n];
        for(ll i = 0; i < n; i++){
            cin >> input[i].f >> input[i].s;
        }

        ans = INT_MAX;
        for(ll i = 0; i < n; i++){
            if(x <= input[i].f) ans = min(ans, 1LL);
        }

        if(ans == 1){
            cout << 1 << "\n";
            continue;
        }

        ll id1 = 0;
        for(ll i = 1; i < n; i++){
            if(input[i].f-input[i].s > input[id1].f-input[id1].s){
                id1 = i;
            }
        }

        ll id2 = 0;
        for(ll i = 1; i < n; i++){
            if(input[i].f > input[id2].f){
                id2 = i;
            }
        }

        if(input[id1].f-input[id1].s > 0){
            if(((x-input[id2].f)%(input[id1].f-input[id1].s)) == 0){
                ans = min(ans, (x-input[id2].f)/(input[id1].f-input[id1].s));
            }
            else{
                ans = min(ans, (x-input[id2].f)/(input[id1].f-input[id1].s) + 1);
            }
        }

        if(ans == INT_MAX) cout << -1 << "\n";
        else cout << ans+1 << "\n";
    }
}
