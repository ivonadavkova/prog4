//dfs al
#include <iostream>
#include <vector>

using namespace std;

void dfs_dlabocina(int teme, const vector<vector<int>>& sosedstvo, vector<bool>& poseteni) {
    poseteni[teme] = true;
    cout << teme << " ";

    for (int sosed : sosedstvo[teme]) {
        if (!poseteni[sosed]) {
            dfs_dlabocina(sosed, sosedstvo, poseteni);
        }
    }
}

void izminuvanje_graf(int broj_jazli, const vector<vector<int>>& sosedstvo) {
    vector<bool> poseteni(broj_jazli, false);

    for (int i = 0; i < broj_jazli; ++i) {
        if (!poseteni[i]) {
            dfs_dlabocina(i, sosedstvo, poseteni);
        }
    }
}

int main() {
    int broj_jazli = 5;
    vector<vector<int>> sosedstvo(broj_jazli);

    sosedstvo[0] = {1, 2};
    sosedstvo[1] = {0, 3, 4};
    sosedstvo[2] = {0};
    sosedstvo[3] = {1};
    sosedstvo[4] = {1};

    izminuvanje_graf(broj_jazli, sosedstvo);

    return 0;
}
