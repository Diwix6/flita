#include <stdio.h>
#include <stdlib.h>

struct Vertex {
    int value, loop;
    struct Vertex *next;
};

void createVerticesFromIncidenceMatrix(int **matrix, int numVertices, int numEdges, struct Vertex *vertices[]) {
    for (int j = 0; j < numEdges; j++) {
        int startVertex = -1, endVertex = -1;
        for (int i = 0; i < numVertices; i++) {
            if (matrix[i][j] == 1) {
                if (startVertex == -1) {
                    startVertex = i;
                } else {
                    endVertex = i;
                    break;
                }
            }
        }
        struct Vertex *newVertex = (struct Vertex*)malloc(sizeof(struct Vertex));
        if (endVertex == -1){
            newVertex->loop = 1;
            newVertex->value = startVertex;
        }
        else newVertex->value = endVertex;
        newVertex->next = vertices[startVertex]->next;
        vertices[startVertex]->next = newVertex;
    }
}

void writeGraphToFile(int numVertices, struct Vertex **vertices) {
    FILE *file = fopen("graph.txt", "w");
    if (file == NULL) {
        printf("Error opening file");
        return;
    }
    fprintf(file, "graph {\n");
    for (int i = 0; i < numVertices; i++) {
        struct Vertex *currentVertex = vertices[i]->next;
        while (currentVertex != NULL) {
            fprintf(file, "  %d -- %d;\n", i, currentVertex->value);
            currentVertex = currentVertex->next;
        }
    }
    fprintf(file, "}\n");
    fclose(file);
}


int main() {
    int numVertices, numEdges, currentColumns = 0, rows = 0, columns = 0;
    char ch, tmp;
    FILE *file = fopen("tests/matrix_of_incendence35.txt", "r");
    while (!feof(file)) {
        int value;
        int count = fscanf(file, "%c%c", &tmp, &ch);
        if (count > 0 && ch != '\n' && tmp != '\n') {
            if (rows == 0) {
                columns++;
            }
        } else {
            rows++;
            if (rows == 1) 
                currentColumns = columns;
            columns = 0;
        }
    }
    numEdges = currentColumns; numVertices = rows;
    int **matrix = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) matrix[i] = (int*)malloc(numEdges * sizeof(int));
    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < numVertices; i++) {
        matrix[i] = (int*)malloc(numEdges * sizeof(int));
        for (int j = 0; j < numEdges; j++)
            fscanf(file, "%d", &matrix[i][j]);
    }
    struct Vertex* vertices[numVertices];
    for (int i = 0; i < numVertices; i++) {
        vertices[i] = (struct Vertex*)malloc(sizeof(struct Vertex));
        vertices[i]->value = i;
        vertices[i]->next = NULL;
        vertices[i]->loop = NULL;
    }

    createVerticesFromIncidenceMatrix(matrix, numVertices, numEdges, &vertices);

    writeGraphToFile(numVertices, vertices);
    system("dot -Tpng graph.txt > graph.png");
    for (int i = 0; i < numVertices; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
