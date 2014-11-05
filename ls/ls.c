/* This is my own version of ls.
This is a very basic implementation
that just list files in an specified directory. 
It provides colors for directories, symbolic links,
executable and regular files.
*/
#include "ls.h" 

void *color(char *buffer,const char *string,const char dp_name[]) {
strcat(buffer,string);
strcat(buffer,dp_name);
strcat(buffer,ANSI_COLOR_RESET);
return NULL;
}
int main(int argc,char *argv[]) {
DIR *dirp;

char path[256];
if (argc == 1) {
strcpy(path,".");
}
else {
strcpy(path,argv[1]);
}
//Creating directory stream to the path specified in the argument
//If not specified, default to current directory "."

dirp=opendir(path);
struct dirent const *dp;

char *buffer=(char *)malloc(256);

node p1;
while ( (dp=readdir(dirp)) !=NULL) {
lstat(dp->d_name,&p1);
mode_t x=p1.st_mode;

//Providing colors to the output 
if (S_ISDIR(x)) 
 color(buffer,ANSI_COLOR_BLUE,dp->d_name);
else if (access(dp->d_name,X_OK))
 color(buffer,ANSI_COLOR_GREEN,dp->d_name);
else if (S_ISREG(x)) 
 color(buffer,ANSI_COLOR_RESET,dp->d_name);
else if (S_ISLNK(x)) 
 color(buffer,ANSI_COLOR_CYAN,dp->d_name);

//Removing . and .. from the output
int n1=strcmp(dp->d_name,".");
int n2=strcmp(dp->d_name,"..");

 if (n1 != 0) 
  if (n2 !=0)
   printf("%s  ",buffer);

memset(buffer,0,sizeof(buffer));
} 
printf("\n");
return 0;
}
