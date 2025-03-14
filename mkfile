spice2:
	f2c spice.f
        ape/cc -D_BSD_EXTENSION -I/usr/glenda/lib/f2c/include -L /usr/glenda/lib/f2c spice.c unix.c -lap -lf2c -o spice2

install:V:
	cp spice2 $home/bin/386

clean:V:
	rm -f spice2
	rm -f *.8
	rm -f *.o
	rm -f spice.c



