evdev-yoga-daemon
=================

*NEW! Now supports (and requires) the on screen keyboard program OnBoard*

This is a daemon that listens for thinkpad 2-in-1 device switch mode events on an ACPI objected registered with evdev.

(Ie. runs on systems like Void Linux, some Gentoo systems, possibly others..)

It does not use or support standard libinput / udev libraries at this time.

When the laptop is converted to tablet mode the keyboard, trackpoint and trackpad / buttons are all explicitly disabled with `xinput`.

When the laptop is converted back to laptop mode, the above devices are explicitly enabled with `xinput`

Reqs:

* user must be in the input group (or be root etc) to run the program
* xinput (assumed to be installed)
* onboard (assumed to be installed)

Build reqs:

* libevdev libraries and a bunch of stdlib stuff.
* make & pkgconfig (assumed to be installed)
* gcc
