//bfs al
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs_sirina(int poceten_jazol, const vector<vector<int>>& sosedstvo, vector<bool>& poseteni) {
    queue<int> redica;

    poseteni[poceten_jazol] = true;
    redica.push(poceten_jazol);

    while (!redica.empty()) {
        int teme = redica.front();
        redica.pop();

        cout << teme << " ";

        for (int sosed : sosedstvo[teme]) {
            if (!poseteni[sosed]) {
                poseteni[sosed] = true;
                redica.push(sosed);
            }
        }
    }
}

void izminuvanje_graf(int broj_jazli, const vector<vector<int>>& sosedstvo) {
    vector<bool> poseteni(broj_jazli, false);

    for (int i = 0; i < broj_jazli; ++i) {
        if (!poseteni[i]) {
            bfs_sirina(i, sosedstvo, poseteni);
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
