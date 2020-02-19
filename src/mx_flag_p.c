#include "uls.h"

void mx_flag_p(t_list *files, s_flags *fl, char *argv) {
	struct stat buf;
    char *full_path = NULL;
    t_list *p = files;
    char *buffer = NULL;

    if (fl->X) {
        while (p) {
            full_path = mx_strjoin_for_path(argv, p->data);
            lstat(full_path, &buf);
            if ((buf.st_mode & S_IFDIR) == S_IFDIR) {
            	buffer = mx_strdup(p->data);
            	free(p->data);
            	p->data = mx_strjoin(buffer, "/");
            }
            mx_strdel(&full_path);
            mx_strdel(&buffer);
            p = p->next;
        }
    }
}
