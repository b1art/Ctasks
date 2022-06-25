#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *value;
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
			printf("%s\n", n->value);
			n = n->next;
		}
	}
}

void add() {
    char* value = (char*)malloc(sizeof(char)*255);
    puts("Enter the element: ");
    scanf("%s", value);

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
    if (head->next == NULL) {
        free(curr);
        head = NULL;
        return;
    }

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
    char value[255];
    puts("Enter the element: ");
    scanf("%s", value);
    if (head ==  NULL){
        puts("List is empty \n");
        return;
    }
    node *a;
    a = head;
    int i = 1;
    while (strcmp(a->value, value) != 0) {
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
