#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <linux/if.h>

#include <tap.h>

#define BUFLEN 1600

int main()
{
    char dev[IFNAMSIZ] = "tap0"; // requested TAP interface name
    uint8_t buf[BUFLEN]; // raw frame buffer

    // creates TAP device and obtains file descriptor
    int tap_fd = tap_alloc(dev);
    printf("TAP device %s created\n", dev);

    while(1)
    {

        // blocking read: waits for ethernet frame from kernel
        int n = read(tap_fd, buf,BUFLEN);
        if (n < 0)
        {
            perror("read");
            continue;
        }

        // at this point, buff contains a full ethernet frame
        printf("Received Ethernet frame (%d bytes)\n", n);
    }

}