#include "btNode.h"
#include <iostream>

// write definition for bst_insert here
bool bst_insert(btNode*& bst_root, int insInt){
    bool inserted = false;
    btNode* cursor = bst_root;
    if(bst_root == 0){
        std::cout << "inserting " << insInt << " at root" << std::endl;
        bst_root = new btNode;
        bst_root->data = insInt;
        bst_root->left = bst_root->right = 0;
        inserted = true;
    }
    while(!inserted){
        if(insInt < cursor->data){
            if(cursor->left != 0){
                cursor = cursor->left;
            }
            else{
                std::cout << "inserting " << insInt << " at " << cursor->data << "'s left link" << std::endl;
                cursor->left = new btNode;
                cursor->left->data = insInt;
                cursor->left->left = cursor->left->right = 0;
                inserted = true;
            }
        }
        else if (insInt > cursor->data){
            if(cursor->right != 0){
                cursor = cursor->right;
            }
            else{
                std::cout << "inserting " << insInt << " at " << cursor->data << "'s right link" << std::endl;
                cursor->right = new btNode;
                cursor->right->data = insInt;
                cursor->right->left = cursor->right->right = 0;
                inserted = true;
            }
        }
        else if(insInt == cursor->data){
            std::cout << "duplicate value, aborting" << std::endl;
            return false; //do not insert if insInt already exists
        }
        //std::cout << "current root is" << bst_root->data << std::endl;
    }
    return inserted;
}
// write definition for bst_remove here
bool bst_remove(btNode*& bst_root,int remInt){
    std::cout << "rm, ";
    bool removed = false;
    if(bst_root != 0){
        if(remInt < bst_root->data){
            removed = bst_remove(bst_root->left, remInt);
        }
        else if(remInt > bst_root->data){
            removed = bst_remove(bst_root->right, remInt);
        }
        else{
            btNode* old_bst_root = bst_root;
            if(bst_root->left == 0 and bst_root->right == 0){ //no children
                bst_root = 0;
                old_bst_root = 0;
            }
            else if(bst_root->left == 0){ //one child cases
                bst_root = bst_root->right;
            }
            else if(bst_root->right == 0){
                bst_root = bst_root->left;
            }
            else{
                bst_remove_max(bst_root->left, bst_root->data);
            }
            delete old_bst_root;
            removed = true;
        }
    }
    return removed;
}
// write definition for bst_remove_max here
void bst_remove_max(btNode*& bst_root,int& removed){
    //std::cout << "called remove_max ";
    if(bst_root->right == 0){
        removed = bst_root->data;
        btNode* old_bst_root = bst_root;
        bst_root = bst_root->left;
        delete old_bst_root;
    }
    else{
        bst_remove_max(bst_root->right, removed);
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
