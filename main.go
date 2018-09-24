package main

/*
#cgo CFLAGS: -I /home/liuzh/work/code/src/github.com/wst-libs/wstrtc/agora
#cgo LDFLAGS: -L /home/liuzh/work/code/src/github.com/wst-libs/wstrtc/agora -lagora -lstdc++
#include "agora.h"
*/
import "C"

import "github.com/wst-libs/wst-sdk/rtc"

func main() {
	C.start()
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
	rtc.Run()
}
