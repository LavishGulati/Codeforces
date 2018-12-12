#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007

ll answer = 0;

ll dfs(ll u, ll parent, vector<pll> **graph, ll *gas, ll n){
    vector<ll> helper;

    for(ll i = 0; i < graph[u]->size(); i++){
        ll v = graph[u]->at(i).f;
        if(v == parent) continue;

        ll smallAns = dfs(v, u, graph, gas, n);
        if(smallAns > graph[u]->at(i).s){
            smallAns -= graph[u]->at(i).s;
            helper.pb(smallAns);
        }
    }

    helper.pb(0);
    helper.pb(0);
    ll size = helper.size();
    sort(all(helper));
    answer = max(answer, gas[u]+helper[size-1]+helper[size-2]);
    return gas[u]+helper[size-1];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;

    ll *gas = new ll[n];
    for(ll i = 0; i < n; i++) cin >> gas[i];

    vector<pll> **graph = new vector<pll> *[n];
    for(ll i = 0; i < n; i++) graph[i] = new vector<pll>;

    ll u, v, c;
    for(ll i = 0; i < n-1; i++){
        cin >> u >> v >> c;
        graph[u-1]->pb(mp(v-1, c));
        graph[v-1]->pb(mp(u-1, c));
    }

    dfs(0, -1, graph, gas, n);
    cout << answer << endl;
}
