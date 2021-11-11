//
// Created by NewUser on 2021/11/11.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <iostream>

class Object {
public:
    Object() {};

    virtual bool IsEqual(Object &object) = 0;

    virtual void Show() = 0;

    virtual ~Object() {};
};

class Node {
    Object *Info;
    Node *Prev, *Next;
public:
    Node() {
        Info = nullptr;
        Prev = nullptr;
        Next = nullptr;
    }

    void FillInfo(Object *object) {
        Info = object;
    }

    friend class List;
};

class List {
    Node *Head, *Tail;
public:
    List() {
        Head = Tail = nullptr;
    }

    ~List() {
        DeleteList();
    }

    void AddNode(Node *node);

    void DeleteNode(Node *node);

    Node *LookUp(Object &object);

    void ShowList();

    void DeleteList();
};

void List::AddNode(Node *node) {
    if (Head == nullptr) {
        Head = Tail = node;
        node->Next = node->Prev = nullptr;
    } else {
        Tail->Next = node;
        node->Prev = Tail;
        node->Next = nullptr;
        Tail = node;
    }
}

void List::DeleteNode(Node *node) {
    if (node == Head) {
        if (node == Tail) {
            Head = Tail = nullptr;
        } else {
            Head = node->Next;
            Head->Prev = nullptr;
        }
    } else {
        node->Prev->Next = node->Next;
        if (node == Tail) {
            Tail = node->Prev;
        } else {
            node->Next->Prev = node->Prev;
        }
    }
}

Node *List::LookUp(Object &object) {
    Node *p = Head;
    while (p) {
        if (p->Info->IsEqual(object)) {
            return p;
        }
        p = p->Next;
    }
    return nullptr;
}

void List::ShowList() {
    Node *p;
    p = Head;
    while (p) {
        p->Info->Show();
        p = p->Next;
    }
    cout << endl;
}

void List::DeleteList() {
    Node *p;
    while (Head) {
        p = Head;
        Head = Head->Next;
        delete p->Info;
        delete p;
    }
    Tail = nullptr;
}


#endif //LINKEDLIST_LINKEDLIST_H
