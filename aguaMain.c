//main.c File 
#include <16F887.h> 
#use delay(crystal=4000000)//Set frequency at 4Mhz 
#include <C_LCD.h>//2x16 Character LCD driver 
#include <DS1302.h>

void bem_vindo(){
   lcd_putc('\f'); 
   lcd_gotoxy(1,1); 
   printf(lcd_putc,"   Bem vindo"); 
   delay_ms(700);
   lcd_putc('\f'); 
}

void main() {
   char hora, min, seg;
   
   lcd_init(); 
   bem_vindo();
   rtc_init(); 
   rtc_set_datetime(4,4,21,1,8,53);
   
   setup_adc(  ADC_CLOCK_INTERNAL  );   
   setup_adc_ports( sAN0 );   
   set_adc_channel(0);
   
   while ( 1 ) {         
      lcd_gotoxy(1,1);
      printf(lcd_putc, "A/D value = %2u", read_adc());  
      
      lcd_gotoxy(1,2);
      rtc_get_time(hora, min, seg);
      printf(lcd_putc,"Hora: %02u:%02u:%02u",hora,min,seg);
            
      delay_ms(1000);      
      lcd_putc('\f'); 
   }            
}
