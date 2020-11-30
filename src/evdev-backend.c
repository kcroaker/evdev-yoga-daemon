#include "backend.h"
#include "tablet-switch.h"

int rc = 1;

struct libevdev *open_acpi_device(const char *devpath) {

	struct libevdev *dev = NULL;
	int fd;

	fd = open(devpath, O_RDONLY|O_NONBLOCK);
	rc = libevdev_new_from_fd(fd, &dev);

	if(rc < 0) {
		printf("Failed to init libevdev");
		return NULL;
	}

    return dev;
}

void acpi_device_loop(struct libevdev *dev) {
    do {
		struct input_event ev;
		rc = libevdev_next_event(dev, LIBEVDEV_READ_FLAG_NORMAL, &ev);
		if (rc == 0) {
			if(ev.type == EV_SW && ev.code == SW_TABLET_MODE) {
				if(ev.value == 0) {
					// printf("*** Laptop mode\n");
					enter_laptop_mode();
				} else if(ev.value == 1) {
					// printf("*** Tablet mode\n");
					enter_tablet_mode();
				}
			}
		}
        sleep(1);
	} while (rc == 1 || rc == 0 || rc == -EAGAIN);
}