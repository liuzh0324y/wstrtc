#include "agora.h"
#include "recorder.hh"
#include <stdio.h>

void start()
{
    Recorder *r = new Recorder();
    printf(r->Out());
    printf("out.");
    delete r;
}