#pragma once
#include <stdint.h>

#define ETH_ADDR_LEN 6

// Ethernet header (14 bytes total)
struct eth_header {
    uint8_t  dmac[ETH_ADDR_LEN];  // Destination MAC
    uint8_t  smac[ETH_ADDR_LEN];  // Source MAC
    uint16_t ether_type;          // EtherType (IPv4, ARP, etc)
} __attribute__((packed));

// Parse raw buffer into Ethernet header
struct eth_header *eth_parse(uint8_t *buf);
