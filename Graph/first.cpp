#include<iostream>
#include<vector>
using namespace std ;
int main()
{
    int n=5,m=6 ;                      // for undirected graph


    // ********************for 2D adjacent matrix****************************************************
/*
    int adjmatrix[n+1][n+1];
    for(int i=0;i<m+1;i++)    
    {
        int u,v ;
        cin>>u>>v ;       // taking two nodes as input
        if(u==0) break ;
        adjmatrix[u][v]=1 ;  // for weighted we have to replace 1 by weight
        adjmatrix[v][u]=1 ;
    }
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(adjmatrix[i][j]!=1) adjmatrix[i][j] = 0;
            cout<<adjmatrix[i][j]<<" ";
        }
        cout<<endl ;
    }
    return 0 ;
*/
    // **************************from adjacent list*******************************************
/*
    vector<int>adjlist[n+1] ;
    for(int i=0;i<m+1;i++)
    {
        int u,v ;
        cin>>u>>v ;
        if(u == 0 ) break ;
        adjlist[v].push_back(u) ;
        adjlist[u].push_back(v) ;
    }
   
    

  for (int i = 0; i < n+1; i++) {
        cout << i << "->";
        for (int& x : adjlist[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
*/

    //   for weighted graph in adjacent matrix 
    vector<pair<int,int>>adjlist[n+1] ;
    for (int i = 0; i < n+1; i++)
    {
        int u,v,weight ;
        cin>>u>>v>>weight ;
        adjlist[u].push_back(v,weight) ;
        adjlist[v].push_back(u,weight) ;
    }
    //   for (int i = 0; i < n+1; i++) {
    //     cout << i << "->";
    //     for (int& x : adjlist[i]) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
       
 }
