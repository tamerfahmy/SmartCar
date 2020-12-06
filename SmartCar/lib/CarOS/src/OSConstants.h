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

/*Voice*/
#define V_TX 2
#define V_RX 4
#define V_VOLUME 18 //Set volume value (0~30).
#define V_EQ DFPLAYER_EQ_NORMAL
#define V_TEST(selector) (selector == 0 ? 1 : 1) // The selector = 0, means folder number, else file number