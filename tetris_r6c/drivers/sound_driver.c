#include "sound_driver.h"

#pragma comment(lib, "winmm.lib") // winmm 라이브러리 링크

void init_sound(const char file_name) {
}

void play_sound(const char* file_path) {
    //const char* filename = "sample2.wav";
    if (PlaySoundA(file_path, NULL, SND_ASYNC | SND_LOOP | SND_FILENAME)) {
        printf("Playing sound: %s\n", file_path);
    }
    else {
        printf("Error: Unable to play sound. Make sure the file exists and is a valid .wav file.\n");
    }
}
void stop_sound(void) {
    PlaySoundA(NULL, NULL, 0);
}