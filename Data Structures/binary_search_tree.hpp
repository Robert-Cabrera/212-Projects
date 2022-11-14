#include <iostream>
#include <stdexcept>
#include <queue>
#include <vector>

using namespace std;

struct Node
{
    int data = 0;
    Node *left = nullptr;
    Node *right = nullptr;

    Node() = default;

    Node(int d)
    {
        data = d;
        left = right = nullptr;
    }

    ~Node()
    {
        delete right;
        delete left;
    }
    
};

class Tree
{
    private:
        Node* root = nullptr;
    public:
        Tree() = default;
        
        Tree(int r)
        {
            root = new Node(r);
        }

        ~Tree()
        {
            delete root;
        }

        void _delete(int d);
        
        void _insert(int d);
        void _insert(Node *n);
        
        bool _search(Node *n);  //search by node
        bool _search(int d);    //search by value

        Node* _succ(Node *n);
        Node* _pred(Node *n);
        
        Node* _min(Node *n);
        Node* _max(Node *n);

        int _max_height(Node *r);
        int _depth(Node *n);

        void _in_order(Node *r);
        void _pre_order(Node *r);
        void _post_order(Node *r);
};


void Tree::_insert(int d)
{
    Node *node = new Node(d);

    if(!root)
    {
        root = node;
        return;
    }

    Node *parent = nullptr;
    Node *curr = root;

    while(curr != nullptr)
    {
        if (d > curr->data)
        {
            parent = curr;
            curr = curr->right;
        }

        else if (d < curr->data)
        {
            parent = curr;
            curr = curr->left;
        }
    }

    if (d > parent->data)
        parent->right = node;
    else
        parent->left = node;
   
}

void Tree::_insert(Node* n)
{

    int d = n->data;

    if(!root)
    {
        root = n;
        return;
    }

    Node *parent = nullptr;
    Node *curr = root;

    while(curr)
    {
        if (d > curr->data)
        {
            parent = curr;
            curr = curr->right;
        }

        else if (d < curr->data)
        {
            parent = curr;
            curr = curr->left;
        }
    }

    if (d > parent->data)
        parent->right = n;
    else
        parent->left = n;
  
}

void Tree::_delete(int d)
{
    if (!root)
        throw runtime_error("There's no tree!");

    if (!_search(d))
        throw runtime_error("The node is not in the tree!");

    // search for the node and keep track of its parent
    Node *curr = root;
    Node *parent;

    while (curr != nullptr && curr->data != d)
    {
        parent = curr;
        if (d > curr->data)
            curr = curr->right;
        else
            curr = curr->left;
    }

    // case 1 : no child or one child
    if (curr->right == nullptr || curr->left == nullptr)
    {
        Node *new_node;

        if (curr->left == nullptr)
            new_node = curr->right;
        else
            new_node = curr->left;

        // if the deleted node was a right child
        if (curr == parent->left)
            parent->left = new_node;
        else
            parent->right = new_node;

        delete (curr);
    }

    // case 2 : two children
    else
    {
        Node *successor = nullptr;
        Node *temp = nullptr;

        // find sucessor
        temp = curr->right;

        while (temp->left != nullptr)
        {
            successor = temp;
            temp = temp->left;
        }

        if (successor != nullptr){
            successor->left = temp->right;
        } 

        else{
            curr->right = temp->right;
        }

        curr->data = temp->data;
        delete temp;
    }
}

bool Tree::_search(int d)
{
    bool flag = false;

    if (!root)
        throw runtime_error("There's no tree");

    Node *curr = root;

    while (curr != nullptr)
    {
        if (d > curr->data)
        {
            curr = curr->right;
        }

        else if (d < curr->data)
        {
            curr = curr->left;
        }

        else
        {
            flag = true;
            break;
        }
    }

    return flag;
}

bool Tree::_search(Node *n)
{
    bool flag = false;
    int d = n->data;

    if (!root)
        throw runtime_error("There's no tree");

    Node *curr = root;

    while (curr != nullptr)
    {
        if (d > curr->data)
        {
            curr = curr->right;
        }

        else if (d < curr->data)
        {
            curr = curr->left;
        }

        else
        {
            flag = true;
            break;
        }
    }

    return flag;
}

Node *Tree::_min(Node *n)
{
    Node *curr = n;

    while (curr && curr->left != nullptr)
    {
        curr = curr->left;
    }

    return curr;
}

Node *Tree::_max(Node *n)
{
    Node *curr = n;

    while (curr && curr->right != nullptr)
    {
        curr = curr->right;
    }

    return curr;
}

Node *Tree::_succ(Node *n)
{
    // case 1 : right subtree
    if (n->right != nullptr)
    {
        return _min(n->right);
    }

    // case 2 : no right subtree
    else
    {
        Node *successor = nullptr;
        Node *curr = root;

        while (curr != nullptr)
        {

            if (n->data < curr->data)
            {
                successor = curr;
                curr = curr->left;
            }

            else if (n->data > curr->data)
            {
                curr = curr->right;
            }

            else
            {
                break;
            }
        }

        return successor;
    }
}

Node *Tree::_pred(Node *n)
{
    if (!root)
        throw runtime_error("There's no tree!");
    
    Node *predecessor = nullptr;
    Node *curr = root;

    while (curr != nullptr)
    {
        if (curr->data == n->data)
        {
            if(curr->left)
            {
                Node *temp = curr->left;
                predecessor =_max(temp);
                return predecessor; 
            }
        }

        else if (curr->data < n->data)
        {
            while(curr->right != nullptr && 
                  curr->right->data != n->data)
            {
                predecessor = curr;
                curr = curr->right;
            }
            
            return predecessor;
        }
    }
}

int Tree::_max_height(Node *root)
{
    if(root == nullptr)
		return -1;    

    int left = _max_height(root->left);
    int	right = _max_height(root->right);

	if (left > right)          
		return left + 1; 
	else
	    return right + 1;
		
}

int Tree::_depth(Node *n)
{
    Node *curr = root;
    unsigned int depth = 0;


    while(curr != nullptr && (curr->data != n->data))
    {
        if(n->data > curr->data)
        {
            curr = curr->right;
            depth++;
        }

        else
        {
            curr = curr->left;
            depth++;
        }
    }

    return depth;
}

void Tree::_in_order(Node* root)
{
    if (!root)
        return;
    
    _in_order(root->left);

    cout << root->data;
    cout << " -> ";

    _in_order(root->right);
    
}

void Tree::_pre_order(Node* root)
{
    if (!root)
        return;
    
    cout << root->data;
    cout << " -> ";

    _pre_order(root->left);

    _pre_order(root->right);
    
}

void Tree::_post_order(Node *root)
{
    if (root == nullptr)
        return;
    
    _post_order(root->left);

    _post_order(root->right);

    cout << root->data;
    cout << " -> ";
    
}
