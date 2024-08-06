    #include<bits/stdc++.h>
    using namespace std;
    class Solution{
   public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
       
       int n = grid.size() ;  // row
       int m = grid[0].size() ; // column
       //{{1,2},t}
       queue<pair<pair<int,int>,int>>q ;
       int vis[n][m] ;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(grid[i][j]==2)
               {
                   vis[i][j] = 2 ;
                   q.push({{i,j},0}) ;
               }
               else  
               vis[i][j] = 0 ;

           }
       }
       int rowArr[]={-1,0,1,0} ;
       int colArr[]={0,1,0,-1} ;
       //{{i,j},time}
       int t = 0 ;
       while(!q.empty())
       {
           int r = q.front().first.first ;
           int c = q.front().first.second ;
           int it = q.front().second ;
           q.pop() ;
          t = max(t,it) ;
           for(int i=0;i<4;i++)
           {
               int visrow = rowArr[i]+r ;
               int viscol = colArr[i]+c ;
               
               if(visrow>=0 && visrow<n && viscol>=0 && viscol<m && vis[visrow][viscol] != 2 && grid[visrow][viscol] == 1 )
               {
                   vis[visrow][viscol] = 2 ;
                   q.push({{visrow,viscol},t+1}) ;
               }
           }
       }
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if( grid[i][j]==1 && vis[i][j]!=2)
               { 
                   return -1 ;
                   
               }
           }
       }
       return t ;
       
    }
    };
  



  int main()
  {
    int n,m ;
    cin>>n>>m ;
    vector<vector<int>>grid(n,vector<int>(m,-1));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j] ;
        }
    }
 
    Solution obj ;
    int ans = obj.orangesRotting(grid) ;
    return 0 ;
    cout<< ans <<"\n" ;
  

    return 0 ;
  }