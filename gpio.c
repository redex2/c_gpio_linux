#include "gpio.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int gpio_init(unsigned int pin_number, char *mode)
{
	char str_pin[4];
	sprintf(str_pin, "%d", pin_number);
	
	int fd_gpio;
	
	if((fd_gpio = open("/sys/class/gpio/export", O_WRONLY)) == -1) return -1;
	if(write(fd_gpio, str_pin, strlen(str_pin))!=strlen(str_pin)) return -2;
	close(fd_gpio);
	
	char direction[59];
	sprintf(direction, "/sys/class/gpio/gpio%s/direction", str_pin);
	if((fd_gpio = open(direction, O_WRONLY)) == -1) return -3;
	if(write(fd_gpio, mode, strlen(mode))!=strlen(mode)) return -4;
	close(fd_gpio);
	return 0;
}
int gpio_mode(unsigned int pin_number, char *mode)
{
	char str_pin[4];
	sprintf(str_pin, "%d", pin_number);
	int fd_gpio;
	
	char direction[59];
	sprintf(direction, "/sys/class/gpio/gpio%s/direction", str_pin);
	if((fd_gpio = open(direction, O_WRONLY)) == -1) return -1;
	if(write(fd_gpio, mode, strlen(mode))!=strlen(mode)) return -2;
	close(fd_gpio);
	return 0;
}
int gpio_read(unsigned int pin_number)
{
	char str_pin[4];
	sprintf(str_pin, "%d", pin_number);
	int fd_gpio;
	
	char value=255;
	char v_f[49];
	sprintf(v_f, "/sys/class/gpio/gpio%s/value", str_pin);
	if((fd_gpio = open(v_f, O_RDONLY)) == -1) return -1;
	if(read(fd_gpio, &value, 1)!=1) return -2;
	close(fd_gpio);
	return value-48;
}

int gpio_set(unsigned int pin_number, bool value)
{
	char v[1];
	sprintf(v, "%d", value);
	
	char str_pin[4];
	sprintf(str_pin, "%d", pin_number);
	int fd_gpio;
	
	char v_f[49];
	sprintf(v_f, "/sys/class/gpio/gpio%s/value", str_pin);
	if((fd_gpio = open(v_f, O_WRONLY)) == -1) return -1;
	if(write(fd_gpio, v, strlen(v))!=strlen(v)) return -2;
	close(fd_gpio);
	return 0;
}