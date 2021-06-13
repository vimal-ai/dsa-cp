void preorder(Node* root){
    if(root==NULL) return;
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==NULL) return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root==NULL) return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelorder(Node* root){
    if(root==NULL) return;
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()){
        int size = q.size();
        while(size--){
            Node* top = q.front();
            q.pop();
            cout<<top->data<<" ";
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
        } 
    }
}

int kthlevelSum(Node* root, int k){
    if(root==NULL) return 0;
    queue<Node*>q;
    q.push(root);
    int level = 0;
    int sum=0;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            Node* top = q.front();
            q.pop();
            if(level == k) sum+=top->data;
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
                
        } 
        level++;
    }
    return sum;
}

void zigzag(Node* root){
    if(root==NULL) return;
    
    deque<Node*>dq;
    dq.push_back(root);
    bool flag = 0;
    while(!dq.empty()){
        int size = dq.size();
        deque<Node*>temp;
        stack<Node*>s;
        while(size--){
            if(flag){
                Node* node = dq.back();
                dq.pop_back();
                s.push(node);
                if(node->left) temp.push_back(node->left);
                if(node->right) temp.push_back(node->right);
                if(!size){
                    while(!s.empty()){
                        cout<<s.top()->data<<" ";
                        s.pop();
                    }
                    dq = temp;
                }
            }else{
                Node* node = dq.front();
                dq.pop_front();
                cout<<node->data<<" ";
                if(node->right) dq.push_back(node->right);
                if(node->left) dq.push_back(node->left);
            }
        }
        flag=!flag;
    }
    
}
