#include "FIREFLY.h"
#include <inttypes.h>
#if defined(ARDUINO) && ARDUINO >= 100

#include "Arduino.h"
#include <SoftwareSerial.h>

#define printIIC(args)	Wire.write(args)
inline size_t LCD_I2C::write(uint8_t value) {
	send(value, Rs);
	return 1;
}

#else
#include "WProgram.h"

#define printIIC(args)	Wire.send(args)
inline void LCD_I2C::write(uint8_t value) {
	send(value, Rs);
}

#endif
#include "Wire.h"



// When the display powers up, it is configured as follows:
//
// 1. Display clear
// 2. Function set: 
//    DL = 1; 8-bit interface data 
//    N = 0; 1-line display 
//    F = 0; 5x8 dot character font 
// 3. Display on/off control: 
//    D = 0; Display off 
//    C = 0; Cursor off 
//    B = 0; Blinking off 
// 4. Entry mode set: 
//    I/D = 1; Increment by 1
//    S = 0; No shift 
//
// Note, however, that resetting the Arduino doesn't reset the LCD, so we
// can't assume that its in that state when a sketch starts (and the
// LiquidCrystal constructor is called).

SPEED::SPEED(int pin) {
	pinMode(pin, OUTPUT);
	_pin = pin;
}
void SPEED::setSpeed(int speed){
speed = map(speed, 0, 100, 0, 1023);
analogWrite(_pin, speed);
}





MOTOR::MOTOR(byte pin1, byte pin2) {
  this->pin1 = pin1;
  this->pin2 = pin2;
  start_motor();
}

MOTOR::MOTOR() {
	
//	EA   = 11
//  EB   = 5
//  IN 1 = 9 
//  IN 2 = 12
//  IN 3 = 10
//  IN 4 = 6 

  byte ea  = 11;
  byte eb  = 5;
  byte in1 = 9;
  byte in2 = 12;
  byte in3 = 6;
  byte in4 = 10;
  start();
}

void MOTOR::start_motor() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  //off();
}

void MOTOR::start() {
	
  pinMode(ea, OUTPUT);
  pinMode(eb, OUTPUT);	
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
}

void MOTOR::leftForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void MOTOR::rightForward() {
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void MOTOR::leftReverse() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void MOTOR::rightReverse() {
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void MOTOR::leftStop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void MOTOR::leftSpeed(int speed){
	speed = map(speed, 0, 100, 0, 1023);
	analogWrite(ea, speed );
}

void MOTOR::rightSpeed(int speed){
	speed = map(speed, 0, 100, 0, 1023);
	analogWrite(eb, speed );
}

void MOTOR::rightStop() {
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}


void MOTOR::forward() {
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
}

void MOTOR::reverse() {
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
}

void MOTOR::stop() {
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
}

ULTRASONIC::ULTRASONIC(byte trig, byte echo) {
  this->trig = trig;
  this->echo = echo;
  start_ultrasonic();
}

ULTRASONIC::ULTRASONIC() {
  byte tri = 7;
  byte ech = 8;
  start();
}

void ULTRASONIC::start_ultrasonic() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  //off();
}

void ULTRASONIC::start() {
  pinMode(tri, OUTPUT);
  pinMode(ech, INPUT);
  //off();
}


int ULTRASONIC::distance() {
  digitalWrite(tri, LOW);
  delayMicroseconds(2);
  digitalWrite(tri, HIGH);
  delayMicroseconds(8);
  digitalWrite(tri, LOW);
  
  int duration;
  int distance ;
   
  duration= pulseIn(ech, HIGH);
  distance = (duration/2) / 29.1;
  
  return distance;
}

int ULTRASONIC::getDistance() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(8);
  digitalWrite(trig, LOW);
  
  int duration;
  int distance ;
   
  duration= pulseIn(echo, HIGH);
  distance = (duration/2) / 29.1;
  
  return distance;
}

RGB::RGB(){
//	RGB
//R = 4
//G = 3 
//B = 2
	
	byte red   = 4;
    byte green = 3;	
	byte blue  = 2;
	start();	
}

void RGB::start(){
	pinMode(red,   OUTPUT);
	pinMode(green, OUTPUT);
	pinMode(blue,  OUTPUT);	
}

void RGB::redOn(){
	digitalWrite(red, HIGH);
		
}

void RGB::redOff(){
	digitalWrite(red, LOW);
}

void RGB::greenOn(){
	
	digitalWrite(green, HIGH);
}

void RGB::greenOff(){
	digitalWrite(green, LOW);	
}

void RGB::blueOn(){
	digitalWrite(blue, HIGH);	
}

void RGB::blueOff(){
	digitalWrite(blue, LOW);	
}

void RGB::purpleOn(){
	digitalWrite(red, HIGH);
	digitalWrite(green, LOW);
	digitalWrite(blue, HIGH);	
}

LIGHT::LIGHT(byte pin) {
  this->pin = pin;
  start_light();
}

