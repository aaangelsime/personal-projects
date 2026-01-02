#pragma once

// Allocate and config a TAP virtual network device
// Returns file descriptor for read/write of ethernet frame
int tap_allocate(char *dev);
