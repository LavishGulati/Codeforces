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
typedef priority_queue< int, vector<int>, greater<int> > minpqi;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    minpqi pQueue;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        pQueue.push(x);
    }

    int helper = 0;
    while(k--){
        if(pQueue.size() == 0){
            cout << 0 << endl;
            continue;
        }

        int element = pQueue.top();
        while(pQueue.size() > 0 && pQueue.top() == element) pQueue.pop();
        cout << element-helper << endl;
        helper = element;
    }
}
