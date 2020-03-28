#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t, b, p, f, h, c, x, ans;
    cin >> t;
    while(t--){
        cin >> b >> p >> f >> h >> c;
        ans = 0;
        if(h >= c){
            x = min(p, b/2);
            ans += x*h;
            p -= x;
            b -= 2*x;
            x = min(f, b/2);
            ans += x*c;
        }
        else{
            x = min(f, b/2);
            ans += x*c;
            f -= x;
            b -= 2*x;
            x = min(p, b/2);
            ans += x*h;
        }
        cout << ans << endl;
    }
}
