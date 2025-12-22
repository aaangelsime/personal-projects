/*
Provides a pointer casting fn that treats a memory address (buffer) as a struct type
enabling direct member access like eth->smac without moving or duplicating the data in RAM
*/
#include "ethernet.h"

//simply casts buffer to Ethernet header
//caller must ensure buffer length >= sizeof(struct eth_header)
struct eth_header *eth_parse(uint8_t *buf)
{
    return(struct eth_header *)buf;
}