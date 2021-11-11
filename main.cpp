#include <iostream>

using namespace std;

#include "LinkedList.h"

class IntObj : public Object {
    int data;
public:
    IntObj(int x = 0) {
        data = x;
    }

    void SetData(int x) {
        data = x;
    }

    bool IsEqual(Object &object) override {
        IntObj &temp = (IntObj &) object;
        return data == temp.data;
    }

    void Show() override {
        cout << "Data=" << data << '\t';
    }
};

int main() {
    IntObj *p;
    Node *pn;
    List list;
    for (int i = 0; i < 5; ++i) {
        p = new IntObj(100 + i);
        pn = new Node;
        pn->FillInfo(p);
        list.AddNode(pn);
    }
    list.ShowList();
    IntObj da;
    da.SetData(102);
    pn = list.LookUp(da);
    if (pn) {
        list.DeleteNode(pn);
    }
    list.ShowList();
    if (pn) {
        list.AddNode(pn);
    }
    list.ShowList();
    return 0;
}
