#include "agora.h"
#include "recorder.hh"

#include <dlfcn.h>

void init(callback b)
{
    RecorderContext::Instance()->Init(b);
}
void start(const char *appId, const char *channelKey, const char *channelId)
{
    RecorderContext::Instance()->StartRecorder(appId, channelKey, channelId);
}  

void stop(const char *channelId)
{

}
const char * out()
{
    return "it's out.";
}