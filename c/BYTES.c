#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int 
len(char *String);
static char *CopiedString;
//int ByteLength(char *String);

/*
    This macro takes in a string, an array of integers, parses through each character
    of the string as a "bit", then assigns that index, or "bit", minus one into the
    byteOutput of that character index.
    
    Then, if byteOutput[0] is -1(which it should always be -1), it will parse through the string
    again, only then adding in 2 bits of memory both being zero.
*/
#define MakeByte(outOfString,byteOutput,StrictBit) \
    /* Setting size if null */\
    static int Total;\
    if(byteOutput==NULL) {\
        byteOutput=malloc(strlen(outOfString)*sizeof(int));\
    }\
    for(int i = 0;i < strlen(outOfString); i++) {\
        byteOutput[i]=i-1;\
        if(i==strlen(outOfString)-1) break;\
    }\
    if(byteOutput[0]==-1) {\
        for(int i = 0;i < strlen(outOfString); i++) {\
            if(!(i==100)) {\
                byteOutput[i]=byteOutput[i]+2;\
            } else {\
                byteOutput[i] = byteOutput[i]+4;/*Adding 4 bits of memory to every hundred bits*/\
            }\
            Total+=byteOutput[i];\
            if(i==strlen(outOfString)-1) {\
                /* adding 2 more bits of memory */\
                byteOutput[strlen(outOfString)+1]=0;\
                byteOutput[strlen(outOfString)+2]=0;\
                Total+=2;/*Adding 2 to Total since there is 2 extra bits of memory*/\
                break;\
            }\
        }\
    }\
    if(StrictBit){\
        /*Checking to see if there is more than 10000 bytes*/\
        if(Total>10000) {\
            /*Copying string*/\
            strcpy(CopiedString,outOfString);\
            /*Assigning the string to an empty string*/\
            strcpy(outOfString,"");\
            /*Assigning bytes to zero*/\
            Total=0;\
            /*Freeing memory out of byteOutput since bytes are erased*/\
            free(byteOutput);\
            printf("No bits aquired");\
        } else {\
            printf("TOTAL: %d\n",Total);\
        }\
    } else {\
        printf("TOTAL: %d\n",Total);\
    }
    

int main(void) {
    char STRING[40] = "YESSIR THAT's CORRECT";
    int *Bytes;
    
    int LENGTH = len(STRING);
    
    MakeByte(STRING,Bytes,true);
}

int
len(char *String) {
    int length=strlen(String);
    return length;
}
