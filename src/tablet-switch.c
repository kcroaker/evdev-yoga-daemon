#include "backend.h"

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
	sprintf(command, "pkill onboard");
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
	sprintf(command, "nohup onboard &");
	system(command);
	return;
}
