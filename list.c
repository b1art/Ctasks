#include <stdio.h>

typedef struct node {
    int *value;
    struct node *next;
} node;

node *head = NULL;

void display() {

	node *n;
	n = head;
	if (n == NULL) {
		puts("List is empty. \n");
		return;
	}
	else {
		puts("Elements are: ");
		while (n != NULL) {
			printf("%d\n", n->value);
			n = n->next;
		}
	}
}

void add() {
    puts("Enter the element: ");
    int value;
    if (scanf("%d", &value) == 0) {
        puts("Wrong input.");
        return 0;
    }
    node *a, *b;
    a = (node*)malloc(sizeof(node));
    a->value = value;
    a->next = NULL;

    if (head == NULL) {
        head = a;
    }
    else {
        b = head;
        while (b->next != NULL) {
            b = b->next;
        }
        b->next = a;
    }
    return;
}

void delete() {
    if (head == NULL) {
        puts("List is empty.");
        return;
    }
    else if (head->next == NULL) {
        printf("%d is deleted", head->value);
        free(head);
        head = NULL;
        return;
    }
    else {
        node *a, *b = NULL;
        a = head;
        while (a->next != NULL) {
            b = a;
            a = a->next;
        }
        b->next = NULL;
        free(a);
    }
    return;
}


void deleteList() {
    if (head == NULL) {
        puts("List is empty.");
        return;
    }
    node *curr = head;
    node *next;
    while (curr->next->next != NULL) {
		next = curr->next;
		free(curr);
		curr = next;
	}
	free(curr->next);
	head = NULL;
	return;
}

void find() {
    puts("Enter the element: ");
    int value;
    if (scanf("%d", &value) == 0) {
        puts("Wrong input.");
        return 0;
    }
    if (head ==  NULL){
        puts("List is empty \n");
        return;
    }
    node *a;
    a = head;
    int i = 1;
    while (a->value != value) {
        if (a->next == NULL) {
            puts("There is no such element. \n");
            return;
        }
        i++;
        a = a->next;
    }
    printf("This is the element on position %d  \n", i);
}

void create() {
    add();
    return;
}


int main() {
	int input;
	while (1) {
		puts("1 - create linked list\n2 - add element in the end of the list\n3 - delete the last element of the list\n4 - print the list\n5 - delete the list\n6 - find the position of element\n7 - exit\n");
		if (scanf("%d", &input) == 0) {
            puts("wrong input.");
            return 0;
		};
		switch (input) {
		case 1:
			create();
			puts("____");
			continue;
		case 2:
			add();
			puts("____");
			continue;
		case 3:
			delete();
			puts("____");
			continue;
		case 4:
			display();
			puts("____");
			continue;
		case 5:
			deleteList();
			puts("____");
			continue;
		case 6:
			find();
			puts("____");
			continue;
		case 7:
			return;
		}
	}
	return 0;
}
