#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int vertices, edges;
    char** matrix;
} mtrx;

void read_dim(int* vertices, int* edges) {
    char transit;
    FILE *matrix = fopen("matrix.txt", "r");
    for (*vertices = 0; !feof(matrix); (*vertices)++) {
        for (*edges = 0; !feof(matrix); (*edges)++) {
            fscanf(matrix, "%c", &transit);
            if (transit == ' ') (*edges)--;
            if (transit == '\n') break;
        }
    }
    fclose(matrix);
}

void read_matrix(int vertices, int edges, char** graph_matrix){

    FILE *matrix = fopen("matrix.txt", "r");
    for (int i = 0; i < vertices && !feof(matrix); i++)
        for (int j = 0; j < edges && !feof(matrix); j++)
            fscanf(matrix, "%c ", &graph_matrix[i][j]);
    fclose(matrix);
}

void write_dot (int vertices, int edges, char** graph_matrix){
    FILE *dot_file = fopen("graph.dot", "w");

    fprintf(dot_file, "graph G {\n");

    for (int i = 0; i < edges; i++) {
        for (int j = 0; j < vertices; j++) {
            if (graph_matrix[j][i] != '0') {

                int k = j++;
                for (j; graph_matrix[j][i] == '0'; j++){}
                if (graph_matrix[j][i] != '1') break;

                fprintf(dot_file, "\t%c -- %c [label = %d];\n", k + 'a', j + 'a', graph_matrix[j][i] - '0');
                break;
            }
        }
    }
    
    fprintf(dot_file, "}");
    fclose(dot_file);
}

int main() {

    int vertices, edges;
    char transit;

    read_dim(&vertices, &edges);

    mtrx graph; 

    graph.matrix = (char**)malloc(sizeof(char*) * edges);
    for(int i = 0; i < edges; i++){
        graph.matrix[i] = (char*)malloc(sizeof(char) * vertices);
    }

    read_matrix(vertices, edges, graph.matrix);

    write_dot(vertices, edges, graph.matrix);

    // system("move graph.dot C:\\Graphviz\\bin & cd C:\\Graphviz\\bin & dot.exe -Tpng graph.dot -o graph.png & move graph.png D:\\c");

    return 0;
}