#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define f first
#define s second
#define pb push_back
#define mp make_pair

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t, n, a, b;
    string s;
    cin >> t;
    ll x, total;
    while(t--){
        cin >> n >> a >> b;
        cin >> s;

        total = 0;
        ll start = 0;
        ll end = n-1;
        while(start < n && s[start] == '0') start++;
        while(end >= 0 && s[end] == '0') end--;

        if(start == n){
            cout << n*a + (n+1)*b << endl;
            continue;
        }

        total = (start+1)*a + start*b;
        total += (n-end)*a + (n-end-1)*b;

        x = 0;
        for(ll i = start; i <= end; i++){
            if(s[i] == '1'){
                total += 2*b+a;
                if(x > 0){
                    x = min((x+2)*a + (x-1)*b, x*a + (x-1)*2*b) + 2*b;
                    total += x;
                }
                x = 0;
            }
            else{
                x++;
            }
        }
        cout << total+2*b << endl;
    }
}
