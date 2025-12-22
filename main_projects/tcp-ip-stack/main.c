#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <linux/if.h>
#include <arpa/inet.h>

#include "tap.h"
#include "ethernet.h"

#define BUFLEN 1600

int main()
{
    tap_init(); // initializes TAP interface
    ethernet_init(); // setup ethernet layer 

    tcp_listen(1337); // listen for incoming tcp connections

    char dev[IFNAMSIZ] = "tap0"; // requested TAP interface name
    uint8_t buf[BUFLEN]; // raw frame buffer

    // creates TAP device and obtains file descriptor
    int tap_fd = tap_allocate(dev);
    printf("TAP device %s created\n", dev);

while (1)
{
    // Blocking read: waits for Ethernet frame from kernel
    int n = read(tap_fd, buf, BUFLEN);
    if (n < 0) {
        perror("read");
        continue;
    }

    // Drop runt frames
    if ((size_t)n < sizeof(struct eth_header)) {
        continue;
    }

    // Parse Ethernet header from buffer
    struct eth_header *eth = eth_parse(buf);

    // Convert ethertype from network byte order
    uint16_t type = ntohs(eth->ether_type);

    printf("Ethernet frame: ");
    printf("SRC %02x:%02x:%02x:%02x:%02x:%02x ",
           eth->smac[0], eth->smac[1], eth->smac[2],
           eth->smac[3], eth->smac[4], eth->smac[5]);

    printf("DST %02x:%02x:%02x:%02x:%02x:%02x ",
           eth->dmac[0], eth->dmac[1], eth->dmac[2],
           eth->dmac[3], eth->dmac[4], eth->dmac[5]);

    printf("TYPE 0x%04x\n", type);
}


}