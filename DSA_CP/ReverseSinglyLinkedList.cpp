#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

// ? Iterative Approach
// Time: O(n)
// Space: O(1)
Node *Reverse(Node *head)
{
    Node *p, *q, *prev = nullptr;

    p = head;
    while (p != nullptr)
    {
        // Note the cyclic nature of variables
        q = p->next;    // Store next node
        p->next = prev; // Reverse link

        prev = p; // Update prev
        p = q;    // Update p
    }

    head = prev; // Update start to point to last node

    return head;
}

// ? Recursive Approach
// Feels more intuitive
// Time: O(n)
// Space: O(n) (recursion stack)
Node *ReverseRecursive(Node *head)
{
    // 0 or 1 node (Base Case)
    if (head == nullptr || head->next == nullptr)
        return head;

    // Reverse rest of the list
    Node *rest = ReverseRecursive(head->next); // rest is the head of the reversed list
    (head->next)->next = head;

    head->next = nullptr;

    return rest;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    head = ReverseRecursive(head);

    while (head != nullptr)
    {
        cout << head->data << " "; // 30 20 10
        head = head->next;
    }

    return 0;
}
