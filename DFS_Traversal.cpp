#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;
class graph{
    //bfs traversal for unconnected undirected graph
    public:
    unordered_map<int,list<int>>adj;

    void build(int u,int v){
        adj[u].push_back(v);
       
            adj[v].push_back(u);
    }
    void dfs_help( unordered_map<int,bool>&visited,vector<int >&ans,int i){
        ans.push_back(i);
        visited[i]=1; 
        for(auto j:adj[i]){
            if(!visited[j]){
                
                dfs_help(visited,ans,j);
            }
        }
    }
    // void dfs() {
    //     unordered_map<int, bool> visited;
    //     vector<int> ans;
    
    //     for (auto& pair : adj) {
    //         int node = pair.first;
    //         if (!visited[node]) {
    //             dfs_help(visited, ans, node);
    //         }
    //     }
    
    //     if (ans.empty()) {
    //         cout << "Graph is empty or disconnected with no reachable nodes." << endl;
    //     } else {
    //         for (int node : ans) {
    //             cout << node << " ";
    //         }
    //         cout << endl;
    //     }
    // }
    void dfs() {
        unordered_map<int, bool> visited;
        vector<int> ans;
    
        for (auto& pair : adj) {
            int node = pair.first;
            if (!visited[node]) {
                dfs_help(visited, ans, node);
            }
        }
        for(auto& pair : adj) {
            int node = pair.first;
            cout<<node<<" -> ";
            for(auto& neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
        if (ans.empty()) {
            cout << "Graph is empty or disconnected with no reachable nodes." << endl;
        } else {
            for (int node : ans) {
                cout << node << " ";
            }
            cout << endl;
        }
    }
    
    // void dfs(int v){
    //     unordered_map<int,bool>visited;
    //     vector<int >ans;
    //     for(int i=0;i<v;i++){
    //         if(!visited[i]){
    //             dfs_help(visited,ans,i);
    //         }
    //     }
        
        
    //     if(!(ans.size()<=1)){

        
    //     for (int i = 0; i < ans.size(); i++) {
    //         cout << ans[i] << " ";
    //     }
    //     cout<<endl;
    // }
    //     else{
    //         cout<<"Ans is empty"<<endl;
    //     }
    // }


   void print(){
        for(auto i:adj){
            cout<<i.first<<" ->";
            for(auto j:i.second){
                cout<< j<<", ";
            }
            cout<<endl;
        }
    }



};


int main(){
    graph g;
    
    g.build(9,2);
    g.build(1,2);
    g.build(1,5);
    g.build(2,3);
    g.build(0,1);
    g.build(3,4);
    g.build(4,5);
    g.print();
    cout<<"Hlejf;lsdkgfgj"<<endl;
    g.dfs();
}