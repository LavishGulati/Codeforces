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

    ll n, m;
    cin >> n >> m;

    ll *input = new ll[n];
    for(ll i = 0; i < n; i++){
        cin >> input[i];
    }

    priority_queue<ll> pq;
    priority_queue<ll, vector<ll>, greater<ll>> pq2;
    stack<ll> st;

    ll total = 0, x = 0, num = 0;
    ll last = -1;
    for(ll i = 0; i < n; i++){
        total += input[i];
        if(total-x > m){
            while(!pq.empty() && total-x > m){
                x += pq.top();
                num++;
                pq2.push(pq.top());
                pq.pop();
            }
        }
        cout << num << " ";
        if(!pq2.empty() && input[i] < pq2.top()) pq.push(input[i]);
        else if(!pq2.empty()){
            x -= pq2.top();
            pq.push(pq2.top());
            pq2.pop();
            x += input[i];
            pq2.push(input[i]);
            while(!pq2.empty() && total-x <= m){
                num--;
                x -= pq2.top();
                pq.push(pq2.top());
                pq2.pop();
            }
        }
        else pq.push(input[i]);
    }
    cout << endl;
}
