#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef map<int, bool> mapib;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;
typedef set<int> seti;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()
#define f first
#define s second
#define MOD 1000000007
#define PI acos(-1)

#define MAX 1e14

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll power[51];
    power[0] = 1;
    for(ll i = 1; i < 51; i++){
        power[i] = power[i-1]*2;
    }

    ll q;
    cin >> q;
    while(q--){
        ll a, b, m;
        cin >> a >> b >> m;

        if(a == b){
            cout << "1 " << a << endl;
            continue;
        }
        else if(b < a){
            cout << -1 << endl;
            continue;
        }
        else if(b < a+m && b > a){
            cout << "2 " << a << " " << b << endl;
            continue;
        }

        ll si = 2;
        ll ei = 50;
        ll n;
        while(si <= ei){
            n = (si+ei)/2;
            if(log2(double(b)/(a+1)) < n-2) ei = n-1;
            else if(log2(double(b)/(a+m)) > n-2) si = n+1;
            else break;
        }

        if(si > ei){
            cout << -1 << endl;
            continue;
        }

        cout << n << " ";

        ll k = (b/power[n-2]) - a;
        ll r = b%power[n-2];

        ll R[n];
        ll temp = r;
        for(ll i = n-1; i > 1; i--){
            R[i] = k+(temp%2);
            temp /= 2;
        }

        if(n == 2){
            cout << a << " " << a+k << endl;
            continue;
        }

        cout << a << " " << a+R[2] << " ";
        temp = a+R[2];
        for(ll i = 3; i < n; i++){
            cout << 2*temp+R[i]-R[i-1] << " ";
            temp = 2*temp+R[i]-R[i-1];
        }
        cout << 2*temp+k-R[n-1] << endl;
    }
}
