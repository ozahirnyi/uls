#include "uls.h"

void mx_flags_trig(char f, s_flags *trig) {
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
	else if (f == 'g')
		trig->g = 1;
	else if (f == 'T')
		trig->T = 1;
	else if (f == 't')
		trig->t = 1;
	else if (f == 'u')
		trig->u = 1;
	else if (f == 'U')
		trig->U = 1;
	else if (f == 'c')
		trig->c = 1;
	else if (f == 'f')
		trig->f = 1;
	else if (f == 'S')
		trig->S = 1;
	else if (f == 'p')
		trig->p = 1;
	else if (f == 'r')
		trig->r = 1;
}
