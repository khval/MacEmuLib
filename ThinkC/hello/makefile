
p =../
incdir += -I ${p}${p}
libdir = -L ${p}${p}lib/
libs = -lMacEmu

objs = ${deps:.c=.o}

name = hello
name_c = $(name).c
name_exe = $(name).exe

opts = -D__USE_INLINE__

all:	$(objs)
	gcc ${incdir} ${libdir} $(opts) $(name_c) $(libs) -o $(name_exe)


%.o:	%.c
		gcc -c ${incdir} ${libdir} $(opts) $< -o $@

clean:
	delete $(objs) $(name_exe)