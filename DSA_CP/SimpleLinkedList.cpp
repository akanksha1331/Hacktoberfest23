// Simple LinkedList implementation with member functions to insert in the beginning and to insert at the end of the list.
// Should have atleast one node for insertFirst and insertLast to work
// Time complexity for insert first => O(1)
// Time complexity to insert at the end => O(n)


#include <iostream>
using namespace std;

struct ListNode{
    int data;
    struct ListNode *next;
    ListNode (int val){
        data = val;
        next = NULL;
    }
    
};

void displayList(struct ListNode* v){
    
    while(v != NULL){
        cout<<v->data;
        v = v->next;
        if (v != NULL) cout<<"->";
    }
    cout<<"\n";
}

void insertFirst(struct ListNode* &v,int d){
    struct ListNode* temp = new ListNode(d);
    temp->next = v;
    v = temp;
    
}

void insertLast(struct ListNode* &v,int d){
    struct ListNode* temp = new ListNode(d);
    struct ListNode* p = v;
    struct ListNode* c = v;
    while (p != NULL){
        c = p;
        p = p->next;
        
    }
     
    c->next = temp;
    
}

int main() {
    // create a sample ll like below
    struct ListNode* f = new ListNode(11);
    f->next = new ListNode(17);
    f->next->next = new ListNode(18);
    
    // To display the list
    displayList(f);
    
    // To insert in the beginning. 
    insertFirst(f,99);
    insertFirst(f,1001);
    displayList(f);
    
    // To insert at the end
    insertLast(f,777);
    insertLast(f,7344);
    displayList(f);
    
    
    return 0;
}
