//
//  main.cpp
//  FinalReview
//
//  Created by Nashir Janmohamed on 6/4/18.
//  Copyright © 2018 Nashir Janmohamed. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int val;
    vector<Node*> children;
};

int nodeCount(Node* node){
    if (node == nullptr)
        return 0;
    int total = 1, index = 0;
    while (index < node->children.size()){
        total += nodeCount(node->children[index]);
        index++;
    }
    return total;
}

int leafCount(Node* node){
    if (node->children.size() == 0)
        return 1;
    int total = 0, index = 0;
    while (index < node->children.size()){
        total += leafCount(node->children[index]);
        index++;
    }
    return total;
}

int main(int argc, const char * argv[]) {
    Node * p = new Node;
    Node * p1 = new Node;
    Node * p2 = new Node;
    Node * p3 = new Node;
    Node * q = new Node;
    Node * q1 = new Node;
    Node * q2 = new Node;
    Node * q3 = new Node;

    p->children.push_back(p1);
    p1->children.push_back(p2);
    p1->children.push_back(p3);
    p->children.push_back(q);
//    q->children.push_back(q1);
//    q1->children.push_back(q2);
//    q1->children.push_back(q3);
    
    cout << nodeCount(p) << endl;
    cout << leafCount(p) << endl;
    return 0;
}
