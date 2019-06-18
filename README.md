# Programming-Assignment-1b
## Unix System Calls
### Objective
The primary objective of this assignment is to practice coding with Unix system calls.

### Details
Write a program that takes two filenames on the command line as arguments and copies the first to the second by using system calls and no functions from the stdio library (stdio functions may be used to print messages to stdout or stderr for debugging and information purposes). If fewer than two or more than two arguments are given print a usage error message and exit. The program will copy the first file to the second (just like cp(1) does). The first argument (argv[1]) is the source file and the program should verify that it exists. If it does not exist, print an error message and exit. The second argument (argv[2]) is the destination file. If it does not exist, proceed to copying the file. If the destination file already exists, prompt to ask if it should be overwritten or not (like cp -i does) and do as the user instructs. Be sure your program works correctly for text and binary files of various sizes.

The system calls you must use for this program are stat(2), open(2), read(2), write(2), close(2), and access(2), which are defined in unistd.h. 

Remember to read Section 2 man pages (man -s 2) of these system calls and always do error checking when using system calls. Test your program on text and binary files of various sizes.

To start, review the program (apue.3e/intro/mycat.c) in Fig. 1.4 of Stevens and Rago's Advanced Programming in the UNIX Environment (APUE) book to learn how to use system calls read(2) and write(2). You may also review the program (apue.3e/intro/ls1.c) in APUE Fig. 1.3 to learn how to access command line arguments. Chapter 3 of APUE describes these system calls in details.

### Use of stat(), open(), and umask()
```
Try the following program, copy.c.

// copy.c --------------
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void
main(int argc, char *argv[])
{
  struct stat   buf;

  // umask(0);   // UMASK

  printf("copy: %s %s ", argv[1], argv[2]);
  if (stat(argv[1], &buf) < 0) {
    perror("stat error");
    exit(1);
  }
  printf("source mode [%o]\n", buf.st_mode);
  open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, buf.st_mode);
}
------------

Execute the following shell commands...

$ \rm b
$ gcc copy.c -o mycp
$ touch a
$ chmod 0777 a
$ ./mycp a b
$ ls -al a b

Compare the permissions of files a and b.

Now, uncomment UMASK line and repeat the commands above
and compare the permissions of files a and b.

Make sure you understand the difference.
```
### About system call access()
```
System call access() alone is not enough to figure out ALL
the permissions a file has.

Try the following program with the shell commands that
follow and compare the outputs.

// myaccess.c --------
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
  if (argc != 2)
    perror("usage: a.out ");

  if (access(argv[1], F_OK) < 0)
    printf("F_OK access error for %sn", argv[1]);
  else
    printf("file %s existsn", argv[1]);

  if (access(argv[1], R_OK) < 0)
    printf("R_OK access error for %sn", argv[1]);
  else
    printf("read R_OK access OKn");

  if (access(argv[1], W_OK) < 0)
    printf("W_OK access error for %sn", argv[1]);
  else
    printf("write W_OK access OKn");

  if (access(argv[1], X_OK) < 0)
    printf("X_OK access error for %sn", argv[1]);
  else
    printf("write X_OK access OKn");

  if (open(argv[1], O_RDONLY) < 0)
    printf("open error for %sn", argv[1]);
  else
    printf("open for reading OKn");
  }

----------
$ gcc myaccess.c
$ touch a
$ chmod 0007 a
$ ls -al a
$ ./a.out a
$ chmod 0070 a
$ ls -al a
$ ./a.out a
$ chmod 0700 a
$ ls -al a
$ ./a.out a
```

### Use of strace
```
$> echo hello > foo 
$> cat foo 

$> strace -e trace=open,read,write,close cat foo
.......
open("foo", O_RDONLY|O_LARGEFILE) = 3  
read(3, "hello\n", 4096)          = 6  
write(1, "hello\n", 6)            = 6 
read(3, "", 4096)                 = 0 
close(3)                          = 0
.......
```
