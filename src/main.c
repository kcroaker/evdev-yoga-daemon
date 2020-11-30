#include "backend.h"
#include <poll.h>
#include <wordexp.h>

#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include <fcntl.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define PROGNAME "evdev-yoga-daemon"

// - xinput enable "AT Translated Set 2 keyboard"
// - xinput enable "SynPS/2 Synaptics TouchPad"
// - xinput enable "TPPS/2 IBM TrackPoint"
void enter_laptop_mode() {
	char command[64];

	sprintf(command, "xinput enable \"%s\" ", "AT Translated Set 2 keyboard");
	system(command);
	sprintf(command, "xinput enable \"%s\" ", "SynPS/2 Synaptics TouchPad");
	system(command);
	sprintf(command, "xinput enable \"%s\" ", "TPPS/2 IBM TrackPoint");
	system(command);
	return;
}

    // - xinput disable "AT Translated Set 2 keyboard"
    // - xinput disable "SynPS/2 Synaptics TouchPad"
    // - xinput disable "TPPS/2 IBM TrackPoint"
void enter_tablet_mode() {
	char command[64];
	sprintf(command, "xinput disable \"%s\" ", "AT Translated Set 2 keyboard");
	system(command);
	sprintf(command, "xinput disable \"%s\" ", "SynPS/2 Synaptics TouchPad");
	system(command);
	sprintf(command, "xinput disable \"%s\" ", "TPPS/2 IBM TrackPoint");
	system(command);
	return;
}

int main(void) {
	const char *devpath = "/dev/input/by-path/platform-thinkpad_acpi-event"; // Tested X1 Yoga gen 1
	//const char *devpath = "/dev/input/event7";

	struct libevdev *dev = NULL;
	int fd;
	int rc = 1;

	fd = open(devpath, O_RDONLY|O_NONBLOCK);
	rc = libevdev_new_from_fd(fd, &dev);

	if(rc < 0) {
		printf("Failed to init libevdev");
		return -1;
	}

	printf("Input device name: \"%s\"\n", libevdev_get_name(dev));

	//printf("Input device ID: bus %#x vendor %#x product %#x\n",
	//	libevdev_get_id_bustype(dev),
	//	libevdev_get_id_vendor(dev),
	//	libevdev_get_id_product(dev));

	if (!libevdev_has_event_type(dev, EV_SW) ||
		!libevdev_has_event_code(dev, EV_SW, SW_TABLET_MODE)) {
			printf("Error: This device does not generate tablet switching events\n");
			exit(1);
	}
	
	do {
		struct input_event ev;
		rc = libevdev_next_event(dev, LIBEVDEV_READ_FLAG_NORMAL, &ev);
		if (rc == 0) {
			if(ev.type == EV_SW && ev.code == SW_TABLET_MODE) {
				if(ev.value == 0) {
					printf("*** Laptop mode\n");
				} else if(ev.value == 1) {
					printf("*** Tablet mode\n");
				}
			}
		}
	} while (rc == 1 || rc == 0 || rc == -EAGAIN);

	return 0;
}
