#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, q;
    cin >> n >> q;
    ll a = n*1+1;
    ll ans = ((n*n+n-a)/2)+2;
    ll b = n*1+2;

    while(q--){
        ll x, y;
        cin >> x >> y;
        if(n%2 == 1){
            if((x+y)%2 == 0) cout << ((n*x+y-a)/2)+1 << endl;
            else cout << ((n*x+y-b)/2)+ans << endl;
        }
        else{
            if((x+y)%2 == 0){
                if((n*x+y) % 2 == 0){
                    cout << ((n*x+y-a-1)/2)+1 << endl;
                }
                else cout << ((n*x+y-a)/2)+1 << endl;
            }
            else{
                if((n*x+y)%2 == 0){
                    cout << ((n*x+y-b)/2)+ans << endl;
                }
                else cout << ((n*x+y-b+1)/2)+ans << endl;
            }
        }
    }
}
