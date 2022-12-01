#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Tree {
    public:
        Tree();
        Tree(string name);
        Tree(Tree* l, Tree* r);
        Tree(Tree* l, Tree* r, string name);
        ~Tree();

        bool isIsomorphic(Tree* other) const;

        Tree* left;
        Tree* right;
        string label;
};

Tree::Tree() {
    this->left = nullptr;
    this->right = nullptr;
    ostringstream oss;
    oss << this;
    this->label = "Tree@" + oss.str();
}

Tree::Tree(string name) {
    this->left = nullptr;
    this->right = nullptr;
    this->label = name;
}

Tree::Tree(Tree* l, Tree* r) {
    this->left = l;
    this->right = r;
    ostringstream oss;
    oss << this;
    this->label = "Tree@" + oss.str();
}

Tree::Tree(Tree* l, Tree* r, string name) {
    this->left = l;
    this->right = r;
    this->label = name;
}

Tree::~Tree() {
    delete this->left;
    delete this->right;
}

bool Tree::isIsomorphic(Tree* other) const {
    if(other == nullptr) return false;
    if((this->left == nullptr && other->left == nullptr) && this->right == nullptr && other->right == nullptr) return true;
    if((this->left != nullptr && other->left == nullptr) || (this->left == nullptr && other->left != nullptr)) return false;
    if((this->right != nullptr && other->right == nullptr) || (this->right == nullptr && other->right != nullptr)) return false;
    if(this->left != nullptr && other->left != nullptr)
        if(!(this->left)->isIsomorphic(other->left)) return false;
    if(this->right != nullptr && other->right != nullptr)
        if(!(this->right)->isIsomorphic(other->right)) return false;
    return true;
}

int main() {
    Tree t = Tree("A");
    t.left = new Tree("B");
    t.right = new Tree("C");
    t.right->right = new Tree("D");
    Tree u = Tree("E");
    u.left = new Tree("F");
    u.right = new Tree("G");
    u.right->right = new Tree("H");
    cout << t.isIsomorphic(t.right) << endl;
    return 0;
}
