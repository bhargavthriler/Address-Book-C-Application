SRCS = $(wildcard *.c)
TRGT = ../Library/libaddress.so
IFLAG = -I../Include

${TRGT} : ${SRCS}
	gcc -fPIC -shared ${IFLAG} $^ -o $@

clean :
	rm ${TRGT}
