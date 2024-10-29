#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<int> middleNode(ListNode* head) {
    vector<int> result;
    if (head == nullptr) {
        return result;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    while (slow != nullptr) {
        result.push_back(slow->val);
        slow = slow->next;
    }
    return result;
}

int main() {
    int n, val;
    
    cout << "Masukkan jumlah node: ";
    cin >> n;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    cout << "Masukkan nilai node:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    vector<int> result = middleNode(head);

    cout << "Output: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}