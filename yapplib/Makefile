GCCFLAGS= -g
ID="$Id: Makefile,v 2.0 1997/01/12 16:51:02 quique Exp quique $"
REVISION="2.1"
OBJECTS=dataentity.o datastream.o datatype.o yappiserver.o \
        dataevent.o datatick.o yappiclient.o

all: libyappi.so

# Construir la dinamica
libyappi.so: $(OBJECTS) Makefile
	gcc -fPIC -shared -Wl,-soname,libyappi.so.1 \
                   -o libyappi.so.1.0 $(OBJECTS)

clean:
	rm -f *.o   

distr:	clean
