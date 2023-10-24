 void Lcd_Display();
 void First_Layout();
 void dec(int loc, int val);
 void inc(int loc, int val);
 
 sbit LCD_RS at RD1_bit;
 sbit LCD_EN at RD0_bit;
 sbit LCD_D4 at RC3_bit;
 sbit LCD_D5 at RC2_bit;
 sbit LCD_D6 at RC1_bit;
 sbit LCD_D7 at RC0_bit;

 sbit LCD_RS_Direction at TRISD1_bit;
 sbit LCD_EN_Direction at TRISD0_bit;
 sbit LCD_D4_Direction at TRISC3_bit;
 sbit LCD_D5_Direction at TRISC2_bit;
 sbit LCD_D6_Direction at TRISC1_bit;
 sbit LCD_D7_Direction at TRISC0_bit;

 char disp1[6]="", disp2[6]="";
 char m_dis1[4]="", m_dis2[4]="";
 char dx1[]="Max:";
 char dx2[]="Min:";
 char dx5[]="Temp:";
 char dx3[]="Set Max:";
 char dx4[]="Set Min:";
 short Max=40, Min=30;
 char i;
 char display1[5];
 char display2[5];
 char display3[8];
 int temp1,temp2,temp3,temp4,cnt;
 short t1,t2,t3,t4,f1,f2,f3,f4;
 float result, volt, tmp,fm;
void main() {
     int mode=0;
     trisb = 0b00000111;
     portb = 0b00000111;
     //me:: Port-C is not set as outbut previously
     trisc=0x00;
     portc=0x00;
     //me:: Port-A is not set as input previously
     trisa=0xff;   //Sensor input
     
     trisd =0x00;  //input button
     portd=0x00;
     
     lcd_init();
     lcd_cmd(_lcd_clear);
     lcd_cmd(_lcd_cursor_off);

     if(EEprom_Read( 0x02 ) == 0xff)  //initialization of initial value check in EEPROM
        EEPROM_Write(0x02,Min);
     if(EEprom_Read( 0x50 ) == 0xff)   //initialization  of Final check in EEPROM
        EEPROM_Write(0x50,Max);
     while(1)
     {
           //Run Mode Function
           if(mode==0)
           {
                delay_ms(250);
                First_Layout();
                /*
                Your Code Should be Inserted Here
                Code Hints: Control load depending average temperature
                */
                //me::
                 if(tmp>=Min && tmp<=Max){
                      portb.f6=0;
                      portb.f7=0;
                      portd.f2=0;
                      portd.f3=0;
                }
                else if(tmp<Min){
                      portb.f6=1;
                      portb.f7=1;
                      portd.f2=0;
                      portd.f3=0;
                }
                else{
                      portb.f6=0;
                      portb.f7=0;
                      portd.f2=1;
                      portd.f3=1;
                }
                //Status Change Btn press
                if(portb.f0==0)
                {
                    delay_ms(3000);
                    if(portb.f0==0)
                        mode=1;
                    Lcd_Cmd(_LCD_CLEAR);
                }
           }
           //Minimum Value Program Mode Function
           if(mode==1)
           {
                delay_ms(250);
                lcd_out(1,1,dx1);
                lcd_out(2,1,dx4);
                Lcd_Display();

                if(portb.f1==0)
                {
                    delay_ms(100);
                    if(portb.f1==0)
                         dec(0x02, Min);
                }
                if(portb.f2==0)
                {
                    delay_ms(100);
                    if(portb.f2==0)
                         inc(0x02, Min);
                }
                //Status Change Btn press
                if(portb.f0==0)
                {
                    delay_ms(3000);
                    if(portb.f0==0)
                        mode=2;
                    Lcd_Cmd(_LCD_CLEAR);
                    Lcd_Cmd(_LCD_FIRST_ROW);
                }
           }
           //Maximum Value Program Mode Function
           if(mode==2)
           {
                delay_ms(250);
                lcd_out(1,1,dx3);
                lcd_out(2,1,dx2);
                Lcd_Display();

                if(portb.f1==0)
                {
                    delay_ms(100);
                    if(portb.f1==0)
                         dec(0x50, Max);
                }
                if(portb.f2==0)
                {
                    delay_ms(100);
                    if(portb.f2==0)
                         inc(0x50, Max);
                }
                //Status Change Btn press
                if(portb.f0==0)
                {
                    delay_ms(3000);
                    if(portb.f0==0)
                        mode=3;
                    Lcd_Cmd(_LCD_CLEAR);
                    Lcd_Cmd(_LCD_FIRST_ROW);
                }
           }
           //All Temperatures display
           if(mode==3)
           {
                delay_ms(250);
                t1=(adc_read(0)*4.88)/10;
                t2=(adc_read(1)*4.88)/10;
                t3=(adc_read(2)*4.88)/10;
                t4=(adc_read(3)*4.88)/10;
                
                //Error Corresion
                t1=t1-12;
                t2=t2-12;
                t3=t3-12;
                t4=t4-12;

                bytetostr(t1,display3);
                lcd_out(1,1,"S1:");
                lcd_out(1,4,display3);
                bytetostr(t2,display3);
                lcd_out(1,10,"S2:");
                lcd_out(1,14,display3);
                bytetostr(t3,display3);
                lcd_out(2,1,"S3:");
                lcd_out(2,4,display3);
                bytetostr(t4,display3);
                lcd_out(2,10,"S4:");
                lcd_out(2,14,display3);

                //Status Change Btn press
                if(portb.f0==0)
                {
                    delay_ms(3000);
                    if(portb.f0==0)
                        mode=0;
                    Lcd_Cmd(_LCD_CLEAR);
                    Lcd_Cmd(_LCD_FIRST_ROW);
                }
           }
     }
}
void First_Layout()
{
     Max = EEprom_Read(0x50);
     bytetostr(Max,display1);
     lcd_out(1,1,dx1);
     lcd_out(1,5,display1);

     Min = EEprom_Read(0x02);
     bytetostr(Min,display2);
     lcd_out(1,10,dx2);
     lcd_out(1,14,display2) ;

     result=0,cnt=0;
     temp1=adc_read(0);
     temp2=adc_read(1);
     temp3=adc_read(2);
     temp4=adc_read(3);
     if(temp1>0){
         result+=temp1;
         cnt++;
     }
     if(temp2>0){
         result+=temp2;
         cnt++;
     }
     if(temp3>0){
         result+=temp3;
         cnt++;
     }
     if(temp4>0){
         result+=temp4;
         cnt++;
     }
     result=result/cnt;
     volt=result*4.88;
     tmp=volt/10;
     
     // Average Error correction
     tmp=tmp-12;
     floattostr(tmp,display3);
     lcd_out(2,1,dx5);
     lcd_out(2,8,display3);
}
void Lcd_Display()
{
     Max = EEprom_Read( 0x50 );
     bytetostr(Max,disp1);
     lcd_out(1,10,disp1);
     Min = EEprom_Read( 0x02 );
     bytetostr(Min,disp2);
     lcd_out(2,10,disp2);
}
void dec(int loc, int val)
{
     val = EEprom_Read( loc );
     delay_ms(20);
     if(val>0)
         val--;
     EEPROM_Write(loc,val);
}
void inc(int loc, int val)
{
     val = EEprom_Read( loc );
     delay_ms(20);
     if(val<99)
         val++;
     EEPROM_Write(loc,val);
}