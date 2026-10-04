#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs_pat(int teme, int protok, const vector<vector<int>>& kapacitet, vector<vector<int>>& matrica_protok, vector<bool>& poseteni, vector<int>& roditel) {
    if (teme == protok) {
        return true;
    }
    poseteni[teme] = true;

    for (int sosed = 0; sosed < kapacitet.size(); ++sosed) {
        if (!poseteni[sosed] && kapacitet[teme][sosed] - matrica_protok[teme][sosed] > 0) {
            roditel[sosed] = teme;
            if (dfs_pat(sosed, protok, kapacitet, matrica_protok, poseteni, roditel)) {
                return true;
            }
        }
    }
    return false;
}

int ford_fulkerson(int izvor, int protok, int broj_jazli, const vector<vector<int>>& kapacitet) {
    vector<vector<int>> matrica_protok(broj_jazli, vector<int>(broj_jazli, 0));
    vector<int> roditel(broj_jazli);
    int maksimalen_protok = 0;

    while (true) {
        vector<bool> poseteni(broj_jazli, false);
        roditel[izvor] = -1;
        if (!dfs_pat(izvor, protok, kapacitet, matrica_protok, poseteni, roditel)) {
            break;
        }

        int tekoven_minimum = 1e9;
        for (int v = protok; v != izvor; v = roditel[v]) {
            int u = roditel[v];
            tekoven_minimum = min(tekoven_minimum, kapacitet[u][v] - matrica_protok[u][v]);
        }

        for (int v = protok; v != izvor; v = roditel[v]) {
            int u = roditel[v];
            matrica_protok[u][v] += tekoven_minimum;
            matrica_protok[v][u] -= tekoven_minimum;
        }

        maksimalen_protok += tekoven_minimum;
    }

    return maksimalen_protok;
}

int main() {
    int broj_jazli, broj_rebra;
    cin >> broj_jazli >> broj_rebra;

    vector<vector<int>> kapacitet(broj_jazli, vector<int>(broj_jazli, 0));

    for (int i = 0; i < broj_rebra; ++i) {
        int u, v, k;
        cin >> u >> v >> k;
        kapacitet[u][v] = k;
    }

    int izvor, protok;
    cin >> izvor >> protok;

    cout << ford_fulkerson(izvor, protok, broj_jazli, kapacitet) << endl;

    return 0;
}
