#include <iostream>
#include <fstream>
#include <limits>
#include <set>
using namespace std;

int knapsack1(int w[], int p[], int N, int C)
{
    int **DP = new int*[N + 1];
    
    for (int i = 0; i <= N; i++) {
        DP[i] = new int[C + 1];
        
        DP[i][0] = 0;
    }

    for (int j = 0; j <= C; j++) {
        DP[0][j] = 0;
    }



    for (int i = 1; i <= N; i++) {
        for (int c = 1; c <= C; c++) {
            if (w[i - 1] <= c) {
                DP[i][c] = max(DP[i - 1][c - w[i - 1]] + p[i - 1], DP[i - 1][c]);
            } else {
                DP[i][c] = DP[i - 1][c];
            }
        }
    }

    int ret_val = DP[N][C];

    for (int i = 0; i <= N; i++) {
        delete [] DP[i];
    }
    delete [] DP;

    return ret_val;
}

int knapsack2rec(int w[], int p[], int i, int c, int **DP)
{
    if (c < 0) {
        return INT16_MIN;
    } else if (i < 0 || c == 0) {
        return 0;
    } else {
        
        if (DP[i][c] < 0) {
            int ntaken = knapsack2rec(w, p, i - 1, c, DP);
            int taken = knapsack2rec(w, p, i - 1, c - w[i], DP) + p[i];
            DP[i][c] = max(ntaken, taken);
        }

        return DP[i][c];
    }
}

int knapsack2(int w[], int p[], int N, int C)
{
    int **DP = new int*[N];
    for (int i = 0; i < N; i++) {
        DP[i] = new int[C + 1];
        for (int j = 0; j <= C; j++) {
            DP[i][j] = -1;
        }
    }

    int ret_val = knapsack2rec(w, p, N - 1, C, DP);

    for (int i = 0; i < N; i++) {
        delete [] DP[i];
    }
    delete [] DP;

    return ret_val;
}

int knapsack3(int w[], int p[], int i, int c, set<pair<int,int>> S)
{
    return 0;
}

int knapsack3(int w[], int p[], int N, int C)
{
    set<pair<int,int>> S;

    return 0;
}

int main() {

    ifstream in("input.txt");
    ofstream out("output.txt");

    int *w, *p, n, c;

    in >> c >> n;

    w = new int[n];
    p = new int[n];

    for (int i = 0; i < n; i++) {
        in >> w[i] >> p[i];
    }

    out << knapsack3(w, p, n, c);

    delete [] w;
    delete [] p;

    return 0;
}