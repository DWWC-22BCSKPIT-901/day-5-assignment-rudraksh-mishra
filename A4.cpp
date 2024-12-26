#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data) , next(nullptr) {}
};

Node* mergeTwoLists(Node* l1, Node* l2) {
    Node dummy(0);
    Node* tail = &dummy;
    
    // Compare elements from both lists and link the smaller one
    while (l1 && l2) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    // Attach remaining elements from either list
    tail->next = l1 ? l1 : l2;
    
    return dummy.next;
}

Node* Merge(vector<Node*>& lists) {
    if (lists.empty()) return nullptr;
    
    int k = lists.size();
    int interval = 1;
    
    while (interval < k) {
        for (int i = 0; i < k - interval; i += interval * 2) {
            lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
        }
        interval *= 2;
    }
    
    return lists[0];
}

int main() {
    Node L11(1), L12(4), L13(5);
    Node L21(1), L22(3), L23(4);
    Node L31(2), L32(6);
    
    L11.next = &L12;
    L12.next = &L13;
    L21.next = &L22;
    L22.next = &L23;
    L31.next = &L32;
    
    vector<Node*> L = {&L11, &L21, &L31};
    
    cout << "Lists : \n";
    for (auto* List : L) {
        while (List != nullptr) {
            cout << "[" << List->data << "] -> ";
            List = List->next;
        }
        cout << "NULL" << endl;
    }

    Node* M = Merge(L);
    
    cout << "\nMerged List : \n"; 
    while (M != nullptr) {
        cout << "[" << M->data << "] -> ";
        M = M->next;
    }
    cout << "NULL" << endl;
    
    return 0;
}