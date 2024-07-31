//*****************************************************************************************************
//
//		File:					AVL.h
//
//		This program will impliment and test a AVL tree class.
//	
//		Other files required: 
//         1. Node.h
//			
//*****************************************************************************************************

#include"Node.h"
#include<iostream>

//*****************************************************************************************************

template<typename T>
class AVLTree
{
public:
    AVLTree();
    ~AVLTree();
    void destroy();
    void insert(const T& item);
    void inorder() const;
    void preorder() const;
    void postorder() const;
    T* search(const T& item) const;
    int height() const;

private:
    Node<T>* root;

    void destroy(Node<T>* node);
    Node<T>* insert(Node<T>* node, const T& item);
    void inorder(Node<T>* node) const;
    void preorder(Node<T>* node) const;
    void postorder(Node<T>* node) const;
    Node<T>* search(Node<T>* node, const T& item) const;
    int height(Node<T>* node) const;
    int max(int a, int b) const;
    void updatebFactors(Node<T>* node);
    void rotateRight(Node<T>*& k1);
    void rotateLeft(Node<T>*& k1);
    int getBalance(Node<T>* node) const;
};

//*****************************************************************************************************

template<typename T>
AVLTree<T>::AVLTree()
{
    root = nullptr;
}

//*****************************************************************************************************

template<typename T>
AVLTree<T>::~AVLTree() 
{
    destroy();
}

//*****************************************************************************************************

template<typename T>
void AVLTree<T>::destroy() 
{
    destroy(root);
    root = nullptr;
}

//*****************************************************************************************************

template<typename T>
void AVLTree<T>::destroy(Node<T>* node)
{
    if (node != nullptr)
    {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

//*****************************************************************************************************

template<typename T>
void AVLTree<T>::insert(const T& item)
{
    root = insert(root, item);
}

//*****************************************************************************************************

template<typename T>
Node<T>* AVLTree<T>::insert(Node<T>* node, const T& item)
{
    if (node == nullptr) 
    {
        node = new Node<T>;
        node->value = item;
        node->left = nullptr;
        node->right = nullptr;
        node->bFactor = 0;
    }
    else if (item < node->value) 
    {
        node->left = insert(node->left, item);
    }
    else
    {
        node->right = insert(node->right, item);
    }

    node->bFactor = getBalance(node);

    if (node->bFactor > 1) 
    {
        if (item < (node->left->value))
        {
            rotateRight(node);
        }
        else
        {
            rotateLeft(node->left);
            rotateRight(node);
        }
    }
    else if (node->bFactor < -1)
    {
        if (item > (node->right->value)) 
        {
            rotateLeft(node);
        }
        else 
        {
            rotateRight(node->right);
            rotateLeft(node);
        }
    }

    return node;
}

//*****************************************************************************************************

template<typename T>
void AVLTree<T>::inorder() const 
{
    inorder(root);
}

//*****************************************************************************************************

template<typename T>
void AVLTree<T>::inorder(Node<T>* node) const 
{
    if (node != nullptr) {
        inorder(node->left);
        std::cout << node->value << " ";
        inorder(node->right);
    }
}

//*****************************************************************************************************

template<typename T>
void AVLTree<T>::preorder() const 
{
    preorder(root);
}

//*****************************************************************************************************

template<typename T>
void AVLTree<T>::preorder(Node<T>* node) const
{
    if (node != nullptr) {
        std::cout << node->value << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

//*****************************************************************************************************

template<typename T>
void AVLTree<T>::postorder() const 
{
    postorder(root);
}

//*****************************************************************************************************

template<typename T>
void AVLTree<T>::postorder(Node<T>* node) const 
{
    if (node != nullptr) {
        postorder(node->left);
        postorder(node->right);
        std::cout << node->value << " ";
    }
}

//*****************************************************************************************************

template<typename T>
T* AVLTree<T>::search(const T& item) const 
{
    Node<T>* result = search(root, item);
    if (result != nullptr) {
        return &result->value;
    }
    else {
        return nullptr;
    }
}

//*****************************************************************************************************

template<typename T>
Node<T>* AVLTree<T>::search(Node<T>* node, const T& item) const 
{
    while (node != nullptr) 
    {
        if (item == node->value)
        {
            return node;
        }
        else if (item < node->value) 
        {
            node = node->left;
        }
        else 
        {
            node = node->right;
        }
    }
    return nullptr;
}

//*****************************************************************************************************

template<typename T>
int AVLTree<T>::height() const 
{
    return height(root);
}

//*****************************************************************************************************

template<typename T>
int AVLTree<T>::height(Node<T>* node) const 
{
    if (node == nullptr)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}

//*****************************************************************************************************

template<typename T>
int AVLTree<T>::max(int a, int b) const {
    return (a > b) ? a : b;
}

//*****************************************************************************************************

template<typename T>
void AVLTree<T>::updatebFactors(Node<T>* node)
{
    if (node != nullptr)
    {
        node->bFactor = getBalance(node);
        updatebFactors(node->left);
        updatebFactors(node->right);
    }
}

//*****************************************************************************************************

template<typename T>
void AVLTree<T>::rotateRight(Node<T>*& k1)
{
    if (k1 == nullptr || k1->left == nullptr)
        return;

    Node<T>* k2 = k1->left;
    k1->left = k2->right;
    k2->right = k1;
    k1 = k2;
}

//*****************************************************************************************************

template<typename T>
void AVLTree<T>::rotateLeft(Node<T>*& k1)
{
    if (k1 == nullptr || k1->right == nullptr)
        return;

    Node<T>* k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1 = k2;
}

//*****************************************************************************************************

template<typename T>
int AVLTree<T>::getBalance(Node<T>* node) const
{
    if (node == nullptr)
        return 0;

    return height(node->left) - height(node->right);
}

//*****************************************************************************************************
