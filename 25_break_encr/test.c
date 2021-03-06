#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
void get_count(FILE * fp,int * frq){
  if(fp==NULL)
    return;
  int c;
  while((c=fgetc(fp))!=EOF){
    if (isalpha(c)) {
      c = tolower(c); 
      c-='a';
      frq[c]+=1;
    }
  }
  return;
}
int decrypt(int * freq,int n){
  int max=freq[0];
  int mi=0;
  for(int i=1;i<n;i++){
    if(freq[i]>max){
      max=freq[i];
      mi=i;
    }
  }
  mi+=22;
  mi=mi%26;
  return mi;
}
int main(int argc,char **argv){
  if(argc!=2){
    fprintf(stderr,"Usage executable encrypted_file \n");
    return EXIT_FAILURE;
  }
  FILE *fp=fopen(argv[1],"r");
  if(fp==NULL){
    fprintf(stderr,"Unable to open file\n");
    return EXIT_FAILURE;
  }
  int key;
  int freq_count[26];
  for(int i=0;i<26;i++){
    freq_count[i]=0;
  }
  get_count(fp,freq_count);
  printf("\n");
  key=decrypt(freq_count,26);
  printf("%d\n",key);
  return EXIT_SUCCESS;
}
