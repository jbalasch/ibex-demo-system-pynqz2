// Copyright lowRISC contributors.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

#include <stdio.h>

#include "demo_system.h"
#include "timer.h"

#include "common.h"
#include "aes-ip-top.h"
#include "gf_256.h"

void test_uart_irq_handler(void) __attribute__((interrupt));

void test_uart_irq_handler(void) {
  int uart_in_char;

  while ((uart_in_char = uart_in(DEFAULT_UART)) != -1) {
    uart_out(DEFAULT_UART, uart_in_char);
    uart_out(DEFAULT_UART, '\r');
    uart_out(DEFAULT_UART, '\n');
  }
}

// Global variables
// ---------------------
uint8_t key[16] = {
	0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c
};

uint8_t pt[16] = {
	0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34
};

uint8_t ct[16] = {0x00};

void putbyte(uint8_t h) {
  int cur_digit;
  // Iterate through h taking top 4 bits each time and outputting ASCII of hex
  // digit for those 4 bits
  for (int i = 0; i < 2; i++) {
    cur_digit = h >> 4;

    if (cur_digit < 10)
      putchar('0' + cur_digit);
    else
      putchar('A' - 10 + cur_digit);

    h <<= 4;
  }
}

int main(void) 
{
  int i;

  install_exception_handler(UART_IRQ_NUM, &test_uart_irq_handler);
  uart_enable_rx_int();

  // This indicates how often the timer gets updated.
  timer_init();
  timer_enable(50000000);

  uint64_t last_elapsed_time = get_elapsed_time();

  unsigned int a1,a2 = 0;
  char buf[32];
  
  /*uint8_t src1 = 0xFE;
  uint8_t src2 = 0x34;
  uint8_t dst; 
  uint8_t dst2;
  
  a1 = get_mcycle();
  for(i=0; i<100; i++)
    gf256Multiply(&dst, src1, src2);
  a2 = get_mcycle();
  snprintf(buf, 32, "cycles: %10d", (a2-a1)/100);

  puts("GFMUL (SW): ");
  puts(buf);
  putchar('\n');
  putbyte(dst);
  putchar('\n');

  a1 = get_mcycle();
  for(i=0; i<100; i++)
    gfmul_hw(&dst2, src1, src2);
  a2 = get_mcycle();
  snprintf(buf, 32, "cycles: %10d", (a2-a1)/100);
  
  puts("GFMUL (HW): ");
  puts(buf);
  putchar('\n');
  putbyte(dst2);
  putchar('\n');

  while(1);*/
  
  while(1) {
    uint64_t cur_time = get_elapsed_time();

    if (cur_time != last_elapsed_time) {
      last_elapsed_time = cur_time;

      // Disable interrupts whilst outputting to prevent output for RX IRQ
      // happening in the middle
      set_global_interrupt_enable(0);

      // Print this to UART (use the screen command to see it).
      puts("Hello Inner-Product AES: ");

      // Re-enable interrupts with output complete
      set_global_interrupt_enable(1);

      // Do AES
      a1 = get_mcycle();
      aes_ip_enc(&ct[0], &pt[0], &key[0]);
      a2 = get_mcycle();
      snprintf(buf, 32, "cycles: %10d", (a2-a1));
      
      // Output result:
      for(i=0; i<16; i++)
        putbyte(ct[i]);
      putchar('\n');
      puts(buf);
      putchar('\n');
    }
    asm volatile ("wfi");
  }
}
