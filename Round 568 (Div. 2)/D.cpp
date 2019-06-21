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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    pll *input = new pll[n];
    ll x;
    for(ll i = 0; i < n; i++){
        cin >> x;
        input[i] = mp(x, i);
    }

    if(n <= 3){
        cout << 1 << endl;
        return 0;
    }

    sort(input, input+n);

    set<ll> st;
    for(ll i = 1; i < n; i++){
        st.insert(input[i].f-input[i-1].f);
    }
    if(st.size() == 1){
        cout << input[0].s + 1 << endl;
        return 0;
    }
    if(st.size() > 3){
        cout << -1 << endl;
        return 0;
    }

    x = input[2].f-input[1].f;
    bool ans = true;
    for(ll i = 3; i < n; i++){
        if(input[i].f-input[i-1].f != x){
            ans = false;
            break;
        }
    }
    if(ans){
        cout << input[0].s+1 << endl;
        return 0;
    }

    x = input[1].f-input[0].f;
    ans = true;
    for(ll i = 2; i < n-1; i++){
        if(input[i].f-input[i-1].f != x){
            ans = false;
            break;
        }
    }
    if(ans){
        cout << input[n-1].s+1 << endl;
        return 0;
    }

    ll i;
    for(i = 1; i < n-1; i++){
        if(input[i].f-input[i-1].f != input[i+1].f-input[i].f){
            break;
        }
    }

    for(ll j = max(i-1, ll(1)); j <= min(i+2, n-2); j++){
        ans = true;
        x = LLONG_MIN;
        for(ll k = 1; k < n; k++){
            if(k == j) continue;
            else if(k == j+1){
                if(x == LLONG_MIN) x = input[k].f-input[k-2].f;
                else{
                    if(x != input[k].f-input[k-2].f){
                        ans = false;
                        break;
                    }
                }
            }
            else{
                if(x == LLONG_MIN) x = input[k].f-input[k-1].f;
                else{
                    if(x != input[k].f-input[k-1].f){
                        ans = false;
                        break;
                    }
                }
            }
        }
        if(ans){
            cout << input[j].s + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}
