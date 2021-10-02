/**
* PROBLEM STATEMENT :

* Given a linked list, reverse the nodes of a linked list k at a time
* and return its modified list.

* k is a positive integer and is less than or equal to the length of the
* linked list. If the number of nodes is not a multiple of k then
* left-out nodes, in the end, should remain as it is.
*/

// The stucture of the linked-list that we will be using in this problem is as follows:

struct Node {
    int data;
    Node *next;
    Node(): data(0),next(nullptr) {}
    Node(int val): data(val), next(nullptr) {}
    Node(int val, Node *next): data(val), next(next) {}
};

// Code snippet to reverse a Linked List
Node* reverseLinkedList(Node* root,int k) {
    Node *new_root = NULL,
        *temp = root;

    while(k--) {
        Node *next_node = temp->next;
        temp->next = new_root;
        new_root = temp;
        temp = next_node;
    }
    return new_root;
}

/***** RECURSIVE APPROACH *****/

Node* reverse_linked_list_in_k_groups(Node* root, int k) {
    int count = 0;
    Node *temp = root;

    while(count < k && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if(count == k) {
        Node *reversed_root = reverseLinkedList(root, k);
        root->next = reverseKGroup(temp, k);
        return reversed_root;
    }
    return root;
}
// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(N/k)




/***** ITERATIVE APPROACH *****/

Node* reverse_linked_list_in_k_groups(Node* root, int k) {
    Node *temp = root,
        *k_tail = NULL,
        *new_root = NULL;

    while(temp != NULL) {
        int count = 0;
        temp = root;

        while(count < k && temp != NULL) {
            temp = temp->next;
            count++;
        }

        if(count == k) {
            ListNode *reversed_root = reverseLinkedList(root, k);

            if(new_root == NULL)
                new_root = reversed_root;

            if(k_tail)
                k_tail->next = reversed_root;

            k_tail = root;
            root = temp;
        }
    }
    if(k_tail)
        k_tail->next = root;
    return (new_root == NULL)?root:new_root;
}
// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(1)