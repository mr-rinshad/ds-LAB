#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[MAX];   // adjacency list
int visited[MAX]; // visited array

void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    Node* temp = adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex])
            dfs(temp->vertex);
        temp = temp->next;
    }
}

int main() {
    int n, edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency list
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u); // For undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(start);
    printf("\n");

    return 0;
}