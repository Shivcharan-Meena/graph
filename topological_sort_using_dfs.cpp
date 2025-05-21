//apllied in directed acyclic graph
//In this Linear ordering of vertices for every edges (u-v)
//such that u always appears before v in that ordering.

#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int,list<int>>adj;
    void build(int u,int v){
        adj[u].push_back(v);
    }

    void print(){
        for(auto x:adj){
            cout<<x.first<<"->";
            for(auto j:x.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        
    }

    void dfs_help(unordered_map<int,bool>&visited,stack<int>&ans,int i){
        visited[i]=1;
        
        for(auto x:adj[i]){
            if(!visited[x]){
                dfs_help(visited,ans,x);
                
            }
        }
        ans.push(i);
    }
    void dfs(){
        unordered_map<int,bool>visited;
        stack<int>ans;
        for(auto &i:adj){
            int node=i.first;
            if(!visited[node]){
                dfs_help(visited,ans,node);
            }
        }
        while(!ans.empty()){
            cout<<ans.top()<<" ";
            ans.pop();
        }
        cout<<endl;
    }
};

int main(){
graph g;
// g.build(0,1);
// g.build(1,2);

// g.build(2,5);
// g.build(5,6);
// g.build(1,4);
// g.build(4,5);
g.build(0,1);
g.build(0,3);
g.build(1,2);
g.build(3,2);
g.print();

g.dfs();
}