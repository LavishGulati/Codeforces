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

vector<int> output;

void dfs(set<int> *graph, int u, bool *isVisited){
    isVisited[u] = true;
    output.pb(u);

    for(auto i = graph[u].begin(); i != graph[u].end(); i++){
        int v = *i;
        if(!isVisited[v]){
            dfs(graph, v, isVisited);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    set<int> *graph = new set<int>[n+1];

    int u, v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        if(u != v){
            graph[u].insert(v);
            graph[v].insert(u);
        }
    }

    bool *isVisited = new bool[n+1];
    for(int i = 1; i <= n; i++) isVisited[i] = false;
    // dfs(graph, 1, isVisited);

    set<int> pq;
    pq.insert(1);
    while(!pq.empty()){
        int u = pq.top();
        output.pb(u);
        pq.pop();
        isVisited[u] = true;

        for(auto i = graph[u].begin(); i != graph[u].end(); i++){
            int v = *i;
            if(!isVisited[v]) pq.insert(v);
        }
    }

    for(int i = 0; i < output.size(); i++){
        cout << output[i] << " ";
    }
    cout << endl;
}
