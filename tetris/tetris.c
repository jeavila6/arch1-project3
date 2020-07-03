#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>

const short bgColor = COLOR_BLACK;
const short fgColor = COLOR_WHITE;

void main() {
  configureClocks();
  lcd_init();
  enableWDTInterrupts();
  or_sr(0x8);
  clearScreen(bgColor);
  
  drawString5x7(0, 0, "tetris", fgColor, bgColor);
}

/* watchdog timer interrupt handler */
void wdt_c_handler() {
  static short count = 0;
  count++;
  if (count == 15) { /* 15 interrupts/sec */
    count = 0;
  }
}
