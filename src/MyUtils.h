#include "Arduino.h"

#ifndef PolyTone_h
#define PolyTone_h

class PolyTone
{
public:
    PolyTone(int pin);
    void tone(int freq, unsigned long duration = 0);
    void noTone();
    void update();
    bool isAvailable();

private:
    int _pin;
    int _freq = 0;
    uint32_t _stopTime = 0;
    bool _timedBuzz = 0;
    bool _pinState = 0;
    uint32_t _prevWave = 0;
    uint32_t _waveOffset = 0;
};
#endif

#ifndef Timer_h
#define Timer_h
class Timer
{
public:
    Timer();
    void start(unsigned long interval, bool repeating = true);
    void startMicro(unsigned long interval, bool repeating = true);
    bool check();
    void stop();
    bool isRunning();
    int flag = 0;

private:
    bool _checkMicros();
    uint32_t _flagpole = 0;
    uint32_t _interval = 0;
    bool _repeating = true;
    bool _isMicros = false;
    bool _isRunning = false;
};
#endif

#ifndef Sequencer_h
#define Sequencer_h
class Sequencer
{
public:
    Sequencer(int size);
    Sequencer(int size, int initialTiming[], int initialValues[]);
    void load(int timing[], int values[]);
    void start(int loops = 0);
    void printDebug();
    int check();
    int checkIndex();
    bool newVal();
    void stop();

private:
    uint32_t _flagpole = 0;
    uint32_t _interval = 0;
    int _size = 0;
    int *_timing;
    int *_values;
    int _loops = 0;
    bool _isRunning = false;
    int _sequencePosition = 0;
    int _prevSeqPos = 0;
};
#endif

#ifndef Picker_h
#define Picker_h
class Picker
{
public:
    Picker(int size);
    Picker(int size, int weights[]);
    Picker(int size, int values[], int weights[]);
    void load(int weights[]);
    void load(int values[], int weights[]);
    int pickWeights();
    int pickEqual();

private:
    int _size = 0;
    int _totalWeight = 0;
    int *_weights;
    int *_values;
    bool _customWeights = false;
    bool _customValues = false;
};
#endif