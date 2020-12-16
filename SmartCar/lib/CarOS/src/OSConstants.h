#define CAR_OS_VERSION "1.0.0"

/*Motor drive module*/
#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11

/*OLED*/
#define OLED_ADDR -1     // Auto detect I2C address
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1    // Reset pin # (or -1 if sharing Arduino reset pin)
#define FLIP_SCREEN 1    // Rotates the screen 180 degree (0 default, 1 to flip)

/*Voice*/
#define V_TX 2
#define V_RX 4
#define V_VOLUME 20 //Set volume value (0~30).
#define V_EQ DFPLAYER_EQ_NORMAL
#define V_TEST(selector) (selector == 0 ? 1 : 1) // The selector = 0, means folder number, else file number

/** Ultralsonic Sensor */
#define U_NUMBER_OF_SENSORS 3
#define U_TRIG_PIN_S0 10   // Buttom Sensor
#define U_TRIG_PIN_S1 10   // Top left sensor
#define U_TRIG_PIN_S2 10   // Top right sensor
#define U_ECHO_PIN 3       // Shared Echo PIN
#define U_TEMPRTURE 20.0   // Temprature
#define U_MAX_DISTANCE 400 // Maximum sensor distance, if 0 or exceeded the maximum then return -1