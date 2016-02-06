#include <stdio.h>
#include <iostream>
#include <string.h>

long long graph[150][150];
long long has_visited[150];

void reset_graph() {
    for (long long i = 0; i < 150; i++) {
        for (long long j = 0; j < 150; j++) {
            graph[i][j] = 0;
        }
    }
}

void reset_has_visited() {
    for (long long i = 0; i < 150; i++) {
        has_visited[i] = 0;
    }
}

void dfs(long long v) {
    has_visited[v] = 1;

    for (long long i = 0; i < 150; i++)
        if (graph[v][i] == 1 && has_visited[i] == 0) dfs(i);
}

int main() {
    long long v_number;

    while (true) {
        reset_graph();

        scanf("%lld", &v_number);

        if (v_number == 0) break;

        long long start_vertex;

        while (true) {
            scanf("%lld", &start_vertex);

            if (start_vertex == 0) break;

            long long connected_vertex;

            while (true) {
                scanf("%lld", &connected_vertex);

                if (connected_vertex == 0) break;

                graph[start_vertex][connected_vertex] = 1;
            }
        }

        char queries[100];
        fgets(queries, sizeof(queries), stdin);
        char delimiters[] = {' '};

        long long query;
        char* word;
        do {
            word = strtok(queries, delimiters);

            printf("%c", word);

            //reset_has_visited();

            //if (query == 0) break;

            //dfs(query);

            //for (long long i = 0; i < 150; i++) {
            //    if (has_visited[i] == 0 && i > 0 && i <= v_number)
            //        printf("%lld ", i);
            //}

            //printf("\n");
        } while (word != NULL);
    }
}