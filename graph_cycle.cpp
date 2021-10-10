#include<bits/stdc++.h>
using namespace std;
vector<int> parent;
int start,stop;

void add_edge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
}

void print_graph(vector<int> adj[],int size)
{
    for(int i=0;i<size;i++)
        {   cout<<i;
            for(auto a: adj[i])
            cout<<"->"<<a;
            cout<<endl;
        }
}

//for cycle_finding

bool dfs(vector<int> adj[],int visit[],int n,int strt_dfs)
{
    visit[strt_dfs]=1;
    for(auto u: adj[strt_dfs])
        {
            if(visit[u]==0)
            {   
                parent[u]=strt_dfs;
                if(dfs(adj,visit,n,u))
                   return true;
            }
            else if(visit[u]==1)
            {  
                start=u;
                stop=strt_dfs;
                return true;
            }
        }
    visit[strt_dfs]=2;
    return false;
}

void cycle_find(vector<int> adj[],int n)
{
    parent.assign(n,-1);
    start = -1;
    int ar[n]={0};
    for(int i=0;i<n;i++)
     {   if(ar[i]==0 && dfs(adj,ar,n,i))
            break;
     }
    if(start==-1)
        cout<<"NO cycle"<<endl;
    else
        {   
            vector<int> cycle;
            cycle.clear();
            cycle.push_back(start);

            for(int i=stop;i!=start;i=parent[i])
             cycle.push_back(i);
            cycle.push_back(start);
            reverse(cycle.begin(),cycle.end());
            
            for(auto a: cycle)
            cout<<a<<" ";

        }
}
int main()
{
    int n=5;
    vector<int> adj[n];
    add_edge(adj,1,2);
    add_edge(adj,2,3);
    add_edge(adj,3,4);
    add_edge(adj,4,1);
    print_graph(adj,n);
    cout<<endl;
    cycle_find(adj,n);
    return 0;
}