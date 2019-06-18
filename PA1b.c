//#include <stdio.h>
//#include <stdlib.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <sys/wait.h>
//#include <unistd.h>
//#include <math.h>
//#include <fcntl.h>
//
//int main(int argc, char *argv[]) {
//
//	int file1 = 0;
//	int file2 = 0;
//	struct stat buf;
//
//	if (argc != 3){
//		perror("Usage Error.\n");
//		exit(1);
//	}
//
//	if ((access(argv[1], F_OK | R_OK) == = 1)) {
//		printf("Please check the file1. \n");
//		exit(1);
//		if ((access(argv[2], W_OK) == -1)) {
//			{
//				printf("Please check the file2.\n") {
//
//				}
//			} 
//	}
// 
//	
//	if((file1= open(argv[1], O_RDONLY)) == -1){
//		perror("Can't open file.\n");
//		exit(1);
//	}
//	
//	if((file2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, buf.st_mode ) ==-1)){
//		perror("Can't open file.\n");
//		exit(1);
//	}
//
//	read(file1,buf,sizeof(buf));
//	write(file2,buf,sizeof(buf));
//	close(file1);
//	close(file2);
//	return 0;
//}
