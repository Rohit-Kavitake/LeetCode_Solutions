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
        if(head == NULL || head -> next == NULL)
            return NULL;

        ListNode* temp = head;
        int len = 0;
        while(temp != NULL){
            len++;
            temp = temp -> next;
        }
        // if(len == n)
        //     return temp-> next;
        len = (len - n);
        temp = head;
        if(len == 0)
            return temp-> next;
        ListNode* curr = NULL;
        ListNode* prev = NULL;
        while(len-1 > 0 && temp != NULL){
            cout << temp -> val;
            temp = temp -> next;
            len--;
        }
        prev = temp;
        curr = temp -> next;
        ListNode* endNode = curr -> next;
        prev -> next = endNode;
        return head;
    }
};