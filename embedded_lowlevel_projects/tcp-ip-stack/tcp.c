#include <stdio.h>
#include <string.h>
#include <arpa/inet.h> // for htons, htonl, ntohs, ntohl

#include "tcp.h"
#include "ethernet.h"

/*
A basic network listener that watches for incoming connection requests 
and performs the initial steps required to establish a reliable TCP 
connection between two computers
*/

// TCP checksum with pseudo-header
uint16_t tcp_checksum(const uint8_t *src_ip, const uint8_t *dst_ip,
                      const tcp_header_t *tcp, const uint8_t *payload, size_t payload_len) 
{
    uint32_t sum = 0;

// adds up all the num in Ip addresses & ports
// << 8 is a bitwise shift ~ a way to combine two 8 bit num into on 16 bit num
// pseudo-header
sum += (src_ip[0] << 8) + src_ip[1];
sum += (src_ip[2] << 8) + src_ip[3];
sum += (dst_ip[0] << 8) + dst_ip[1];
sum += (dst_ip[2] << 8) + dst_ip[3];

sum += htons(6); // tcp protocal 
sum += htons(TCP_HEADER_LEN + payload_len);

    // Send via IPv4
    ipv4_send(dst_ip, src_ip, 6, (uint8_t*)&tcp, TCP_HEADER_LEN);
}


// Minimal TCP listener
void tcp_listen(uint16_t port, const uint8_t *my_ip) 
{
    while(1) 
    {
        tcp_header_t incoming;
        uint8_t src_ip[4];
        uint16_t src_port;

        size_t len = ipv4_receive(src_ip, 6, (uint8_t*)&incoming, sizeof(incoming));
        if(len < TCP_HEADER_LEN) continue;

        src_port = ntohs(incoming.src_port);

        // sees a request to connect ~ sends a reply printf
        if(incoming.flags & TCP_FLAG_SYN) 
        {
            uint32_t isn = 1000; // simple static ISN
            printf("Received SYN from port %u, sending SYN-ACK...\n", src_port);
            tcp_send_synack(port, src_port, isn, ntohl(incoming.seq_num)+1, my_ip, src_ip);
        } 
        // sees the final confirmation and prints printf
        else if(incoming.flags & TCP_FLAG_ACK)
        {
            printf("TCP connection established with port %u\n", src_port);
        }
    }
}