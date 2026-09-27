//dfs am
#include <iostream>
#include <vector>

using namespace std;

void dfs_dlabocina(int teme, const vector<vector<int>>& matrica_sosedstvo, vector<bool>& poseteni) {
    poseteni[teme] = true;
    cout << teme << " ";

    for (int sosed = 0; sosed < matrica_sosedstvo.size(); ++sosed) {
        if (matrica_sosedstvo[teme][sosed] == 1 && !poseteni[sosed]) {
            dfs_dlabocina(sosed, matrica_sosedstvo, poseteni);
        }
    }
}

void izminuvanje_graf(int broj_jazli, const vector<vector<int>>& matrica_sosedstvo) {
    vector<bool> poseteni(broj_jazli, false);

    for (int i = 0; i < broj_jazli; ++i) {
        if (!poseteni[i]) {
            dfs_dlabocina(i, matrica_sosedstvo, poseteni);
        }
    }
}

int main() {
    int broj_jazli = 5;
    vector<vector<int>> matrica_sosedstvo = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0}
    };

    izminuvanje_graf(broj_jazli, matrica_sosedstvo);

    return 0;
}
