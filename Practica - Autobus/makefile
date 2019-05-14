all: servidor_ncurses principal_l2 cliente

servidor_ncurses: servidor_ncurses.c comun.c definiciones.h comun.h
	cc servidor_ncurses.c comun.c -o servidor_ncurses -lncurses

principal_l2: principal_l2.c comun.c
	cc principal_l2.c comun.c -o principal_l2

cliente: cliente.c comun.c
	cc cliente.c comun.c -o cliente