#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector< list< pair< int , int > > > graph;
int v;

void add_edge(int src , int des , int wt , bool is_directed = true){
    graph[src].push_back({des , wt});
    if(is_directed){
        graph[des].push_back({src , wt});
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
    graph.resize(v , list<pair<int , int>> ());
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