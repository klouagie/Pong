/*
 * File:   video.c
 * Author: kjell.louagie
 *
 * Created on September 27, 2023, 9:50 AM
 */

/*
 * Basic draw functions
 */

#include "video.h"
#include "signalgeneration.h"
#include <stdio.h>
#include "math.h"


#define showpixel asm volatile("MOV    [W0], W9" ); \
    asm("MOV    W9, PORTB"); \
    asm("MOV    W9, PORTC"); \
    asm("INC2   W0, W0");
#define show8pixels showpixel showpixel showpixel showpixel showpixel showpixel showpixel showpixel


#define showBackgroundPixel asm("MOV    W0, PORTB"); \
    asm("MOV    W0, PORTC"); \
    asm("nop"); \
    asm("nop"); \
    asm("nop");
#define showBackgroundLine showBackgroundPixel; showBackgroundPixel; showBackgroundPixel; showBackgroundPixel; showBackgroundPixel; showBackgroundPixel; showBackgroundPixel; showBackgroundPixel;



void drawBackground(uint16_t color)
{
     asm("nop"); \
     asm("nop"); \
     asm("nop"); \
     asm("nop"); \
     asm("nop"); \
     asm("nop");
    showBackgroundLine; showBackgroundLine; showBackgroundLine; showBackgroundLine; showBackgroundLine; showBackgroundLine; showBackgroundLine; showBackgroundLine; showBackgroundLine; showBackgroundLine;
    PORTC = 0;
    _LATB9 = 0;
}

void drawLine(const uint16_t *address)
{
    show8pixels show8pixels show8pixels show8pixels show8pixels show8pixels show8pixels show8pixels show8pixels show8pixels
    _LATB9 = 0;
    asm("nop");
    PORTC = 0;
}