void LIGHT::start_light() {
  pinMode(pin, OUTPUT);
  
}

void LIGHT::on() {
  digitalWrite(pin, HIGH);
  
}

void LIGHT::off() {
  digitalWrite(pin, LOW);
  
}

BLUETOOTH::BLUETOOTH() {
	
  start_bluetooth();
}

void BLUETOOTH::start_bluetooth() {
  Serial.begin(9600);
  
}

char BLUETOOTH::receiveCommand() {
	char data;
  if(Serial.available() > 0)  // Send data only when you receive data:
   {
  data = Serial.read(); 
   }
  return data;
}

String BLUETOOTH::receive() {
	String data;
  if(Serial.available() > 0)  // Send data only when you receive data:
   {
   data = Serial.read(); 
   }
  return data;
  
}

void BLUETOOTH::sendNumber(int data) {
  Serial.println(data);
}

void BLUETOOTH::sendMessage(String data) {
  Serial.println(data);
}


IR::IR(byte irpin) {
  this->irpin = irpin;
  start_ir();
}

void IR::start_ir() {
  pinMode(irpin, INPUT);
  
}

bool IR::detected() {
  digitalRead(irpin) == HIGH;
  
}

bool IR::undetected() {
  digitalRead(irpin) == LOW;
  
}

BUZZER::BUZZER(byte buzzpin) {
  this->buzzpin = buzzpin;
  start_buzzer();
}

void BUZZER::start_buzzer() {
  pinMode(buzzpin, OUTPUT);
  
}

void BUZZER::on() {
  digitalWrite(buzzpin, HIGH);
  
}

void BUZZER::off() {
  digitalWrite(buzzpin, LOW);
  
}

LCD_I2C::LCD_I2C(uint8_t lcd_Addr,uint8_t lcd_cols,uint8_t lcd_rows)
{
  _Addr = lcd_Addr;
  _cols = lcd_cols;
  _rows = lcd_rows;
  _backlightval = LCD_NOBACKLIGHT;
}

void LCD_I2C::init(){
	init_priv();
}

void LCD_I2C::init_priv()
{
	Wire.begin();
	_displayfunction = LCD_4BITMODE | LCD_1LINE | LCD_5x8DOTS;
	begin(_cols, _rows);  
}

void LCD_I2C::begin(uint8_t cols, uint8_t lines, uint8_t dotsize) {
	if (lines > 1) {
		_displayfunction |= LCD_2LINE;
	}
	_numlines = lines;

	// for some 1 line displays you can select a 10 pixel high font
	if ((dotsize != 0) && (lines == 1)) {
		_displayfunction |= LCD_5x10DOTS;
	}

	// SEE PAGE 45/46 FOR INITIALIZATION SPECIFICATION!
	// according to datasheet, we need at least 40ms after power rises above 2.7V
	// before sending commands. Arduino can turn on way befer 4.5V so we'll wait 50
	delay(50); 
  
	// Now we pull both RS and R/W low to begin commands
	expanderWrite(_backlightval);	// reset expanderand turn backlight off (Bit 8 =1)
	delay(1000);

  	//put the LCD into 4 bit mode
	// this is according to the hitachi HD44780 datasheet
	// figure 24, pg 46
	
	  // we start in 8bit mode, try to set 4 bit mode
   write4bits(0x03 << 4);
   delayMicroseconds(4500); // wait min 4.1ms
   
   // second try
   write4bits(0x03 << 4);
   delayMicroseconds(4500); // wait min 4.1ms
   
   // third go!
   write4bits(0x03 << 4); 
   delayMicroseconds(150);
   
   // finally, set to 4-bit interface
   write4bits(0x02 << 4); 


	// set # lines, font size, etc.
	command(LCD_FUNCTIONSET | _displayfunction);  
	
	// turn the display on with no cursor or blinking default
	_displaycontrol = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;
	display();
	
	// clear it off
	clear();
	
	// Initialize to default text direction (for roman languages)
	_displaymode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;
	
	// set the entry mode
	command(LCD_ENTRYMODESET | _displaymode);
	
	home();
  
}

/********** high level commands, for the user! */
void LCD_I2C::clear(){
	command(LCD_CLEARDISPLAY);// clear display, set cursor position to zero
	delayMicroseconds(2000);  // this command takes a long time!
}

void LCD_I2C::home(){
	command(LCD_RETURNHOME);  // set cursor position to zero
	delayMicroseconds(2000);  // this command takes a long time!
}

void LCD_I2C::setCursor(uint8_t col, uint8_t row){
	int row_offsets[] = { 0x00, 0x40, 0x14, 0x54 };
	if ( row > _numlines ) {
		row = _numlines-1;    // we count rows starting w/0
	}
	command(LCD_SETDDRAMADDR | (col + row_offsets[row]));
}

