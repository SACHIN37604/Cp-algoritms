#include<bits/stdc++.h>
using namespace std;
void depthFirstSearch(int node , vector<vector<int>>& adj , vector<bool>& visited){
	visited[node] = true;
	// cout << node << " ";
	for(int& child : adj[node]){
		if(!visited[child]){
		    // cout << node << " " << child << "\n";
			depthFirstSearch(child , adj , visited);
		}
	}
}
int main(){
	int noOfNodes;
	cin >> noOfNodes;
	vector<vector<int>> adj(noOfNodes);
	int noOfEdges;
	cin >> noOfEdges;
	for(int i = 0 ; i < noOfEdges ; i++){
		int x , y;
		cin >> x >> y; x--,y--;
		adj[x].push_back(y);
		adj[y].push_back(x); //comment this if graph is directed 
	}
	int root;
	cin >> root; root--;
	vector<bool> visited(noOfNodes , 0);
	for(int i = 0 ; i < noOfNodes ; i++){
		if(!visited[i]){
			depthFirstSearch(i , adj , visited);
		}
	}

	return 0;
}
