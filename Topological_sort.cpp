#include <bits/stdc++.h>
using namespace std;


//bfs solution is known as kahn's algorithm
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void getindegree(vector<int> adj[], vector<int> &in,int v){
	    for(int i =0;i<v;i++){
	        for(auto v : adj[i]){
	            in[v]++;
	        }
	    }
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> indegree(V+1,0);
	    getindegree(adj,indegree,V);
	    queue<int> qu;
	    for(int i =0;i<V;i++){
	        if(indegree[i] == 0) qu.push(i);    //get the nodes which have 0 indegree
	    }
	    vector<int> res;
		// res.em
	    while(!qu.empty()){
	        int node = qu.front();
	        qu.pop();
	        res.push_back(node);
	        for(auto v : adj[node]){
	            indegree[v]--;
	            if(indegree[v] ==0) qu.push(v);
	        }
	    }
	    return res;
	}
};

int main(){
	vector<int> v = {1,2,4,5,6};
	// v.front
	cout<<v[v.size()-1]<<endl;
}