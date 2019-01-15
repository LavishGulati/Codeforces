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

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()
#define f first
// #define s second
#define MOD 1000000007

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    bool flag = true;
    vector<string> *input = new vector<string>;
    string s, s1;
    while(cin >> s){
        if(s.substr(0,6) == "\\cite{"){
            int id = 6;
            for(; id < s.length(); id++){
                if(s[id] == '}') break;
            }
            input->pb(s.substr(6,id-6));
        }

        if(s == "\\begin{thebibliography}{99}") break;
    }
    cin >> s1;

    umapss m;
    // cout << input->size() << endl;
    for(int i = 0; i < input->size(); i++){
        getline(cin, s);
        if(i == 0) s = s1+s;
        // cout << s.length() << " " << s << endl;
        // cout << i << " " << s << endl;
        int id = 9;
        for(; id < s.length(); id++){
            if(s[id] == '}') break;
        }
        // cout << s.length() << " " << id << endl;
        if(s.substr(9, id-9) != input->at(i)) flag = false;
        m[s.substr(9, id-9)] = s.substr(id+1);
    }
    cin >> s;

    if(flag) cout << "Correct" << endl;
    else{
        cout << "Incorrect" << endl;
        cout << "\\begin{thebibliography}{99}" << endl;
        for(int i = 0; i < input->size(); i++){
            cout << "\\bibitem{" << input->at(i) << "}";
            cout << m[input->at(i)] << endl;
        }
        cout << "\\end{thebibliography}" << endl;
    }
}
