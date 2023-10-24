# Poultry-Firm-Automation-System



### FOR MORE UNDERSTAND, DOWNLODE THE DOCX FILE AND READ IT......

SYMMETRIC DESCRIPTION

First of all, we were taking the environment temperature using a temperature sensor LM-35. We were used four sensor for finding four different places temperature of the poultry farm such that we did catch the approximate temperature of the poultry farm. Then we calculated average temperature of those four temperature values. We were select two threshold values using two button as button-1 and button-2. Button-1 was used to increase minimum/maximum threshold value and Button-2 was used to decreased the minimum/maximum threshold value. With respect to the average temperature and two threshold, the objects will shift on into off or off into on. The objects can be fans, lights, motors, generator, alarm, air conditioner etc. 

The whole system information was displayed on the LCD (16 X 2) display. For showing the information of the system, we were use three different stage. For changing the stage, We used a button called button-3

PSEUDO CODE:

Declaration part;
Set microcontroller pin to set lcd display pin;

Main function() {
       Clear LCD display;
       Set input / output port with objects;
       Set constant value into EEPROM;
       
      While loop (1){
             If(mode==0){
                 First_Layout();
                 Decision making temperature was where;
                 Stage change;
            }
            If(mode==1){
                 LCD_display();
                 Set minimum threshold value;
                 DEC();
                 INC();
                 Stage change;
           }
           If(mode==2){
                 LCD_display();
                 Set maximum threshold value;
                 DEC();
                 INC();
                 Stage change;
           }
           If(mode==3){
            All sensor value is displayed on the lcd display;
            Stage change; 
           } 
     }
}

First Layout(){
    Read all sensor value;
    Measure average temperature;
    Display on the LCD display;
}

LCD_display(){
    Display minimum threshold value;
    Display maximum threshold value;
}
DEC(){
    Decreased the value;
    And return;
}
INC(){
    Increase the value;
    And return;
}

