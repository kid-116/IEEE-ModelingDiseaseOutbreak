// https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef tuple<short, short, short> edge; 
typedef vector<int> vi;

int main() {
    short N;
    int M;
    cin >> N >> M;
    vector<edge> e(M);
    for(int i = 0; i < M; i++) {
        short a, b;
        short w;
        cin >> a >> b >> w;
        --a; --b;
        e[i] = make_tuple(w, a, b);
    }
    sort(e.begin(), e.end());
    vi set_id(N);
    for(int i = 0; i < N; i++) {
        set_id[i] = i;
    }
    int sum = 0;
    for(int i = 0; i < M; i++) {
        short a = get<1>(e[i]), b = get<2>(e[i]);
        short w = get<0>(e[i]);
        if(set_id[a] != set_id[b]) {
            sum += w;
            int id = set_id[a];
            for(int j = 0; j < N; j++) {
                if(set_id[j] == id) {
                    set_id[j] = set_id[b];
                }
            }
        }
        // for(int k = 0; k < N; k++) {
        //     cout << set_id[k] << " ";
        // }
        // cout << "\n";
    }
    cout << sum << "\n";
    return 0;
}