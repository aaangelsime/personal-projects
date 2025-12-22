#include "ethernet.h"

//simply casts buffer to Ethernet header
//takes raw pile of data (buf) and puts the struct over the buf which then treats the first 6 bytes 
// as the destination MAC, the next 6 as the source 
//caller must ensure buffer length >= sizeof(struct eth_header)
struct eth_header *eth_parse(uint8_t *buf)
{
    return(struct eth_header *)buf;
}