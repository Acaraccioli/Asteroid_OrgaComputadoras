#include "system.h"

uint16_t vgafb[VGAFB_SIZE]; // VGA frame buffer
uint8_t foreground;
uint8_t background;
uint8_t rows;
uint8_t columns;

/*
  TODO implement the following functions:
  clear_screen
  set_cursor
  set_color
  get_cursor
  put_char
*/




void set_cursor(uint8_t row, uint8_t column) {
rows=row;
columns= column;
}

void get_cursor(uint8_t *row, uint8_t *column) {

row=&rows;
column=&columns;
}

void set_color(uint8_t fgcolor, uint8_t bgcolor) {
 background=bgcolor;
 foreground=fgcolor;
}

void put_char(uint8_t ch) {

 if(ch == '\n'){
    rows = rows + 0x1;
        columns = 0x0;    
     }
   else{
    uint16_t data = (((background<<4)|foreground)<<8)| ch;
    uint16_t *vgapfb = (uint16_t *)(((((rows*ROW_COUNT)*0x2)+(columns)*0x2))+VGA_START_ADDR);
    *vgafb = data;
        if(columns == COL_COUNT){//lega al fin de la columna
            rows = rows + 0x1;
            columns = 0x0;
        }
        else{//le suma a la columna
            columns = columns + 0x1;
        }
     }

}
void clear_screen() {
  set_cursor(0x0,0x0);
  for(int i=0; i<VGAFB_SIZE; i++)
  {
    put_char(' ');
  }
  //set_cursor(0x0,0x0);
}









