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
    void reorderList(ListNode* head) {
        
        ListNode * tmp = head;
        vector<int> number;

        while(tmp)
        {
            number.push_back(tmp->val);
            tmp = tmp->next;
        }

        int left=0;
        int right = number.size()-1;
        vector<int> output(number.size(),0);

        int index=0;
        while(left<right)
        {
            output[index++] = number[left++];
            output[index++] = number[right--];
        }
        output[number.size()-1] = number[left];
        tmp=head;
        index=0;
        while(tmp)
        {
            tmp->val=output[index++];
            tmp=tmp->next;
        }
    }
};