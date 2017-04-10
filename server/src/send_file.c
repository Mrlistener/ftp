#include "func.h"
//发送文件函数
void hand_request(int new_fd)
{
		int len;
		char buf1[1000];
		int ret;
		while(1)
		{
				if(1)
				{
						bzero(buf1,sizeof(buf1));
						recv(new_fd,&len,sizeof(len),0);
						ret=recv_n(new_fd,buf1,len,0);
						if(ret<0)
						{
								goto end;
						}
				}
				printf("%s\n",buf1);
				if(0==strcmp("pwd",buf1))
				{	
						printf("%s\n",buf1);
						getcwd(buf1,sizeof(buf1));	
						len=strlen(buf1);
						send(new_fd,&len,4,0);//发送命令长度
						send_n(new_fd,buf1,len,0);
				}else if(0==strcmp("ls",buf1))
				{
						char buf2[1000];
						bzero(buf2,sizeof(buf2));
						ls_prit(buf2);
						len=strlen(buf2);
						send(new_fd,&len,4,0);//发送命令长度
						send_n(new_fd,buf2,len,0);
				}else if(0==strncmp("cd",buf1,2))
				{
						int m=0;
						int n=2;
						buf1[strlen(buf1)]='\0';
						char buf2[1000];
						bzero(buf2,sizeof(buf2));
						for(n;buf1[n]!='\0';n++)
						{
								buf2[m]=buf1[n];
								m++;
						}
						buf2[strlen(buf2)]='\0';
						chdir(buf2);
						char buf3[]="cd success";
						int len=strlen(buf3);
						send(new_fd,&len,4,0);//发送命令长度
						send_n(new_fd,buf3,len,0);

				}else if(0==strncmp("rm",buf1,2))
				{
						int m=0;
						int n=2;
						buf1[strlen(buf1)]='\0';
						char buf2[1000];
						bzero(buf2,sizeof(buf2));
						for(n;buf1[n]!='\0';n++)
						{
								buf2[m]=buf1[n];
								m++;
						}
						buf2[strlen(buf2)]='\0';
						remove(buf2);
						char buf3[]="rm success";
						int len=strlen(buf3);
						send(new_fd,&len,4,0);//发送命令长度
						send_n(new_fd,buf3,len,0);
				}else if(0==strncmp("gets",buf1,4))
				{
						int m=0;
						int n=4;
						buf1[strlen(buf1)]='\0';
						char buf2[1000];
						bzero(buf2,sizeof(buf2));
						for(n;buf1[n]!='\0';n++)
						{
								buf2[m]=buf1[n];
								m++;
						}
						buf2[strlen(buf2)]='\0';
						pdownload(new_fd,buf2);
				}else if(0==strncmp("puts",buf1,4))
				{
						printf("%s\n",buf1);
						pupload(new_fd);
				}
		}
end:
		close(new_fd);
}
