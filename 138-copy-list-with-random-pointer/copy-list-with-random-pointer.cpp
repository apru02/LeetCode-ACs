/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,int> mp1;
        Node* temp = head;
        int n = 0;
        while(temp != NULL){
            mp1[temp] = n;
            n++;
            temp = temp->next;
        }
        if(n == 0){
            Node* ans = NULL;
            return ans;
        }
        map<int,Node*> mp2;
        Node* AnsHead = new Node(head->val);
        Node* temp2 = AnsHead;
        temp = head->next;
        int i = 0;
        mp2[i] = temp2;
        i++;
        while(temp !=NULL){
            Node* newNode = new Node(temp->val);
            temp2->next = newNode;
            temp2 = temp2->next;
            temp = temp->next;
            mp2[i] = temp2;
            i++;
        }
        int j = 0;
        temp2 = AnsHead;
        temp = head;
        while(temp !=NULL){
            Node* RandOriginal = temp->random;
            if(RandOriginal == NULL){
                 temp2->random = NULL;
                 temp = temp->next;
                 temp2 = temp2->next;
                 continue;
            }
            int RandInd = mp1[RandOriginal];
            Node* randPointer = mp2[RandInd];
            temp2->random = randPointer;
            temp = temp->next;
            temp2 = temp2->next;
        }
        return AnsHead;
        
    }
};