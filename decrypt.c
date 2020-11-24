#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int xor1(int i,int j)
{
  int x;

  x=i^j;
  return (x>126||x<33||x==91||x==93||x==61)?i:x;
}
void main()
{
  FILE *f;
  int i,l;
  char s[80],s1[80];

  printf("Please enter the path to your Windows directory\n");
  gets(s1);
  sprintf(s,"%s%scontrol.ini",s1,s1[strlen(s1)-1]=='\\'?"":"\\");
  if((f=fopen(s,"rt"))==NULL){
    printf("File Error : %s\n",sys_errlist[errno]);
    exit(0);
  }
  while(strnicmp(fgets(s1,70,f),"password",8)!=0&&!feof(f));
  fclose(f);
  strtok(s1,"=\n");
  strcpy(s,strtok(NULL,"\n"));
  i=strlen(s)-1;
  for(l=i;l>-1;l--)
    s1[l]=xor1(xor1(xor1(s[l],l==i?42:s[l+1]),l==i?0:l),i+1);
  for(l=0;l<i+1;l++)
    s[l]=xor1(xor1(xor1(s1[l],l?s1[l-1]:42),l?l:0),i+1);
  printf("The Password is: %s\n",s);
}
