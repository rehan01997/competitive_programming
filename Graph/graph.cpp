#include<bits/stdc++.h>
using namespace std;

class Edge
{   
    public:
    int v = 0 ;
    int w = 0; 
    Edge( int v , int w)
    {
        this -> v = v ;
        this -> w = w;
    }
    Edge()
    {
    }
};

vector<vector<Edge*> > graph(8,vector<Edge*>());
void AddEdge(int u , int v , int w)
{
    if( u < 0 || v < 0 || u > graph.size() || v > graph.size() )
        return;
    graph[u].push_back( new Edge( v , w ));
    graph[v].push_back( new Edge( u , w ));
}

void display()
{
    for(int i = 0 ; i < graph.size() ; i++ )
    {   cout<< i <<"-->";
        for( int j = 0 ; j < graph[i].size() ; j++)
        {
            cout<<  "(" << graph[i][j]->v <<"," << graph[i][j]->w <<")";
        }
        cout<< endl;
    }
}
void deleteEdge( int u , int v )
{
    for(int i = 0 ; i < graph[u].size() ; i++)
    {
        if( graph[u][i] -> v == v)
        {
            graph[u].erase(graph[u].begin() + i);
            break;
        }
    }
    for(int i = 0 ; i < graph[v].size() ; i++)
    {
        if( graph[v][i] -> v == u)
        {
            graph[v].erase(graph[v].begin() + i);
            break;
        }
    }
}
void delete_vert(int u)
{
    for( int  c = graph[u].size() - 1; c >= 0  ; c--)
    {   cout<<"a";
        deleteEdge( graph[u][c]-> v , u) ;
    }
}
void print_all_path(int src , int dest , vector<bool>isvisited , string ans)
{   
    if(src == dest)
    {
        cout<<ans<<endl;
        return;
    }
    isvisited[src] = true;
    for( Edge *e : graph[src])
    {
        int v = e -> v;
        if(!isvisited[v])
        {           
            print_all_path( v , dest , isvisited , ans + to_string(v) + "->");
        }
    }   
    isvisited[src] = false ; 
}
bool print_1_path( int src , int dest , vector<bool> &visited , string ans)
{
    if( src == dest)
    {
        cout<<ans<<endl;
        return true;               
    }
    bool res = false;
    visited[src] = true;
    for(Edge * e : graph[src])
    {
        int v = e ->v;
        if(!visited[v] )
        {
            res = res || print_1_path( v , dest , visited , ans + to_string(v) + "->");
        } 
    }
    return res;
}

class bfds
{
    public:

    int vtx = 0 ;
    int wtsoFar = 0 ; 
    string pathsofar = "";
    
    bfds( int vtx , int wtsoFar , string pathsofar)
    {
        this -> vtx = vtx;
        this -> wtsoFar = wtsoFar;
        this -> pathsofar = pathsofar;
    }
    bfds()
    {
    }
};

void bfs_shortest_path(int src , int dest)
{
    int cycle = 1 ;
    int level = 0 ;
    bool ispath = false; 
    vector<bool> visited (7,false);
    list<bfds* > que;
    que.push_back(new bfds( src , 0 , to_string(src) + "" ));
   // ques.push_back(-1);

    while(que.size() != 0)
    {
        
        int size = que.size();
        while (size --)
        { 
        bfds * rpair = que.front();
        que.pop_front();              
        //cycle
        if(visited[rpair -> vtx])
        {
            cout<<"cycle number : "<< cycle <<"--"<< rpair-> pathsofar <<endl;
            cycle ++;
        }
        

        if( rpair ->vtx == dest  & !ispath)  
        {
            cout<< rpair->vtx << "@" <<rpair -> wtsoFar <<"--" << rpair ->pathsofar<<" "<<"level : "<<level <<endl;
            ispath = true;
        }
        //mark
        visited[ rpair -> vtx ] = true;

        for( Edge * e: graph[rpair ->vtx])
        {
            int v = e -> v;
            int w = e -> w;
            if(!visited[v])
            {
                bfds *pair = new bfds( v , rpair -> wtsoFar + w ,  rpair -> pathsofar + to_string(v));
                que.push_back(pair);
            }
        }
        }
        level ++;
    }
}    
void no_of_connected_graph()
{
    vector<bool> visited(graph.size() , false);
    int no_conn = 0 ;
    for(int i = 0 ; i < graph.size() ; i ++)
    {
        if(visited[i]) continue; //if that vertex is already there in graph
        
       // visited[i] = true;
        no_conn ++;
        queue<int> Q;
        Q.push(i);

        int size = Q.size();
        while( !Q.empty())
        {
            int curr = Q.front();
            Q.pop();
            visited[curr] = true;
            for( Edge * e : graph[curr])
            {
                int v = e -> v;
                if(!visited[v])
                {
                    Q.push(v);
                }    
            }         
        }
    }
    cout<<no_conn;
}

void solve()
{
    //AddEdge(0,3,10);
    AddEdge(0,1,10);
    //AddEdge(1,0,10);
    AddEdge(1,2,10);
    //AddEdge(2,1,10);
    //AddEdge(1,3,40);
    AddEdge(3,0,10);
    AddEdge(3,2,40);
    AddEdge(3,4,2);
    //AddEdge(4,3,2);
    AddEdge(4,6,8);
    AddEdge(4,5,2);
    //AddEdge(5,4,2);
    AddEdge(5,6,3);
    
   // AddEdge(6,5,3);
   // AddEdge(6,4,8);
}
int main()
{
    solve();

    //deleteEdge(2,3);
    //delete_vert(3);
    //display();
    cout<<endl;

    //vector<bool> visited( 7 ,false);
    //print_all_path( 0 , 6 , visited , "0->");
    //print_1_path( 0 , 6 , visited , "0->");

   // bfs_shortest_path(0 , 6);
     
    no_of_connected_graph();
    //display();
    return 0;
    
}