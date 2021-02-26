/*
 * File:   main.c
 * Author: 21192692
 *
 * Created on 24 de Fevereiro de 2021, 14:05
 */


#include <xc.h>
#include "config.h"
#include "delay.h"
#include "disp7seg.h"
#include "botoes.h"


void main(void) 
{
    char estado = 0;
     d7seg.init();
     botoes_init();
        
    while ( 1 )
    {   
        switch (estado)
        {
            case 0:
                estado = 1;
                break;
             
        
            case 1:
                if (adicionar() == 1 );
                    estado = 2;
                    break;
             
            case 2:
               if (adicionar() == 0 );
               estado = 3;
                break;
                
            case 3: 
                ++cont;
                estado = 0;
                break;        
                       
        }
        d7seg.print(cont);
        
        if( cont >= 10)
            cont = 0;
        if( cont < 0)
            cont = 9;
                      
    }
}
