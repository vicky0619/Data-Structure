#include<bits/stdc++.h>
using namespace std;

int find_anc(int node, int anc[]) {
    if (anc[node] == node) {
        return node;
    }
    return anc[node] = find_anc(anc[node], anc);
}

int main() {
    int c, t, total = 0;
    cin >> c >> t;
    set<pair<int, pair<int, int>>> roads;
    set<pair<int, int>> result;
    int anc[c + 1];

    for (int i = 1; i <= c; i++) {
        anc[i] = i;
    }

    while (t--) {
        int u, v, n;
        cin >> u >> v >> n;
        roads.insert((u < v) ? make_pair(n, make_pair(u, v)) : make_pair(n, make_pair(v, u)));
    }

    for (auto i = roads.begin(); i != roads.end(); i++) {
        if (find_anc((i->second).first, anc) != find_anc((i->second).second, anc)) {
            result.insert(make_pair((i->second).first, (i->second).second));
            total += i->first;
            anc[find_anc((i->second).second, anc)] = find_anc((i->second).first, anc);

        }
    }

    cout << total << endl;
    for (auto i = result.begin(); i != result.end(); ++i) {
        cout << "city" << i->first << " - city" << i->second<<endl;
    }
}
