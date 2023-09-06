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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int n = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            n++;
            temp = temp->next;
        }
        int size = n/k;
        int greater = n - size*k;
        temp = head;
        int c = greater*(size+1);
        while(temp != NULL){
            ListNode* newNode = temp;
            ListNode* prev = newNode;
            if(c > 0){
                for(int i = 0;i<size + 1;i++){
                    prev = temp;
                    temp = temp->next;
                    c--;
                }
                prev->next = NULL;
                ans.push_back(newNode);
            }
            else{     
                for(int i = 0;i<size ;i++){
                    prev = temp;
                    temp = temp->next;
                }
                prev->next = NULL;
                ans.push_back(newNode);
            }
        }
        if(k > n){
            for(int j = 0;j< k -n ;j++){
                ListNode* node = NULL;
                ans.push_back(node);
            }
        }
        return ans;

    }
};