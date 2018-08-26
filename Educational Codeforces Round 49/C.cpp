#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double output(ll a, ll b){
    double x = (double)a;
    double y = (double)b;
    return ((x+y)*(x+y))/(x*y);
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        map<ll, ll> m;

        for(int i = 0; i < n; i++){
            ll x;
            cin >> x;
            if(m.find(x) == m.end()) m[x] = 1;
            else (m[x])++;

            // cout << x << " " << m[x] << endl;
        }

        bool flag = false;

        vector<ll> v;

        for(map<ll, ll>::iterator i = m.begin(); i != m.end(); i++){
            if((i->second) < 2) m.erase(i);
            else if((i->second) > 3){
                ll ans = i->first;
                printf("%lld %lld %lld %lld\n", ans, ans, ans, ans);
                flag = true;
                break;
            }
            else{
                v.push_back(i->first);
                // cout << i->first << " " << i->second << endl;
            }
        }


        if(!flag){

            /*
            ll id1 = 0;
            ll id2 = 1;
            double w = output(v[id1], v[id2]);

            for(ll i = 0; i < v.size(); i++){
                for(ll j = i+1; j < v.size(); j++){
                    if(output(v[i], v[j]) < w){
                        w = output(v[i], v[j]);
                        id1 = i;
                        id2 = j;
                    }
                }
            }

            cout << v[id1] << " " << v[id1] << " " << v[id2] << " " << v[id2] << endl;
            */
            /*
            ll id = 1;
            double w;

            // for(int i = 0; i < v.size(); i++) cout << v[i] << endl;

            w = output(v[id-1], v[id]);

            for(int i = 2; i < v.size(); i++){
                // cout << output(v[i-1], v[i]) << endl;
                if(output(v[i-1], v[i]) < w){
                    id = i;
                    w = output(v[i-1], v[i]);
                }
            }

            cout << v[id] << " " << v[id] << " " << v[id-1] << " " << v[id-1] << endl;
            */



            map<ll, ll>::iterator answer = m.begin();
            answer++;
            double w;

            map<ll, ll>::iterator i = m.begin();
            ll a = i->first;
            i++;
            ll b = i->first;

            w = output(a, b);
            a = b;
            i++;

            for(; i != m.end(); i++){
                b = i->first;
                if(output(a, b) < w){
                    answer = i;
                    w = output(a, b);
                }

                a = b;
            }

            cout << answer->first << " " << answer->first << " ";
            answer--;
            cout << answer->first << " " << answer->first << endl;

        }
    }
}
