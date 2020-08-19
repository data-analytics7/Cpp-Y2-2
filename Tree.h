#pragma once
#include "Callback.h"
using namespace std;

template <class T>
struct BSTNode
{
    T element;
    BSTNode<T>* left;
    BSTNode<T>* right;
};

template <class T>
class BST
{
public:

    /**
    * @brief Constructor
    * @param none
    * @pre none
    * @post sets root to null pointer - pntr
    * @return none
    */
    BST();

    /**
    * @brief Destructor that deletes the tree
    * @param none
    * @pre none
    * @post deletes the null pointer pointing to the root of the tree
    * @return none
    */
   ~BST();

   /**
    * @brief Copy Constructor
    * @param none
    * @pre none
    * @post calls function to copy the tree
    * @return none
    */
    BST(const BST<T>& cpytree);

   /**
    * @brief Assignment operator overloading
    * @param none
    * @pre none
    * @post creates tree copy
    * @return none
    */
    const BST<T>& operator = (const BST<T>& rhs);

    /**
    * @brief calls the private Recursive function to insert elements into the tree
    * @param newelement
    * @pre none
    * @post populates the tree
    * @return boolean
    */
    bool insertElement(const T& newelement);

    /**
    * @brief calls the private to perform inOrder tree traversal
    * @param function pointer
    * @pre none
    * @post inOrder tree traversal
    * @return void
    */
    void inOrderTraversal(void (*funcPntr)(const T& pelem)) const;

    /**
    * @brief calls the private to perform preOrder tree traversal
    * @param function pointer
    * @pre none
    * @post preOrder tree traversal
    * @return void
    */
    void preOrderTraversal(void (*funcPntr)(const T& pelem)) const;

    /**
    * @brief calls the private to perform postOrder tree traversal
    * @param function pointer
    * @pre none
    * @post postOrder tree traversal
    * @return void
    */
    void postOrderTraversal(void (*funcPntr)(const T& pelem)) const;

    /**
    * @brief calls the private function to search for an element in the tree
    * @param searchelement
    * @pre none
    * @post returns true if element is found, else false
    * @return bool
    */
    bool Search(const T& searchelement) const;

    /**
    * @brief calls the private function to Delete the tree
    * @param none
    * @pre none
    * @post tree is deleted
    * @return void
    */
    void deleteTree();

private:
    BSTNode<T>* root;

    /**
    * @brief Recursive function to insert elements into the tree
    * @param root pointer, newelement
    * @pre none
    * @post populates the tree
    * @return bool
    */
    bool insertElement(BSTNode<T> * &root, const T& newelement);

    /**
    * @brief Recursive function to perform inOrder tree traversal
    * @param searchnode pointer, function pointer
    * @pre none
    * @post inOrder tree traversal
    * @return void
    */
    void inOrderTraversal(BSTNode<T>* searchnode, void (*funcPntr)(const T& pelem)) const;

     /**
    * @brief Recursive function to perform preOrder tree traversal
    * @param searchnode pointer, function pointer
    * @pre none
    * @post postOrder tree traversal
    * @return void
    */
    void preOrderTraversal(BSTNode<T>* searchnode, void (*funcPntr)(const T& pelem)) const;

     /**
    * @brief Recursive function to perform postOrder tree traversal
    * @param searchnode pointer, function pointer
    * @pre none
    * @post postOrder tree traversal
    * @return void
    */
    void postOrderTraversal(BSTNode<T>* searchnode, void (*funcPntr)(const T& pelem)) const;

    /**
    * @brief Recursive function to search for an element in the tree
    * @param root pointer, searchelement
    * @pre none
    * @post returns true if element is found, else false
    * @return bool
    */
    bool Search(BSTNode<T> *root, const T& searchelement) const;

    /**
    * @brief Recursive function to delete the tree
    * @param node pointer
    * @pre none
    * @post tree is deleted
    * @return void
    */
    void deleteTree(BSTNode<T> * &node);

    /**
    * @brief Recursive function to copy the tree
    * @param none
    * @pre none
    * @post function to copy the tree
    * @return void
    */
    void copyTree(BST<T>* & cpytree, const BST<T>* & myTree);
};

template <class T>
BST<T>::BST()
{
    root = nullptr;
}

