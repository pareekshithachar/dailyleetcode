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
        ListNode* ans = NULL;
        ListNode* tail = NULL;
        head = head->next;
        while(head){
            if(head->val == 0){
                if(ans == NULL){
                    ans = new ListNode(sum);
                    tail = ans;
                }else{
                    ListNode* cur = new ListNode(sum);
                    tail->next = cur;
                    tail  = cur;
                }
                sum = 0;
            }
            sum+= head->val;
            head = head->next;
        }
        return ans;
    }
};