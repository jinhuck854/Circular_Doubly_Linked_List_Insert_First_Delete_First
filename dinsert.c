#include <stdio.h> // circular + doubly ��ũ ����Ʈ
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* llink;	// ListNode�� ����
	struct ListNode* rlink;	// ListNode�� ������
}ListNode;

void init(ListNode* head) { // ��� ��� : Head ������ ��� X
	head->llink = head; // �ڱ� �ڽ��� ����Ű���� �ʱ�ȭ
	head->rlink = head;
}

void dinsert(ListNode* before, element value) {	// ù ��° ��ġ�� ��� ���� = Insert First
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;

	// Doubly Linked List : p�� llink�� ���� ���� ����, p�� rlink�� ���� ����� ���� ���� ����
	p->llink = before;
	p->rlink = before->rlink;

	// Circular Linked List : �Ǿ� ����� llink�� ������ ���� ���� + �ǵ� ����� rlink�� ù��° ���� ����
	before->rlink->llink = p;
	before->rlink = p;
}

void ddelete(ListNode* head, ListNode* removed) { // ù ��° ��ġ ��� ���� = Delete First
	if (head == NULL) return NULL;
	removed->llink->rlink = removed->rlink;
	// removed->rlink->llink = removed->llink;
	removed->rlink->llink = head;
	free(removed);
}

void print_dlist(ListNode* head) { // ��� �Լ�
	printf("Head ");
	for (ListNode* p = head->rlink; p != head; p = p->rlink) { // head->link ���� ~ head����
		printf("<- || %d || -> ", p->data);
	}
	printf("Head\n");
}

void start() {
	ListNode* head = (ListNode*)malloc(sizeof(ListNode)); // ListNode ���� �Ҵ�
	init(head); // �ʱ�ȭ
	printf("Circular + Doubly Linked List !\n");

	printf("\n������ �߰�\n");
	for (int i = 0; i < 5; i++) {
		dinsert(head, i); print_dlist(head);
	}

	printf("\n������ ����\n");
	for (int i = 0; i < 5; i++) {
		print_dlist(head);
		ddelete(head, head->rlink);
	}

	free(head);
}

int main(void) {
	start();
	return 0;
}