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
#define pf push_front

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, q;
    cin >> n >> q;
    ll *input = new ll[n];
    for(ll i = 0; i < n; i++) cin >> input[i];

    pll query[q];
    for(ll i = 0; i < q; i++){
        cin >> query[i].f;
        query[i].s = i;
    }
    sort(query, query+q);

    ll MaxEl = 0;
    for(ll i = 0; i < n; i++) MaxEl = max(MaxEl, input[i]);

    deque<ll> MyQueue;
    for(ll i = 0; i < n; i++) MyQueue.pb(input[i]);

    pll output[q];
    ll i = 0, a, b, num = 1;
    while(MyQueue.front() != MaxEl){
        a = MyQueue.front();
        MyQueue.pop_front();
        b = MyQueue.front();
        MyQueue.pop_front();

        while(query[i].f == num){
            output[query[i].s].f = a;
            output[query[i].s].s = b;
            i++;
        }

        if(a > b){
            MyQueue.pf(a);
            MyQueue.pb(b);
        }
        else{
            MyQueue.pf(b);
            MyQueue.pb(a);
        }

        num++;
    }

    for(ll i = 0; i < n; i++){
        input[i] = MyQueue.front();
        MyQueue.pop_front();
    }

    ll x;
    while(i < q){
        output[query[i].s].f = input[0];
        x = query[i].f;
        output[query[i].s].s = input[((x-num)%(n-1))+1];
        i++;
    }

    for(ll i = 0; i < q; i++){
        cout << output[i].f << " " << output[i].s << endl;
    }
}
