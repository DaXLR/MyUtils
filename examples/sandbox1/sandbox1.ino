#include <MyUtils.h>

int time[] = {110, 20, 110, 20, 110, 20, 390, 390, 390, 130, 160, 100, 500, 10};
int val1[] = {349, 0, 349, 0, 349, 0, 349, 277, 311, 349, 0, 311, 349, 0};
int val2[] = {261, 0, 261, 0, 261, 0, 261, 207, 233, 261, 0, 233, 261, 0};

PolyTone buzz1 = PolyTone(2);
PolyTone buzz2 = PolyTone(3);
Timer t = Timer();
Sequencer seq1 = Sequencer(14, time, val1);
Sequencer seq2 = Sequencer(14, time, val2);

void setup()
{
    Serial.begin(115200);
    t.start(4000);
    seq1.start(1);
    seq2.start(1);
}
void loop()
{
    if (t.check())
    {
        seq1.start(1);
        seq2.start(1);
    }
    if (seq1.newVal())
    {
        buzz1.tone(seq1.check());
    }
    if (seq2.newVal())
    {
        buzz2.tone(seq2.check());
    }
    buzz1.update();
    buzz2.update();
}