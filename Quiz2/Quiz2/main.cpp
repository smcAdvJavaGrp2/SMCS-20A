//
//  main.cpp
//  Quiz2
//
//  Created by Nashir Janmohamed on 5/28/18.
//  Copyright © 2018 Nashir Janmohamed. All rights reserved.
//

#include <iostream>
#include "sdll.h"

using std::endl;
using std::cout;

#define test1


int powerThree(int n){
    if (n < 1)
        return 1;
    if (n == 1)
        return 3;
    return (powerThree(n-1) + powerThree(n-1) + powerThree(n-1));
}

int recursivePow(int base, int exp){
    if (exp < 1)
        return 1;
    return (base * recursivePow(base, exp-1));
}

int main(int argc, const char * argv[]) {
//    SortedLinkedList sll;
//#ifdef test1
//    sll.insert(6);
//    sll.insert(4);
//    sll.insert(2);
//    sll.printIncreasingOrder();
//    cout << "=========" << endl;
//    sll.insert(5);
//    sll.printIncreasingOrder();
//    cout << "=========" << endl;
//#endif
//#ifdef test2
//    sll.insert(5);
//    sll.printIncreasingOrder();
//    #endif
//#ifdef test3
//    sll.insert(10);
//    sll.insert(6);
//    sll.printIncreasingOrder();
//    cout << "=========" << endl;
//    sll.insert(5);
//    sll.printIncreasingOrder();
//#endif
//#ifdef test4
//    sll.insert(6);
//    sll.printIncreasingOrder();
//    cout << "=========" << endl;
//    sll.insert(5);
//    sll.printIncreasingOrder();
//#endif
//#ifdef test5
//    sll.insert(1);
//    sll.printIncreasingOrder();
//    cout << "=========" << endl;
//    sll.insert(5);
//    sll.printIncreasingOrder();
//    cout << "=========" << endl;
//#endif
//#ifdef test6
//    sll.insert(1);
//    sll.printIncreasingOrder();
//    cout << "=========" << endl;
//    sll.insert(5);
//    sll.printIncreasingOrder();
//    cout << "=========" << endl;
//    sll.insert(10);
//    sll.printIncreasingOrder();
//    cout << "=========" << endl;
//#endif
//#ifdef test1
//    const Node* p = sll.search(4);
//    Node *remove=const_cast<Node*>(p);
//    sll.remove(remove);
//    sll.printIncreasingOrder();
//    cout << "=========" << endl;
//#endif
//
//    cout << recursivePow(3, 3) << endl;
//    cout << powerThree(4) << endl;

    int counter = 0;
    int n = 0;
    counter++;
    int k = 1;
    counter++;
    while (k <= n){
        counter++;
        int j = 2*k;
        counter++;
        while (j >= 1){
            counter++;
            cout << j << endl;
            counter++;
            j /= 2;
            counter++;
        }
        k++;
        counter++;
    }

    cout << counter << endl;
    return 0;
}
