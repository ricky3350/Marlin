/**
* AM3350 Board Configuration
* Copyright (C) 2018 ricky3350
* 
* Marlin 3D Printer Firmware
* Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
*
* Based on Sprinter and grbl.
* Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#if !defined(__AVR_ATmega2560__)
#error "Oops!  Make sure you have 'Arduino Mega' selected from the 'Tools -> Boards' menu."
#endif

#ifndef BOARD_NAME
#define BOARD_NAME "AMR3350"
#endif

//
// Limit Switches
//
#define X_MIN_PIN           47
#ifndef X_MAX_PIN
#define X_MAX_PIN         46
#endif
#define Y_MIN_PIN          45
#define Y_MAX_PIN          44
#define Z_MIN_PIN          17 // 17 for the 12V Z- pin, 43 otherwise
#define Z_MAX_PIN          42

//
// Steppers
//
#define X_STEP_PIN         68
#define X_DIR_PIN          69
#define X_ENABLE_PIN       67
#define X_CS_PIN           -1

#define Y_STEP_PIN         23
#define Y_DIR_PIN          24
#define Y_ENABLE_PIN       22
#define Y_CS_PIN           -1

#define Z_STEP_PIN         26
#define Z_DIR_PIN          27
#define Z_ENABLE_PIN       25
#define Z_CS_PIN           -1

#define E0_STEP_PIN        29
#define E0_DIR_PIN         39
#define E0_ENABLE_PIN      28
#define E0_CS_PIN          -1

#define E1_STEP_PIN        15
#define E1_DIR_PIN         30
#define E1_ENABLE_PIN      14
#define E1_CS_PIN          -1

//
// Temperature Sensors
//
#define TEMP_0_PIN         4   // Analog Input
#define TEMP_1_PIN         2   // Analog Input
#define TEMP_BED_PIN       3   // Analog Input

// SPI for Max6675 or Max31855 Thermocouple
#if DISABLED(SDSUPPORT)
#define MAX6675_SS       60 // Do not use pin 53 if there is even the remote possibility of using Display/SD card
#else
#define MAX6675_SS       60 // Do not use pin 11 as this is tied to the switch inside the SD card socket to detect if there is an SD card present
#endif

//
// Heaters / Fans
//
#ifndef MOSFET_D_PIN
#define MOSFET_D_PIN  -1
#endif
#ifndef AM_D5_PIN
#define AM_D5_PIN   5
#endif
#ifndef AM_D2_PIN
#define AM_D2_PIN   2
#endif
#ifndef AM_D3_PIN
#define AM_D3_PIN   3
#endif

#define HEATER_0_PIN     AM_D3_PIN
#define HEATER_1_PIN   AM_D2_PIN
#define HEATER_BED_PIN AM_D5_PIN

#ifndef FAN_PIN
#define FAN_PIN 6
#endif

//
// Misc. Functions
//
#define SDSS               53
#define LED_PIN            13

#ifndef FILWIDTH_PIN
#define FILWIDTH_PIN      48   // Analog Input on AUX2
#endif

#define FIL_RUNOUT_PIN      -1

#ifndef PS_ON_PIN
#define PS_ON_PIN        19
#endif

//
// Průša i3 MK2 Multiplexer Support
//
#ifndef E_MUX0_PIN
#define E_MUX0_PIN 63   // Z_CS_PIN
#endif
#ifndef E_MUX1_PIN
#define E_MUX1_PIN 61   // E0_CS_PIN
#endif
#ifndef E_MUX2_PIN
#define E_MUX2_PIN 62   // E1_CS_PIN
#endif

//////////////////////////
// LCDs and Controllers //
//////////////////////////

#if ENABLED(ULTRA_LCD)

//
// LCD Display output pins
//
#if ENABLED(REPRAPWORLD_GRAPHICAL_LCD)

#define LCD_PINS_RS         10 // CS chip select /SS chip slave select
#define LCD_PINS_ENABLE     51 // SID (MOSI)
#define LCD_PINS_D4         52 // SCK (CLK) clock

#elif ENABLED(NEWPANEL) && ENABLED(PANEL_ONE)

#define LCD_PINS_RS         63
#define LCD_PINS_ENABLE     61
#define LCD_PINS_D4         59
#define LCD_PINS_D5         60
#define LCD_PINS_D6         62
#define LCD_PINS_D7         64

#else

#if ENABLED(CR10_STOCKDISPLAY)

#define LCD_PINS_RS       12
#define LCD_PINS_ENABLE   16
#define LCD_PINS_D4       11

#if DISABLED(NEWPANEL)
#define BEEPER_PIN      37
#endif

#else

#if ENABLED(MKS_12864OLED) || ENABLED(MKS_12864OLED_SSD1306)
#define LCD_PINS_DC     11 // Set as output on init
#define LCD_PINS_RS     12 // Pull low for 1s to init
// DOGM SPI LCD Support
#define DOGLCD_CS       49
#define DOGLCD_MOSI     48
#define DOGLCD_SCK      18
#define DOGLCD_A0       LCD_PINS_DC
#else
#define LCD_PINS_RS     49
#define LCD_PINS_ENABLE 48
#define LCD_PINS_D4     18
#define LCD_PINS_D5     11
#define LCD_PINS_D6     12
#endif

#define LCD_PINS_D7       16

#if DISABLED(NEWPANEL)
#define BEEPER_PIN      41
#endif

#endif

#endif

//
// LCD Display input pins
//
#if ENABLED(NEWPANEL)

#if ENABLED(REPRAP_DISCOUNT_SMART_CONTROLLER)

#define BEEPER_PIN        37

#if ENABLED(CR10_STOCKDISPLAY)
#define BTN_EN1         48
#define BTN_EN2         18
#else
#define BTN_EN1         38
#define BTN_EN2         41
#endif

#define BTN_ENC           40
#define SD_DETECT_PIN     10
#define KILL_PIN          35

#if ENABLED(BQ_LCD_SMART_CONTROLLER)
#define LCD_BACKLIGHT_PIN 36
#endif

#elif ENABLED(REPRAPWORLD_GRAPHICAL_LCD)

#define BTN_EN1           64
#define BTN_EN2           66
#define BTN_ENC           65
#define SD_DETECT_PIN     61

#elif ENABLED(LCD_I2C_PANELOLU2)

#define BTN_EN1           32
#define BTN_EN2           34
#define BTN_ENC           31
#define LCD_SDSS          53
#define KILL_PIN          35

#elif ENABLED(LCD_I2C_VIKI)

#define BTN_EN1           17 // http://files.panucatt.com/datasheets/viki_wiring_diagram.pdf explains 40/42.
#define BTN_EN2            4 // 17/4 are unused on AMR3350.
#define BTN_ENC           -1

#define LCD_SDSS          53
#define SD_DETECT_PIN     10

#elif ENABLED(VIKI2) || ENABLED(miniVIKI)

#define DOGLCD_CS         33
#define DOGLCD_A0         62
#define LCD_SCREEN_ROT_180

#define BEEPER_PIN        41
#define STAT_LED_RED_PIN  31
#define STAT_LED_BLUE_PIN 40

#define BTN_EN1           17
#define BTN_EN2            4
#define BTN_ENC           36

#define SDSS              53
#define SD_DETECT_PIN     -1 // Pin 10 for display sd interface, 72 for easy adapter board
#define KILL_PIN          38

#elif ENABLED(ELB_FULL_GRAPHIC_CONTROLLER)

#define DOGLCD_CS         16
#define DOGLCD_A0         12

#define BEEPER_PIN        18
#define LCD_BACKLIGHT_PIN 41

#define BTN_EN1           40
#define BTN_EN2           37
#define BTN_ENC           38

#define LCD_SDSS          53
#define SD_DETECT_PIN     10
#define KILL_PIN          35

#elif ENABLED(MKS_MINI_12864)  // Added in Marlin 1.1.6

#define DOGLCD_A0         12
#define DOGLCD_CS         11

// GLCD features
//#define LCD_CONTRAST   190
// Uncomment screen orientation
//#define LCD_SCREEN_ROT_90
//#define LCD_SCREEN_ROT_180
//#define LCD_SCREEN_ROT_270

#define BEEPER_PIN        37
// not connected to a pin
#define LCD_BACKLIGHT_PIN 59 // backlight LED on A5/D59

#define BTN_EN1           38
#define BTN_EN2           41
#define BTN_ENC           40

#define SDSS              53
#define SD_DETECT_PIN     10
#define KILL_PIN          64

#elif ENABLED(MINIPANEL)

#define BEEPER_PIN        61
// not connected to a pin
#define LCD_BACKLIGHT_PIN 59 // backlight LED on A5/D59

#define DOGLCD_A0         62
#define DOGLCD_CS         60

// GLCD features
//#define LCD_CONTRAST   190
// Uncomment screen orientation
//#define LCD_SCREEN_ROT_90
//#define LCD_SCREEN_ROT_180
//#define LCD_SCREEN_ROT_270

#define BTN_EN1           63
#define BTN_EN2           65
#define BTN_ENC           56

#define SDSS              53
#define SD_DETECT_PIN     10
#define KILL_PIN          64

#else

// Beeper on AUX-4
#define BEEPER_PIN        41

// Buttons are directly attached using AUX-2
#if ENABLED(REPRAPWORLD_KEYPAD)
#define SHIFT_OUT       63
#define SHIFT_CLK       62
#define SHIFT_LD        61
#define BTN_EN1         64
#define BTN_EN2         66
#define BTN_ENC         65
#elif ENABLED(PANEL_ONE)
#define BTN_EN1         66 // AUX2 PIN 3
#define BTN_EN2         65 // AUX2 PIN 4
#define BTN_ENC         10 // AUX3 PIN 7
#else
#define BTN_EN1         37
#define BTN_EN2         40
#define BTN_ENC         38
#endif

#if ENABLED(G3D_PANEL)
#define SD_DETECT_PIN   10
#define KILL_PIN        35
#endif

#endif
#endif // NEWPANEL

#endif // ULTRA_LCD

#if ENABLED(ZONESTAR_LCD)
#define LCD_PINS_RS        64
#define LCD_PINS_ENABLE    62
#define LCD_PINS_D4        65
#define LCD_PINS_D5        63
#define LCD_PINS_D6        61
#define LCD_PINS_D7        59
#define ADC_KEYPAD_PIN     19
#define BTN_EN1            -1
#define BTN_EN2            -1
#define BTN_ENC            -1
// pin 29 N/C
#endif // ZONESTAR_LCD
