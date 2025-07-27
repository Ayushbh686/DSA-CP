// User function template for C++

class Solution {
  public:
    // Function to return a list of lists of integers denoting the members
    // of strongly connected components in the given graph.
    
    void dfs(int u , vector<int>&disc ,  vector<int>&low , vector<int>&vis , vector<int> adj[] , vector<vector<int>>&ans , stack<int>&st  , vector<int>&stMember){
        static int time = 0;
        low[u] = disc[u] = ++time;
        
        vis[u] = 1;
        
        st.push(u);
        stMember[u] = 1;
        for(auto ele : adj[u]){
            if(vis[ele] == 0){
                dfs(ele , disc , low , vis , adj , ans , st , stMember);
                
                low[u] = min(low[u] , low[ele]);
            }
            
            else if(stMember[ele] == true){ // exploring , still part of stack , means back edge (no cross edge)
                low[u] = min(low[u] , disc[ele]);
            }
        }
        
        vis[u] = 2;
        if(low[u] == disc[u]){ // means this is the root for a SCC
            vector<int>temp;
            temp.push_back(u);
            while(!st.empty() and st.top() != u){
                temp.push_back(st.top());
                stMember[st.top()] = false;
                st.pop();
            }
            st.pop();
            stMember[u] = 0;
            sort(temp.begin() , temp.end());
            ans.push_back(temp);
        }
        
        return;
    }
    
    vector<vector<int>> tarjans(int V, vector<int> adj[]) {
        vector<int>disc(V, -1), low(V , -1) , stMember(V , 0);
        vector<int>vis(V , 0); // 0 means unexplored , 1 means still exploring , 2 means explored
        
        vector<vector<int>> ans;
        stack<int>st;
        for(int i=0 ; i<V ; i++){
            vector<int>temp;
            if(!vis[i]) dfs(i , disc , low , vis ,  adj , ans , st , stMember);
        }
        
        sort(ans.begin() , ans.end());
        
        return ans;
    }
};