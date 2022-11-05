#include "mbed.h"
DigitalOut myled(A2);
DigitalIn ButtonS1(A4);
DigitalIn ButtonS2(A5);
DigitalIn ButtonS3(D2);
DigitalIn ButtonS4(D7);
// main() runs in its own thread in the OS
int main()
{

    DigitalIn keyboard[] = {ButtonS1, ButtonS2, ButtonS3, ButtonS4};
    keyboard[0].mode(PullNone);
    keyboard[1].mode(PullNone);
    keyboard[2].mode(PullNone);
    keyboard[3].mode(PullNone);

    
    while(1)
    {
        int i;
        for (int i = 0; i < 4; i++)
        {
            printf("Button state is: %d\n\r", keyboard[i].read());
            if (keyboard[i] == 0)
            {
                myled = !myled; // Toggle the LED state
                wait(0.2); // 200 ms                
            }
            
        }
        
    }

}
