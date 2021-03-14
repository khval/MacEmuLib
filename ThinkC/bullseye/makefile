
p =../
incdir = -I ${p}${p}shockmac/ShockMac/Libraries/
incdir += -I ../

libdir = -I ${p}${p}shockmac/ShockMac/LIB/

deps = bullwindow.c 
deps += ${p}emuMac.c

objs = ${deps:.c=.o}

name = bullseye.exe

opts = -D__USE_INLINE__

all:	$(objs)
	gcc ${incdir} ${libdir} $(opts) bullseye.c $(objs) -o $(name)


%.o:	%.c
		gcc -c ${incdir} ${libdir} $(opts) $< $(libs) -o $@

clean:
	rm $(objs) $(name)