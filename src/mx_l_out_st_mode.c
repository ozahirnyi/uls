#include "uls.h"

void mx_l_out_st_mode(unsigned long n) {
	char prava[11];

	prava[1] = (n & S_IRUSR) == S_IRUSR ? 'r' : '-';
	prava[2] = (n & S_IWUSR) == S_IWUSR ? 'w' : '-';
	prava[3] = (n & S_IXUSR) == S_IXUSR ? 'x' : '-';
	prava[4] = (n & S_IRGRP) == S_IRGRP ? 'r' : '-';
	prava[5] = (n & S_IWGRP) == S_IWGRP ? 'w' : '-';
	prava[6] = (n & S_IXGRP) == S_IXGRP ? 'x' : '-';
	prava[7] = (n & S_IROTH) == S_IROTH ? 'r' : '-';
	prava[8] = (n & S_IWOTH) == S_IWOTH ? 'w' : '-';
	prava[9] = (n & S_IXOTH) == S_IXOTH ? 'x' : '-';
	if ((n & S_IFMT) == S_IFDIR) /* directory */
		prava[0] = 'd';
	else if ((n & S_IFMT) == S_IFLNK) /* link */
		prava[0] = 'l';
	else 
		prava[0] = '-';




// #define S_IRWXU  0000700  /* RWX mask for owner */
// 	#define S_IRUSR  0000400        /* R ead permission, owner */ 
// 	#define S_IWUSR  0000200        /* W rite permission, owner */
// 	#define S_IXUSR  0000100        /* X execute/search permission, owner */
// #define S_IRWXG  0000070  /* RWX mask for group */
// 	#define S_IRGRP  0000040        /* R ead permission, group */
// 	#define S_IWGRP  0000020        /* W rite permission, group */
// 	#define S_IXGRP  0000010        /* X execute/search permission, group */
// #define S_IRWXO  0000007  /* RWX mask for other */
// 	#define S_IROTH  0000004        /* R ead permission, other */
// 	#define S_IWOTH  0000002        /* W rite permission, other */
// 	#define S_IXOTH  0000001        /* X execute/search permission, other */
// 	if ((n & S_IFMT) == S_IFDIR) /* directory */
// 		mx_printstr("dir           ");
// 	if ((n & S_IFMT) == S_IFCHR) /* char special */
// 		mx_printstr("char spec     ");
// 	if ((n & S_IFMT) == S_IFBLK) /* block special */
// 		mx_printstr("block spec    ");
// 	if ((n & S_IFMT) == S_IFREG) /* regular file */
// 		mx_printstr("reg file      ");
// 	if ((n & S_IFMT) == S_IFIFO) /* fifo */
// 		mx_printstr("fifo          ");
// 	if ((n & S_IFMT) == S_IFLNK) /* symbolic link */
// 		mx_printstr("symbolic link ");
// 	if ((n & S_IFMT) == S_IFSOCK) /* socket */
// 		mx_printstr("socket        ");
    mx_printstr(prava);
    mx_printchar('\t');
}
