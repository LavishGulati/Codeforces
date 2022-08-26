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

vector<int> bipartite[2];

void dfs(int u, vector<int> *graph, int id, bool *IsVisited){
    IsVisited[u] = true;
    bipartite[id].pb(u);

    for(int v : graph[u]){
        if(!IsVisited[v]){
            dfs(v, graph, id^1, IsVisited);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t, n, m, u, v;
    cin >> t;
    while(t--){
        bipartite[0].clear();
        bipartite[1].clear();

        cin >> n >> m;
        vector<int> *graph = new vector<int>[n];
        for(int i = 0; i < m; i++){
            cin >> u >> v;
            graph[u-1].pb(v-1);
            graph[v-1].pb(u-1);
        }

        bool *IsVisited = new bool[n];
        for(int i = 0; i < n; i++) IsVisited[i] = false;

        dfs(0, graph, 0, IsVisited);
        if(bipartite[0].size() <= n/2){
            m = bipartite[0].size();
            cout << m << endl;
            for(int i = 0; i < m; i++){
                cout << bipartite[0][i]+1 << " ";
            }
            cout << endl;
        }
        else{
            m = bipartite[1].size();
            cout << m << endl;
            for(int i = 0; i < m; i++){
                cout << bipartite[1][i]+1 << " ";
            }
            cout << endl;
        }
    }
}
