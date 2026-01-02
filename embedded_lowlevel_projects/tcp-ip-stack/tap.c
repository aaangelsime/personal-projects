#include "tap.h"
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/if.h>
#include <linux/if_tun.h>
#include <stdio.h>
#include <stdlib.h>

int tap_allocate(char *dev)
{
    struct ifreq ifr; // Interface request structure
    int fd;

    // Open TAP char device
    // Opens a connection to the systems "TUN/TAP" driver
    fd = open("/dev/net/tun", O_RDWR);

    if (fd < 0)
    {
        perror("open /dev/net/tun");
        exit(1);
    }

    // Zero structure to avoid trash flags
    memset(&ifr, 0, sizeof(ifr));

    // IFF_TAP  -> Ethernet Device 
    //          -> Faking the signal, including MAC address

    // IFF_NO_PI -> Disable extra packet info header
    //           -> Doesn't add any extra instructional stickers to the packets. raw data only
    ifr.ifr_flags = IFF_TAP | IFF_NO_PI;

    // Request specific device name (e.g., "tap0")
    // If name isn't picked, linux will pick one (e.g., "tap1")
    if(*dev)
        strncpy(ifr.ifr_name, dev, IFNAMSIZ);

    // Register device with kernel
    if (ioctl(fd, TUNSETIFF, &ifr) < 0)
    {
        perror("ioctl TUNSETIFF");
        close(fd);
        exit(1);
    }

    // Kernal may assign a different name; copy it back
    strcpy(dev, ifr.ifr_name);

    return fd;
}


