#include "backend.h"

#define PROGNAME "evdev-yoga-daemon"

int main(void) {
	//const char *devpath = "/dev/input/event7";
	const char *devpath = "/dev/input/by-path/platform-thinkpad_acpi-event"; // Tested X1 Yoga gen 1

	struct libevdev *dev;

	dev = open_acpi_device(devpath);

	//printf("Input device name: \"%s\"\n", libevdev_get_name(dev));

	//printf("Input device ID: bus %#x vendor %#x product %#x\n",
	//	libevdev_get_id_bustype(dev),
	//	libevdev_get_id_vendor(dev),
	//	libevdev_get_id_product(dev));

	if (!libevdev_has_event_type(dev, EV_SW) ||
		!libevdev_has_event_code(dev, EV_SW, SW_TABLET_MODE)) {
			printf("Error: This device does not generate tablet switching events\n");
			exit(1);
	} else {
		acpi_device_loop(dev); // basically runs indefinitely
	}	

	return 0;
}
