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
        vector<int> arr;
        ListNode* prev = head;
        ListNode* temp = head->next;
        int node = 2;
        while (temp->next != nullptr) {
            if ((temp->val < prev->val && temp->val < temp->next->val) ||
                (temp->val > prev->val && temp->val > temp->next->val)) {
                arr.push_back(node);
            }
            prev = temp;
            temp = temp->next;
            node++;
        }
        if (arr.size() < 2)
            return {-1, -1};
        int maxi = arr[arr.size() - 1] - arr[0];
        int mini = INT_MAX;
        for (int i = 1; i < arr.size(); i++) {
            mini = min(mini, arr[i] - arr[i - 1]);
        }
        return {mini, maxi};
    }
};