all: myapp


#Which compiler
CC = gcc

#Where to install
#INSTDIR = /usr/local/bin
INSTDIR = ./installdir_tmp

#Where are include files kept
INCLUDE =

#Options for development
CFLAGS = -g -Wall -ansi

#Options for release
#CFLAGS = -O -Wall -ansi

#Local Libraries
MYLIB = mylib.a

myapp: main.o $(MYLIB)
	$(CC) -o myapp main.o $(MYLIB)

$(MYLIB): $(MYLIB)(2.o) $(MYLIB)(3.o)

main.o: main.c a.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c main.c

2.o: 2.c a.h b.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c 2.c

3.o: 3.c b.h c.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c 3.c

clean:
	-rm main.o 2.o 3.o $(MYLIB)

install: myapp
	@if [ -d $(INSTDIR) ];\
		then\
		cp myapp $(INSTDIR);\
		chmod a+x $(INSTDIR)/myapp;\
		chmod og-w $(INSTDIR)/myapp;\
		echo "Installed in $(INSTDIR)";\
		else\
		echo "Sorry, $(INSTDIR) does not exit";\
	fi


dist: myapp-1.0.tar.gz

myapp-1.0.tar.gz: myapp 
	-rm -rf myapp-1.0
	mkdir myapp-1.0
	cp *.o *.h *.c Makefile myapp-1.0
	tar acvf $@ myapp-1.0

