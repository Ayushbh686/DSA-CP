/*
leetcode 133
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    unordered_map<int , Node*> mp;

    Node* cloneGraph(Node* node) {
        if(node == NULL) return node;
        int val = node->val;
        if(mp.find(val) != mp.end()) return mp[val];
        Node* newNode = new Node(node->val);
        mp[val] = newNode;
        for(auto it : node->neighbors){
            (newNode->neighbors).push_back(cloneGraph(it));
        }
        return newNode;
    }
};