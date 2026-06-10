#include <bits/stdc++.h>
using namespace std;

// add actual functions
int addM(int a, int b) { return a + b; }
int mulM(int a, int b) { return a * b; }

struct Matrix
{
    vector<vector<int>> mat;
    int n;
    Matrix(int sz)
    {
        n = sz;
        mat.assign(n, vector<int>(n, 0));
    }
    Matrix operator*(const Matrix &other) const
    {
        Matrix res(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    res.mat[i][j] =
                        addM(res.mat[i][j], mulM(mat[i][k], other.mat[k][j]));
                }
            }
        }
        return res;
    }
};

Matrix matExp(Matrix base, int power)
{
    int n = base.n;
    Matrix res(n);
    for (int i = 0; i < n; i++)
        res.mat[i][i] = 1;
    while (power > 0)
    {
        if (power & 1)
            res = res * base;
        base = base * base;
        power >>= 1;
    }
    return res;
}

int main() { return 0; }
