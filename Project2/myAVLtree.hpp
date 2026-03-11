#ifndef MYAVLTREE_HPP
#define MYAVLTREE_HPP
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <chrono>

struct AVLnode 
{
    //Struct stuff
    AVLnode *right;
    AVLnode *left;

    //Helper variables
    int height; 
    int element;

    //A constructor which gives a value to its left/right node and its height
    AVLnode(const int &ele, AVLnode *lt, AVLnode *rt, int h = 0) : 
    element(ele), left(lt), right(rt), height(h) {}

    //USING STd::MOVE WHICH MEANS R-VALUES RAHHHHHHHH
    //Manages moving elements from one node to another
    AVLnode(int &&ele, AVLnode *lt, AVLnode *rt, int h = 0) : 
    element(std::move(ele)), left(lt), right(rt), height(h) {}
};

//Manages the height of the node
int height(AVLnode *t);

//Manages the inserting process into the subtree
void insert(const int &x, AVLnode *&t);

//Manages balancing the tree
void balance(AVLnode *&t);

//Manages the different type of rotations amongst the nodes
void rotateWithLeftChild(AVLnode *&k2);
void rotateWithRightChild(AVLnode *&k1);
void doubleWithLeftChild(AVLnode *&k3);
void doubleWithRightChild(AVLnode *&k1);

//Manages the removal of nodes within the subtree
void remove(const int &x, AVLnode *&t);

//Finds the lowest value within the avl tree
AVLnode *findMinimum(AVLnode *t);

//Finds the highest value within the avl tree
AVLnode *findMaximum( AVLnode *t );

//Take in the vector from the main file yippie
void treeMedian(const std::vector<int> *instructions);

#endif