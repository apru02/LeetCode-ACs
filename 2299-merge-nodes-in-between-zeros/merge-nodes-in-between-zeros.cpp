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
        ListNode* ans = new ListNode(0);
        ListNode* current = ans;
        ListNode* next;
        int sum = 0;
        ListNode* temp = head->next;
        while(temp != nullptr){
            if(temp->val == 0){
                current->val = sum;
                sum = 0;
                next = new ListNode(sum);
                if(temp->next != nullptr) current->next = next;
                current = next;
            }
            else{
                sum += temp->val;
            }
            temp = temp->next;
        }
        return ans;
    }
};