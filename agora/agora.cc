#include "agora.h"
#include "recorder.hh"

#include <dlfcn.h>

void start()
{
    Recorder *r = new Recorder;
    delete r;
}