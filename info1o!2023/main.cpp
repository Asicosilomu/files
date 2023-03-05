#include <fstream>
#include <algorithm>

using namespace std;

ifstream in("sosete.in");
ofstream out("sosete.out");

int main() {
    int n, x, p, m; in >> n; in >> x; int v[n]; bool blacklist[100001]; p = 0; m = n - 1;
    for (int i = 0; i < n; i++) in >> v[i];
    for (int i = 0; i < m; i++)
    {
        int n1 = v[i];
        if (blacklist[n1] != 1 && n1 != 0)
        {
            int p2 = p;
            int target = x - n1;
            for (int i2 = i + 1; i2 < n; i2++)
            {
                int n2 = v[i2];
                if (n2 != 0 && n2 == target) { p++; v[i2] = 0; break; };
            }
            if (p2 == p) { blacklist[n1] = 1; };
        };
    };
    out << p;
    in.close(); out.close();
    return 0;
}
