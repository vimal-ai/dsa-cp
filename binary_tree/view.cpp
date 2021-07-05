
// right view of binary tree
void rightView(Node* root){
    if(root==NULL) return;
    
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
        int size=q.size();
        while(size--){
            Node* node = q.front();
            q.pop();
            
            if(!size) cout<<node->data<<" ";
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
}

// right view of binary tree
void leftView(Node* root){
    if(root==NULL) return;
    
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
        int size = q.size();
        int count = size-1;
        while(size--){
            Node* node = q.front();
            q.pop();
            
            if(size==count) cout<<node->data<<" ";
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
}

// Top view of binary tree
    vector<int> topView(Node *root)
    {
        vector<int>v;
        map<int, int>mp;
        queue<pair<int, Node*>>q;
        q.push({0, root});
        
        while(!q.empty()){
            int hd = q.front().first;
            Node* node = q.front().second;
            q.pop();
            if(mp.find(hd)==mp.end()) mp[hd] = node->data;
            if(node->left) q.push({hd-1, node->left});
            if(node->right) q.push({hd+1, node->right});
        }
        
        for(auto i:mp){
            v.push_back(i.second);
        }
        return v;
    }
