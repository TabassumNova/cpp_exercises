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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* temp = nullptr;

        while (current != nullptr) {
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        } 
        return prev;
    }
};

int main() {
    Solution s;

    ListNode head(1);
    ListNode next2(2);
    ListNode next3(3);
    ListNode next4(4);
    ListNode next5(5);
    head.next = &next2;
    next2.next = &next3;
    next3.next = &next4;
    next4.next = &next5;

    ListNode* result = s.reverseList(&head);
    // return 0 ;
} 