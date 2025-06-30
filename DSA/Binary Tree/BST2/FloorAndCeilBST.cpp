// floor

int floor(Node* root, int x) {
    if(!root) return -1;
    int floorVal = -1;
        
    while(root != NULL){
        if(root->data == x){
            return x;
        }
        
        else if(root->data > x){
            root = root->left;
        }
            
        else{ //root->data < x this means root can be posiible floorValue so we will store it and move to right
            floorVal = root->data;
            root = root->right;
        }
    }
        
    return floorVal;
        
}



//ceil
int findCeil(Node* root, int input) {
    if(!root) return NULL;
    
    int ceilVal = -1;
    
    while(root != NULL){
        if(root->data == input){
            return input;
        }
        
        else if(root->data < input){
            root = root->right;
        }
        
        else{ // root->data > input this means root can possibly the ceilVal of this input so store it move left
            ceilVal = root->data;
            root = root->left;
        }
    }
    
    return ceilVal;
}