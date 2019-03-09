
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int accno;
	char name[80];
	int balance;
	struct node *next;
} node;
void accept(node **p, int n) {
	int i = 1;
	int accno;
	node *temp = *p;
	while (n != 0) {
		node *newnode = (node *) malloc(sizeof(node));
		newnode->next = NULL;
		printf("Enter data for record %d", i++);
		printf("Enter account no");
		scanf("%d", &accno);
		newnode->accno = accno;
		printf("Enter name");
		scanf("%s", newnode->name);
		newnode->balance = 0;
		if (*p == NULL) {
			*p = newnode;
		} else {
			temp->next = newnode;
		}	temp = newnode;

		n--;
	}
}
	void deposit(node **p, int n, int accno, int amount) {
		node *temp = *p;
		while (temp != NULL) {
			if (temp->accno == accno) {
				temp->balance += amount;
				break;
			} else {
				temp = temp->next;
			}
		}
	}
	void withdraw(node **p, int n, int accno, int amount) {
		node *temp = *p;
		while (temp != NULL) {
			if (temp->accno == accno) {
				temp->balance -= amount;
				break;
			} else {
				temp = temp->next;
			}
		}
	}
	int search(node *p, int n, int accno) {
		int i;
		node *temp = p;
		while (temp != NULL) {
			if (temp->accno == accno) {
				i = 1;
				break;
			} else {
				i = 0;
				temp = temp->next;
			}
		}
		return i;
	}
	void display(node *p, int n) {
		node *temp = p;
		while (temp != NULL) {
			printf("\n NAME=%s", temp->name);
			printf("\n ACCNO=%d", temp->accno);
			printf("\n BALANCE=%d", temp->balance);
			temp = temp->next;
			printf("\n\n");

		}
	}

	int main(void) {
		node *root = NULL;
		int n;
		int accno, amount, choice;
		printf(" \n     BANKING SYSTEM    ");
		printf("\nNUMBER OF CUSTOMER RECORDS YOU WANT TO ENTER ?");
		scanf("%d", &n);
		accept(&root, n);
		do {
			printf("\n BANKING SYSTEM MENU\n");
			printf("\n PRESS 1 TO DISPLAY ALL RECORDS\n ");
			printf("\n PRESS 2 TO SEARCH A RECORD\n");
			printf("\n PRESS 3 TO DEPOSIT AMOUNT\n");
			printf("\n PRESS 4 TO WITHDRAW AMOUNT\n");
			printf("\n 0 TO EXIT");
			scanf("%d", &choice);
			switch (choice) {
			case 1:
				display(root, n);
				break;
			case 2:
				printf("\nENTER ACCOUNT NO TO SEARCH:");
				scanf("%d", &accno);
				int i = search(root, n, accno);
				if (i == 1)
					printf("\n RECORD  FOUND");
				else {
					printf("\n RECORD NOT FOUND");
				}
				break;
			case 3:
				printf("\n ENTER ACCOUNT NO:");
				scanf("%d", &accno);
				printf("\n ENTER AMOUNT TO DEPOSIT");
				scanf("%d", &amount);
				deposit(&root, n, accno, amount);
				break;
			case 4:
				printf("\n ENTER ACCOUNT NO:");
				scanf("%d", &accno);
				printf("\n ENTER AMOUNT TO WITHDRAW");
				scanf("%d", &amount);
				withdraw(&root, n, accno, amount);
			}
		} while (choice != 0);

		return 0;
	}



