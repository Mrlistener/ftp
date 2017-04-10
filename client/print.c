#include "func.h"

void print(int new_fd,char *buf)
{
		int len;	
		char buf1[1000];
		bzero(buf1,sizeof(buf1));
		buf[strlen(buf)-1]='\0';
		check_buf(buf);
		if(0==strcmp("pwd",buf))
		{		
				len=strlen(buf);
				send(new_fd,&len,4,0);//发送命令长度
				send_n(new_fd,buf,len,0);
				if(1)
				{
						bzero(buf1,sizeof(buf1));
						recv(new_fd,&len,sizeof(len),0);
						recv_n(new_fd,buf1,len,0);
				}
				system("clear");
				printf("%s\n",buf1);
		}else if(0==strcmp("ls",buf))
		{
				len=strlen(buf);
				send(new_fd,&len,4,0);//发送命令长度
				send_n(new_fd,buf,len,0);
				if(1)
				{
						bzero(buf1,sizeof(buf1));
						recv(new_fd,&len,sizeof(len),0);
						recv_n(new_fd,buf1,len,0);
				}
				system("clear");
				printf("%s\n",buf1);
		}else if(0==strncmp("cd",buf,2))
		{
				len=strlen(buf);
				send(new_fd,&len,4,0);//发送命令长度
				send_n(new_fd,buf,len,0);
				if(1)
				{
						bzero(buf1,sizeof(buf1));
						recv(new_fd,&len,sizeof(len),0);
						recv_n(new_fd,buf1,len,0);
				}
				system("clear");
				printf("%s\n",buf1);

		}else if(0==strncmp("rm",buf,2))
		{
				len=strlen(buf);
				send(new_fd,&len,4,0);//发送命令长度
				send_n(new_fd,buf,len,0);
				if(1)
				{
						bzero(buf1,sizeof(buf1));
						recv(new_fd,&len,sizeof(len),0);
						recv_n(new_fd,buf1,len,0);
				}
				system("clear");
				printf("%s\n",buf1);
		}else if(0==strncmp("gets",buf,4))
		{
			len=strlen(buf);
			send(new_fd,&len,4,0);//发送命令长度
			send_n(new_fd,buf,len,0);
			pdownload(new_fd);
		}else if(0==strncmp("puts",buf,4))
		{		
			len=strlen(buf);
			send(new_fd,&len,4,0);//发送命令长度
			send_n(new_fd,buf,len,0);
			printf("1%s\n",buf);
			int m=0;
 	        int n=4;
    	    buf[strlen(buf)]='\0';
			printf("2%s\n",buf);
        	char buf2[1000];
       		bzero(buf2,sizeof(buf2));
	        for(n;buf[n]!='\0';n++)
    	    {
                buf2[m]=buf[n];
                m++;
    	    }
	   	   	buf2[strlen(buf2)]='\0';
			printf("3%s\n",buf2);
			pupload(new_fd,buf2);
		}
}
