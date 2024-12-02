#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 100

void encolador(const char* filename1) {
    char input_path[100];
    sprintf(input_path, "CarpetaPedidos/%s", filename1);

    FILE *file = fopen(input_path, "r");
    if (file == NULL) {
        printf("Failed to open input file.\n");
        return;
    }

    char line[MAX_LINE_LEN];
    fgets(line, MAX_LINE_LEN, file);
    int order_num = atoi(line);

    fgets(line, MAX_LINE_LEN, file);
    char priority_num[10], client_code[10];
    sscanf(line, "%s %s", client_code, priority_num);

    char filename[50];
    sprintf(filename, "./CarpetaPedidos/%s_pedido_%d_%s.txt", priority_num, order_num, client_code);

    FILE *outfile = fopen(filename, "w");
    if (outfile == NULL) {
        printf("Failed to create output file.\n");
        return;
    }

    fprintf(outfile, "%d\n", order_num);
    fprintf(outfile, "%s", line);

    while (fgets(line, MAX_LINE_LEN, file) != NULL) {
        fprintf(outfile, "%s", line);
    }

    fclose(file);
    fclose(outfile);

    char input_file_path[100];
    sprintf(input_file_path, "./CarpetaPedidos/%s", filename1);
    if (remove(input_file_path) != 0) {
        printf("Failed to delete the original file.\n");
        return;
    }
}



