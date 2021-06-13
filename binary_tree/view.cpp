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

void topView(Node* root){
    if(root==NULL) return;
    
    queue<Node*> q;
    q.push(root);
    
    stack<Node*>s;
    while(!q.empty()){
        int size = q.size();
        int count = size-1;
        while(size--){
            Node* node = q.front();
            q.pop();
            if(count==size) s.push(node);
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    while(s.size()>1){
        cout<<s.top()->data<<" ";
        s.pop();
    }
    
    q.push(root);
    
    while(!q.empty()){
        int size= q.size();
        
        while(size--){
            Node* node = q.front();
            q.pop();
            
            if(!size) cout<<node->data<<" ";
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
}
