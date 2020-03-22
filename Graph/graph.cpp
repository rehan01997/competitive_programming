#include <bits/stdc++.h>
using namespace std;
class Edge
{   public:
    int v =0 ;
    int w = 0 ;
    Edge(int v, int w)
    {
        this->v =  v;
        this->w = w;
    }
    Edge(){}
};
vector<vector<Edge *>>graph(7,vector<Edge *>());
void AddEdge(int u , int v, int w)
{
    if(u < 0 || v < 0 || u > graph.size() || v > graph.size()) return ;
    graph[u].push_back(new Edge(v,w));
    graph[v].push_back(new Edge(u,w));
}
void display()
{
    for(int i = 0 ; i < graph.size() ; i++)
    {
        cout<<i<<"=>";
        for(int  j = 0 ; j < graph[i].size() ; j++)
        {
            cout<<"("<<graph[i][j]->v << "," <<graph[i][j]->w <<")";
        }cout<<endl;
    }
}

int main() {
    AddEdge(0,3,10);
    AddEdge(0,1,10);
    //AddEdge(1,0,10);
    AddEdge(1,2,10);
    //AddEdge(2,1,10);
    AddEdge(2,3,40);
    //AddEdge(3,0,10);
   // AddEdge(3,2,40);
    AddEdge(3,4,2);
   // AddEdge(4,3,2);
    AddEdge(4,6,8);
    AddEdge(4,5,2);
    //AddEdge(5,4,2);
    AddEdge(5,6,3);
    //AddEdge(6,5,3);
   // AddEdge(6,4,8);
    display();
    return 0 ;
}
