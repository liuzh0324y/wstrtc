#ifndef AGORA_H
#define AGORA_H

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

    void init(callback b);

    void start(const char *appId, const char *channelKey, const char *channelId);

    void stop(const char *channelId);
    
    const char * out();

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // AGORA_H