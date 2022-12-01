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

int main() {
    Tree t = Tree("A");
    t.left = new Tree("B");
    t.right = new Tree("C");
    t.right->right = new Tree();
    cout << t.right->right->label << endl;
    return 0;
}