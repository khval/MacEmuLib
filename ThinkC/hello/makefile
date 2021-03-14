
p =../
incdir = -I ${p}${p}shockmac/ShockMac/Libraries/
incdir += -I ../

libdir = -I ${p}${p}shockmac/ShockMac/LIB/

deps += ${p}emuMac.c

objs = ${deps:.c=.o}

name = hello
name_c = $(name).c
name_exe = $(name).exe

opts = -D__USE_INLINE__

all:	$(objs)
	gcc ${incdir} ${libdir} $(opts) $(name_c) $(objs) -o $(name_exe)


%.o:	%.c
		gcc -c ${incdir} ${libdir} $(opts) $< $(libs) -o $@

clean:
	delete $(objs) $(name_exe)