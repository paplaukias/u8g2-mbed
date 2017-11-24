#include "mbed.h"
#include "u8g2.h"

DigitalOut led(D13);

uint8_t u8x8_gpio_and_delay_stm32f4(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);
u8g2_t myScreen;

void setup() {
  u8g2_Setup_ssd1306_i2c_128x64_noname_f(&myScreen, U8G2_R0, u8x8_byte_sw_i2c, u8x8_gpio_and_delay_stm32f4);
  u8g2_InitDisplay(&myScreen);
  u8g2_SetPowerSave(&myScreen, 0);
  u8g2_ClearBuffer(&myScreen);

  u8g2_SetFont(&myScreen, u8g2_font_freedoomr10_tu);
  u8g2_DrawUTF8(&myScreen, 0, 12, "NECTARSUN");
  u8g2_SetFont(&myScreen, u8g2_font_amstrad_cpc_extended_8f);
  u8g2_DrawUTF8(&myScreen, 0, 24, "ačiū");
  u8g2_SetFont(&myScreen, u8g2_font_b10_t_japanese1);
  u8g2_DrawUTF8(&myScreen, 0, 34, "こんにちは世界");
  u8g2_SetFont(&myScreen, u8g2_font_unifont_t_chinese2);
  u8g2_DrawUTF8(&myScreen, 0, 54, "你好世界");

  u8g2_SendBuffer(&myScreen);
}

int main() {
  led = 0;
  // printf("Hello world");
  setup();
  
  while(1) {
    led = !led;
    wait(1.0);
  }
  return 0;
}