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
        return result; // Kembalikan vektor kosong jika linked list kosong
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // slow sekarang menunjuk ke node tengah (atau node tengah kedua jika jumlah node genap)
    while (slow != nullptr) {
        result.push_back(slow->val);
        slow = slow->next;
    }
    return result;
}


int main() {
    // Contoh 1
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    vector<int> result1 = middleNode(head1);
    cout << "Contoh 1: ";
    for (int val : result1) {
        cout << val << " ";
    }
    cout << endl;


    // Contoh 2
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    head2->next->next->next->next->next = new ListNode(6);

    vector<int> result2 = middleNode(head2);
    cout << "Contoh 2: ";
    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}