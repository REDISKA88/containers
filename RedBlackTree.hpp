#include <iostream>

struct Node{
public:
    bool isRed;
    int key;
    Node *parent;
    Node *left;
    Node *right;

    Node(int key) {
        this->key = key;
        this->parent = nullptr;
        this->left = nullptr;
        this->right = nullptr;
        this->isRed = false;
    }
};

class RedBlackTree {
    public:
        Node *root;
        Node *replacingNode;
        Node *siblingNode;

        void rotateLeft(Node *_node);
        void rotateRight(Node *_node);
        void insertNode(Node *_node);
        void insertFix(Node *_node);
        void transplant(Node *_oldNode, Node *_newNode);
        void deleteNode(Node *_node);
        void deleteFix(Node *_node);
        void inOrderWalk(Node *_node);
        Node *treeMin(Node *_begin);

        RedBlackTree(){};
};