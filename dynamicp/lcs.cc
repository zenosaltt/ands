#include <iostream>
using namespace std;

int lcs(int T[], int U[], int n, int m)
{
    int **DP = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        DP[i] = new int[m + 1];
    }

    for (int i = 0; i <= n; i++) {
        DP[i][0] = 0;
    }

    for (int j = 0; j <= m; j++) {
        DP[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (T[i - 1] == U[j - 1]) {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            } else {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    int ret = DP[n][m];

    for (int i = 0; i <= n; i++) {
        delete [] DP[i];
    }
    delete [] DP;

    return ret;
}

int main() {

    int A[] = {7, 4, 6, 6, 8, 7};
    int B[] = {4, 7, 8, 6, 8, 0};

    cout << lcs(A, B, 6, 6) << endl;
    
    return 0;
}