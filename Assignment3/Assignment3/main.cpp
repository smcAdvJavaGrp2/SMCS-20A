//
//  main.cpp
//  Assignment3
//
//  Created by Nashir Janmohamed on 3/20/18.
//  Copyright © 2018 Nashir Janmohamed. All rights reserved.
//

#include <iostream>
using namespace std;

class A {
public:
    A() :m_msg("Apple") {}
    A(string msg) : m_msg(msg) {}
    virtual ~A() { message(); }
    virtual void message() const {
        cout << m_msg << endl;
    }
private:
    string m_msg;
};

class B :public A {
public:
    B() :A("Orange") {}
    B(string msg) : A(msg), m_a(msg) {}
    void message() const {
        m_a.message();
    }
private:
    A m_a;
};

int main(){
    
    A *b1 = new B;
    B *b2 = new B;
    A *b3 = new B("Apple");
    b1->message();
    b2->message();
    (*b3).message();
    delete b1;
    delete b2;
    delete b3;
    
}


