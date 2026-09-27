//bfs am

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs_sirina(int poceten_jazol, const vector<vector<int>>& matrica_sosedstvo, vector<bool>& poseteni) {
    queue<int> redica;

    poseteni[poceten_jazol] = true;
    redica.push(poceten_jazol);

    while (!redica.empty()) {
        int teme = redica.front();
        redica.pop();

        cout << teme << " ";

        for (int sosed = 0; sosed < matrica_sosedstvo.size(); ++sosed) {
            if (matrica_sosedstvo[teme][sosed] == 1 && !poseteni[sosed]) {
                poseteni[sosed] = true;
                redica.push(sosed);
            }
        }
    }
}

void izminuvanje_graf(int broj_jazli, const vector<vector<int>>& matrica_sosedstvo) {
    vector<bool> poseteni(broj_jazli, false);

    for (int i = 0; i < broj_jazli; ++i) {
        if (!poseteni[i]) {
            bfs_sirina(i, matrica_sosedstvo, poseteni);
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
