/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 ListNode* newHead = NULL;
class Solution {
public:
    ListNode* reverseKero(ListNode* head){
        if(!head->next){
            newHead = head;
            return head;
        }
        ListNode* gotIt = reverseKero(head->next);
        gotIt->next = head;
        head->next = NULL;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        reverseKero(head);
        return newHead;
    }
};