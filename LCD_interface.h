#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
/* clock cycle is 62.5ns
 * Enable pin can't rise before 40ns from control pins change		ALREADY DONE
 * Enable must held HIGH for at least 230ns							DELAY REQUID
 * Enable can't fall before 80ns from data pins change				DELAY REQUID
 * Data pins and control can't change before 10ns after enable fall ALREADY DONE
 * Enable can't rise before 500ns after rise						DELAY REQUID
 *
 * First set control pins
 * Then set enable HIGH
 * Set data pins
 * Make 230ns delay
 * Set enable LOW
 * Make 500ns delay
 */

//Second argument in send function
#define insr 0
#define data 1
//End

//First argument in send function
#define Clear_Display 0x01
//Clear entire display and back cursor to home position

#define Return_Home 0x02
//Back cursor to home position and display from shifting

#define left 1
#define right 0
#define increase 1
#define decrease 0
#define cursor 0
#define display 1
#define Shift_Control(a,b) ((0x04)|(a<<1)|(b))
//Set cursor to move forward or backward or shift display right or left when writing data to lcd
//(a) specify if cursor or display go left or write
//(b) specify is the cursor or display shifting gone operated when write to display

#define Left_Once 0//Other define like Shift_Control
#define Right_Once 1
#define Shift_Once(a,b) ((0x10)|(b<<3)|(a<<2))
//Set cursor to move forward or backward or shift display right or left
//It take action immediately and once
//(a) specify if cursor or display go left or write
//(b) specify is the cursor or display shifting gone operated when write to display

#define Dis_On 1
#define Dis_Off 0
#define Cursor_On 1
#define Cursor_Off 0
#define Cursor_Blink 1
#define Cursor_Static 0
#define Display_Control(a,b,c) ((0x08)|(a<<2)|(b<<1)|(c))
//(a) Turn display on or off (1-0)
//(b) cursor on or off (1-0)
//(c) cursor blinking on or off (1-0)

#define DDRAM_Address(a,b) ((0x80)|(a + ((b==2) ? (63) : (-1))))
//Change address of DDRAM (used to change cursor address)
//(a) choose which char in display line to go (1-16)
//(b) choose which line to go (1-2)

#define CGRAM_Address(a,b) ((0x40)|((a)&(0x38))|((b)&(0x07)))
//Change address of CGRAM (used to write created char to any display address)
//(a) choose CGRAM char you ant to draw in (0-8)
//(b) choose which line in char you want to draw in (0-8)

#define CG_Char_1 0x00
#define CG_Char_2 0x01
#define CG_Char_3 0x02
#define CG_Char_4 0x03
#define CG_Char_5 0x04
#define CG_Char_6 0x05
#define CG_Char_7 0x06
#define CG_Char_8 0x07
//end


#define bit0 4
#define bit1 5
#define bit2 6
#define bit3 7

#define enable 3
#define rw 4
#define rs 1


void Lcd_Init(void);//lcd initial

void Lcd_Cmd(u8 data_r, u8 data_type);//First argument is data to send  Second is instructure or data (0-1)

u8 Lcd_Busy(void);//read busy flag

void Lcd_Print(u8 *string );//Print on lcd

void CG_Char_Write(u8 *CG_Char, u8 Char_Num);//Save a character generated to ram of lcd
//First argument is array of char [8] that have draw of character
//Second argument is which CG char you want to save in (1-8)

void Lcd_Print_num(u16 num);

#endif /* LCD_INTERFACE_H_ */
