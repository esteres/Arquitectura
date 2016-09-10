/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */

#define T_DELAY		20000

int display [10] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x03, 0x78, 0x00, 0x18};


void PortInit(void){
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK; // Habilita el reloj para el módulo de control de puerto C
	PORTC_PCR0 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK; // configura el pin 0 para GPIO y como Drive Strength
	PORTC_PCR1 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK; // configura el pin 1 para GPIO y como Drive Strength 
	PORTC_PCR2 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK; // configura el pin 2 para GPIO y como Drive Strength 
	PORTC_PCR3 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK; // configura el pin 3 para GPIO y como Drive Strength 
	PORTC_PCR4 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK; // configura el pin 4 para GPIO y como Drive Strength 
	PORTC_PCR5 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK; // configura el pin 5 para GPIO y como Drive Strength 
	PORTC_PCR6 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK; // configura el pin 6 para GPIO y como Drive Strength 
	PORTC_PCR7 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK; // configura el pin 7 para GPIO y como Drive Strength 
	GPIOC_PDDR |=  0x000000FF; // configura los 8 pines menos significativos del puerto C como salida de datos

}


void Delay(int Ticks){
 int i;
 for(i=0;i<Ticks;i++) {}
}

void onDisplay(){
	int i; 
	GPIOC_PCOR = 0xFF;
	for(i=0; i<10; i++){
		
		GPIOC_PSOR = display[i];
		Delay(T_DELAY);
	}
}


int main(void){
	PortInit();
	onDisplay();
	return 0;
}




