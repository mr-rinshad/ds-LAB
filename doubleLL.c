#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insertfront(int x);
void insertend(int x);
void deleteNode(int key);
void display();
void search(int key);

int main() {
    int ch, x, key;

    while (1) {
        printf("\n---- MENU ----\n");
        printf("1. Insert front\n");
        printf("2. Insert end\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Search\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &x);
            insertfront(x);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &x);
            insertend(x);
            break;
        case 3:
            printf("Enter node to delete: ");
            scanf("%d", &key);
            deleteNode(key);
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Enter node to search: ");
            scanf("%d", &key);
            search(key);
            break;
        case 6:
            printf("Program exited.\n");
            return 0;
        default:
            printf("Enter a valid choice.\n");
        }
    }
}


void display() {
    struct node *ptr = head;
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        printf("Elements are: ");
        while (ptr != NULL) {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}


void insertfront(int x) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL) {
        head->prev = newnode;
    }
    head = newnode;
    display();
}


void insertend(int x) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
    } else {
        struct node *ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->prev = ptr;
    }
    display();
}


void deleteNode(int key) {
    struct node *ptr = head;

    if (head == NULL) {
        printf("Deletion not possible, list is empty.\n");
        return;
    }

    
    if (head->data == key) {
        struct node *temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        display();
        return;
    }

   
    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Data not found.\n");
        return;
    }

    if (ptr->next != NULL) {
        ptr->next->prev = ptr->prev;
    }
    if (ptr->prev != NULL) {
        ptr->prev->next = ptr->next;
    }

    free(ptr);
    display();
}


void search(int key) {
    struct node *ptr = head;
    int pos = 0;

    while (ptr != NULL) {
        if (ptr->data == key) {
            printf("Data found at position %d.\n", pos);
            return;
        }
        ptr = ptr->next;
        pos++;
    }
    printf("Data not found in list.\n");
}
