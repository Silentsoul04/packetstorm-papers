/************************************************/
/* 	 	--==PROXIFIER==-- 		*/
/* 						*/
/* This is an automated Proxy List Generator	*/
/* 	   for www.proxy4free.com		*/
/*						*/
/* Code-in FreeBSD 5.3]# gcc -o pro proxifier.c	*/
/*    This is for educational purpose only	*/
/*						*/
/* Send Comments to netgeker[A.T]secureroot.com	*/
/* December 2005 @ by Netgeker    	APCORE	*/
/*						*/
/* NOTE: Modification to suite for  other site	*/
/*	 dont forget to Send me a copy 		*/
/************************************************/
 		
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define LMT 1024

  
int main(int argc, char *argv[]) {

  printf("\n\n\nAPCore: NETGEKER\n");
  printf("\n----====PROXYFIER====----\n");
  printf("Proxy List Stripper for sock4free.com\n");
  printf("Mabuhay Philippines!!!\n\n");


  char shell[BUFSIZ];
  char shell2[BUFSIZ];
  char p[1024];
  char buf[1024];
  int i=0, j=0, x=0, dot=0, r=0;
  
  FILE *fp;
  char ch;
   
     
  for(i=1;i<=10;i++) {
    snprintf(p, sizeof(p), "%i", i);
    sprintf(shell, "wget http://www.proxy4free.com/page%s.html", p);
    system(shell);
  }
 
  printf("\n[+] Done fetching html proxy list.\n");
  printf("[+] Stripping and Concatenating.\n");
 
     
  for(j=1; j<=10; j++) {
     sprintf(shell, "page%i.html", j);
     if((fp=fopen(shell, "r")) == NULL) {
        printf("[-] ERROR OPENING FILE\n");
     } else {
        printf("\r[+] FILE %s OPENED\n",shell );
        ch=getc(fp);
       while(ch!=EOF) {
         if(ch != '\n') {
 	    buf[x] = ch; x++;
 	    if(ch == '.') { dot++; }
 	} else {
 	   buf[x] = '\0';
 	   sprintf(p,"%s",buf);
 	   x=0;
 	   if(r==1) {
               if ((strstr(p,"tr") != NULL) || (strstr(p,"a") != NULL) || (strstr(p,"w") != NULL) || (strstr(p,"p") != NULL))  {
 	            printf(" ");
	         } else {	      
 	      		sprintf(shell, "echo \"%s:%s\" >> save.txt",shell2,p); 
 	      		system(shell);
     		r=0;
 	      }
 	   }
 	   if(dot >= 3) {
      	      
               if ((strstr(p,"tr") != NULL) || (strstr(p,"a") != NULL) || (strstr(p,"w") != NULL) || (strstr(p,"p") != NULL))  {
 	            printf(" ");
 	         } else {
 	            sprintf(shell2, "%s", p); 
	            r=1;
 	      }   
 	   }
 	   dot=0;
 	}
 	ch = getc(fp);
       }
       
     }
     fclose(fp);
   }  
     
   
   sprintf(shell,"sed -e 's/<td>//g'  save.txt > save1.txt");
   system(shell);
   sprintf(shell,"sed -e 's/<\\/td>//g' save1.txt > save.txt");
   system(shell);
   sprintf(shell,"rm -rf save1.txt");
   system(shell);  
   sprintf(shell,"sed -e 's/ //g' save.txt > proxified.txt");
   system(shell);
   sprintf(shell,"rm -rf save.txt");
   system(shell);  
   
   printf("\n[+] And there it goes to proxified.txt");
   printf("\n[+] Mail comments to netgeker[AT]secureroot[DOT]com\n");
   return 0;
}
 
