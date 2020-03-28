#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

#define pb push_back
#define umap unordered_map
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

#define MAX 100009

pii A[MAX];
pii B[MAX];

struct Time{
	int id, t;
	bool isStart;

	Time(int id, int t, bool isStart){
		this->id = id;
		this->t = t;
		this->isStart = isStart;
	}
};

// bool compare(int i, int j){
// 	if(A[i].f < A[j].f){
// 		return true;
// 	else if(A[i].f == A[j].f){
// 		return A[i].s < A[j].s;
// 	}
// 	else{
// 		return false;
// 	}
// }

bool compare2(Time a, Time b){
	if(a.t < b.t){
		return true;
	}
	else if(a.t == b.t){
		if(a.isStart) return true;
		else return false;
	}
	else{
		return false;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> A[i].f >> A[i].s >> B[i].f >> B[i].s;
	}

	vector<Time> time;
	for(int i = 0; i < n; i++){
		time.pb(Time(i, A[i].f, true));
		time.pb(Time(i, A[i].s, false));
	}

	sort(all(time), compare2);

	set<int> st;

	int as = 0, ae, bs = 0, be;
	int k = 0;

	map<int, int> startB;
	map<int, int> endB;
	map<int, int> startA;
	map<int, int> endA;

	for(int i = 0; i < 2*n; i++){
		int id = time[i].id;

		if(time[i].isStart){
			startB[B[id].f]++;
			endB[B[id].s]++;
			startA[A[id].f]++;
			endA[A[id].s]++;

			if(st.empty()){
				k = i;
				as = A[id].f;
				ae = A[id].s;
				bs = B[id].f;
				be = B[id].s;
				st.insert(id);
			}
			else if(max(A[id].f, as) <= min(ae, A[id].s)){
				st.insert(id);
				as = max(as, A[id].f);
				ae = min(ae, A[id].s);
				if(!(max(bs, B[id].f) <= min(be, B[id].s))){
					cout << "NO" << endl;
					return 0;
				}
				bs = max(bs, B[id].f);
				be = min(B[id].s, be);
			}
			else{
				k = i;
				st.clear();
				as = A[id].f;
				ae = A[id].s;
				if(max(B[id].f, bs) <= min(be, B[id].s)){
					cout << "NO" << endl;
					return 0;
				}
				bs = B[id].f;
				be = B[id].s;
				st.insert(id);
			}
		}
		else{
			if(st.size() > 1){
				// Update bs, be
				auto it = startB.find(B[id].f);
				
				it++;
				if(it == startB.end()){
					it--; it--;
					bs = it->f;
					it++;
					if(it->s == 1){
						startB.erase(it);
					}
					else{
						(it->s)--;
					}
				}
				else{
					it--;
					if(it->s == 1){
						startB.erase(it);
					}
					else{
						(it->s)--;
					}
				}
				

				it = endB.find(B[id].s);
				if(it == endB.begin()){
					if(it->s == 1){
						endB.erase(it);
					}
					else{
						(it->s)--;
					}

					it++;
					be = it->f;
				}
				else{
					if(it->s == 1){
						endB.erase(it);
					}
					else{
						(it->s)--;
					}
				}

				// Update as, ae
				it = startA.find(A[id].f);
				
				it++;
				if(it == startA.end()){
					it--; it--;
					as = it->f;
					it++;
					if(it->s == 1){
						startA.erase(it);
					}
					else{
						(it->s)--;
					}
				}
				else{
					it--;
					if(it->s == 1){
						startA.erase(it);
					}
					else{
						(it->s)--;
					}
				}



				it = endA.find(A[id].s);
				

				if(it == endA.begin()){
					if(it->s == 1){
						endA.erase(it);
					}
					else{
						(it->s)--;
					}

					it++;
					ae = it->f;
				}
				else{
					if(it->s == 1){
						endA.erase(it);
					}
					else{
						(it->s)--;
					}
				}
			}
			st.erase(id);
		}
	}

	pii C[n];
	for(int i = 0; i < n; i++){
		C[i] = A[i];
	}
	for(int i = 0; i < n; i++){
		A[i] = B[i];
		B[i] = C[i];
	}

	time.clear();
	for(int i = 0; i < n; i++){
		time.pb(Time(i, A[i].f, true));
		time.pb(Time(i, A[i].s, false));
	}

	sort(all(time), compare2);

	st.clear();

	startB.clear();
	endB.clear();
	startA.clear();
	endA.clear();

	for(int i = 0; i < 2*n; i++){
		int id = time[i].id;

		if(time[i].isStart){
			startB[B[id].f]++;
			endB[B[id].s]++;
			startA[A[id].f]++;
			endA[A[id].s]++;

			if(st.empty()){
				k = i;
				as = A[id].f;
				ae = A[id].s;
				bs = B[id].f;
				be = B[id].s;
				st.insert(id);
			}
			else if(max(A[id].f, as) <= min(ae, A[id].s)){
				st.insert(id);
				as = max(as, A[id].f);
				ae = min(ae, A[id].s);
				if(!(max(bs, B[id].f) <= min(be, B[id].s))){
					cout << "NO" << endl;
					return 0;
				}
				bs = max(bs, B[id].f);
				be = min(B[id].s, be);
			}
			else{
				k = i;
				st.clear();
				as = A[id].f;
				ae = A[id].s;
				if(max(B[id].f, bs) <= min(be, B[id].s)){
					cout << "NO" << endl;
					return 0;
				}
				bs = B[id].f;
				be = B[id].s;
				st.insert(id);
			}
		}
		else{
			if(st.size() > 1){
				// Update bs, be
				auto it = startB.find(B[id].f);
				
				it++;
				if(it == startB.end()){
					it--; it--;
					bs = it->f;
					it++;
					if(it->s == 1){
						startB.erase(it);
					}
					else{
						(it->s)--;
					}
				}
				else{
					it--;
					if(it->s == 1){
						startB.erase(it);
					}
					else{
						(it->s)--;
					}
				}
				

				it = endB.find(B[id].s);
				if(it == endB.begin()){
					if(it->s == 1){
						endB.erase(it);
					}
					else{
						(it->s)--;
					}

					it++;
					be = it->f;
				}
				else{
					if(it->s == 1){
						endB.erase(it);
					}
					else{
						(it->s)--;
					}
				}

				// Update as, ae
				it = startA.find(A[id].f);
				
				it++;
				if(it == startA.end()){
					it--; it--;
					as = it->f;
					it++;
					if(it->s == 1){
						startA.erase(it);
					}
					else{
						(it->s)--;
					}
				}
				else{
					it--;
					if(it->s == 1){
						startA.erase(it);
					}
					else{
						(it->s)--;
					}
				}



				it = endA.find(A[id].s);
				

				if(it == endA.begin()){
					if(it->s == 1){
						endA.erase(it);
					}
					else{
						(it->s)--;
					}

					it++;
					ae = it->f;
				}
				else{
					if(it->s == 1){
						endA.erase(it);
					}
					else{
						(it->s)--;
					}
				}
			}
			st.erase(id);
		}
	}

	cout << "YES" << endl;
}