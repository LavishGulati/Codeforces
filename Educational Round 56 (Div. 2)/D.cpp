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
#define MOD 998244353

#define MAX 300005

bool dfs(vector<ll> **graph, ll source, bool *isVisited, ll *color, ll &count0, ll &count1){
    isVisited[source] = true;

    for(ll i = 0; i < graph[source]->size(); i++){
        ll v = graph[source]->at(i);
        if(!isVisited[v]){
            color[v] = 1-color[source];
            if(color[v] == 1) count1++;
            else if(color[v] == 0) count0++;
            if(!dfs(graph, v, isVisited, color, count0, count1)) return false;
        }
        else{
            if(color[v] == color[source]) return false;
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    bool isBipartite;
    ll *power = new ll[MAX];
    power[0] = 1;
    for(ll i = 1; i < MAX; i++){
        power[i] = (power[i-1]*2)%MOD;
    }
    while(t--){
        isBipartite = true;
        ll n, m;
        cin >> n >> m;
        vector<ll> **graph = new vector<ll> *[n];
        for(ll i = 0; i < n; i++) graph[i] = new vector<ll>;

        ll u, v;
        for(ll i = 0; i < m; i++){
            cin >> u >> v;
            graph[u-1]->pb(v-1);
            graph[v-1]->pb(u-1);
        }

        bool *isVisited = new bool[n];
        ll *color = new ll[n];
        for(ll i = 0; i < n; i++) isVisited[i] = false;

        ll total = 1;
        for(ll i = 0; i < n; i++){
            if(!isVisited[i]){
                ll count0 = 1, count1 = 0;
                color[i] = 0;
                if(!dfs(graph, i, isVisited, color, count0, count1)){
                    isBipartite = false;
                    cout << 0 << endl;
                    break;
                }
                else total = (total*((power[count0]+power[count1])%MOD))%MOD;
            }
        }

        if(isBipartite) cout << total << endl;
    }
}
