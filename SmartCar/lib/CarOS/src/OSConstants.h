#define CAR_OS_VERSION "1.1.1"

/****************************/
/*        Car Modes         */
/****************************/
#define CAR_DEFAULT_MODE 16738455       // Default is IR Mode
#define CAR_IR_MODE_KEY 16738455        // IR remote btn #1
#define CAR_BLUETOOTH_MODE_KEY 16750695 // IR remote btn #2
#define CAR_AUTO_MODE_KEY 16756815      // IR remote btn #3
#define CAR_LINE_MODE_KEY 167568110     // IR remote btn #4
/****************************/
/*         IR Mode         */
/****************************/
#define IR_KEY_HOLD_TIMEOUT 150 // time in ms to detect the IR key hold behavior
#define IR_MODE_CAR_SPEED 250   // IR remote btn #4
#define IR_AVG_DIST_THRSHOLD 30
/****************************/

/****************************/
/*          Modules        */
/****************************/
/****************************/
/*       Motor Module       */
/****************************/
#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
/****************************/
/*       OLED Module        */
/****************************/
#define OLED_ADDR -1     // Auto detect I2C address
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1    // Reset pin # (or -1 if sharing Arduino reset pin)
#define FLIP_SCREEN 1    // Rotates the screen 180 degree (0 default, 1 to flip)
/****************************/
/*       Voice Module       */
/****************************/
#define V_TX 2
#define V_RX 4
#define V_VOLUME 30 //Set volume value (0~30).
#define V_EQ DFPLAYER_EQ_NORMAL
#define V_TEST(selector) (selector == 0 ? 1 : 1) // The selector = 0, means folder number, else file number
/****************************/
/*    Ultralsonic Module    */
/****************************/
#define U_NUMBER_OF_SENSORS 3
#define U_TRIG_PIN_S0 10   // Buttom Sensor
#define U_TRIG_PIN_S1 10   // Top left sensor
#define U_TRIG_PIN_S2 10   // Top right sensor
#define U_ECHO_PIN 13      // Shared Echo PIN
#define U_TEMPRTURE 20.0   // Temprature
#define U_MAX_DISTANCE 400 // Maximum sensor distance, if 0 or exceeded the maximum then return -1
/****************************/
/*    Servo Motor Module    */
/****************************/
#define SERVO_PIN 3
#define SERVO_MIN_ANGLE 5
#define SERVO_MAX_ANGLE 175
/****************************/
/*           IR             */
/****************************/
#define IR_PIN 12                      // IR RCV PIN
#define IR_DEFAULT 4294967295          // Unkown
#define IR_FORWARD 16736925            // FORWARD
#define IR_BACKWARD 16754775           // BACK
#define IR_LEFT 16720605               // LEFT
#define IR_RIGHT 16761405              // RIGHT
#define IR_STOP 16712445               // STOP
#define IR_UNKNOWN_FORWARD 5316027     // FORWARD
#define IR_UNKNOWN_BACKWARD 2747854299 // BACK
#define IR_UNKNOWN_LEFT 1386468383     // LEFT
#define IR_UNKNOWN_RIGHT 553536955     // RIGHT
#define IR_UNKNOWN_STOP 3622325019     // STOP
/****************************/

/****************************/
/*    Voice Files on SD     */
/****************************/
/*    1- System Folder      */
/****************************/
#define V_SYSTEM_FOLDER 1
#define V_TESTING_VOICE 1
#define V_IR_MODE 6
#define V_BLUETOOTH_MODE 7
#define V_AUTO_MODE 8
#define V_LINE_TRACKING_MODE 9
#define V_READY 10
#define V_MOVE_FORWARD 11
#define V_MOVE_BACKWARD 12
#define V_MOVE_RIGHT 13
#define V_MOVE_LEFT 14
#define V_STOP 15