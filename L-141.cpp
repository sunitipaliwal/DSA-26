// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         unordered_map<ListNode*, int> mpp;
//         ListNode* temp=head;
//         while(temp!=NULL){
//             if(mpp.find(temp)!=mpp.end()){
//                 return true;
//             }
//             mpp[temp]=1;
//             temp=temp->next;
//         }
//         return false;
//     }
// };
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;          // move 1 step
            fast = fast->next->next;    // move 2 steps

            if (slow == fast) {         // cycle detected
                return true;
            }
        }
        return false; // reached null → no cycle
    }
};
