#include "btNode.h"

// write definition for bst_insert here
bool bst_insert(btNode*& bst_root,int insInt){
    bool inserted = false;
    if(bst_root != 0){
        if(insInt < bst_root->data){
            bst_insert(bst_root->left, insInt);
        }
        if(insInt > bst_root->data){
            bst_insert(bst_root->right, insInt);
        }
    }
    else{
        bst_root = new btNode;
        bst_root->data = insInt;
        bst_root->left = bst_root->right = 0;
        inserted = true;
    }
    return inserted;
}
// write definition for bst_remove here
bool bst_remove(btNode*& bst_root,int remInt){
    bool removed = false;
    if(bst_root != 0){
        if(remInt < bst_root->data){
            bst_remove(bst_root->left, remInt);
        }
        else if(remInt > bst_root->data){
            bst_remove(bst_root->right, remInt);
        }
        else{
            btNode* old_bst_root = bst_root;
            if(bst_root->left == 0 and bst_root->right == 0){ //no children
                bst_root = 0;
            }
            else if(bst_root->left == 0){ //one child cases
                bst_root = bst_root->right;
            }
            else if(bst_root->right == 0){
                bst_root = bst_root->left;
            }
            else{
                bst_remove_max(bst_root->left, bst_root->data);//in progress
            }
            delete old_bst_root;
        }
    }
    return removed;
}
// write definition for bst_remove_max here
void bst_remove_max(btNode*& bst_root,int& removed){
    if(bst_root->right != 0){
        bst_remove_max(bst_root->right, removed);
    }
    else{
        removed = bst_root->data;
        bst_remove(bst_root, bst_root->data);
    }
}

void portToArrayInOrder(btNode* bst_root, int* portArray)
{
   if (bst_root == 0) return;
   int portIndex = 0;
   portToArrayInOrderAux(bst_root, portArray, portIndex);
}

void portToArrayInOrderAux(btNode* bst_root, int* portArray, int& portIndex)
{
   if (bst_root == 0) return;
   portToArrayInOrderAux(bst_root->left, portArray, portIndex);
   portArray[portIndex++] = bst_root->data;
   portToArrayInOrderAux(bst_root->right, portArray, portIndex);
}

void tree_clear(btNode*& root)
{
   if (root == 0) return;
   tree_clear(root->left);
   tree_clear(root->right);
   delete root;
   root = 0;
}

int bst_size(btNode* bst_root)
{
   if (bst_root == 0) return 0;
   return 1 + bst_size(bst_root->left) + bst_size(bst_root->right);
}
