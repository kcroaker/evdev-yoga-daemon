#ifndef LIBINPUT_BACKEND_H
#define LIBINPUT_BACKEND_H
// #define LIBINPUT_UDEV // Not implemented, lol!
#define LIBEVDEV


#ifdef LIBEVDEV
/* In reality I'm targeting my dev machine, with evdev providing udev support. The libs do not seem cross compatible, so I must use: */
#include <libevdev/libevdev.h>
#include <libevdev/libevdev-uinput.h>

struct libevdev *open_acpi_device(const char *devpath);
void acpi_device_loop(struct libevdev *dev);
#endif

/* In theory this could be updated to support the classic libinput / udev setup most systemd systems would be running 
 * but I have no real incentive or time right now to do so. Still, it would probably start like this and run as a replacement 
 * for the above LIBEVDEV block. but nah,
 */
// #ifdef LIBINPUT_UDEV
// #include <libinput.h>
// #include <libudev.h>
// #endif

//#include <poll.h>
//#include <wordexp.h>

#include <errno.h>
//#include <string.h>
//#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
//#include <stdarg.h>
//#include <stdbool.h>


#endif