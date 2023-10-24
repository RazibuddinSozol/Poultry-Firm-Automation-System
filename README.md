# Poultry-Firm-Automation-System



### MORE UNDERSTAND DOWNLODE THE DOCX FILE AND READ IT......
  SYMMETRIC DESCRIPTION

First of all, we were taking the environment temperature using a temperature sensor LM-35. We were used four sensor for finding four different places temperature of the poultry farm such that we did catch the approximate temperature of the poultry farm. Then we calculated average temperature of those four temperature values. We were select two threshold values using two button as button-1 and button-2. Button-1 was used to increase minimum/maximum threshold value and Button-2 was used to decreased the minimum/maximum threshold value. With respect to the average temperature and two threshold, the objects will shift on into off or off into on. The objects can be fans, lights, motors, generator, alarm, air conditioner etc. 

The whole system information was displayed on the LCD (16 X 2) display. For showing the information of the system, we were use three different stage. For changing the stage, We used a button called button-3. The stages are discuss below.   

Stage-1: In stage-1, we were showing the maximum (Max) and minimum (Min) threshold values lying on first row. And the calculated average temperature (Temp) value was shown in the second row. As given the figure. If we want to change threshold value, we will change the stage pressed by button-3 and hold on exact 3second. After 3 second the stage was changed and gone to second stage.










Figure-3.1: showing max, min and temp value on LCD display
Stage-2: In stage-2, we were setting the minimum threshold value by clicking button button-1 and button-2. If we clicked button-1 , the minimum threshold value was increased one by one. If we clicked button-2, the minimum threshold value was decreased one by one. If we want to change the maximum threshold value, we would be changed the stage to press the button-3 and hold on exact 3 second. After 3 second the stage was changed and gone to third stage.











Figure-3.2: set minimum threshold value

Stage-3: In this stage, we were setting the maximum threshold value by clicking button button-1 and button-2. If we clicked button-1, the maximum threshold value was increased one by one. If we clicked button-2, the maximum threshold value was decreased one by one. we would be changed the stage to press the button-3 and hold on exact 3 second. After 3 second the stage was changed and gone to fourth stage.








Figure-3.3: Set maximum threshold value
Stage-4 : In this stage, the four temperature sensor LM35 values were displayed. For this case , we understood which sensor was giving a exact room temperature and which sensor was damaged. We were showing s1, s2, s3, s4 to indicate the sensor-1, sensor-2, sensor-3 and sensor-4 respectively. Then we pressed and hold on 3-second the button -3.the program stage was return back to the satge-1. And changed the threshold value then relay act with respect to this value.   










Figure-3.4: Displaying four input temperature value















3.2:  CIRCUIT DIAGRAM
The circuit diagram is arranged on the proteus-8 professional software. All the components were available in that software. All components were well suit such as microcontroller clock frequency is 8MHz. Crystal oscillator clock frequency 8MHz, capacitor 22pF etc, A block diagram of this system is shown below.


Figure-3.5: Circuit diagram

3.3: PSEUDO CODE

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

