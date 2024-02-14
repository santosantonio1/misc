// https://leetcode.com/problems/add-two-numbers/description/
// @santosantonio1
// 12 ms runtime...
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(), *itr = res, *itr1 = l1, *itr2 = l2;
        int sum = 0, carry = 0;
        while(1){
            sum = itr1->val + itr2->val + carry;
            itr->val = sum % 10;
            carry = sum / 10;
            if(!itr1->next && !itr2->next) break;
            itr->next = new ListNode();
            if(!itr1->next) itr1= new ListNode();
            else itr1 = itr1->next;
            if(!itr2->next) itr2 = new ListNode();
            else itr2 = itr2->next;
            itr = itr->next;
        }
        if(carry) itr->next = new ListNode(carry);
        return res;
    }
};