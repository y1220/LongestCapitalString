#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
///put "PSEUDOpseudohypoparaTHYROIDISM" into command line
void longestSubstring(char *, char **);
int main(int argc, char **argv)
{
    char *out;
    if(argc!=2){
        printf("ERROR command line!\n");
    }
    longestSubstring(argv[1],&out);
    int j;
    printf("\nout:");
    for(j=0;j<strlen(out);j++){
           printf("%c",out[j]);
    }
    return 0;
}
void longestSubstring(char *in, char **out){
    int max =0;
    int max_pos =0;
    int pos =0;
    int cnt =0;
    int k;
    for(k=0;k<strlen(in);k++){
        while(isupper(in[k])){
            if(cnt==0)
                pos=k;
            cnt++;
            k++;
        }
        if(max<cnt){
            max =cnt;
            max_pos =pos;
            cnt =0;
            pos =0;
        }
        cnt=0;
    }///put the result into out
    *out= (char*)malloc(max*sizeof(char));
    if(*out==NULL){
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    int j;
    char res[max];
    for(j=0;j<max;j++){
           res[j]=in[max_pos+j];
    }
    strcpy(*out,res);
}
