/*#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"

char buf[512];

void
cat(int fd1, int fd2)
{
  int n;

  while((n = read(fd1, buf, sizeof(buf))) > 0) {
    //write(1, buf, n);
    printf(fd2, "%s", buf);
  }
  if(n < 0){
    printf(1, "copy: read error\n");
    exit();
  }
}

int
main(int argc, char *argv[])
{
  int fd1;
  if(argc < 3){
    printf(1, "copy: read error\n");
    exit();
  }
  if((fd1 = open(argv[2], 0)) < 0){
    printf(1, "copy: cannot open %s\n", argv[1]);
    exit();
  }
  int fd2;
  
  if ((fd2 = open(argv[1], O_CREATE | O_RDWR)) < 0) {
    printf(1, "copy: error initializing file: %s\n", argv[2]);
    exit();
  }
  cat(fd2,fd1);
  close(fd1);
  close(fd2);
  exit();
}*/

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char buf[512];

int main(int argc, char *argv[])
{
	int fd0, fd1, n;

	if(argc<=2){
	printf(1,"Need 2 arguments!\n");
	exit();
}

	if((fd0 = open(argv[1], O_RDONLY)) < 0 ){
	printf(1, "cp: cannot open %s\n", argv[1]);
	exit();
}
	if((fd1 = open(argv[2],0))<0){
	printf(1, "cp:cannot open %s\n", argv[2]);
	exit();
}

	while ( ( n=read ( fd0, buf, sizeof(buf))) > 0){
	write (fd1,buf,n);
	}
	close(fd0);
	close(fd1);

	exit();
}
