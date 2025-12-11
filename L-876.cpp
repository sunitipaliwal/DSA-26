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
     int getCount(struct ListNode* head) {

        // Code here
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
    }
    ListNode* middleNode(ListNode* head) {
        int count =getCount(head);
        ListNode* temp=head;
     for(int i=0;i<count/2;i++){
            temp=temp->next;
        }
         return temp;
    }
};