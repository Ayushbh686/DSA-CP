#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector< unordered_map<int , int> > graph;   // its always for weighted , use unordered set for unweighted
int v;

void add_edge(int src , int des , int wt , bool is_directed = true){
    graph[src][des] = wt;
    if(!is_directed){
        graph[des][src] = wt;
    }
    return ;
}

void print_graph(){
    for(int i=0 ; i<graph.size(); i++){
        cout<<i<<" : ";
        for(auto el :graph[i]){
            cout<<" ("<<el.first<<" , "<<el.second<<") "<<" ";
        }
        cout<<endl;
    }
    return;
}

int main(){
    cin>>v;
    graph.resize(v , unordered_map<int , int> ());
    int e;
    cin>>e;
    while(e--){
        int src , des , wt;
        cin>>src>>des>>wt;
        add_edge(src , des , wt , false); //4th argument true for directed
    }
    print_graph();
    return 0;
}