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
#define sec second
#define MOD 1000000007

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    int input[m];
    for(int i = 0; i < m; i++) cin >> input[i];

    int count = 0;
    map<int, int> mp;
    string answer = "";
    queue<int> q;
    for(int i = 0; i < m; i++){
        if(mp.find(input[i]) == mp.end()){
            mp[input[i]] = 1;
            count++;
        }
        else mp[input[i]]++;

        if(count == n){
            answer += '1';
            for(auto j = mp.begin(); j != mp.end(); j++){
                if(j->sec == 1){
                    q.push(j->f);
                    count--;
                }
                else (j->sec)--;
            }

            while(!q.empty()){
                mp.erase(q.front());
                q.pop();
            }
        }
        else answer += '0';
    }

    cout << answer << endl;
}
