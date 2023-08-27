#include <bits/stdc++.h>
using namespace std;



int orangesRotting(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();

    int vis[n][m];
    queue<pair<pair<int,int>,int>> q;
        int freshorg=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==2) {
                    q.push({{i,j,},0});
                }
                if(grid[i][j]==1) {
                    freshorg++;
                }
                vis[i][j]=0;
            }
        }
        int time=0;
        while(!q.empty()) {
            int i=q.front().first.first;
            int j=q.front().first.second;
            int t=q.front().second;
            q.pop();
            time=max(time,t);
            if(i+1 < n && grid[i+1][j]==1 && vis[i+1][j]==0 ) {
                q.push({{i+1,j},t+1});
                vis[i+1][j]=2;
            }
            if(j+1 < m && grid[i][j+1]==1 && vis[i][j+1]==0) {
                q.push({{i,j+1},t+1});
                vis[i][j+1]=2;
            }
            if(i-1 >=0 && grid[i-1][j]==1 && vis[i-1][j]==0) {
                q.push({{i-1,j},t+1});
                vis[i-1][j]=2;
            }
            if(j-1 >=0 && grid[i][j-1]==1 && vis[i][j-1]==0) {
                q.push({{i,j-1},t+1});
                vis[i][j-1]=2;
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(vis[i][j]!=2 && grid[i][j]==1)  return -1;
            }
        }

    return time;
}


int main () {
    int  n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int> (m));

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>grid[i][j];
        }
    }

    cout<<orangesRotting(grid);
}
