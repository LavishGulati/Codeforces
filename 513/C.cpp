#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sum(ll **matrix, ll ax, ll ay, ll bx, ll by){
    if(ax > 0 && ay > 0){
        return matrix[bx][by]+matrix[ax-1][ay-1]-matrix[ax-1][by]-matrix[bx][ay-1];
    }
    else if(ax > 0){
        return matrix[bx][by]-matrix[ax-1][by];
    }
    else if(ay > 0){
        return matrix[bx][by]-matrix[bx][ay-1];
    }
    else return matrix[bx][by];
}

int main(){
    ll n, m;
    cin >> n >> m;

    ll *a = new ll[n];
    for(ll i = 0; i < n; i++) cin >> a[i];

    ll *b = new ll[m];
    for(ll i = 0; i < m; i++) cin >> b[i];

    ll k;
    cin >> k;

    ll **matrix = new ll*[n];
    for(ll i = 0; i < n; i++){
        matrix[i] = new ll[m];
        for(ll j = 0; j < m; j++) matrix[i][j] = a[i]*b[j];
    }

    for(ll i = 0; i < n; i++){
        for(ll j = 1; j < m; j++) matrix[i][j] += matrix[i][j-1];
    }
    for(ll j = 0; j < m; j++){
        for(ll i = 1; i < n; i++) matrix[i][j] += matrix[i-1][j];
    }

    ll area = 0, max = 0;
    ll ax, ay, bx, by;
    ax = 0;
    ay = 0;
    bx = 0;
    by = 0;
    while(ax < n && ay < m && bx < n && by < m){
        while(ax < n && ay < m && bx < n && by < m){
            while(ax < n && ay < m && bx < n && by < m){
                // cout << ax << "," << ay << " " << bx << "," << by << endl;
                if(sum(matrix, ax, ay, bx, by) <= k){
                    // cout << ax << "," << ay << " " << bx << "," << by << endl;
                    if(area < (by-ay+1)*(bx-ax+1)){
                        // cout << ax << "," << ay << " " << bx << "," << by << endl;
                        area = (by-ay+1)*(bx-ax+1);
                    }
                    by++;
                }
                else{
                    bx++;
                    // cout << ax << "," << ay << " " << bx << "," << by << endl;
                    if(bx == n) break;
                    by = 0;
                    // cout << ax << "," << ay << " " << bx << "," << by << endl;
                    // cout << bx << "," << by << endl;
                    if(sum(matrix, ax, ay, bx, by) > k) break;
                }

                if(by == m){
                    bx++;
                    by = 0;
                }
            }

            ay++;
            bx = ax;
            by = ay;
            if(sum(matrix, ax, ay, bx, by) > k) break;

        }

        ay = 0;
        ax++;
        bx = ax;
        by = ay;

    }
    cout << area << endl;
}
