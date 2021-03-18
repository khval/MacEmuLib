
p =../
incdir += -I ${p}${p}

libdir = -L ${p}${p}lib/

libs = -lMacEmu

deps = bullwindow.c 
deps += bullMenus.c

objs = ${deps:.c=.o}

name = bullseye.exe

opts = -D__USE_INLINE__

all:	$(objs)
	gcc ${incdir} ${libdir} $(opts) bullseye.c $(objs) $(libs) -o $(name)


%.o:	%.c
		gcc -c ${incdir} ${libdir} $(opts)  $< -o $@

clean:
	rm $(objs) $(name)