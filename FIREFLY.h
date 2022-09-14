#ifndef FIREFLY_H
#define FIREFLY_H_H

#include <Arduino.h>
#include <inttypes.h>
#include "Print.h" 
#include <Wire.h>
#include <SoftwareSerial.h>

// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

// flags for backlight control
#define LCD_BACKLIGHT 0x08
#define LCD_NOBACKLIGHT 0x00

#define En B00000100  // Enable bit
#define Rw B00000010  // Read/Write bit
#define Rs B00000001  // Register select bit


class SPEED {
public:
	SPEED(int pin);
	void setSpeed(int speed);
private:
	int _pin;
};




class MOTOR {
  
  private:
    byte pin1;
	byte pin2;
  
  byte ea  = 11;
  byte eb  = 5;
  byte in1 = 9;
  byte in2 = 12;
  byte in3 = 6;
  byte in4 = 10;
    
  public:
    // Setup pin1 and pin2 for MOTOR object and call start_motor()
    MOTOR(byte pin1, byte pin2);
	MOTOR();

    // Setup both pin1 and pin2 as OUTPUT
    void start_motor();
	void start();
    
    // Move MOTOR forward
    void forward();
	void leftForward();
	void rightForward();

    // Move MOTOR reverse
    void reverse();
	void leftReverse();
	void rightReverse();
	
	
	//Make MOTOR stop
	void stop();
	void leftStop();
	void rightStop();
	
	//Control MOTOR SPEED
	void leftSpeed(int speed);
	void rightSpeed(int speed);
};

class ULTRASONIC {
  
  private:
    byte trig;
	byte echo;
    byte tri = 7;
    byte ech = 8;
  public:
    // Set parameters trig and echo for ULTRASONIC object and call start_ultrasonic()
    ULTRASONIC(byte trig, byte echo);
	ULTRASONIC();

    // Derive distance data
    int getDistance();
	int distance();
    
    // Configure ULTRASONIC pins 
    void start_ultrasonic();
    void start();

};

class RGB {
  
  private:
    //	RGB
//R = 4
//G = 3 
//B = 2
	
	byte red   = 4;
    byte green = 3;	
	byte blue  = 2;
	
    
  public:
    // Set pin parameter for LIGHT object and call start()
    RGB();

    
    
    // Configure LIGHT pin
    void start();
	
	// Turn LIGHT pin ON
    void redOn();
	
	// Turn LIGHT pin OFF
    void redOff();
	
	// Turn LIGHT pin OFF
    void greenOn();
	
	// Turn LIGHT pin OFF
    void greenOff();
	
	// Turn LIGHT pin OFF
    void blueOn();
	
	// Turn LIGHT pin OFF
    void blueOff();
	
	// Turn Purple light ON
    void purpleOn();
	
	// Turn Purple light OFF
    void purpleOff();


};

class LIGHT {
  
  private:
    byte pin;
	
    
  public:
    // Set pin parameter for LIGHT object and call start()
    LIGHT(byte pin);

    
    
    // Configure LIGHT pin
    void start_light();
	
	// Turn LIGHT pin ON
    void on();
	
	// Turn LIGHT pin OFF
    void off();


};

class BLUETOOTH {
  
  private:
    //byte pin;
	
    
  public:
    // Set pin parameter for LIGHT object and call start()
    BLUETOOTH();

    
    
    // Configure LIGHT pin
    void start_bluetooth();
	
	// Turn LIGHT pin ON
    void sendNumber(int data);
	
	// Turn LIGHT pin ON
    void sendMessage(String data);
	
	// Turn LIGHT pin OFF
    char receiveCommand();
	
	// Turn LIGHT pin OFF
    String receive();


};

class IR {
  
  private:
    byte irpin;
	
    
  public:
    // Set pin parameter for IR object and call start_ir()
    IR(byte irpin);

    
    
    // Configure IR pin
    void start_ir();
	
	// Monitor IR pin for detection
    bool detected();
	
	// Monitor IR pin for undetection
    bool undetected();


};

class BUZZER {
  
  private:
    byte buzzpin;
	
    
  public:
    // Set pin parameter for LIGHT object and call start()
    BUZZER(byte buzzpin);

    
    
    // Configure LIGHT pin
    void start_buzzer();
	
	// Turn LIGHT pin ON
    void on();
	
	// Turn LIGHT pin OFF
    void off();


};

class LCD_I2C : public Print {
public:
  LCD_I2C(uint8_t lcd_Addr,uint8_t lcd_cols,uint8_t lcd_rows);
  void begin(uint8_t cols, uint8_t rows, uint8_t charsize = LCD_5x8DOTS );
  void clear();
  void home();
  void noDisplay();
  void display();
  void noBlink();
  void blink();
  void noCursor();
  void cursor();
  void scrollDisplayLeft();
  void scrollDisplayRight();
  void printLeft();
  void printRight();
  void leftToRight();
  void rightToLeft();
  void shiftIncrement();
  void shiftDecrement();
  void noBacklight();
  void backlight();
  void autoscroll();
  void noAutoscroll(); 
  void createChar(uint8_t, uint8_t[]);
  void setCursor(uint8_t, uint8_t); 
#if defined(ARDUINO) && ARDUINO >= 100
  virtual size_t write(uint8_t);
#else
  virtual void write(uint8_t);
#endif
  void command(uint8_t);
  void init();

////compatibility API function aliases
void blink_on();						// alias for blink()
void blink_off();       					// alias for noBlink()
void cursor_on();      	 					// alias for cursor()
void cursor_off();      					// alias for noCursor()
void setBacklight(uint8_t new_val);				// alias for backlight() and nobacklight()
void load_custom_character(uint8_t char_num, uint8_t *rows);	// alias for createChar()
void printstr(const char[]);

////Unsupported API functions (not implemented in this library)
uint8_t status();
void setContrast(uint8_t new_val);
uint8_t keypad();
void setDelay(int,int);
void on();
void off();
uint8_t init_bargraph(uint8_t graphtype);
void draw_horizontal_graph(uint8_t row, uint8_t column, uint8_t len,  uint8_t pixel_col_end);
void draw_vertical_graph(uint8_t row, uint8_t column, uint8_t len,  uint8_t pixel_col_end);
	 

private:
  void init_priv();
  void send(uint8_t, uint8_t);
  void write4bits(uint8_t);
  void expanderWrite(uint8_t);
  void pulseEnable(uint8_t);
  uint8_t _Addr;
  uint8_t _displayfunction;
  uint8_t _displaycontrol;
  uint8_t _displaymode;
  uint8_t _numlines;
  uint8_t _cols;
  uint8_t _rows;
  uint8_t _backlightval;
};

#endif