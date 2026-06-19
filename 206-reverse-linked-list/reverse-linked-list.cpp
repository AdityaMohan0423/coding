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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
      ListNode* prev = NULL;
      ListNode* curr = head;
      ListNode* nexti = head->next;

        while(nexti){
            curr->next = prev;
            prev = curr;
            curr = nexti;
            nexti = nexti->next;
        }
        curr->next = prev;

        return curr;
    }
};