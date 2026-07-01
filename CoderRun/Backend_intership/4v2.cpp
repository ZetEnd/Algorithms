#include <iostream>

using namespace std;
struct Node{

    Node* left = nullptr;
    Node* right = nullptr;
    int val = 0;
};

int insert(Node*& node, int val){


    int depth = 1;
    if(node == nullptr){
        node = new Node();
        node->val = val;
        return depth;
    }

    if(val < node->val)
        depth = insert(node->left, val)+1;
    else if(val > node->val)
        depth = insert(node->right, val)+1;

    return depth;

}

int main() 
{
    Node* root = nullptr;

    int num = 1;
    int max_depth = 0;

    while(cin >> num && num != 0){
        max_depth = max(insert(root,num), max_depth);
        //cout << "S = " << max_depth;
    }

    cout << max_depth;



	return 0;
}
