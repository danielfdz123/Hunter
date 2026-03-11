#include "myAVLtree.hpp"

//Manages the height of the node
int height(AVLnode *node) 
{
    //If node is empty, return -1
    if(node == nullptr) 
    {
        return -1;
    } 
    //Returns the height of the node
    else 
    {
        return node -> height;
    }
}

//Manages the inserting process into the subtree
void insert(const int &num, AVLnode *&node) 
{
    //If node is empty, make a new node and insert value into it
    if(node == nullptr) 
    {
        node = new AVLnode(num, nullptr, nullptr);
    } 
    //If child has a smaller value than its parent, insert it as a left node    
    else if(num <= node->element) 
    {
        insert(num, node->left);
    } 
    //If child has a bigger value than its parent, insert it as a right node    
    else if(node->element < num) 
    {
        insert(num, node->right);
    }
    //Calls balancing function to maintin the AVL tree property
    balance(node);
}

//Assume node is balanced or within one of being balanced
void balance(AVLnode *&node)
{
    //If node is empty, exit the function because you cant balance nothing silly
    if(node == nullptr) 
    {
        return;
    }
    //If theres an inmabance greater than 1 on the left side..
    if(height(node->left) - height(node->right) > 1) 
    {
        //Perform single rotation
        if(height(node->left->left) >= height(node->left->right)) 
        {
            rotateWithLeftChild(node);
        } 
        //Perform double rotation (RL Rotation)
        else 
        {
            doubleWithLeftChild(node);
        }
    } 
    //If theres an inmabance greater than 1 on the right side..
    else if (height(node->right) - height(node->left) > 1) 
    {
        //Perform single rotation
        if(height(node->right->right) >= height(node->right->left)) 
        {
            rotateWithRightChild(node);
        } 
        //Perform double rotation (LR Rotation)
        else 
        {
            doubleWithRightChild(node);
        }
    }
    node->height = std::max(height(node->left), height(node->right)) + 1; 
}

//Resonsible for moving the nodes around and performing a Left rotation
void rotateWithLeftChild(AVLnode *&k2)
{
    //k1 = kid 1 (child 1)
    //k2 = kid 2 (child 2)
    AVLnode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = std::max(height(k2->left), height(k2->right)) + 1;
    k1->height = std::max(height(k1->left), k2->height) + 1;
    k2 = k1;
}

//Resonsible for moving the nodes around and performing a Right rotation
void rotateWithRightChild(AVLnode *&k2)
{
    AVLnode *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = std::max(height(k2->right), height(k2->left)) + 1;
    k1->height = std::max(height(k1->right), k2->height) + 1;
    k2 = k1;
}

//Calls in the functions necessary to make an RL Rotation
void doubleWithLeftChild(AVLnode *&k3)
{
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

//Calls in the functions necessary to make an LR rotation
void doubleWithRightChild(AVLnode *&k3) 
{
    rotateWithLeftChild(k3->right); 
    rotateWithRightChild(k3); 
}

//Manages the removal of nodes within the subtree
void remove(const int &num, AVLnode *&node)
{
    //If the node is empty, do nothing since there is nothing to remove
    if (node == nullptr) 
    {
        return;
    }
    //Loops through the tree wether ot not a value is less/greater than the current node
    if (num < node->element) 
    {
        remove(num, node->left);
    } 
    else if (node->element < num) 
    {
        remove(num, node->right); 
    } 
    //This 'else if' removes both left/right children and replaces the value with the minimum value
    else if (node->left != nullptr && node->right != nullptr) 
    {
        node->element = findMinimum(node->right)->element;
        remove(node->element, node->right);
    } 
    //Removes node with one/no child at all, deallocating its memory and setting it to nullptr
    else
    {
        AVLnode *oldNode = node; 
        node = (node->left != nullptr) ? node->left : node->right; 
        delete oldNode;
        oldNode = nullptr;
    }
    //Rebalance once removals are done
    balance(node);
}

//Finds lowest value of the AVL tree
AVLnode *findMinimum(AVLnode *node)
{
    //If the node is empty, return nothing
    if(node == nullptr)
    {
        return nullptr;
    }
    //If the left node has nothing, return the node since mininum has been found
    if(node->left == nullptr)
    {
        return node;
    }
    //Calls function to find the lowest node (median)
    return findMinimum(node->left);
}

//Calls function to find the highest value in the tree
AVLnode *findMaximum(AVLnode *node)
{
    //If the node is not empty....
    if (node != nullptr)
    {
        //move down to the right node if it isnt empty
        while(node->right != nullptr)
        {
            node = node->right;
        }
    }
    //Return the designated node once max is found
    return node;
}

void treeMedian(const std::vector<int> *instructions)
{
    //This will time the program and see how long it'll take to finish 
    const auto t1_start = std::chrono::steady_clock::now();

    //New vector, which will hold all the median values
    std::vector<int> medians;

    //Pointers that can be assigned to nodes later on
    AVLnode *max = nullptr;
    AVLnode *min = nullptr; 

    //Helper variables (used to help keep track of balancing)
    int countmax = 0;
    int countmin = 0;

    //This will iterate through the instructions vector from the main file, and pop the median when necessary
    for (auto it = instructions->begin(); it != instructions->end(); it++)
    {
        //If max is empty and the value isn't -1, then we....
        if(max == nullptr && *it != -1) 
        {
            //Insert in the tree
            insert(*it, max);
            countmax += 1; 
        } 
        //If we come across a -1...
        else if(*it == -1) 
        {
            //Finds the largest value in 'max', adds it to the medians vector
            AVLnode *rightMost = findMaximum(max);
            medians.push_back(rightMost->element); 
            //Calls remove so that function deletes that same value
            remove(rightMost->element, max);
            countmax -= 1; 
            //Checks for a possible node swap or some type of change
            if(countmin > countmax) 
            {
                //Nodes are swapped around
                AVLnode *leftMost = findMinimum(min);
                auto copy = leftMost->element;
                remove(copy, min);
                insert(copy, max);
                countmin -= 1;
                countmax += 1;
            }
        } 
        else 
        {
            //If term is less than or = to max element, we need to make necessary changes so things stay in order
            if(*it <= findMaximum(max)->element) 
            {
                insert(*it, max);
                countmax += 1;
                if(countmax > countmin + 1) 
                {
                    AVLnode *rightMost = findMaximum(max);
                    int copyy = rightMost->element;
                    remove(copyy, max);
                    insert(copyy, min); 
                    countmax -= 1;
                    countmin += 1; 
                }
            } 
            //If the rterm is greater than or = the max, we also make necessary changes so things stay in order
            else if(*it > findMaximum(max)->element) 
            {
                insert(*it, min);
                countmin += 1; 
                if(countmin > countmax)
                {
                    AVLnode *leftMost = findMinimum(min);
                    auto coppyyy = leftMost->element;
                    remove(coppyyy, min);
                    insert(coppyyy, max);
                    countmin -= 1;
                    countmax += 1;
                }
            }
        }
    }

    //Will loop through the medianVector and will print out values from the list
    for(int i = 0; i < medians.size(); i++) 
    {
    std::cout << medians[i] << " ";
    }

    //Stops the timing and will output how long it'll take to run this algorithm
    const auto t1_end = std::chrono::steady_clock::now();
    int t1 = std::chrono::duration<double, std::micro>(t1_end - t1_start).count();
    std::cout << "\nThis program's runtime: " << t1 << " microseconds" << std::endl;

}