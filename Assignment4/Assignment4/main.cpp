//
//  main.cpp
//  Assignment4
//
//  Created by Nashir Janmohamed on 4/23/18.
//  Copyright © 2018 Nashir Janmohamed. All rights reserved.
//

#include <iostream>
using namespace std;

bool isPalindrome(string s){
    int len = (int)s.length();
    
    if (len <= 1)
        return true;
    
    if (s[0] == s[len-1])
        return isPalindrome(s.substr(1, len-2));
    else
        return false;
}

int mystery1(int a, int b){
    if (b == 0) return 1;
    
    if (b % 2 == 0) return mystery1(a*a, b/2);
    
    return mystery1(a*a, b/2) * a;
}

int mystery2(int a, int b){
    if (b == 0) return 0;
    
    if (b % 2 == 0) return mystery1(a+a, b/2);
    
    return mystery1(a+a, b/2) + a;
}

void printReverse(int *arr, int size){
    if (size == 0)
        return;
    cout << arr[size-1];
    printReverse(arr, size-1);
}


struct Node{
    int val;
    Node* next;
};

void printLinkedList(Node* head){
    if (head == nullptr)
        return;
    else
        cout << head->val << endl;
    
    if (head->next != nullptr)
        printLinkedList(head->next);
}

void deleteLinkedList(Node* head){
    if (head == nullptr)
        return;
    if (head->next != nullptr)
        deleteLinkedList(head->next);
//    cout << "deleting Node #" << head->val << endl;
    delete head;
}


#include <cmath>

//int magicsumOfDigits(int n){
//    int sum, temp, power = log10(n);
//    sum = temp = 0;
//    while (power >= 0){
//        temp = n/pow(10, power);
//        sum += temp;
//        n -= pow(10, power) * temp;
//        power -= 1;
//    }
//    return sum;
//}

int sumOfDigits(int n){
    int power = log10(n);
    if (power == 0)
        return n;
    return sumOfDigits(n/10) + (n % 10);
}

Node* inPlaceMerge(Node* list1, Node* list2){
    //base cases
    if (list1 == nullptr && list2 == nullptr)
        return nullptr;
    else if (list2 == nullptr)
        return list1;
    else if (list1 == nullptr)
        return list2;
    else{
        Node* newList;
        
        if (list1->val < list2->val){
            newList = list1;
            newList->next = inPlaceMerge(list1->next, list2);
        }else{
            newList = list2;
            newList->next = inPlaceMerge(list1, list2->next);
        }
        return newList;
    }
}

int main(int argc, const char * argv[]) {
    string s = "wow";
    
    cout << s << " ";
    if (isPalindrome(s))
        cout << "is";
    else
        cout << "isn't";
    cout << " a palindrome!" << endl;
    
    int a = 5, b = 2;
    cout << a << "^" << b << " is " << mystery1(a, b) << endl;
    
    cout << a << "*" << b << " is " << mystery2(a, b) << endl;
    
    int arr [] = {1, 2, 3, 4, 5};
    
    printReverse(arr, 5);
    
    cout << endl;
    
    int n = 20815;
    int sum = sumOfDigits(n);
    cout << "the sum of the digits in " << n << " is " << sum << endl;
    
    Node* first1 = new Node;
    Node* second1 = new Node;
    Node* third1 = new Node;
    Node* list1 = first1;
    first1->val = 8;
    first1->next = second1;
    second1->val = 23;
    second1->next = third1;
    third1->val = 23054853;
    third1->next = nullptr;
    
    Node* first2 = new Node;
    Node* second2 = new Node;
    Node* third2 = new Node;
    Node* list2 = first2;
    first2->val = -3294;
    first2->next = second2;
    second2->val = 6;
    second2->next = third2;
    third2->val = 394;
    third2->next = nullptr;
    
//    printLinkedList(list1);
//    deleteLinkedList(list1);
    
    Node* newList = inPlaceMerge(list1, list2);
    
    cout << "the sorted list is:" << endl;
    printLinkedList(newList);
    
    return 0;
}
