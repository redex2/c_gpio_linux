#ifndef GPIO_H
#define GPIO_H

#define LOW 0
#define HIGH 1
static char INPUT[] = "in";
static char OUTPUT[] = "out";

int gpio_init(unsigned int pin_number, char *mode);
int gpio_mode(unsigned int pin_number, char *mode);
int gpio_read(unsigned int pin_number);
int gpio_set(unsigned int pin_number, bool value);

#endif