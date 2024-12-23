struct ListNode {
    int val;
    ListNode *next;
    ListNode()
        : val(0), next(nullptr) {
    }
    ListNode(int x)
        : val(x), next(nullptr) {
    }
    ListNode(int x, ListNode *next)
        : val(x), next(next) {
    }
};

class Solution {
  public:
    ListNode *reverseAll(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *next = head->next;
        ListNode *new_head = reverseAll(next);
        next->next = head;
        head->next = nullptr;
        return new_head;
    }

    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if (left == right) {
            return head;
        }
        int i = 1;
        struct ListNode *prev = nullptr;
        struct ListNode *rear = nullptr;
        struct ListNode *leftp = nullptr;
        struct ListNode *rightp = nullptr;
        for (struct ListNode *p = head; p != nullptr; p = p->next) {
            if (i == left - 1) {
                prev = p;
            }
            if (i == left) {
                leftp = p;
            }
            if (i == right) {
                rightp = p;
                rear = p->next;
            }
            i++;
        }

        if (prev != nullptr) {
            prev->next = nullptr;
        }
        rightp->next = nullptr;

        ListNode *new_left = reverseAll(leftp);
        ListNode *new_right = leftp;

        new_right->next = rear;
        if (prev != nullptr) {
            prev->next = new_left;
            return head;
        }
        return new_left;
    }
};