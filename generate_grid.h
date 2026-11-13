#ifndef GENERATE_GRID
#define GENERATE_GRID
#define WALL_CHAR '*'
#define fmax(a, b) ((a) > (b) ? (a) : (b))
#define acc(grid, i, j) ((grid)[(i) * (c) + j])
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string.h>
using std::cin;
using std::cout;
using std::endl;

static void fill_walls(char *grid, int r, int c) {
    //10% walls
    int nwalls = fmax(r * c / 10, 1), rr, cc;
    for (int i = 0; i < nwalls; i++) {
        do {
            rr = rand() % r, cc = rand() % c; //pick a random cell
        } while (acc(grid, rr, cc) == WALL_CHAR);
        acc(grid, rr, cc) = WALL_CHAR;
    }
}

static char *generate(int r, int c) {
    srand(time(NULL));
    size_t sz = sizeof(char) * r * c;
    char *grid = (char *)malloc(sz);
    memset(grid, '.', sz);
    fill_walls(grid, r, c);
    return grid;
}

static void print_grid(char *grid, int r, int c) {
    cout << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << acc(grid, i, j) << " ";
        }
        cout << "\n";
    }
    cout << endl;
}

#endif
