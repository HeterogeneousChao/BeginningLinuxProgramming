all: application


INCLUDE=/usr/include/gdbm
#LIBS=gdbm
# On some distributions you may need to change the above line to include 
# the commpatability libaray, as show below

LIBS=gdbm_compat


#CFLAGS=
	app_ui.o: app_ui.c cd_data.h
#		gcc $(CFLAGS) -I$(INCLUDE) -c app_ui.c
		gcc -I$(INCLUDE) -c app_ui.c -lgdbm_compat -lgdbm

	
	access.o: access.c cd_data.h
#		gcc $(CFLAGS) -I$(INCLUDE) -c access.c
		gcc -I$(INCLUDE) -c access.c


	application: app_ui.o access.o
#		gcc $(CFLAGS) -o application app_ui.o access.o -l$(LIBS)
		gcc -o application app_ui.o access.o -l$(LIBS) -lgdbm


clean:
	rm -f application *.o

nodbmfiles:
	rm -f *.dir *.pag


