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
    signed char cont = 0;
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
                if (adicionar() == 1 )
                    estado = 3;
                if (subtrair() == 1)
                    estado = 4;               
                    break;
             
            case 2:
               if (adicionar() == 0 && subtrair() ==0)
                   estado = 0;
                   break;
                
            case 3:
                if ( cont < 9 )
                    ++cont;
                else                    
                    cont = 0;
                estado = 2;
                break;
                
            case 4:
                if ( cont > 0)
                    --cont;
                else
                    cont = 9;
                estado = 2;
                break;
                                                          
        }
               
               d7seg.print(cont);
    }
}
