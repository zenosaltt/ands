/*
 * STRING MATCHING APPROSSIMATO
 * 
 * 
 * 
 * DP[i][j] = "minimo valore di k di un'occorrenza k-approssimata del pattern P(i) nel testo T(j) e terminante in T[j]"
 * 
 * 
 * 
 *            0                                      i = 0
 * DP[i][j] = i                                      j = 0
 *            max{                                   i,j > 0
 *                DP[i - 1][j - 1] + (P[i] != U[j]),
 *                DP[i - 1][j],
 *                DP[i][j - 1]
 *            }
 */           

#include <iostream>
#include <cstring>
using namespace std;

int fun(char *P, char *T)
{
    int i, j;

    int p = strlen(P);
    int t = strlen(T);

    int **DP = new int*[p + 1];
    for (i = 0; i <= p; i++) {
        DP[i] = new int[t + 1];

        DP[i][0] = i;
    }

    for (j = 0; j <= t; j++) {
        DP[0][j] = 0;
    }


    for (i = 1; i <= p; i++) {
        for (j = 1; j <= t; j++) {
            DP[i][j] = 0;

            DP[i][j] = std::max(DP[i][j], DP[i - 1][j - 1] + (P[i] != T[j] ? 1 : 0));
            DP[i][j] = std::max(DP[i][j], DP[i - 1][j]);
            DP[i][j] = std::max(DP[i][j], DP[i][j - 1]);
        }
    }

    //TODO find max in the last row

    for (i = 0; i <= p; i++) {
        delete [] DP[i];
    }
    delete [] DP;
}

int main()
{

    return 0;
}