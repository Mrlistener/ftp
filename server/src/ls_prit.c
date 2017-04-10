#include "func.h"

#define MAXSIZE 50
void  ls_prit(char *buf1){
		DIR *pd;
		char lspath[1000];
		getcwd(lspath,sizeof(lspath));
		pd = opendir(lspath);
		if(NULL == pd){
				perror("opendir");
				return;
		}
		struct tm *ptminfo;
		char timebuf[MAXSIZE];
		char filetype_sets[16] = {' ',' ',' ',' ','d',' ',' ',' ','-',' ',' ',' ',' ',' ',' ',' '};
		int i, filetype;
		unsigned int temp;
		struct dirent *p;
		off_t position;
		int	ret;
		struct stat buf;
		char path[512] = {0};
		char buf2[1000];
		char buf3[30];
		int a=0;
		bzero(buf2,sizeof(buf2));
		bzero(buf3,sizeof(buf3));
		while((p = readdir(pd))!= NULL){
				if(strcmp(p->d_name,".")==0 ||strcmp(p->d_name,"..")==0){
						continue;
				}
				sprintf(path, "%s%s%s",lspath,"/",p->d_name);
				ret = stat(path, &buf);
				if(ret!=0){
						perror("stat");
						return;
				}
				filetype = buf.st_mode>>12 & 15;
//				printf("%c %8ld %-s\n", filetype_sets[filetype],buf.st_size,p->d_name);

				buf2[a]=filetype_sets[filetype];
				a=strlen(buf2);
				strcpy(buf2+a,"   ");
				a=strlen(buf2);				
				sprintf(buf2+a,"%ld",buf.st_size);
				a=strlen(buf2);
				strcpy(buf2+a,"   ");
				a=strlen(buf2);				
				strcpy(buf2+a,p->d_name);
				a=strlen(buf2);				
				strcpy(buf2+a,"\n");
				a=strlen(buf2);				
		}
		buf2[strlen(buf2)-1]='\0';
//		printf("%s\n",buf2);
		strcpy(buf1,buf2);
		closedir(pd);
		return;
}


