#include<bits/stdc++.h>

void getTotalIslandsHelper(int** mat, int n, int m, int x, int y, int dx[], int dy[],vector<vector<bool>>&vis)
{
    // Check if this cell is valid.
    if(!(x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == 1 && !vis[x][y]))
    {
        return;
    }

    vis[x][y] = true;

    for(int i=0; i<8; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        getTotalIslandsHelper(mat, n, m, nextX, nextY,dx,dy,vis);
    }
}

int getTotalIslands(int** mat, int n, int m)
{
    vector<vector<bool>>vis(n, vector<bool>(m, false));
    int islands = 0;

    int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(mat[i][j] == 1 && !vis[i][j])
            {
                // We have found an undiscovered island.
                islands++;
                getTotalIslandsHelper(mat, n, m, i, j,dx,dy,vis);
            }
        }
    }

    return islands;
}
