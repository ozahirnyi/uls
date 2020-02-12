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
	else if (f == 's')
		trig->s = 1;
}
