#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

void DFS(int x, int y, int m, int n, char grid[][100], bool visited[][100]) {

    visited[x][y] = true;

    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
            if (grid[nx][ny] == '1' && !visited[nx][ny]) {
                DFS(nx, ny, m, n, grid, visited);
            }
        }
    }
}

int main() {
    int m, n, Islands = 0;
    cin >> m >> n;

    bool visited[100][100];
    char grid[100][100];
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            visited[i][j] = false;
        }
    }

     for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1' && !visited[i][j]) {
                Islands++;
                DFS(i, j, m, n, grid, visited);
            }
        }
    }

    cout << Islands << endl;
}