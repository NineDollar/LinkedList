#include <iostream>

using namespace std;

#include "LinkedList.h"
#include "String.h"

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

class StringObj : public Object {
    String string1;
public:

    StringObj() {}

    StringObj(const char *str) {
        string1.SetString(str);
    }

    bool IsEqual(Object &object) override {
        StringObj &stringObj = (StringObj &) object;
        return string1 == stringObj.string1;
    }

    void Show() override {
        string1.show();
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

    StringObj *stringObj;
    Node *node;
    List list1;
    char array[4][20] = {{"This is One."},
                         {"This is two."},
                         {"This is four."},
                         {"This is five."}};
    for (int i = 0; i < 4; ++i) {
        stringObj = new StringObj(array[i]);
        node = new Node;
        node->FillInfo(stringObj);
        list1.AddNode(node);
    }
    list1.ShowList();
    StringObj stringObj1("This is One.");
    node = list1.LookUp(stringObj1);
    if (node) {
        cout << "stringObj1 in list1 Yes!" << endl;
    } else{
        cout << "stringObj1 in list1 No!" << endl;
    }
    return 0;
}
