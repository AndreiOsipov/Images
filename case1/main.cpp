#include "mbed.h"

DigitalIn a1(A4);
DigitalIn a2(A5);
DigitalIn d2(D2);
DigitalIn d4(D7);
int inputtedPassword = 0;
int rightPassword = 1111;
DigitalIn buttonArr[4] = {a1,a2,d2,d4};
bool buttonWasPressed;
bool foundPressedButton;
bool passwordIsInputting = true;

// main() runs in its own thread in the OS
int main()
{
    while (true) {

        //printf("btn1=%d\n",a1.read());
        
        if (passwordIsInputting)
        {
            foundPressedButton = false;
            for(int i = 0; i < 4; i++)
            {
                if(buttonArr[i].read() == 0)
                {
                    foundPressedButton = true;
                    if(!buttonWasPressed)
                    {
                        printf("button is pressed\n");
                        buttonWasPressed = true;
                        if(inputtedPassword/1000 == 0)
                        {
                            inputtedPassword=inputtedPassword*10 + i + 1;
                            printf("%d\n", inputtedPassword);
                            if (inputtedPassword == rightPassword)
                            {
                                printf("inputted password is right\n");
                                passwordIsInputting = false;
                            }
                        }
                        if(inputtedPassword/1000 != 0) inputtedPassword = 0;
                    }    
                }
            }
            if(!foundPressedButton) buttonWasPressed = false;
            thread_sleep_for(100);
       }
       else 
       {
            passwordIsInputting = true;
       }
    }
}

