#include "func.h"

int check_buf(char *buf)
{
	int i,j=0;
    for(i=0;buf[i]!='\0';i++)
    {
        if(buf[i]!=' ')
        {
            buf[j++]=buf[i];
        }
    }
    buf[j]='\0';
}
