#include<stdio.h>

// Define the maximum number of elements
#define MAX 100

int parent[MAX];  // Array to store parent of each element

// Step 1: Create and initialize the parent array
void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i; // Each element is its own parent initially
    }
}

// Step 2: Find function to get the parent (representative) of an element
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);  // Path compression (optional optimization)
    }
    return parent[x];
}

// Step 3: Union function to join two sets by connecting their parents
void unionSets(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    
    if (rootA != rootB) {
        parent[rootB] = rootA;  // Make rootA the parent of rootB
    }
}

// Step 4: Display function to show parent array
void display(int n) {
    printf("\nElement\tParent\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t----->%d\n", i, parent[i]);
    }
}

int main() {
    int n, choice, a, b;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    makeSet(n);

    while(1) {
        printf("\n--- Disjoint Set Menu ---\n");
        printf("1. Find parent\n");
        printf("2. Union two sets\n");
        printf("3. Display parent array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to find parent: ");
                scanf("%d", &a);
                printf("Parent of %d is %d\n", a, find(a));
                break;

            case 2:
                printf("Enter two elements to union: ");
                scanf("%d %d", &a, &b);
                unionSets(a, b);
                printf("Union performed between %d and %d\n", a, b);
                break;

            case 3:
                display(n);
                break;

            case 4:
                printf("Exiting...\n");
                return 0;
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
