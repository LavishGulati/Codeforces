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

void dfs(vector<int> **graph, int u, int n, bool *IsVisited, set<int> &helper){
    IsVisited[u] = true;
    helper.insert(u);

    for(int i = 0; i < graph[u]->size(); i++){
        int v = graph[u]->at(i);
        if(!IsVisited[v]){
            dfs(graph, v, n, IsVisited, helper);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> **graph = new vector<int> *[n];
    for(int i = 0; i < n; i++) graph[i] = new vector<int>;

    vector<int> input;
    int num, i, x, j;
    for(i = 0; i < m; i++){
        cin >> num;
        for(j = 0; j < num; j++){
            cin >> x;
            input.pb(x);
        }
        for(j = 1; j < num; j++){
            graph[input[0]-1]->pb(input[j]-1);
            graph[input[j]-1]->pb(input[0]-1);
        }
        input.clear();
    }

    int output[n];
    set<int> helper;
    bool *IsVisited = new bool[n];
    for(i = 0; i < n; i++) IsVisited[i] = false;
    for(i = 0; i < n; i++){
        if(!IsVisited[i]){
            dfs(graph, i, n, IsVisited, helper);
            for(auto k = helper.begin(); k != helper.end(); k++){
                output[*k] = helper.size();
            }
            helper.clear();
        }
    }

    for(int i = 0; i < n; i++){
        cout << output[i] << " ";
    }
    cout << endl;
}
