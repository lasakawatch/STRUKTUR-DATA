#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}
void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == nullptr) {
        *head = newNode;return;
    }
    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;}
    temp->next = newNode;
    newNode->prev = temp;
}
int findMax(Node* head) {
    if (head == nullptr) return -1;
    int maxVal = head->data;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data > maxVal)
        maxVal = temp->data;
        temp = temp->next;}
    return maxVal;
}
void printList(Node* head) {
    Node* temp = head;
    int count = 1;
    while (temp != nullptr) {
        cout << "node " << count << " : " << temp->data << endl;
        temp = temp->next;
        count++;
    }
}
int main() {
    Node* head = nullptr;
    int n, value;
    cout << "Masukkan jumlah node: ";
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cout << "Input data untuk node " << i << ": ";
        cin >> value; insertEnd(&head, value);
    }
    cout << "Data yang dimasukkan ke dalam daftar adalah :" << endl;
    printList(head);
    cout << "Nilai Maksimum dalam Linked List: " << findMax(head) << endl;
    return 0;
}