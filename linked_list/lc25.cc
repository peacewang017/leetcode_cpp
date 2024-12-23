#include "../type/linked_list.h"

class Solution {
  public:
    ListNode* reverseAll(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* next = head->next;
        ListNode* new_head = reverseAll(next);
        next->next = head;
        head->next = nullptr;
        return new_head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* vHead = new ListNode(0, head);
        ListNode* l = vHead;
        ListNode* r = vHead;

        while (1) {
            for (int cnt = 1; cnt < k; cnt++) {
                if (!r) {
                    return vHead->next;
                }
                r = r->next;
            }
            if (!r || !r->next) {
                return vHead->next;
            }

            ListNode* newNext = r->next->next;
            ListNode* start = l->next;
            ListNode* end = r->next;
            end->next = nullptr;
            reverseAll(start);
            l->next = end;
            start->next = newNext;
            l = start;
            r = l;
        }
    }
};