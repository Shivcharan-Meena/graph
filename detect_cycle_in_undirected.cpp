//detecting cycle in disconnected undirected graph

#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

class graph{
    public:
    unordered_map<int,list<int>>adj;

    void build (int u,int v){
        adj[v].push_back(u);
        adj[u].push_back(v);

    }
    bool helper_BFS(unordered_map<int,bool>visited,int i){
        unordered_map<int,int>parent;
        parent[i]=-1;
        visited[i]=1;
        queue<int> q;
        q.push(i);
        while ((!q.empty()))
        {
            int front =q.front();
            q.pop();
            for(auto j:adj[front]){
                if(visited[j]==1&& parent[j]!=front){
                    return true;
                }
                else if(!visited[j]){
                    visited[j]=1;
                    q.push(j);
                    parent[j]=front;
                }
            }
        }
        return false;
        
    }
    string isCyclic_BFS(int v){
        unordered_map<int,bool>visited;

        for(int i=0;i<v;i++){
            if(!visited[i]){
                if(helper_BFS(visited,i)){
                    return "YES";
                }
            }
        }
        return "NO";
    }

    bool helper_DFS( unordered_map<int,bool>visited,int parent,int i){
        visited[i]=1;

        for(auto j:adj[i]){
            if(!visited[j]){
                bool isdetected=helper_DFS(visited,i,j);
                if(isdetected){
                    return true;
                }
            }
            else if(j!=parent){
                return true;
            }
        }
        return false;
    }

    string isCyclic_DFS(int v){
        unordered_map<int,bool>visited;

        for(int i=0;i<v;i++){
            if(!visited[i]){
                if(helper_DFS(visited,-1,i)){
                    return "YES";
                }
            }
        }
        return "NO";
    }
};

int main(){
    graph g;
    g.build(1,2);
    g.build(2,3);
    g.build(3,1);
    // g.build(4,5);
    // g.build(5,6);
    // g.build(5,7);
    // g.build(6,8);
    // g.build(7,8);
    // g.build(8,9);
    int v=3;
    cout<<g.isCyclic_DFS(v)<<endl;
    return 0;
}