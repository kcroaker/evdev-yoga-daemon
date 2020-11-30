#ifndef LIBINPUT_BACKEND_H
#define LIBINPUT_BACKEND_H

#ifdef LIBINPUT_UDEV
/* In theory this could be updated to support the classic libinput / udev setup most systemd systems would be running */
//#include <libinput.h>
//#include <libudev.h>
#else
/* In reality I'm targeting my dev machine, with evdev providing udev support, and the libs do not seem cross compatible */
#include <libevdev/libevdev.h>
#include <libevdev/libevdev-uinput.h>
#endif

#endif