#include"Formular.h"

void Formular::clear() {
    ListNode* temp = head;

    while (temp != NULL) {
        ListNode* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    head = NULL;
    prev = NULL;
    cur = NULL;
}