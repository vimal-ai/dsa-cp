void subTreeNodes(Node* root, int k){
    if(root==NULL) return;
    if(!k) cout<<root->data<<" ";
    
    subTreeNodes(root->left, k-1);
    subTreeNodes(root->right, k-1);
}

bool ancestors(Node* root, Node* &node, vector<Node*> &v){
    if(root==NULL) return 0;
    
    v.push_back(root);
    if(root==node) return 1;
    
    if(!ancestors(root->left, node, v) && !ancestors(root->right, node, v)){
        v.pop_back();
        return 0;
    } 
    return 1;
}

void nodesATk(Node* root, Node* node, int k){
    
    subTreeNodes(node, k);
    
    vector<Node*>v;
    if(ancestors(root, node, v)){
        int size = v.size()-1;
        while(size && k--){
            Node* next = v[size];
            if(!k){
                cout<<next->data;
                break;
            } 
            
            Node* node = v[size-1];
            if(node->left == next){
                subTreeNodes(node->right, k-1);
            }else{
                subTreeNodes(node->left, k-1);
            }
            size--;
        }
        
    }
}
