#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            int cycleLength = 1;
            ListNode *ptr1 = slow->next;
            while (ptr1 != slow) {
                ptr1 = ptr1->next;
                cycleLength++;
            }

            ListNode *ptr2 = head;
            for (int i = 0; i < cycleLength; i++) {
                ptr2 = ptr2->next;
            }

            while (ptr2 != head) {
                ptr2 = ptr2->next;
                head = head->next;
            }

            return head;
        }
    }

    return nullptr;
}

int main() {
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    ListNode *cycleStart = detectCycle(head);

    if (cycleStart) {
        std::cout << "Cycle starts at node with value: " << cycleStart->val << std::endl;
    } else {
        std::cout << "No cycle detected." << std::endl;
    }

    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}