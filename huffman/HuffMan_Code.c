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

void encode(FILE * fp_in, FILE * fp_out, int num){
    char c;
    int i = 0;
    int j = 0;
    int k = 0;

    while ( ( c = fgetc(fp_in) ) != EOF) {
        if ( c == '\n' ) {
            fputc('\n',fp_out);
            continue;
        }
        for (i = 0; i < num; i++) {
            if (c == ch[i]) {
                fprintf(fp_out,"%s",ring[i]);
                break;
            }
        }
    }
}

void read_file(FILE * fp, FILE * fp_out){
    char c;
    int k = 0;
    int i = 0;
    unsigned char temp = 0x00;

    while ( ( c = fgetc(fp) ) != EOF) {
        if (c == '\n') {
            continue;
        }
        switch(c){
            case '1':
                temp = temp | 0x1 << (7 - k);
                break;
            case '0':
                temp = temp | 0x0 << (7 - k);
                break;
        }
        k++;
        if ( k == 8 ) {
            printf("HELLO\n");
            printf("%x\n",temp & 0xFF);
            fprintf(fp_out, "%x", temp & 0xFF);
            temp = 0x00;
            k = 0;
        }
    }
    if ( c == EOF ) {
        fprintf(fp_out, "%x", temp & 0xFF);
    }
}


int main(int argc, char *argv[])
{
    FILE * fp_in;
    FILE * fp_out;
    FILE * fp_table;
    FILE * fp_out_bit;
    char * name;
    char filename[20];

    printf("Enter File Name: \n");
    scanf("%s",filename);
    fp_in = fopen(filename, "r");
    fp_table = fopen("table.txt","r");
    fp_out_bit = fopen("bit.txt","w");
    name = strtok(filename, ".");
    strcat(name, "_code.txt");
    fp_out = fopen(name,"w");
    int num = read_table(fp_table);
    printf("number %d\n",num);             
    int i;
    for (i = 0; i < num; i++) {
        printf("%c %s\n", ch[i], ring[i]);
    }
    encode(fp_in, fp_out, num);
    fclose(fp_out);
    fp_out = fopen(name,"r");
    read_file(fp_out, fp_out_bit);
    fclose(fp_out_bit);
    fclose(fp_in);
    fclose(fp_out);
}
