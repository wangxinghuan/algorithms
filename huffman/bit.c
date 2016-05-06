#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void read_file(FILE * fp, FILE * fp_out){
    char c;
    int k = 0;
    int i = 0;
    unsigned char temp = 0x00;

    while ( ( c = fgetc(fp) ) != EOF) {
        if (c == '\n') {
            continue;
        }
        switch (c){
            case '1' : 
        temp = temp | (0x1 << (7 - k));
        break;
            case '0' :
        temp = temp | (0x0 << (7 - k ));
            break;
        }
        k++;
        if ( k == 8 ) {
            printf("HELLO\n");
            printf("%x\n",temp);
            printf("%x\n",temp & 0xFF);
            fprintf(fp_out, "%x", temp & 0xFF);
            temp = 0x00;
            k = 0;
        }
    }
}

int main(int argc, char *argv[])
{
    FILE * fp_in;
    FILE * fp_out;
    char filename[20];

    printf("Enter File Name: \n");
    scanf("%s",filename);
    fp_in = fopen(filename, "r");
    fp_out = fopen("2.txt","w");
    read_file(fp_in,fp_out);
}
