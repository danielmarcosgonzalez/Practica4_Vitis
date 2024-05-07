/******************************************************************************
* Copyright (C) 2023 Advanced Micro Devices, Inc. All Rights Reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/
/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xgpio.h"

XGpio sw_gpio, led_gpio;

void init_driver(){

  int status;
   status = XGpio_Initialize(&sw_gpio,XPAR_GPIO_SW_DEVICE_ID);
   
  if(status!=XST_SUCCESS){
     print("Failed to initialize switch gpio. In\r");
  }else{
    print("Initialized switch gpioln/r");
    XGpio_SetDataDirection(&sw_gpio, 1,1);
  }

   status = XGpio_Initialize(&led_gpio,XPAR_GPIO_LED_DEVICE_ID);
   if(status!=XST_SUCCESS) {
    print("Failed to initialize led gpio. \n\r");

   }else{
    print ("Initialized led gpio\n\r");
    XGpio_SetDataDirection (&led_gpio, 1,0);
    XGpio_DiscreteWrite(&led_gpio, 1,0);
  }

}

int main (){

    int sw_val;


    init_platform();
    init_driver();
    print ("Hello World\n\r");
    print("Successfully ran Hello World application");
    
   while (1){

     sw_val= XGpio_DiscreteRead(&sw_gpio,1);
     switch (sw_val){

      case 0:
        XGpio_DiscreteWrite(&led_gpio, 1, 0x0); 
        break;

      case 1:
        XGpio_DiscreteWrite(&led_gpio, 1, 0x1);
        break;

     case 2:
        XGpio_DiscreteWrite(&led_gpio, 1, 0x2);
        break;
     case 3:
        XGpio_DiscreteWrite(&led_gpio, 1, 0x3);
        break;
         case 4:
        XGpio_DiscreteWrite(&led_gpio, 1, 0x4);
        break;
         case 5:
        XGpio_DiscreteWrite(&led_gpio, 1, 0x5);
        break;
         case 6:
        XGpio_DiscreteWrite(&led_gpio, 1, 0x6);
        break;
         case 7:
        XGpio_DiscreteWrite(&led_gpio, 1, 0x7);
        break;
      
     

      }


}


    cleanup_platform();
    return 0;


}

