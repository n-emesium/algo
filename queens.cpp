#define pb push_back
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using std::cout;
using std::string;
using std::vector;
using std::ostream;
void populate(vector<vector<string>>& ans, int n, char *cur, char *cfull, int p);
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    char cur[n * n];
    char cfull[n];
    memset(cfull, 0, sizeof(cfull));
    memset(cur, '.', sizeof(cur));
    populate(ans, n, cur, cfull, 0);
    return ans;
}

#define qcheck(a) ((a) >= 0 && a < n)
#define isq(a, b) (*(cur + a * n + b) == 'Q')
    char valid(int n, char *cur, int r, int c) { //check diagonal
        int rr = 1;
        while (rr < n) {
            int i1 = r - rr, j1 = c + rr, j2 = c - rr;
            int qi1 = qcheck(i1), qj1 = qcheck(j1), qj2 = qcheck(j2);
            if (qi1 && qj1 && isq(i1, j1)) return 0;
            if (qi1 && qj2 && isq(i1, j2)) return 0;
            rr++;
        }
        return 1;
    }
// char valid(int n, char cur[n][n], int r, int c)
vector<string> convert(int n, char *cur);
void populate(vector<vector<string>>& ans, int n, char *cur, char *cfull, int p) {
    if (p == n) {
        ans.pb(convert(n, cur));
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!cfull[i] && valid(n, cur, p, i)) {
            cfull[i] = 1;
            int cache = p * n + i;
            *(cur + cache) = 'Q';
            populate(ans, n, cur, cfull, p + 1);
            cfull[i] = 0;
            *(cur + cache) = '.';
        }
    }
}


    vector<string> convert(int n, char *cur) {
        vector<string> ret(n);
        for (int i = 0; i < n; i++) {
            string str = "";
            for (int j = 0; j < n; j++) {
                str += *(cur + i * n + j);
            }
            ret[i] = str;
        }
        return ret;
    }


static inline int matoi(char * __restrict p) {
    int c = 0;
    while (*p && (c = 10 * c + (*p++ - '0')));
    return c;
}


ostream& operator<<(ostream& os, vector<vector<string>> ans) {
    size_t sz = ans.size();
    for (size_t i = 0; i < sz; i++) {
        size_t mv = ans[i].size();
        for (int j = 0; j < mv; j++) {
            for (int x = 0; x < mv; x++) {
                os << ans[i][j][x] << " ";
            }
            os << "\n";
        }
        os << "\n\n";
    }
    return os;
}

int main(int argc, char *argv[]) {
    if (argc == 1) return -1;
    int n = matoi(argv[1]);
    if (n) {
        vector<vector<string>> ans = solveNQueens(n);
        cout << ans;
        cout << "Number of solutions for " << n << " x " << n << " many squares is: " << ans.size() << "\n";
    }
    return 0;
}
