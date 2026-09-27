//bfs el
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Rebro {
    int od_jazol;
    int do_jazol;
};

void bfs_sirina(int poceten_jazol, const vector<Rebro>& lista_rebra, vector<bool>& poseteni) {
    queue<int> redica;

    poseteni[poceten_jazol] = true;
    redica.push(poceten_jazol);

    while (!redica.empty()) {
        int teme = redica.front();
        redica.pop();

        cout << teme << " ";

        for (const auto& rebro : lista_rebra) {
            if (rebro.od_jazol == teme && !poseteni[rebro.do_jazol]) {
                poseteni[rebro.do_jazol] = true;
                redica.push(rebro.do_jazol);
            } else if (rebro.do_jazol == teme && !poseteni[rebro.od_jazol]) {
                poseteni[rebro.od_jazol] = true;
                redica.push(rebro.od_jazol);
            }
        }
    }
}

void izminuvanje_graf(int broj_jazli, const vector<Rebro>& lista_rebra) {
    vector<bool> poseteni(broj_jazli, false);

    for (int i = 0; i < broj_jazli; ++i) {
        if (!poseteni[i]) {
            bfs_sirina(i, lista_rebra, poseteni);
        }
    }
}

int main() {
    int broj_jazli = 5;
    vector<Rebro> lista_rebra = {
        {0, 1},
        {0, 2},
        {1, 3},
        {1, 4}
    };

    izminuvanje_graf(broj_jazli, lista_rebra);

    return 0;
}
