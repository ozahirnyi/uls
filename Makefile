NAME = uls

FILES = main \
		mx_flag_l \
		mx_l_out_st_mode \
		mx_l_out_st_nlink \
		mx_l_out_st_uid \
		mx_l_out_st_gid \
		mx_l_out_st_size \
		mx_l_out_st_mtime \
		mx_read_uls \
		mx_print_uls \
		mx_longest_name \

LIBMX_A = libmx/libmx.a

SRC_PREFFIX = $(addprefix "src/", $(FILES))

HEADER = inc/uls.h

DEL_SRC = $(addsuffix ".c", $(FILES))

SRC = $(addsuffix ".c", $(SRC_PREFFIX))

SRC_COMPILE = $(addsuffix ".c", $(FILES))

OBJ = $(addsuffix ".o", $(FILES))

CFLAGS = -std=c11 -Werror -Wall -Wextra -Wpedantic

LIB_A = libmx.a

all: install

install:
	@make -C libmx install
	@cp $(HEADER) .
	@cp $(SRC) .
	@cp $(LIBMX_A) .
	@clang $(CFLAGS) -c $(SRC_COMPILE)
	@clang $(CFLAGS) $(OBJ) $(LIB_A) -o $(NAME)
	@mkdir -p obj
	@cp $(OBJ) obj/
	@rm -rf $(OBJ)

uninstall: clean
	@make -C libmx uninstall
	@rm -rf $(NAME)

clean:
	@make -C libmx clean
	@rm -rf obj
	@rm -rf $(DEL_SRC)
	@rm -rf $(OBJ)
	@rm -rf $(LIB_A)
	@rm -rf uls.h

reinstall: uninstall install
