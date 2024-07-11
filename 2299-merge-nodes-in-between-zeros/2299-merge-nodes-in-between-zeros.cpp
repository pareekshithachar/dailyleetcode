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
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        ListNode* ans = head;
        ListNode* finalhead = head;
        head = head->next;
        while(head){
            if(head->val == 0){
                ans->val = sum;
                sum = 0;
                if(head->next)ans = ans->next;
            }
            sum+= head->val;
            head = head->next;
        }
        ans->next = NULL;
        return finalhead;
    }
};