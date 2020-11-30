!! evdev-yoga-daemon

This is a daemon that listens for thinkpad 2-in-1 device switch mode events on an ACPI objected registered with evdev.

(Ie. runs on systems like Void Linux, some Gentoo systems, possibly others..)

It does not use or support standard libinput / udev libraries at this time.

When the laptop is converted to tablet mode the keyboard, trackpoint and trackpad / buttons are all explicitly disabled with `xinput`.

When the laptop is converted back to tablet mode, the above devices are explicitly enabled with `xinput`

Reqs:

* run as root (!)
* xinput (assumed to be installed)

Build reqs:

* libevdev libraries and a bunch of stdlib stuff.
* make & pkgconfig (assumed to be installed)
