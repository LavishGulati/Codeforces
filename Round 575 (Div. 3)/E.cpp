#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second
#define mp make_pair
#define pb push_back

int main(){
    int q, b, w, row;
    cin >> q;
    while(q--){
        cin >> b >> w;
        if(b < w) row = 3;
        else row = 2;

        if(max(w, b) > 3*min(b, w)+1){
            cout << "NO" << endl;
            continue;
        }

        vector<pii> black;
        vector<pii> white;
        if(row == 2){
            for(int i = 2; i <= 2*w; i += 2) white.pb(mp(i, row));
            for(int i = 1; i <= 2*w+1 && b > 0; i += 2){
                black.pb(mp(i, row));
                b--;
            }
            for(int i = 2; i <= 2*w && b > 0; i += 2){
                black.pb(mp(i, row-1));
                b--;
                if(b == 0) break;
                black.pb(mp(i, row+1));
                b--;
            }
        }
        else{
            for(int i = 2; i <= 2*b; i += 2) black.pb(mp(i, row));
            for(int i = 1; i <= 2*b+1 && w > 0; i += 2){
                white.pb(mp(i, row));
                w--;
            }
            for(int i = 2; i <= 2*b && w > 0; i += 2){
                white.pb(mp(i, row-1));
                w--;
                if(w == 0) break;
                white.pb(mp(i, row+1));
                w--;
            }
        }

        cout << "YES" << endl;
        b = black.size();
        for(int i = 0; i < b; i++){
            cout << black[i].f << " " << black[i].s << endl;
        }
        w = white.size();
        for(int i = 0; i < w; i++){
            cout << white[i].f << " " << white[i].s << endl;
        }
    }
}