template <class T>
BST<T>::~BST()
{
    BSTNode<T> *pntr = root;
    deleteTree(pntr);
}

template <class T>
BST<T>::BST(const BST<T>& cpytree)
{
    copyTree(cpytree);  //myTree
}


template<class T>
void BST<T>::copyTree(BST<T>* & cpytree, const BST<T>* & myTree)
{
    cpytree = myTree;
    if(myTree->right != nullptr)
        cpytree->right = new BSTNode<T>();

    copytree(cpytree->right, myTree->right);
}

template <class T>
const BST<T> & BST<T>::operator = (const BST<T>& rhs)
{
    if(root != nullptr) deleteTree(root );
    copyTree(rhs);
}

template<class T>
void BST<T>::deleteTree()
{
    deleteTree(root);
}

template<class T>
void BST<T>::deleteTree(BSTNode<T> *&node)
{
    if(node!=NULL)
    {
        deleteTree(node->left);
        deleteTree(node->right);
        delete(node);
        if(node->left!=NULL)
            node->left=NULL;
        if(node->right!=NULL)
            node->right=NULL;
        node=NULL;
    }
}

template <class T>
bool BST<T>::insertElement(const T& newelement)
{
    return insertElement(root, newelement);
}

template <class T>
bool BST<T>::insertElement(BSTNode<T> * &root, const T& newelement)
{
    if(root == nullptr)
    {
        root = new BSTNode<T>;
        root->element = newelement;
        root->left = nullptr;
        root->right = nullptr;
        return true;
    }
    else if(newelement < root -> element)
    {
        if(root -> left == nullptr)
        {
            root -> left =new BSTNode<T>;
            root->left->right = nullptr;
            root->left->left = nullptr;
            root->left->element = newelement;
            return true;
        }
        else
            return insertElement(root->left, newelement);
    }

    if(newelement > root -> element)
    {
        if(root -> right == nullptr)
        {
            root -> right =new BSTNode<T>;
            root->right->right = nullptr;
            root->right->left = nullptr;
            root->right->element = newelement;
            return true;
        }
        else
            return insertElement(root->right, newelement);
    }
    return false;

}

template<class T>
void BST<T>:: inOrderTraversal(BSTNode<T>* searchnode, void (*printpntr)(const T& pelem)) const
{
    if(searchnode !=nullptr)
    {
        inOrderTraversal(searchnode->left, printpntr);
        printpntr(searchnode -> element);
        inOrderTraversal(searchnode->right, printpntr);
    }
}

template<class T>
void BST<T>:: inOrderTraversal(void (*printpntr)(const T& pelem)) const
{
    inOrderTraversal(root, printpntr);
}

template<class T>
void BST<T>:: preOrderTraversal(BSTNode<T>* searchnode, void (*funcPntr)(const T& pelem)) const
{
    if(searchnode != nullptr)
    {
        funcPntr(searchnode -> element);
        preOrderTraversal(searchnode -> left, funcPntr);
        preOrderTraversal(searchnode -> right, funcPntr);
    }
}

template<class T>
void BST<T>:: preOrderTraversal(void (*funcPntr)(const T& pelem)) const
{
    preOrderTraversal(root, funcPntr);
}

template<class T>
void BST<T>:: postOrderTraversal(BSTNode<T>* searchnode, void (*funcPntr)(const T& pelem)) const
{
    if(searchnode != nullptr)
    {
        postOrderTraversal(searchnode -> left, funcPntr);
        postOrderTraversal(searchnode -> right, funcPntr);
        funcPntr(searchnode -> element);
    }
}

template<class T>
void BST<T>:: postOrderTraversal(void (*funcPntr)(const T& pelem)) const
{
    postOrderTraversal(root, funcPntr);
}

template <class T>
bool BST<T>::Search(const T& searchelement) const
{
    return Search(root, searchelement);
}

template<class T>
bool BST<T>::Search(BSTNode<T> *root, const T& searchelement) const
{
    if (root == nullptr)
        return false;

    else
        if (root->element == searchelement)
        {
            cout<<"date found: "<< root->element<<endl;
            return true;
        }

        else
            if (root->element < searchelement)
                return Search(root->right, searchelement);

            else
                return Search(root->left, searchelement);
}



