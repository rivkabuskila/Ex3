#include<stdio.h>
#include "ex3.h"


int main()
{
char txt[1024];

char word[30];


int i=-1;
do{
    i++;
 scanf("%c", &word[i]);
}while ((word[i]!=' ')&&(word[i]!='\t')&&(word[i]!='\n'));



 int j=-1;
do{
    j++;
 scanf("%c", &txt[j]);
}while ((txt[j]!='~'));

GemString(txt, word , i, j);
printf("\n");
AtbashString(txt, word,i,j);
printf("\n");
AnagramString(txt,word , i, j);
return 0;
}
