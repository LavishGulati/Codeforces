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

ll helper(vector<ll> **tree, ll u, ll n, bool *isVisited){
    isVisited[u] = true;
    ll answer = 1;
    for(ll i = 0; i < tree[u]->size(); i++){
        ll v = tree[u]->at(i);
        if(!isVisited[v]){
            answer += helper(tree, v, n, isVisited);
        }
    }

    return answer;
}

vector<ll> dfs(vector<ll> **tree, ll n, bool *isVisited){
    vector<ll> output;
    for(ll i = 0; i < n; i++){
        if(!isVisited[i]){
            output.pb(helper(tree, i, n, isVisited));
        }
    }
    return output;
}

ll power(ll n, ll k){
    if(k == 0) return 1;
    else if(k == 1) return (n%MOD);

    if(k%2 == 0){
        ll ans = power(n, k/2);
        return (ans*ans)%MOD;
    }
    else{
        ll ans = power(n, (k-1)/2);
        return (((ans*ans)%MOD)*n)%MOD;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, k;
    cin >> n >> k;
    vector<ll> **tree = new vector<ll> *[n];
    for(ll i = 0; i < n; i++){
        tree[i] = new vector<ll>;
    }

    ll u, v, x;
    for(ll i = 0; i < n-1; i++){
        cin >> u >> v >> x;
        if(x == 0){
            tree[u-1]->pb(v-1);
            tree[v-1]->pb(u-1);
        }
    }

    bool *isVisited = new bool[n];
    for(ll i = 0; i < n; i++) isVisited[i] = false;
    vector<ll> output = dfs(tree, n, isVisited);
    // for(ll i = 0; i < output.size(); i++){
    //     cout << output[i] << " ";
    // }
    // cout << endl;

    ll answer = power(n, k);
    // cout << answer << endl;
    for(ll i = 0; i < output.size(); i++){
        answer = (MOD+((answer-power(output[i], k))%MOD))%MOD;
        // answer -= power(output[i], k);
    }
    cout << answer << endl;
}
