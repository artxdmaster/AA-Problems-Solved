#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct subset {
    int parent;
    int rank;
} subsets[110];

struct edge {
    int from;
    int to;
    int dist;
} edges[11000];

bool compare(edge x, edge y) {
    return x.dist < y.dist;
}

int find(struct subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int main() {
    int n, m, c = 0;

    while (scanf("%d %d", &n, &m), n) {
        c++;
        for (int i = 0; i <= n; i++) {
            subsets[i].parent = i;
            subsets[i].rank = 0;
        }

        for (int i = 0; i < m; i++)
            scanf("%d %d %d", &edges[i].from, &edges[i].to, &edges[i].dist);

        sort(edges, edges+m, compare);

        vector < pair < int, int > > ramos;
        for (int i = 0; i < m; i++) {
            int x = find(subsets, edges[i].from);
            int y = find(subsets, edges[i].to);

            if (x != y) {
                Union(subsets, edges[i].from, edges[i].to);
                if (edges[i].from <= edges[i].to)
                    ramos.push_back(make_pair(edges[i].from, edges[i].to));
                else
                    ramos.push_back(make_pair(edges[i].to, edges[i].from));
            }
        }

        printf("Teste %d\n", c);

        for (int i = 0; i < ramos.size(); i++) {
            printf("%d %d\n", ramos[i].first, ramos[i].second);
        }

        printf("\n");

    }

    return 0;
}
