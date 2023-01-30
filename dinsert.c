#include <stdio.h> // circular + doubly 링크 리스트
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* llink;	// ListNode의 왼쪽
	struct ListNode* rlink;	// ListNode의 오른쪽
}ListNode;

void init(ListNode* head) { // 헤드 노드 : Head 포인터 사용 X
	head->llink = head; // 자기 자신을 가르키도록 초기화
	head->rlink = head;
}

void dinsert(ListNode* before, element value) {	// 첫 번째 위치에 노드 삽입 = Insert First
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;

	// Doubly Linked List : p의 llink는 이전 노드와 연결, p의 rlink는 이전 노드의 다음 노드와 연결
	p->llink = before;
	p->rlink = before->rlink;

	// Circular Linked List : 맨앞 노드의 llink는 마지막 노드와 연결 + 맨뒤 노드의 rlink는 첫번째 노드와 연결
	before->rlink->llink = p;
	before->rlink = p;
}

void ddelete(ListNode* head, ListNode* removed) { // 첫 번째 위치 노드 삭제 = Delete First
	if (head == NULL) return NULL;
	removed->llink->rlink = removed->rlink;
	// removed->rlink->llink = removed->llink;
	removed->rlink->llink = head;
	free(removed);
}

void print_dlist(ListNode* head) { // 출력 함수
	printf("Head ");
	for (ListNode* p = head->rlink; p != head; p = p->rlink) { // head->link 시작 ~ head까지
		printf("<- || %d || -> ", p->data);
	}
	printf("Head\n");
}

void start() {
	ListNode* head = (ListNode*)malloc(sizeof(ListNode)); // ListNode 동적 할당
	init(head); // 초기화
	printf("Circular + Doubly Linked List !\n");

	printf("\n데이터 추가\n");
	for (int i = 0; i < 5; i++) {
		dinsert(head, i); print_dlist(head);
	}

	printf("\n데이터 삭제\n");
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