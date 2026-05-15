// https://www.geeksforgeeks.org/problems/sort-a-stack/1

class Solution {
  public:
  
    void insert(stack<int>& s, int temp) {
        // Base case: if the stack is empty or temp is larger than the top element
        if (s.empty() || s.top() <= temp) {
            s.push(temp);
            return;
        }
        
        // Otherwise, pop the top element and recursively insert
        int val = s.top();
        s.pop();
        insert(s, temp);
        
        // Push the popped element back
        s.push(val);
    }
        
  
    void sortStack(stack<int> &st) {
        int n = st.size();
        
        if(n != 0){
            int ele = st.top();
             
            st.pop();
             
            sortStack(st);
            
            
            insert(st , ele);
        }
        
        return;
    }
};
