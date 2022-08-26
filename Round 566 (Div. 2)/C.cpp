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

    int n;
    cin >> n;

    map<char, int> id;
    id['a'] = 0;
    id['e'] = 1;
    id['i'] = 2;
    id['o'] = 3;
    id['u'] = 4;

    string input[n];
    int freq[n];
    char LastChar[n];

    map<pii, vector<int>> m;
    string s;
    int num;
    char last;
    for(int i = 0; i < n; i++){
        cin >> s;
        input[i] = s;
        num = 0;
        for(int j = 0; j < s.length(); j++){
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'){
                num++;
                last = s[j];
            }
        }
        freq[i] = num;
        LastChar[i] = last;
        m[mp(num, last)].pb(i);
    }

    queue<int> sec;
    queue<int> fir;

    for(auto i : m){
        if(i.s.size()%2 == 1){
            fir.push(i.s[0]);
            for(int j = 1; j < i.s.size(); j++){
                sec.push(i.s[j]);
            }
        }
        else{
            for(int j = 0; j < i.s.size(); j++){
                sec.push(i.s[j]);
            }
        }
    }

    vector<string> output;

    int a, b, c, d;
    while(!sec.empty() && !fir.empty()){
        a = fir.front();
        fir.pop();
        b = -1;

        while(!fir.empty()){
            if(freq[fir.front()] == freq[a]){
                b = fir.front();
                fir.pop();
                break;
            }
            else{
                a = fir.front();
                fir.pop();
            }
        }
        if(b == -1) break;

        c = sec.front();
        sec.pop();
        d = sec.front();
        sec.pop();

        // cout << a << " " << b << " " << c << " " << d << endl;

        output.pb(input[a]+' '+input[c]+'\n'+input[b]+' '+input[d]);
    }

    while(sec.size() >= 4){
        a = sec.front();
        sec.pop();
        b = sec.front();
        sec.pop();
        c = sec.front();
        sec.pop();
        d = sec.front();
        sec.pop();
        output.pb(input[a]+' '+input[c]+'\n'+input[b]+' '+input[d]);
    }

    cout << output.size() << endl;
    for(int i = 0; i < output.size(); i++){
        cout << output[i] << endl;
    }
}
