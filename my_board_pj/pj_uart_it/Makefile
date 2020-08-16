#project name value
NAME  = uart_it
#input compl;ier of all.c
OBJS  = start.o main.o led.o delay.o clk.o bsp_int.o exti.o epit.o uart.o
#add the include path
VPATH =   ./              \
		  :./include/clk  \
		  :./include/delay\
		  :./include/led  \
		  :./include/env  \
		  :./include/int  \
		  :./include/exti \
		  :./include/epit \
		  :./include/uart \


$(NAME).bin:$(OBJS)
	arm-linux-gnueabihf-ld -Timx6u.lds  -o $(NAME).elf $^
	arm-linux-gnueabihf-objcopy -O binary -S $(NAME).elf $@
	arm-linux-gnueabihf-objdump -D -m arm $(NAME).elf > $(NAME).dis

%.o:%.c
	arm-linux-gnueabihf-gcc -nostdlib -fno-builtin -c  $< -o $@

%.o:%.S
	arm-linux-gnueabihf-gcc -nostdlib -fno-builtin -c  $< -o $@

clean:
	rm *.o *.elf *.dis $(NAME).bin 
