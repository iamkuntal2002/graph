#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
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
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        for(int i =0;i<N-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(),s2.size());
            for(int j =0;j<len;j++){
                if(s1[j] != s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        vector<int> toposort = topoSort(K,adj);
        string res = "";
        for(auto el : toposort){
            res += (char)(el + 'a');
        }
        return res;
    }
};


int main() {
    string dict[] = {"baa","abcd","abca","cab","cad"};
    Solution ob;
    string res = ob.findOrder(dict,5,4);
    cout<<res<<endl;
}
