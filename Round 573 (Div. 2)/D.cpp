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
typedef vector<int> vi;

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

    ll n, x;
    cin >> n;

    map<ll, ll> mp;
    for(ll i = 0; i < n; i++){
        cin >> x;
        mp[x]++;
    }

    if(mp[0] >= 2){
        cout << "cslnb" << endl;
        return 0;
    }

    ll pairs = 0;
    for(pll a : mp){
        if(a.s >= 2) pairs += a.s-1;
    }
    if(pairs >= 2){
        cout << "cslnb" << endl;
        return 0;
    }

    for(pll a : mp){
        if(mp.find(a.f - 1) != mp.end()){
            if(a.s >= 2 && mp[a.f-1] >= 1){
                cout << "cslnb" << endl;
                return 0;
            }
        }
    }

    ll total = 0;
    ll id = 0, j;
    for(pll i : mp){
        j = i.s;
        while(j--){
            total += i.f-id;
            total %= 2;
            id++;
        }
    }
    if(total%2){
        cout << "sjfnb" << endl;
    }
    else{
        cout << "cslnb" << endl;
    }
}
