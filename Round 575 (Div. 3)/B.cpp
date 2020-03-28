#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll q, n, k, len, total;
    cin >> q;
    while(q--){
        cin >> n >> k;
        ll *input = new ll[n];
        for(ll i = 0; i < n; i++) cin >> input[i];

        len = 0;
        total = 0;
        for(ll i = 0; i < n; i++){
            total += input[i];

            if(total%2 == 1){
                len++;
                total = 0;
            }
        }

        if(k <= len && ((len-k)%2) == 0){
            cout << "YES" << endl;
            total = 0;
            for(ll i = 0; i < n; i++){
                total += input[i];
                if(total%2 == 1 && k > 1){
                    k--;
                    total = 0;
                    cout << i+1 << " ";
                }
            }
            cout << n << endl;
        }
        else cout << "NO" << endl;
    }
}
