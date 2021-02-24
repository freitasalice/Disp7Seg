/*
 * File:   disp7seg.c
 * Author: 21192692
 *
 * Created on 24 de Fevereiro de 2021, 15:47
 */


#include <xc.h>
#include "config.h"


void disp7seg_init (void)
{
    TRISD = 0x00;
    PORTD = 0x00;  
}

void display7seg (int c)
{
    PORTD = c;
}