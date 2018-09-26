package callback

/*
#include <stdio.h>
extern int EventHandler(const char * channelID, int status);
*/
import "C"

// export EventHandler
func EventHandler(channelID *C.char, status C.int) {

}
