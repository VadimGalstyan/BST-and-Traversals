#include <iostream>
#include <queue>

template <typename T>
struct BSTNode
{
    T data;
    BSTNode* left = nullptr;
    BSTNode* right = nullptr;

    BSTNode(const T& value) : data(value),left(nullptr),right(nullptr)
    {
    }
};

template <typename T>
BSTNode<T>* newBSTNode(const T& value)
{
    BSTNode<T>* obj = new BSTNode<T>(value);

    return obj;
}

template <typename T>
void insert(BSTNode<T>** root,const T& value)
{
    if ((*root) == nullptr)
    {
        (*root) = newBSTNode(value);
        return;
    }
    else
    {
        if (value <= (*root)->data)
        {
            insert(&((*root)->left),value);
            return;
        }
        else
        {
            insert(&((*root)->right),value);
            return;
        }
    }
    
}

//Left -> Root -> Right
template <typename T>
void inorderTraversal(BSTNode<T> const* const root) 
{
    if (root == nullptr)
    {
        return;
    }

    inorderTraversal(root->left);
    std::cout<<root->data<<" ";    
    inorderTraversal(root->right);
}

//Root -> left -> right
template <typename T>
void preorderTraversal(BSTNode<T> const* const root) 
{
    if (root == nullptr)
    {
        return;
    }

    std::cout<<root->data<<" ";    
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

//Left -> Right -> Root
template <typename T>
void postorderTraversal(BSTNode<T> const* const root) 
{
    if (root == nullptr)
    {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    std::cout<<root->data<<" ";    
}


template <typename T>
void levelOrderTraversal(BSTNode<T>* const root)
{
    if (root == nullptr)
    {
        return;
    }
    
    std::queue<BSTNode<T>*> q;

    q.push(root);

    while (!q.empty())
    {
        BSTNode<T>* node = q.front();
        std::cout<<node->data<<" ";
        q.pop();

        if (node->left != nullptr)
        {
            q.push(node->left);
        }
        
        if (node->right != nullptr)
        {
            q.push(node->right);
        }
        
    }
    
}

int main()
{
///JUST TREE//////////////////////////////////////////////////////////////////

    BSTNode<int>* root = nullptr;

    root = newBSTNode(1);

    root->left = newBSTNode(2);
    root->right = newBSTNode(3);

    (root->left)->left = newBSTNode(4);
    (root->left)->right = newBSTNode(5);

    (root->right)->left = newBSTNode(6);
    (root->right)->right = newBSTNode(7);

    std::cout<<"Just tree"<<std::endl;
    inorderTraversal(root);
    std::cout<<" - Inorder"<<std::endl;
    preorderTraversal(root);
    std::cout<<" - Preorder"<<std::endl;
    postorderTraversal(root);
    std::cout<<" - Postorder"<<std::endl;
    levelOrderTraversal(root);
    std::cout<<" - Level order"<<std::endl;


///BINARY SEARCH TREE/////////////////////////////////////////////////////////

    BSTNode<int>* root1 = nullptr;

    insert(&root1,2);
    insert(&root1,4);
    insert(&root1,5);
    insert(&root1,1);
    insert(&root1,6);
    insert(&root1,3);
    insert(&root1,7);

    std::cout<<"Binary search tree"<<std::endl;
    inorderTraversal(root1);
    std::cout<<" - Inorder"<<std::endl;
    preorderTraversal(root1);
    std::cout<<" - Preorder"<<std::endl;
    postorderTraversal(root1);
    std::cout<<" - Postorder"<<std::endl;
    levelOrderTraversal(root1);
    std::cout<<" - Level order"<<std::endl;

    return 0;
}