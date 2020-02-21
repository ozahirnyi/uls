#include "uls.h"

static bool mx_check_flag3(char f, s_flags *trig) {
	if (f == 'g')
		trig->g = 1;
	else if (f == 'T')
		trig->T = 1;
	else if (f == 'f')
		trig->f = 1;
	else if (f == 'p')
		trig->p = 1;
	else if (f == 'r')
		trig->r = 1;
	else if (f == 't')
		trig->t = 1;
	else
		return false;
	return true;
}

static bool mx_check_flag2(char f, s_flags *trig) {
	if (f == 'U'){
		trig->U = 1;
		trig->c = 0;
		trig->u = 0;
	}
	else if (f == 'c'){
		trig->U = 0;
		trig->c = 1;
		trig->u = 0;
	}
	else if (f == 'u'){
		trig->U = 0;
		trig->c = 0;
		trig->u = 1;
	}
	else
		return false;
	return true;
}

static bool mx_check_flag1(char f, s_flags *trig) {
	if (f == 'A')
		trig->A = 1;
	else if (f == 'a')
		trig->a = 1;
	else if (f == 'l')
		trig->l = 1;
	else if (f == 'o')
		trig->o = 1;
	else if (f == '1')
		trig->one = 1;
	else if (f == 'S')
		trig->S = 1;
	else
		return false;
	return true;
}

void mx_flags_trig(char f, s_flags *trig) {
	if (!mx_check_flag1(f, trig) && !mx_check_flag2(f, trig) 
		&& !mx_check_flag3(f, trig)) {
        mx_printerr("usage: ls [-ATSUalo1gtucfpr] [file ...]\n");
        exit(1);
    }
}
