#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int n, a[4];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sort(a, a+n);

    if (n == 0) printf("YES\n1\n1\n3\n3\n");
    else if (n == 1) printf("YES\n%d\n%d\n%d\n", a[0], 3*a[0], 3*a[0]);
    else if (n == 4) {
        if ((a[0] + a[1] + a[2] + a[3]) / 4 == (a[1] + a[2]) / 2 && (a[1] + a[2]) / 2 == a[3] - a[0]) printf("YES\n");
        else printf("NO\n");
    }
    else if (n == 2) {
        if (3*a[0] < a[1]) printf("NO\n");
        else printf("YES\n%d\n%d\n", 4*a[0] - a[1], 3*a[0]);
    }
    else {
        if (3*a[0] < a[2]) printf("NO\n");
        else if ((a[0] + a[1] + a[2] + 3*a[0]) / 4 == (a[1] + a[2]) / 2 && (a[1] + a[2]) / 2 == 2*a[0]) printf("YES\n%d\n", 3*a[0]);
        else if ((a[2]/3 + a[0] + a[1] + a[2]) / 4 == (a[0] + a[1]) / 2 && (a[0] + a[1]) / 2 == a[2] - a[2]/3) printf("YES\n%d\n", a[2]/3);
        else if ((a[0] + a[1] + (a[0] + a[2] - a[1]) + a[2]) / 4 == (a[1] + (a[0] + a[2] - a[1])) / 2 && (a[1] + (a[0] + a[2] - a[1])) / 2 == a[2] - a[0]) printf("YES\n%d\n", (a[0] + a[2] - a[1]));
        else printf("NO\n");
    }

    return 0;
}
