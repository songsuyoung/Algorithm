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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *newNode=NULL;
        ListNode *tmpNode=NULL;
        ListNode *pre=head;
        for(ListNode *tmp=head;tmp!=NULL;tmp=tmp->next){
            if(val==tmp->val){
                pre->next=tmp->next;
            }else{
                if(tmp==head||newNode==NULL){
                    newNode=new ListNode(tmp->val,tmp);
                    newNode->next=NULL;
                    tmpNode=newNode;
                }else{
                    ListNode *node=new ListNode(tmp->val,tmp);
                    tmpNode->next=node;
                    node->next=NULL;
                    tmpNode=node;
                }
            }
            pre=tmp;
        }

        return newNode;
    }
};