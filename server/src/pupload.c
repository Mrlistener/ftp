#include "func.h"

void pupload(int new_fd)
{
		int len;
		char buf[1000];
		bzero(buf,sizeof(buf));
		recv(new_fd,&len,sizeof(len),0);
		recv(new_fd,buf,len,0);
		int fd;
		fd=open(buf,O_CREAT|O_RDWR,0600);
		if(-1==fd)
		{
				perror("open");
				close(new_fd);
		}
		while(1)
		{
				recv_n(new_fd,&len,sizeof(len));//先读4个字节
				if(len>0)
				{
						bzero(buf,sizeof(buf));
						recv_n(new_fd,buf,len);
						write(fd,buf,len);
				}else{
						break;
				}
		}
		close (fd);
}
