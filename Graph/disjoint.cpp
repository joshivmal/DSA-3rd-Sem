#include<iostream>
#include<vector>
using namespace std ;
class Disjoint
{
    private :
    vector<int>rank,parent,size ;

    public:
    Disjoint(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1) ;
        size.resize(n+1,1) ;

        for(int i=0;i<n;i++)
        {
            parent[i] = i ;
        }
    }

     int findUparent(int node)
     {
        if(node == parent[node])  return node ;
        return parent[node] = findUparent(parent[node]) ;
     }

     void unionbyrank(int u,int v)
     {
        int ult_u = findUparent(u) ;
        int ult_v = findUparent(v) ;

        if(ult_u == ult_v) return ;
        else if(rank[ult_u] < rank[ult_v])   parent[ult_u] = ult_v ; 
        else if(rank[ult_u] > rank[ult_v])   parent[ult_v] = ult_u ;
        else 
        {
            parent[ult_v] = ult_u ;
            rank[ult_u]++ ; 
        }
     }

     void unionBySize(int u,int v)
     {
        int ult_u = findUparent(u) ;
        int ult_v = findUparent(v) ;

        if(ult_v == ult_u) return  ;
        else if(size[ult_u]>size[ult_v]){
              parent[ult_v]  = ult_u ;
              size[ult_u]+=size[ult_v] ;   }
        else
        {
            parent[ult_u] = ult_v ;
            size[ult_v]+=size[ult_u] ;
        } 
     }
} ;


int main()
{
    Disjoint obj(7) ;
    obj.unionBySize(1,2);
    obj.unionBySize(2,3);
    obj.unionBySize(4,5);
    obj.unionBySize(6,7);
    obj.unionBySize(5,6);
    if(obj.findUparent(1)== obj.findUparent(7)) cout<<"same"<<endl ;
    else cout<<"not same\n";
    obj.unionBySize(3,7);
    if(obj.findUparent(1) == obj.findUparent(7)) cout<<"same"<<endl ;
    else cout<<"not same\n";
    return 0;
}