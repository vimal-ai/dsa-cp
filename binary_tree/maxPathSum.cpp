int maxPathSumUtil(Node* root, int &ans){
    if(root==NULL) return 0;
    
    int left = maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right, ans);
    
    int nodeMax = max(max(root->data, root->data+left+right), max(root->data+left, root->data+right));
    
    ans = max(ans, nodeMax);
    
    return max(root->data, max(root->data+left, root->data+right));
    
}

int maxPathSum(Node* root){
    int ans =INT_MIN;
    maxPathSumUtil(root, ans);
    cout<<ans;
}
