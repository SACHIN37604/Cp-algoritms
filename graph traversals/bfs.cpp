#include<bits/stdc++.h>
using namespace std;
void breadthFirstSearch(int root , vector<int> adj[] , bool visited[]){
	queue<int> q;
	q.push(root);
	visited[root] = true;
	while(!q.empty()){
		int par = q.front();
		// cout << par << " " ;
		q.pop();
		for(int& child : adj[par]){
			if(!visited[child]){
			 //   cout << par << " " << child << "\n"; 
				q.push(child);
				visited[child] = true;
			}
		}
	}
}
int main(){
	int noOfNodes;
	cin >> noOfNodes;
	vector<int> adj[noOfNodes ];
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
	bool visited[noOfNodes];
	memset(visited , false , sizeof(visited));
	for(int i = 0 ; i < noOfNodes ; i++){
		if(!visited[i]){
			breadthFirstSearch(i , adj , visited);
		}
	}
	return 0;
}