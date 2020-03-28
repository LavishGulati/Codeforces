#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
#define f first
#define s second
#define pb push_back
#define mp make_pair

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cout << "? ";
    for(ll i = 0; i < 100; i++){
        cout << (i<<7)+127 << " ";
    }
    cout << endl;

    ll a;
    cin >> a;

    cout << "? ";
    for(ll i = 0; i < 100; i++){
        cout << 16256+i << " ";
    }
    cout << endl;

    ll b;
    cin >> b;

    a = (a)%(1<<7);
    a ^= 127;
    b = (b>>7);
    b ^= 127;
    ll ans = (b*pow(2,7))+a;
    // ll ans = (a)%(1<<7) + (b>>7);
    // ans ^= ((1<<14)-1);
    cout << "! " << ans << endl;
}
