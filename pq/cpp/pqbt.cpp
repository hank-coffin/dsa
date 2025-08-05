#include <iostream>

struct node {
    node(   int priority = 0 
          , node* parent = nullptr
          , node* left = nullptr
          , node* right = nullptr
          ) 
        : priority( priority ) 
        , parent (  parent )
        , left( left )
        , right( right ) { 
    }

    int priority;
    node* parent;
    node* left;
    node* right;
};

class pq {
public:
    pq();

    void insert( int priority );
    int pop();

private:
    node* root = nullptr;
};

// heap/priority queue rules
// the node value is always greater than child values
// leaf nodes populate from left to right 
//   -> height of tree is log ( elements )
// 
//       +50
//   +20     +25  
// +4 +10  +12 +15
// +1  +3
//


void pq::insert( int priority ) {
    node* n = new node( priority );

    if ( root == nullptr ){
        root = n;
    }
    else {
        bool done = false;
        node* r = root;

        while (!done){
            if ( priority > r->priority )
            {
                n->parent = r->parent;
                r->parent = n;
                 = new node( priority, )
            }
        }

    }

}

int pq::pop()
{
    if ( root ) {
        node* r = root;
        int priority = r->priority;

        if ( r->left && r->right ) { 
            if ( r->left->priority > r->right->priority ) {
                root = r->left; 
            }
            else {
                root = r->right; 
            }
        }
        return priority;
    }
    return 0;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
