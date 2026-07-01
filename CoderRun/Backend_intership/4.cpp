#include <iostream>

using namespace std;
struct Node{

    Node* left = nullptr;
    Node* right = nullptr;
    int val = 0;
};

Node* insert(Node* node, int val, int& depth){

    depth++;
    if(node == nullptr){
        node = new Node();
        node->val = val;
        return node;
    }

    if(val < node->val)
        node->left = insert(node->left, val,depth);
    else if(val > node->val)
        node->right = insert(node->right, val,depth);

    return node;

}

int main() 
{
    Node* root = nullptr;

    int num = 1;
    int max_depth = 0;

    while(cin >> num && num != 0){

        int cur_depth = 0;
        root = insert(root,num,cur_depth);
        max_depth = max(cur_depth, max_depth);
        //cout << "S = " << max_depth;
    }

    cout << max_depth;



	return 0;
}
