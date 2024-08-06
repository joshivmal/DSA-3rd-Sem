#include<bits/stdc++.h> 
// #include<queue.h>
// #include<vector>
using namespace std;
void corona(vector<vector<int>>adj[] )
{
    int n = adj.size() ;
    int m = adj[0].size();
    queue<pair<int,int>,int>q ;
    int vis[n][m] ;
    int rowArr[] = {-1,0,1,0} ;
    int colArr[] = {0,-1,0,-1} ;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(adj[i][j] == 1)
            {
                q.push({{i,j},0});
                vis[i][j] = 1 ;
            }
            else vis[i][j] = 0 ;
        }
    }
    int cntNwPnt =0 ;
    int t = 0 ;  
    while(!q.empty())
    {
        int row = q.front().first.first ;
        int col = q.front().first.second ;
        int it = q.front().second ;
        t = max(t,it) ;
        for(int i=0;i<4;i++)
        {
            int visrow = row + rowArr[i] ;
            int viscol = col + colArr[i] ;

            if( visrow >= 0 && visrow<n && viscol >=0 && viscol < m && adj[visrow][viscol] == -1 
            && vis[visrow][viscol] != 1)
            {
                vis[visrow][viscol] = 1 ;
                q.push({{visrow,viscol},t+1}) ;
                cntNwPnt++ ;
            }
        }
        
    }
    cout<<cntNwPnt<<t<<endl ;


}

int main()
{
    int n,m ;
    cin>>n>>m ;
    vector<vector<int>>adjmat(n,vector<int>(m,0)) ;
    int vis[n][m]={3} ;
    for(int i =0 ; i<n ;i++)
    {
        for(int j=0 ; j<m ;j++)
        {
            cin>>adjmat[i][j] ;
        }
    }
    corona(adjmat);


    return 0 ;
}