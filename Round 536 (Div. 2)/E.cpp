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

class envelope{
public:
    ll s, e, d, w;
};

envelope input[100009];

bool compare(envelope a, envelope b){
    return a.f < b.f;
}

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

    ll n, m, k;
    cin >> n >> m >> k;

    for(ll i = 0; i < k; i++){
        cin >> input[i].s >> input[i].e >> input[i].d >> input[i].w;
    }

    sort(input, input+n, compare);
    priority_queue<envelope, vector<envelope>, Compare> pq;


}
