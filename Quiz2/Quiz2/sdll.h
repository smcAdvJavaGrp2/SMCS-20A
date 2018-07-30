#ifndef sdll_h
#define sdll_h

#include <iostream>

struct Node {
    int value;
    Node *prev;
    Node *next;
};

class SortedLinkedList {
public:
    SortedLinkedList();
    bool insert(const int &value);
    const Node *search(const int &value) const;
    void remove(Node *node);
    int size() const { return m_size; }
    void printIncreasingOrder() const;
private:
    Node * m_head;
    Node *m_tail;
    int m_size;
};

SortedLinkedList::SortedLinkedList() {
    m_size = 0;
    m_head = m_tail = nullptr;
}

bool SortedLinkedList::insert(const int &value) {
    m_size++;
    if (m_head == nullptr){
        Node* n = new Node;
        n->value = value;
        n->next = n->prev = nullptr;
        m_head = m_tail = n;
        return true;
    }
    if (m_head->value > value){
        Node* n = new Node;
        n->value = value;
        n->prev = nullptr;
        n->next = m_head;
        m_head->prev = n;
        m_head = n;
        return true;
    }
    Node* p = m_head;
    while (p != nullptr){
        if (p->value == value){
            m_size--;
            return false;
        }
        if (p->next != nullptr && p->next->value > value){
            Node* n = new Node;
            n->value = value;
            n->next = p->next;
            n->prev = p;
            p->next = n;
            n->next->prev = n;
            return true;
        }
        p = p->next;
    }
    Node* n = new Node;
    n->value = value;
    n->next = nullptr;
    m_tail->next = n;
    n->prev = m_tail;
    m_tail = n;
    return true;
}

const Node *SortedLinkedList::search(const int &value) const{
    Node *p = m_head;
    while (p != nullptr){
        if (p->value == value)
            return p;
        p = p->next;
    }
    return nullptr; //if p not found or if list is empty
}

void SortedLinkedList::remove(Node *node){
    if (node == nullptr)
        return;
    else if (node == m_head){
        if (m_head == m_tail)
            m_head = m_tail = nullptr;
        else{ //more than one element in list
            m_head = node->next;
            m_head->prev = nullptr;
        }
    }
    else if (node == m_tail){
        m_tail = node->prev;
        m_tail->next = nullptr;
    }
    else{
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    delete node;
    m_size--;
}

void SortedLinkedList::printIncreasingOrder() const{
    Node* p = m_head;
    while (p != nullptr){
        std::cout << p->value << std::endl;
        p = p->next;
    }
}

#endif /* sdll_h */
