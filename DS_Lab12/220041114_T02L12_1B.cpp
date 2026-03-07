#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> buildsparse(const vector<int> &a)
{
    int n = a.size();
    int max_log = floor(log2(n)) + 1;
    vector<vector<int>> sparse(n, vector<int>(max_log, INT_MAX));
    for (int i = 0; i < a.size(); i++)
    {
        sparse[i][0] = a[i];
    }
    for (int j = 1; j < max_log; j++)
    {
        for (int i = 0; i + (1 << j) - 1 < n; i++)
        {
            sparse[i][j] = min(sparse[i][j - 1], sparse[i + (1 << j) - 1][j - 1]);
        }
    }
    return sparse;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> table = buildsparse(a);
    cout << "Ranges to be stored in Sparse Table:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < floor(log2(n)); j++)
        {
            if (i + (1 << j) <= n)
            {
                cout << "(" << i << "," << i + (1 << j) - 1 << ")";
            }
        }
        cout << endl;
    }
    cout << "Status of Sparse Table:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= floor(log2(n)); j++)
        {
            if (i + (1 << j) - 1 < n)
            {
                cout << table[i][j] << " ";
            }
        }
        cout << endl;
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;
        int window = r - l + 1;
        int j = floor(log2(window));
        cout << "\nQuery-" << i << ": Min=" << min(table[l][j], table[r - (1 << j) + 1][j]) << " min([" << l + 1 << "," << r + 1 << "])" << endl;
    }
}