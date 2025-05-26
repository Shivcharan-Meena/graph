// find parent of all nodes then bactrack from the destination node through its parent upto source node

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
  // do bfs
   void shortest_path(int s,int d){

       unordered_map<int,bool>visited; 
       unordered_map<int,int>parent;
       queue<int>q;
       q.push(s);
       visited[s]=1;
        parent[s]=-1;
       while(!q.empty()){
        int front=q.front();
        q.pop();

        for(auto i:adj[front]){
            if(!visited[i]){
                visited[i]=1;
                parent[i]=front;
                q.push(i);
            }
        }
    }
       
        // Prepare shortest path
        vector<int>ans;
        int current_node=d;
        ans.push_back(d);
        while(current_node!=s){
            current_node=parent[current_node];
            ans.push_back(current_node);
        }  

        reverse(ans.begin(),ans.end());
        for(auto i:ans){
            cout<<i<<" ";
        }
        cout<<endl;
       
    }
};

int main(){
graph g;
g.build(1,2);
g.build(1,3);
g.build(1,4);
g.build(2,5);
g.build(5,8);
g.build(3,8);
g.build(4,6);
g.build(6,7);
g.build(7,8);
// g.print();

g.shortest_path(1,8);
return 0;
}