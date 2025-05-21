#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
    unordered_map<int,list<int>>adj;

    void build(int u,int v){
        adj[u].push_back(v);
       
       
           
    }

    bool cycle_dfs_help( unordered_map<int,bool>&visited,int i, unordered_map<int,bool>dfsvisited){
        dfsvisited[i]=1;
        visited[i]=1;
        for(auto j:adj[i]){
            if(!visited[j]){

                bool k=cycle_dfs_help(visited,j,dfsvisited  );
                if(k){
                    return true;
                }
            }
            else{
                if(dfsvisited[j]==1){
                    return true;
                }
            }
        }
        dfsvisited[i]=0;
        return false;
    }

    void dfs(int v){
        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfsvisited;
        for(int i=0;i<v;i++){
            if(!visited[i]){
                bool detected=cycle_dfs_help(visited,i,dfsvisited);
                if(detected){
                    cout<<"Detected"<<endl;
                    return;
                }
            }
        }
        cout<<"NOT Detected"<<endl;
    }
};


int main(){
    graph g;
    g.build(1,2);
    g.build(2,3);
    g.build(3,4);
    g.build(3,5);
    g.build(5,4);
    g.build(2,6);
    g.build(6,7);
    g.build(7,8);
    g.build(6,8);
    g.dfs(8);
}