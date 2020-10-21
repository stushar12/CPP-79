vector<int> abc(Node * root,vector<int> &v)
{
    queue<Node *> q;
    stack<int> s;
    bool val=true;
    if(root==NULL)
    return v;
   q.push(root);
        while(q.empty()!=true)
        {   
            int n=q.size();
            for(int i=0;i<n;i++)
            {   Node* t=q.front();
                q.pop();
                if(val)
                {
                    s.push(t->data);
                }
                else
                {
                    v.push_back(t->data);
                }
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            if(val)
            {
                while(s.empty()!=true)
                {
                    v.push_back(s.top());
                    s.pop();
                }
            }
            val=!val;
        }
    return v;
}
vector<int> findSpiral(Node *root)
{
    vector<int>v;
    vector<int>a;
    a=abc(root,v);
    return a;
}
