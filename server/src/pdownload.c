#include "func.h"

#define MAXSIZE 50
int pdownload(int new_fd,char *buf1){
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
				//发送文件
				if(0==strcmp(buf1,p->d_name))
				{
						train t;//定义小火车
						//传输文件名
						bzero(&t,sizeof(t));
						t.len=strlen(buf1);
						strcpy(t.buf,buf1);
						send(new_fd,&t,4+t.len,0);//发送文件名到客户端
						//发送文件内容
						int fd;
						fd=open(buf1,O_RDWR);
						if(-1==fd)
						{
								perror("open");
								close(new_fd);
								return;
						}		
						int ret;
						//循环读取文件内容，并发送			
						while((t.len=read(fd,t.buf,sizeof(t.buf)))>0)
						{
								ret=send_n(new_fd,&t,4+t.len);
								if(-1==ret)
								{
										goto end;
								}
						}
						//发送结束
						t.len=0;
						send(new_fd,&t.len,4,0);
end:
						close(fd);					
						break;
				}							
		}
		return 1;
}


