#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

class graph{
    public:
    unordered_map<int,list<int>>adj;

    void build(int u,int v,bool dirc){
        //dirc=0 --> for undirected graph
        //dirc=1 --> for directed graph
        adj[u].push_back(v);
        if(dirc==0){
            adj[v].push_back(u);
        }

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

// Time Complexity: O(V+E) where V is the number of vertices and E is the number of edges
class grph {
    public:
        vector<vector<int>> ans;
    
        void build(int u, int v, bool dirc) {
            if (u >= ans.size()) ans.resize(u + 1);
            if (v >= ans.size()) ans.resize(v + 1);
    
            ans[u].push_back(v);
            if (dirc == 0) {
                ans[v].push_back(u);
            }
        }
    
        void print() {
            for (int i = 0; i < ans.size(); i++) {
                cout << i << " -> ";
                for (int j = 0; j < ans[i].size(); j++) {
                    cout << ans[i][j] << ", ";
                }
                cout << endl;
            }
        }
    };
//in vector form



int main(){
    grph g;
    g.build(0,1,0);
    g.build(0,2,0);
    g.build(1,2,0);
    g.build(2,3,0);
    g.build(3,4,0);
    g.build(4,5,0);
    g.print();
}