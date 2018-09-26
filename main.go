package main

/*
#cgo CFLAGS: -I ${SRCDIR}/agora
#cgo CXXFLAGS: -std=c++11
#cgo LDFLAGS: -L ${SRCDIR}/agora -lagora -L ${SRCDIR}/agora/sdk/libs -lrecorder -lstdc++ -lpthread -lm
#include <stdio.h>
#include "agora.h"
typedef int (*callback)(const char * channelId, int status);

*/
import "C"
import (
	"fmt"
)

//-L ${SRCDIR}/agora/sdk/libs -lrecorder
const (
	appID      = "ssdfsd"
	channelKey = ""
	channelID  = "ES"
)

func callback(channelID string, status int) {

}
func main() {
	C.init(callback)
	C.start(C.CString(appID), C.CString(channelKey), C.CString(channelID))

	out := C.GoString(C.out())
	fmt.Println(out)
	// C.printf("%d", 1)
	// ctx, cancel := context.WithCancel(context.Background())
	// cmd := exec.CommandContext(ctx, "ls")
	// cmd.Stdout = os.Stdout
	// cmd.Start()

	// time.Sleep(100 * time.Second)
	// cancel()
	// cmd.Wait()

	// cmd := exec.Command("/home/liuzh/work/code/src/git.llvision.com/Agora_Recording_SDK_for_Linux_FULL/samples/cpp/release/bin/recorder")
	// stdout, err := cmd.StdoutPipe()
	// if err != nil {
	// 	log.Fatal(err.Error())
	// }
	// defer stdout.Close()

	// if err := cmd.Start(); err != nil {
	// 	log.Fatal(err)
	// }

	// b, err := ioutil.ReadAll(stdout)
	// if err != nil {
	// 	log.Fatal(err)
	// }
	// log.Println(string(b))
	// rtc.Run()
}
