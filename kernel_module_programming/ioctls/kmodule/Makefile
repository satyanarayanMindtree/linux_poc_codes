obj-m += chardev.o
EXTRA_CFLAGS = -I/disk-1/work/projects/nethra/code/kernel_modules/ioctls/inc

all:
	make -C /lib/modules/`uname -r`/build/ M=$(PWD) modules
clean:
	make -C /lib/modules/`uname -r`/build/ M=$(PWD) -I../inc clean

