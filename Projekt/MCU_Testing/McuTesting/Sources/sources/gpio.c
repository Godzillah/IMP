#include "../libs/gpio.h"

/**
 * author: (c) 2019 Michal Bidlo, BUT FIT, bidlom@fit.vutbr.cz
 */
void initClockAndPins(void)
{
	// clock settings + turning watchdog off
    MCG_C4 |= ( MCG_C4_DMX32_MASK | MCG_C4_DRST_DRS(0x01) );
    SIM_CLKDIV1 |= SIM_CLKDIV1_OUTDIV1(0x00);
    WDOG_STCTRLH &= ~WDOG_STCTRLH_WDOGEN_MASK;

    // turn on all clock ports
    SIM->SCGC5 = SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTE_MASK | SIM_SCGC5_PORTA_MASK;

    // set the LEDs
    PORTB->PCR[5] = PORT_PCR_MUX(0x01); // D9
    PORTB->PCR[4] = PORT_PCR_MUX(0x01); // D10
    PORTB->PCR[3] = PORT_PCR_MUX(0x01); // D11
    PORTB->PCR[2] = PORT_PCR_MUX(0x01); // D12

    PORTE->PCR[10] = PORT_PCR_MUX(0x01); // SW2
    PORTE->PCR[12] = PORT_PCR_MUX(0x01); // SW3
    PORTE->PCR[27] = PORT_PCR_MUX(0x01); // SW4
    PORTE->PCR[26] = PORT_PCR_MUX(0x01); // SW5
    PORTE->PCR[11] = PORT_PCR_MUX(0x01); // SW6

    PORTA->PCR[4] = PORT_PCR_MUX(0x01);  // Speaker

    // change PTB as outputs to logic 1
    PTB->PDDR = GPIO_PDDR_PDD(0x3C);     // LED ports as outputs
    PTA->PDDR = GPIO_PDDR_PDD(SPK);     // Speaker as output
    PTB->PDOR |= GPIO_PDOR_PDO(0x3C);    // turn all LEDs OFF
    PTA->PDOR &= GPIO_PDOR_PDO(~SPK);   // Speaker off, beep_flag is false
}

void clockAndPinsExample() {
	initClockAndPins();

	while (1) {
		if ((GPIOE_PDIR & BTN_SW5) == 0) {
			GPIOA_PDOR ^= SPK;   // beep
		} else {
			GPIOA_PDOR &= ~SPK; // do not beep
		}

		if ((GPIOE_PDIR & BTN_SW3) == 0) {
			GPIOB_PDOR ^= LED_D9;                // turn on Diode 9 state
			GPIOB_PDOR ^= LED_D10;               // turn on Diode 10 state
			GPIOB_PDOR ^= LED_D11;               // turn on Diode 11 state
			GPIOB_PDOR ^= LED_D12;               // turn on Diode 12 state
		} else if ((GPIOE_PDIR & BTN_SW4) == 0){
			printf("\r\n[IMPORTANT] - You clicked on LEFT BUTTON");
		} else if ((GPIOE_PDIR & BTN_SW2) == 0) {
			printf("\r\n[IMPORTANT] - You clicked on RIGHT BUTTON");
		}
		sleep(1000);
	}
}
