# @author Victor Woo
# @sid          430323825
# This makefile is to compile any new changes to the host dispatcher so it is up to date

hostd: hostd.c pcb.c mab.c rsrc.c
	gcc -Wall -g -std=gnu99 -pedantic hostd.c pcb.c mab.c rsrc.c -o hostd
