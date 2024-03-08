#include <cmath>
//   Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int length = getCount(head);
        ListNode* temp = head;
        int sum = 0;
        for (int i=length-1; i>=0; i--) {
            sum += temp->val * pow(2, i);
            temp = temp->next;
        }
        return sum;
    }
    int getCount(ListNode* head)
    {
        int count = 0; // Initialize count
        ListNode* current = head; // Initialize current
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};

int main() {
    Solution s;

    ListNode head(1);
    ListNode next(0);
    ListNode next_next(1);
    head.next = &next;
    next.next = &next_next;

    int result = s.getDecimalValue(&head);
    // return 0 ;
} 