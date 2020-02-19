#include "uls.h"

void mx_sort_by_time(s_flags *fl, t_list *files, char *argv) {
	struct stat buf1;
    struct stat buf2;
    char *full_path1 = NULL;
    char *full_path2 = NULL;
    t_list *p = files;
    int i = mx_list_size(files);

    while (i > 0) {
    	while (p->next) {
            full_path1 = mx_strjoin_for_path(argv, p->data);
            full_path2 = mx_strjoin_for_path(argv, p->next->data);
            lstat(full_path1, &buf1);
            lstat(full_path2, &buf2);
            if (fl->t && !fl->u && !fl->c && !fl->U) {
                if (buf1.st_mtime < buf2.st_mtime)
                    mx_list_swap(p);
            }
            else if (fl->t && fl->u && !fl->c && !fl->U) {
                if (buf1.st_atime < buf2.st_atime)
                    mx_list_swap(p);
            }
            else if (fl->t && !fl->u && fl->c && !fl->U) {
                if (buf1.st_ctime < buf2.st_ctime)
                    mx_list_swap(p);
            }
            else if (fl->t && !fl->u && !fl->c && fl->U) {
                if (buf1.st_birthtime < buf2.st_birthtime)
                    mx_list_swap(p);
            }
            mx_strdel(&full_path1);
            mx_strdel(&full_path2);
            p = p->next;
        }
        i--;
        p = files;
    }
}
