#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)
#include <algorithm>
#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here

bool equalPathsHelper(Node *node, int depth, int &leafDepth) {
    if (!node) {
        return true; 
    }
    if (!node->left && !node->right) { 
        if (leafDepth == -1) {
            leafDepth = depth; 
            return true;
        }
        return depth == leafDepth;
    }
    return equalPathsHelper(node->left, depth + 1, leafDepth) &&
           equalPathsHelper(node->right, depth + 1, leafDepth);
}

bool equalPaths(Node *root) {
    int leafDepth = -1;
    return equalPathsHelper(root, 0, leafDepth);
}
