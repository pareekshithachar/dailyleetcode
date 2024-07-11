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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int prev = head->val;
        int prevmin = -1;
        int first = -1;
        head = head->next;
        int count = 1;
        int minans = INT_MAX;
        while(head && head->next){
            int iscrit = (head->val < prev && head->val < head->next->val) || (head->val > prev && head->val > head->next->val);
            if(iscrit){
                if(first == -1){
                    first = count;
                }else{
                    minans = min(count-prevmin,minans);
                }
                prevmin = count;
            }
            count++;
            prev = head->val;
            head = head->next;
        }

        if(minans == INT_MAX){
            return {-1,-1};
        }
        return {minans,prevmin-first};
    }
};