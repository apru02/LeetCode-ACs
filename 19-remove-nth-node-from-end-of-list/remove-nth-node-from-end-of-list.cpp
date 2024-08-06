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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total = 0;
        ListNode* temp = head;
        while(temp!= nullptr){
            total++;
            temp= temp->next;
        }
        int node = total - n;
        if(node == 0){
           head = head->next;
           return head;
        }
        temp = head;
        ListNode* prev = head;

        while(node!=0){
            node--;
            prev = temp;
            temp =temp->next;
        }
        prev->next = temp->next;
        temp->next = nullptr;
        return head;

    }
};