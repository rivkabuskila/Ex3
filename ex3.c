#include<stdio.h>
#include<string.h>

int equal(char c) {
if (c >= 'a' && c <= 'z') {
int a=c - 'a' + 'A';
return a-('A'-1);
}
if((c <'a' && c > 'Z')||c < 'A'||c>'z' ){
return 0;
}
return c-('A'-1);
}


int sumchar(char* c){
    int sum=0;
    for(int i=0; i<strlen(c); i++){
        int a= equal(c[i]);
          sum=sum+a; 
      }
   return sum;
}

void GemString(char* str, char* word){
char *p=str;
char *p1=str;
char arr[1024]={'0'};

int pa =0;
int sumW=sumchar(word);
int  sum=0;
int i=0;
 while (i < strlen(str)-1){
    int a=equal(*p);
    sum=sum+a;
if(sum==sumW){
   
while(p1<=p){
    arr[pa]=*p1;
    pa++;
    p1++;
}
arr[pa]='~';
pa++;
i++;
sum=0;

      p=&str[i];
      p1=&str[i];
}else if (sum<sumW){

int aa=equal(*p1);
if(aa==0){
    p1++;
    i++;
}

      p++;
  } else if(sum>sumW){
      sum=0;
      i++;
      p=&str[i];
      p1=&str[i];
     
  }
}
printf("Gematria Sequences: ");
for (int i = 0; i < pa-1; i++) {
   printf("%c", arr[i]);
}


 
 }


 char ATchar(char c){
  int a =equal(c);
  char ans='0';
  if(c=='A'){
      return 'Z';
      
  }
   if(c=='a'){
       return 'z';   
   }
   if((c <'a' && c > 'z')||(c < 'A' && c > 'Z')){
   return '0';
   }
   if((c > 'A' && c <= 'Z')){
   int b=(int)'Z'-(int)c;
   b=b+(int)c;
   ans=(char)b-a+1; 
   }
   
  if((c > 'a' && c <= 'z')){
   int b=(int)'z'-(int)c;
   b=b+(int)c;
    ans=(char)b-a+1;
    }

  return ans;
}

char* sumchar1(char* a){
    char* P=NULL;
    char ans[1024]={'0'};
    char* Q=a;
    P=ans;
    for (int i = 0; i < strlen(a); i++) {
        
        char c=ATchar(*Q);
        ans[i]=c;
        Q++;
    }
    return P;
}



void AtbashString(char* str, char* word){
char *p;
char *p1;
char *startAT;
char *endAT;
char arr[1024]={'0'};
 int pa =0;
 char *atbashW= sumchar1(word);
 p=str;
 p1=str;
 startAT=atbashW;
 endAT=atbashW+ strlen(atbashW)-2;
 char *end=endAT;
 int i=0;
 while (i < strlen(str)-1){
     int k=0;
     startAT=atbashW;
     endAT=end;
     while(str[i]== ' '){
         i++;
     }
     p=&str[i];
     p1=p;
     if(startAT <= end && *p1==*startAT){
       while(startAT <= end && *p1==*startAT){
     p1++;
     startAT++;
     k++;
     while((*p1== ' ')&&(k!=strlen(atbashW)-1)){
         p1++;
     }
  }    
 }   
  else if (endAT >=atbashW && *p1==*endAT){
    while(endAT >=atbashW && *p1==*endAT){
         p1++;
         endAT--;
         k++;
     while((*p1== ' ') && (k!=strlen(atbashW)-1)){
         p1++;
     }
    }    
 }
    if (k==strlen(atbashW)-1){
         while(p!=p1){
          arr[pa]=*p;
          pa++;
          p++;
          
        }
        arr[pa]='~';
        pa++;
        } 
    i++;
 }
 printf("Atbash Sequences: ");
for (int i = 0; i < pa-1; i++) {
   printf("%c", arr[i]);
}



 }



void AnagramString(char* str, char* word){
  char *p;
  int j=0;
  char *p1;
  char arr[1024]={'0'};
  char temp[30]={'0'};
  int sum =0;
  int pa=0;
  p=str;
  p1=str;
  int tr = 0;
 int i=0;
  for (int t = 0; t < strlen(word)-1; t++) {
        temp[t]=word[t];
     }
 while (i < strlen(str)-1){
     while(*p==' '){
         p++;
     }
     while(*p1==' '){
         p1++;
         i++;
     }
     tr=0;
     j=0;
   while( tr == 0 && j < strlen(temp)) {
       if(*p==temp[j]){
           p++;
           temp[j]=' ';
           sum++;
           tr=1;
       }
       else{
                 j++;
       }
       
   }
   if(sum==strlen(temp)){
       while(p1<p){
           arr[pa]=*p1;
           p1++;
           pa++;
       }
       arr[pa]='~';
       pa++;
   }
  if (tr==0 || (sum==(strlen(temp)))){ 
   sum=0;
   i++;
   p=&str[i];
   p1=&str[i];
    for (int t = 0; t < strlen(word)-1; t++) {
        temp[t]=word[t];
     }
}
}
printf("Anagram Sequences: ");
for (int i = 0; i < pa-1; i++) {
   printf("%c", arr[i]);
}
 }