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
int ford_fulkerson(int izvor, int protok, const vector<pair<int,int>>& rebra, const vector<int>& kapaciteti, int broj_jazli) {
    vector<vector<int>> kapacitet(broj_jazli, vector<int>(broj_jazli, 0));

    for (size_t i = 0; i < rebra.size(); ++i) {
        int u = rebra[i].first;
        int v = rebra[i].second;
        kapacitet[u][v] = kapaciteti[i];
    }

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
    //FF Killer test case
    vector<pair<int,int>> FF_killer = {
        {0,1}, {1,0},
        {0,2}, {2,0},
        {1,3}, {3,1},
        {2,1}, {1,2},
        {2,3}, {3,2}
    };
    vector<int> FF_killer_caps = {
        8,0, 8,0, 8,0, 1,0, 8,0
    };
    cout << "FF Killer max flow: " << ford_fulkerson(0,3,FF_killer,FF_killer_caps,4) << '\n';


    //CP4X8531 test case
    vector<pair<int,int>> cp4x8531 = {
        {0,1},{1,0}, {0,2},{2,0}, {0,3},{3,0},
        {1,6},{6,1}, {1,5},{5,1}, {1,4},{4,1},
        {2,5},{5,2}, {3,5},{5,3},
        {4,7},{7,4}, {5,7},{7,5}, {6,7},{7,6}
    };
    vector<int> cp4x8531_caps = {
        1,0, 1,0, 1,0,
        1,0, 1,0, 1,0,
        1,0, 1,0,
        1,0, 1,0, 1,0
    };
    cout << "CP4X8531 max flow: " << ford_fulkerson(0,7,cp4x8531,cp4x8531_caps,8) << '\n';


    //CS4234MFDemo test case
    vector<pair<int,int>> cs4234mfdemo = {
        {0,1},{1,0}, {0,2},{2,0}, {0,3},{3,0},
        {1,2},{2,1}, {1,5},{5,1}, {1,4},{4,1},
        {2,5},{5,2}, {2,3},{3,2}, {3,6},{6,3},
        {4,5},{5,4}, {4,7},{7,4}, {5,6},{6,5},
        {5,7},{7,5}, {6,7},{7,6}, {6,2},{2,6}
    };
    vector<int> cs4234mfdemo_caps={
        10,0, 5,0, 15,0,
        4,0, 15,0, 9,0,
        8,0, 4,0, 16,0,
        15,0, 10,0, 15,0,
        10,0, 10,0, 6,0
    };
    cout << "CS4234 MF Demo max flow: " << ford_fulkerson(0,7,cs4234mfdemo,cs4234mfdemo_caps,8) << '\n';


    //Matching with Capacity test case
    vector<pair<int,int>> mwc = {
        {0,1},{1,0},
        {0,2},{2,0},
        {1,3},{3,1},
        {1,4},{4,1},
        {2,4},{4,2},
        {3,5},{5,3},
        {4,5},{5,4}
    };
    vector<int> mwc_caps={
        1,0, 3,0, 99,0, 99,0, 99,0, 2,0, 2,0
    };
    cout << "Matching with Capacity max flow: " << ford_fulkerson(0,5,mwc,mwc_caps,6) << '\n';

    return 0;
}
