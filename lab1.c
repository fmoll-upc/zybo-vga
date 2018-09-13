/*
 * lab1.c demo code
 *
 *  Created on: 13/09/2018
 *      Author: francesc.moll
*/



#include "xparameters.h"
#include "xgpio.h"


//====================================================

int main (void)
{

// Pointer and variable declaration
    XGpio xpos, push, leds;
	int i, psb_check;

    xil_printf("-- Start of the Program --\r\n");

// Pointer initialization
// Check out your own XPAR ID symbol name declared in xparameters.h
// The format is always XPAR_<NAME_IN_VIVADO>_DEVICE_ID


	XGpio_Initialize(&push, XPAR_BUTTONS_DEVICE_ID);
	XGpio_SetDataDirection(&push, 1, 0xffffffff); //input

	XGpio_Initialize(&leds, XPAR_LEDS_DEVICE_ID);
	XGpio_SetDataDirection(&leds, 1, 0x00000000); //output

	XGpio_Initialize(&xpos, XPAR_XPOS_DEVICE_ID);
	XGpio_SetDataDirection(&xpos, 1, 0x00000000); //output

	while (1)
	{
// Read value of buttons
	  psb_check = XGpio_DiscreteRead(&push, 1);

	  xil_printf("Push Buttons Status %x\r\n", psb_check);


// Write value of buttons to leds
	  XGpio_DiscreteWrite(&leds, 1, psb_check);

// Write value of buttons to xpos (example)
	  XGpio_DiscreteWrite(&xpos, 1, psb_check<<1);

	  // Waiting cycles
	  for (i=0; i<9999999; i++);
	}

}
