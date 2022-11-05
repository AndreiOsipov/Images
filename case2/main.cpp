#include "mbed.h"
#include "Sht31.h"
//sda, scl
Sht31   temp_sensor(I2C_SDA, I2C_SCL);
Thread mesaure_thread;
Thread blink_thread;

double current_hydro; 

void 
void 
int main()

{
    float t;
    float h;

    while (true) {
        t = temp_sensor.readTemperature();
        h = temp_sensor.readHumidity();
        printf("%f", t);
        printf(" %f\n\r", h);
        thread_sleep_for(500);
    }
}