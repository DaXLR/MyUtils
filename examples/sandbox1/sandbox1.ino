#include <MyUtils.h>

Timer t = Timer();

void setup()
{
    Serial.begin(115200);
    t.start(1000);
}
void loop()
{
    if (t.check())
    {
        Serial.println("check!");
    }
}