// Turn the display on/off (quickly)
void LCD_I2C::noDisplay() {
	_displaycontrol &= ~LCD_DISPLAYON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void LCD_I2C::display() {
	_displaycontrol |= LCD_DISPLAYON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Turns the underline cursor on/off
void LCD_I2C::noCursor() {
	_displaycontrol &= ~LCD_CURSORON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void LCD_I2C::cursor() {
	_displaycontrol |= LCD_CURSORON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Turn on and off the blinking cursor
void LCD_I2C::noBlink() {
	_displaycontrol &= ~LCD_BLINKON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void LCD_I2C::blink() {
	_displaycontrol |= LCD_BLINKON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// These commands scroll the display without changing the RAM
void LCD_I2C::scrollDisplayLeft(void) {
	command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVELEFT);
}
void LCD_I2C::scrollDisplayRight(void) {
	command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVERIGHT);
}

// This is for text that flows Left to Right
void LCD_I2C::leftToRight(void) {
	_displaymode |= LCD_ENTRYLEFT;
	command(LCD_ENTRYMODESET | _displaymode);
}

// This is for text that flows Right to Left
void LCD_I2C::rightToLeft(void) {
	_displaymode &= ~LCD_ENTRYLEFT;
	command(LCD_ENTRYMODESET | _displaymode);
}

// This will 'right justify' text from the cursor
void LCD_I2C::autoscroll(void) {
	_displaymode |= LCD_ENTRYSHIFTINCREMENT;
	command(LCD_ENTRYMODESET | _displaymode);
}

// This will 'left justify' text from the cursor
void LCD_I2C::noAutoscroll(void) {
	_displaymode &= ~LCD_ENTRYSHIFTINCREMENT;
	command(LCD_ENTRYMODESET | _displaymode);
}

// Allows us to fill the first 8 CGRAM locations
// with custom characters
void LCD_I2C::createChar(uint8_t location, uint8_t charmap[]) {
	location &= 0x7; // we only have 8 locations 0-7
	command(LCD_SETCGRAMADDR | (location << 3));
	for (int i=0; i<8; i++) {
		write(charmap[i]);
	}
}

// Turn the (optional) backlight off/on
void LCD_I2C::noBacklight(void) {
	_backlightval=LCD_NOBACKLIGHT;
	expanderWrite(0);
}

void LCD_I2C::backlight(void) {
	_backlightval=LCD_BACKLIGHT;
	expanderWrite(0);
}



/*********** mid level commands, for sending data/cmds */

inline void LCD_I2C::command(uint8_t value) {
	send(value, 0);
}


/************ low level data pushing commands **********/

// write either command or data
void LCD_I2C::send(uint8_t value, uint8_t mode) {
	uint8_t highnib=value&0xf0;
	uint8_t lownib=(value<<4)&0xf0;
       write4bits((highnib)|mode);
	write4bits((lownib)|mode); 
}

void LCD_I2C::write4bits(uint8_t value) {
	expanderWrite(value);
	pulseEnable(value);
}

void LCD_I2C::expanderWrite(uint8_t _data){                                        
	Wire.beginTransmission(_Addr);
	printIIC((int)(_data) | _backlightval);
	Wire.endTransmission();   
}

void LCD_I2C::pulseEnable(uint8_t _data){
	expanderWrite(_data | En);	// En high
	delayMicroseconds(1);		// enable pulse must be >450ns
	
	expanderWrite(_data & ~En);	// En low
	delayMicroseconds(50);		// commands need > 37us to settle
} 


// Alias functions

void LCD_I2C::cursor_on(){
	cursor();
}

void LCD_I2C::cursor_off(){
	noCursor();
}

void LCD_I2C::blink_on(){
	blink();
}

void LCD_I2C::blink_off(){
	noBlink();
}

void LCD_I2C::load_custom_character(uint8_t char_num, uint8_t *rows){
		createChar(char_num, rows);
}

void LCD_I2C::setBacklight(uint8_t new_val){
	if(new_val){
		backlight();		// turn backlight on
	}else{
		noBacklight();		// turn backlight off
	}
}

void LCD_I2C::printstr(const char c[]){
	//This function is not identical to the function used for "real" I2C displays
	//it's here so the user sketch doesn't have to be changed 
	print(c);
}


// unsupported API functions
void LCD_I2C::off(){}
void LCD_I2C::on(){}
void LCD_I2C::setDelay (int cmdDelay,int charDelay) {}
uint8_t LCD_I2C::status(){return 0;}
uint8_t LCD_I2C::keypad (){return 0;}
uint8_t LCD_I2C::init_bargraph(uint8_t graphtype){return 0;}
void LCD_I2C::draw_horizontal_graph(uint8_t row, uint8_t column, uint8_t len,  uint8_t pixel_col_end){}
void LCD_I2C::draw_vertical_graph(uint8_t row, uint8_t column, uint8_t len,  uint8_t pixel_row_end){}
void LCD_I2C::setContrast(uint8_t new_val){}

	

