#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Tree {
    public:
        void init(Tree* l, Tree* r, string name);
        Tree();
        Tree(string name);
        Tree(Tree* l, Tree* r);
        Tree(Tree* l, Tree* r, string name);
        ~Tree();

        bool isIsomorphic(Tree* other) const;
        int numVertices() const;
        int numLeaves() const;

        Tree* left;
        Tree* right;
        string label;
};

// Initialize all values, used from constructors
void Tree::init(Tree* l, Tree* r, string name) {
    this->left = l;
    this->right = r;
    this->label = name;
}

Tree::Tree() {
    ostringstream oss;
    oss << this;
    this->init(nullptr, nullptr, "Tree@" + oss.str());
    
}

Tree::Tree(string name) {
    this->init(nullptr, nullptr, name);
}

Tree::Tree(Tree* l, Tree* r) {
    ostringstream oss;
    oss << this;
    this->init(l, r, "Tree@" + oss.str());
}

Tree::Tree(Tree* l, Tree* r, string name) {
    this->init(l, r, name);
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

int Tree::numVertices() const {
    int numVertices = 1;
    if(this->left != nullptr) numVertices += this->left->numVertices();
    if(this->right != nullptr) numVertices += this->right->numVertices();
    return numVertices;
}

int Tree::numLeaves() const {
    if(this->left == nullptr && this->right == nullptr) return 1;
    else return (this->left == nullptr ? 0 : this->left->numLeaves()) + (this->right == nullptr ? 0 : this->right->numLeaves());
}

int main() {
    Tree* t = new Tree("A");
    t->left = new Tree("B");
    t->right = new Tree("C");
    t->right->right = new Tree("D");
    Tree* u = new Tree("E");
    u->left = new Tree("F");
    u->right = new Tree("G");
    u->right->right = new Tree("H");
    t->right->left = new Tree(u, nullptr, "lolz");
    t->right->left->right = new Tree(nullptr, nullptr, "helo");
    cout << u->left->isIsomorphic(t->right->left->left->left) << endl;
    cout << t->numVertices() << endl;
    cout << u->numLeaves() << endl;
    cout << t->numLeaves() << endl;
    delete t;
    return 0;
}
