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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    int tests[n];
    for(int i = 0; i < n; i++) cin >> tests[i];

    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    for(int i = 0; i < k && i < n; i++) pq.push(mp(tests[i], mp(tests[i], i)));

    bool isInteresting[n];
    for(int i = 0; i < n; i++) isInteresting[i] = false;

    int id = k;
    int complete = 0;
    while(!pq.empty()){
        pair<int, pii> curr = pq.top();
        pq.pop();
        complete++;

        vector<pair<int, pii>> helper;
        while(!pq.empty()){
            helper.pb(mp(pq.top().f-curr.f, mp(pq.top().s.f, pq.top().s.s)));
            pq.pop();
        }

        for(int i = 0; i < helper.size(); i++){
            pq.push(helper[i]);
        }

        if(id < n){
            pq.push(mp(tests[id], mp(tests[id], id)));
            id++;
        }

        double d = (((double)complete)/((double)n))*100;
        int q = (int)floor(d+0.5);
        pair<int, pii> next = pq.top();

        if(pq.size() > 0 && pq.top().s.f-pq.top().f < q && pq.top().s.f >= q){
            isInteresting[pq.top().s.s] = true;
        }

        helper.clear();
        while(!pq.empty()){
            helper.pb(pq.top());
            pq.pop();
        }
        for(int i = 0; i < helper.size(); i++){
            if(helper[i].s.s == next.s.s) continue;
            if(helper[i].s.f-helper[i].f < q && helper[i].s.f-helper[i].f+next.f >= q){
                isInteresting[helper[i].s.s] = true;
            }
        }
        for(int i = 0; i < helper.size(); i++) pq.push(helper[i]);
        helper.clear();

    }

    int answer = 0;
    for(int i = 0; i < n; i++){
        if(isInteresting[i]) answer++;
    }
    cout << answer << endl;
}
