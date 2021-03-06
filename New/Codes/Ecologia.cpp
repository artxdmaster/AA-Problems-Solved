#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n, m, nums[55][55];

#define pii pair < int, int >

struct piece {
    vector < pii > coords;
    int min_x, max_x, min_y, max_y;

    piece(vector < pii > cds, int a, int b, int c, int d) {
        coords = cds;
        min_x = a, max_x = b, min_y = c, max_y = d;
    }

    bool operator < (piece other) const {
        for (int j = 1; j < (int) coords.size(); j++) {
            int dif_a = coords[j].first - coords[j-1].first;
            int dif_b = coords[j].second - coords[j-1].second;
            int dif_c = other.coords[j].first - other.coords[j-1].first;
            int dif_d = other.coords[j].second - other.coords[j-1].second;

            if (dif_a < dif_c) return true;
            if (dif_a > dif_c) return false;
            if (dif_b < dif_d) return true;
            if (dif_b > dif_d) return false;
        }
        return false;
    }
};

set < piece > pieces[15];
vector < piece > pieces1[15];

vector < pii > find_bordas(piece p) {
    vector < pii > result;

    for (int i = 0; i < (int) p.coords.size(); i++) {
        bool a = true, b = true, c = true, d = true;
        pii pa = make_pair(p.coords[i].first+1, p.coords[i].second);
        pii pb = make_pair(p.coords[i].first-1, p.coords[i].second);
        pii pc = make_pair(p.coords[i].first, p.coords[i].second+1);
        pii pd = make_pair(p.coords[i].first, p.coords[i].second-1);

        for (int j = 0; j < (int) p.coords.size(); j++) {
            if (p.coords[j] == pa) a = false;
            else if (p.coords[j] == pb) b = false;
            else if (p.coords[j] == pc) c = false;
            else if (p.coords[j] == pd) d = false;
        }

        if (a) result.push_back(pa);
        if (b) result.push_back(pb);
        if (c) result.push_back(pc);
        if (d) result.push_back(pd);
    }

    return result;
}

void generate_pieces(int siz) {
    for (set < piece >::iterator it = pieces[siz-1].begin(); it != pieces[siz-1].end(); it++) {
        vector < pii > bordas = find_bordas(*it);

        for (int j = 0; j < (int) bordas.size(); j++) {
            vector < pii > aux = (*it).coords;
            aux.push_back(bordas[j]);

            sort(aux.begin(), aux.end());

            piece p = piece(aux, min((*it).min_x, bordas[j].first),
                                 max((*it).max_x, bordas[j].first),
                                 min((*it).min_y, bordas[j].second),
                                 max((*it).max_y, bordas[j].second));

            if (!pieces[siz].count(p))
                pieces[siz].insert(p);
        }
    }
}

int main() {
    //Generating poliominos
    vector < pii > aux;
    aux.push_back(make_pair(0, 0));
    pieces[1].insert(piece(aux, 0, 0, 0, 0));

    for (int i = 2; i <= 10; i++)
        generate_pieces(i);

    for (int i = 0; i <= 10; i++)
        for (set < piece >::iterator it = pieces[i].begin(); it != pieces[i].end(); it++)
            pieces1[i].push_back(*it);

    //Code
    while(scanf("%d %d", &n, &m) != EOF) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &nums[i][j]);

        int maximum = 0;
        for (int k = 0; k < (int) pieces1[m].size(); k++) {
            for (int i = max(0, -pieces1[m][k].min_x); i < n - pieces1[m][k].max_x; i++)
                for (int j = max(0, -pieces1[m][k].min_y); j < n - pieces1[m][k].max_y; j++) {
                    int x = 0;
                    for (int l = 0; l < (int) pieces1[m][k].coords.size(); l++)
                        x += nums[i+pieces1[m][k].coords[l].first][j+pieces1[m][k].coords[l].second];

                    maximum = max(maximum, x);
                }
        }
        printf("%d\n", maximum);
    }
    return 0;
}
