//dfs el
#include <iostream>
#include <vector>

using namespace std;

struct Rebro {
    int od_jazol;
    int do_jazol;
};

void dfs_dlabocina(int teme, const vector<Rebro>& lista_rebra, vector<bool>& poseteni) {
    poseteni[teme] = true;
    cout << teme << " ";

    for (const auto& rebro : lista_rebra) {
        if (rebro.od_jazol == teme && !poseteni[rebro.do_jazol]) {
            dfs_dlabocina(rebro.do_jazol, lista_rebra, poseteni);
        } else if (rebro.do_jazol == teme && !poseteni[rebro.od_jazol]) {
            dfs_dlabocina(rebro.od_jazol, lista_rebra, poseteni);
        }
    }
}

void izminuvanje_graf(int broj_jazli, const vector<Rebro>& lista_rebra) {
    vector<bool> poseteni(broj_jazli, false);

    for (int i = 0; i < broj_jazli; ++i) {
        if (!poseteni[i]) {
            dfs_dlabocina(i, lista_rebra, poseteni);
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
