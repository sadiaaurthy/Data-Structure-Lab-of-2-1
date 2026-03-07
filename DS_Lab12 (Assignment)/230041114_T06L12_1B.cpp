#include <iostream>
#include <vector>
using namespace std;

void DFS(int x, int y, vector<vector<int> >& grid, vector<vector<bool> >& visited) {
    visited[x][y] = true;

    int m = grid.size();
    int n = grid[0].size();

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
            if (!visited[nx][ny] && grid[nx][ny] >= grid[x][y]) {
                DFS(nx, ny, grid, visited);
            }
        }
    }
}

int main() {
    int m, n, x;
    cin >> m >> n;
    vector<vector<int> > grid;
    vector<vector<bool> > green;
    vector<vector<bool> > red;

    for (int i = 0; i < m; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            cin >> x;
            row.push_back(x);
        }
        grid.push_back(row);
    }
    
    for (int i = 0; i < m; i++) {
        vector<bool> r1;
        vector<bool> r2;
        for (int j = 0; j < n; j++) {
            r1.push_back(false);
            r2.push_back(false);
        }
        green.push_back(r1);
        red.push_back(r2);
    }

    for (int j = 0; j < n; j++) {
        if (!green[0][j]) {
            DFS(0, j, grid, green);
        }
    }
    for (int i = 0; i < m; i++) {
        if (!green[i][0]) {
            DFS(i, 0, grid, green);
        }
    }

    for (int j = 0; j < n; j++) {
        if (!red[m - 1][j]) {
            DFS(m - 1, j, grid, red);
        }
    }
    for (int i = 0; i < m; i++) {
        if (!red[i][n - 1]) {
            DFS(i, n - 1, grid, red);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (green[i][j] && red[i][j]) {
                cout << 'O' << " ";
            } else {
                cout << 'X' << " ";
            }

        }
        cout << endl;
    }

    return 0;
}