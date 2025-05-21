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
    void bfs_help(vector<bool>&visited, vector<int>&ans,int i){
        visited[i]=1;
        queue<int>q;
       q.push(i);
       while(!q.empty()){
           int front=q.front();
           q.pop();
           ans.push_back(front);
           for(auto j:adj[front]){
               if(!visited[j]){
                   visited[j]=1;
                   q.push(j);
               }
           }
       }

    }

    void bfs(int v) {
        vector<bool> visited(v, false); // Resize and initialize with 'false'
        vector<int> ans;

        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                bfs_help(visited, ans, i);
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout<<endl;

    }

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
    g.build(0,2);
    g.build(1,2);
    g.build(1,5);
    g.build(2,3);
    g.build(0,1);
    g.build(3,4);
    g.build(4,5);
    g.print();
    cout<<"Hlejf;lsdkgfgj"<<endl;
    g.bfs(6);
}