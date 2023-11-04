// Takes two binary trees T1 and T2 as input, and perform the following tasks:
// * Check T1 and T2 are mirror image of each other.


#include<iostream>

struct Trees
{
    int data;
    Trees *left;
    Trees *right;
};

struct Trees *start = NULL;

Trees *insert(Trees *node,int data)
{
    if (node == NULL)
    {
        struct Trees *temp = new Trees();
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    else if(data < node->data)
    {
        node->left = insert(node->left,data);
    }
    else
    {
        node->right = insert(node->right,data);
    }
    return node;
}

bool mirror(Trees *T1, Trees *T2)
{
    if(T1 == NULL && T2 == NULL)
    {
        return true;
    }
    if(T1 == NULL || T2 == NULL)
    {
        return false;
    }
    if(T1->data == T2->data)
    {
        return mirror(T1->right,T2->right) && mirror(T1->left,T2->left);
    }
    return false;
}

void preorder(Trees *node)
{
    if(node == NULL)
    {
        return;
    }
    std::cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

int main()
{
    struct Trees *root1 = NULL;
    root1 = insert(root1,3);
    insert(root1,5);
    insert(root1,1);

    struct Trees *root2 = NULL;
    root2 = insert(root2,3);
    insert(root2,5);
    insert(root2,1);

    std::cout << "Tree T1: ";
    preorder(root1);
    std::cout << std::endl;

    std::cout << "Tree T2: ";
    preorder(root2);
    std::cout << std::endl;
    
    if(mirror(root1,root2))
    {
        std::cout <<"Trees are mirror image. ";
    }
    else
    {
        std::cout <<"Trees are not mirror image. ";
    }

    return 0;
}


