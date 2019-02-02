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

pll food[100009];

class Index{
public:
    ll id;

    Index(ll i){
        id = i;
    }
};

class Compare
{
public:
    bool operator() (Index id1, Index id2)
    {
        if(food[id1.id].s != food[id2.id].s){
            return food[id1.id].s > food[id2.id].s;
        }
        else{
            return id1.id > id2.id;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, m;
    cin >> n >> m;

    for(ll i = 1; i <= n; i++){
        cin >> food[i].f;
    }
    for(ll i = 1; i <= n; i++){
        cin >> food[i].s;
    }

    priority_queue<Index, vector<Index>, Compare> pq;
    for(ll i = 1; i <= n; i++){
        pq.push(Index(i));
    }

    // while(!pq.empty()){
    //     cout << pq.top().id << endl;
    //     pq.pop();
    // }

    ll t, d, cost;
    while(m--){
        cost = 0;
        cin >> t >> d;
        if(food[t].f > 0){
            ll num = min(d, food[t].f);
            cost += food[t].s*num;
            d -= num;
            food[t].f -= num;
        }

        // cout << cost << " ";

        if(d > 0){
            while(d != 0 && !pq.empty()){
                Index index = pq.top();
                ll num = min(food[index.id].f, d);
                cost += food[index.id].s*num;
                d -= num;
                food[index.id].f -= num;
                if(food[index.id].f == 0) pq.pop();
            }
        }

        if(d > 0) cost = 0;

        cout << cost << endl;
    }
}
