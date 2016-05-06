#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char ch[100];
char ring[100][100];

int read_table(FILE * fp){
    char c;
    int i = 0;
    int j = 0;
    int k = 0;
    char temp;
    long pos;

    while ( ( c = fgetc(fp) ) != EOF) {
        if (c == ' ') {
             pos = ftell(fp); 
             temp = fgetc(fp);
             if ( temp != ' ' ) {
                 fseek(fp, pos, SEEK_SET);
             }
             else {
             ch[k] = c;
             k++;
             }

            fgets(ring[i],40,fp); 
            for (j = 0;  ; j++) {
                if (ring[i][j] == '\n') {
                    ring[i][j] = '\0';
                    i++;
                    break;
                }
            }
            continue;
        }
        else if (c == '\n') {
            continue;
        }
        else {
            ch[k] = c;
            k++;
        }
    }

    return k;
}

void Decode(FILE * fp_in, FILE * fp_out, int num){
    char c;
    int i = 0;
    int j = 0;
    int k = 0;
    char temp[100] = "0";

    while ( ( c = fgetc(fp_in) ) != EOF) {
        if ( c == '\n' ) {
            fputc('\n',fp_out);
            continue;
        }
        temp[j] = c;
        j++;
        for (i = 0; i < num; i++) {
            if ((strcmp(temp, ring[i])) == 0) {
                fputc(ch[i],fp_out);
                for (k = 0; k < j; k++) {
                    temp[k] = '\0';
                }
                j = 0;
                break;
            }
        }
    }
}
int main(int argc, char *argv[])
{
    FILE * fp_in;
    FILE * fp_out;
    FILE * fp_table;
    char * name;
    char filename[20];

    printf("Enter File Name :\n");
    scanf("%s",filename);
    fp_in = fopen(filename, "r");
    fp_table = fopen("table.txt","r");
    name = strtok(filename, ".");
    strcat(name, "_decode.txt");
    fp_out = fopen(name,"w");
    int num = read_table(fp_table);
    int i;
    for (i = 0; i < num; i++) {
        printf("%c %s\n", ch[i], ring[i]);
    }
    Decode(fp_in, fp_out, num);
}
