#ifndef __SOUND_DRIVER_H__
#define __SOUND_DRIVER_H__

#include <stdio.h>
#include <Windows.h>

void init_sound(const char file_name);
void play_sound(const char* file_path);
void stop_sound(void);
#endif
