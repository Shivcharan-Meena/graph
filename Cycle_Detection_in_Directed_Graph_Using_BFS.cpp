

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

   
    void algo(){
        //first find indegrees
        int n = adj.size();

        vector<int>indegree(n,0);
        for(auto i:adj){
            for(auto j:i.second){
                indegree[j]++;
            }
        }
       
        vector<int>ans;
       
        queue<int>q;
        
        for(auto &x:indegree){
            if(x==0){
                q.push(x);
            }
        }

        while(!q.empty()){
            int front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto neigh:adj[front]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        if (ans.empty()){
            cout<<"Cycle is present";
            return;
        }
        for(auto &x:ans){
            cout<<x<<" ";
        }

    }

   
    
};

int main(){
graph g;
g.build(0,1);
g.build(0,3);
g.build(1,2);
g.build(3,2);
g.print();
g.algo();
return 0;
}