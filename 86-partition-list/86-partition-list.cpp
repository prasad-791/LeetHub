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
    ListNode* partition(ListNode* head, int x) {
        ListNode* replace = head;
        while(replace!=NULL && replace->val<x){
            replace = replace->next;
        }
        ListNode* p = replace;
        while(p!=NULL){
            while(p!=NULL && p->val >= x){
                p = p->next;
            }
            if(p!=NULL){
                ListNode* q = replace;
                int val = p->val;
                while(q!=p){
                    int x = q->val;
                    q->val = val;
                    val = x;
                    q = q->next;
                }
                q->val = val;
                replace = replace->next;
            }
        }
        return head;
    }
};