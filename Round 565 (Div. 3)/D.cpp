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

#define MAX 3000000

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll *sieve = new ll[MAX];
    for(ll i = 0; i < MAX; i++) sieve[i] = -1;
    sieve[1] = 1;

    vector<ll> primes;
    for(ll i = 2; i < MAX; i++){
        if(sieve[i] == -1){
            for(ll j = i*i; j < MAX; j += i){
                if(sieve[j] == -1) sieve[j] = i;
            }
            sieve[i] = i;
        }
    }

    for(ll i = 2; i < MAX; i++){
        if(sieve[i] == i) primes.pb(i);
    }

    ll n, x;
    cin >> n;
    map<ll, ll> m;
    for(ll i = 0; i < 2*n; i++){
        cin >> x;
        m[x]++;
    }

    vector<ll> output;
    for(auto i = m.rbegin(); i != m.rend(); i++){
        if(i->s > 0 && !binary_search(all(primes), i->f)){
            x = (i->f)/sieve[i->f];
            for(ll j = 0; j < i->s; j++) output.pb(i->f);
            m[x] -= i->s;
            m[i->f] = 0;
        }
    }

    for(auto i = m.begin(); i != m.end(); i++){
        if(i->s > 0){
            x = primes[i->f - 1];
            for(ll j = 0; j < i->s; j++) output.pb(i->f);
            m[x] -= i->s;
            m[i->f] = 0;
        }
    }

    for(ll i = 0; i < n; i++){
        cout << output[i] << " ";
    }
    cout << endl;
}
