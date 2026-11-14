#include "generate_grid.h"
// #include <iostream>
#include <string.h>
// #include <cstring>
// #include <fstream>
#include <vector>
#define NVALID_POS(i, j, r, c, grid, seen) \
    ((i) < 0 || (i) >= (r) || (j) < 0 || (j) >= (c) || (acc((grid),(i), (j)) == (WALL_CHAR)) || acc((seen),(i), (j)))
using std::vector;
using std::pair;
// using std::ifstream;
using std::string;
using std::endl;

//int solve(int r, int c, char grid[][c], int k, int sr, int sc) {
int solve(int r, int c, char *grid, int k, int sr, int sc) {
    pair<int, int> cur;
    vector<pair<int, int>> expl = {{sr, sc}}; //explore
    char seen[r * c], dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1}; memset(seen, 0, sizeof(seen));
    int count = acc(grid, sr, sc) != WALL_CHAR, t, nr, nc;
    if (!count) return 0; //starting at a wall
    acc(seen, sr, sc) = 1;
    for (int i = 0; i < k && !expl.empty(); i++) { //at most k many steps
        vector<pair<int, int>> next;
        t = expl.size();
        for (int j = 0; j < t; j++) {
            cur = expl[j];
            for (int x = 0; x < 4; x++) {
                nr = cur.first + dr[x], nc = cur.second + dc[x];
                if (NVALID_POS(nr, nc, r, c, grid, seen)) continue; //skip
                count++;
                acc(seen, nr, nc) = 1;
                next.push_back((pair<int, int>){nr, nc});
            }
        }
        expl.swap(next);
    }
    return count;
}

//source, destination
#define macro_v DO_NOT_USE_FOR_VARIABLE_NAME
#define string_copy(s, d) \
    for (int macro_v = 0; (s)[macro_v]; macro_v++) (d)[macro_v] = (s)[macro_v];
int main() {
    int r, c, k, sr, sc, count;
    cout << "Usage: ROW COL K START_ROW START_COL\n";
    cin >> r >> c >> k >> sr >> sc;
    char *grid = generate(r, c);
    cout << "generated\n";
    print_grid(grid, r, c);
    /*
    ifstream input("grid.txt");
    if (!input) return 1; //file not found
    char read;
    string buffer;
    int index = 0;
    while (input.get(read)) {
        if (read != '\n') buffer += read;
        else {
            string_copy(buffer, &acc(grid, index, 0));
            index++;
            buffer.clear();
        }
    }
    if (buffer[0]) string_copy(buffer, &acc(grid, index, 0));
//int solve(int r, int c, char grid[][c], int k, int sr, int sc) {
*/
    count = solve(r, c, grid, k, sr, sc);
    free(grid);
    //read from a file called grid.txt
    //take_input() for the board somehow
    //call solve()
    cout << count << endl;
    return 0;
}
// int solve(int r, int c, char grid[], int k, int sr, int sc) {
//     //total row, total col, grid is grid, k is max steps, start row, start col
//     // vector<pair<int, int>> it = {sr, sc};
//     vector<pair<int, int>> it = {{sr, sc}};
//     signed char mr[] = {1, -1, 0, 0}, mc[] = {0, 0, 1, -1}, seen[r][c];
//     memset(seen, 0, sizeof(seen));
//     seen[sr][sc] = 1;
//     int count = 1;
//     for (int i = 0; i < k && !it.empty(); i++) { //go at most k many steps
//         vector<pair<int, int>> next;
//         int sz = it.size();
//         for (int j = 0; j < sz; j++) {
//             for (int x = 0; x < 4; x++) {
//                 int nr = r + mr[x], nc = c + mc[x];
//                 // if (nr < 0 || nr >= r || nc < 0 || nc >= c || grid[nr][nc] || seen[nr][nc]) continue;
//                 if (NVALID_POS(nr, nc, r, c, grid, seen)) continue;
//                 seen[nr][nc] = 1;
//                 next.push_back({nr, nc});
//                 count++;
//             }
//         }
//         it.swap(next);
//
//     }
//     return count;
// }
