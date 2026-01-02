#pragma once 
#include <stdint.h>
#include <stddef.h>

#define TCP_HEADER_LEN 20

// TCP Flags
#define TCP_FLAG_FIN 0x01
#define TCP_FLAG_SYN 0x02
#define TCP_FLAG_RST 0x04
#define TCP_FLAG_PSH 0x08
#define TCP_FLAG_ACK 0x10
#define TCP_FLAG_URG 0x20

// TCP header struct
typedef struct __attribute__((packed))
{
    uint16_t src_port;
    uint16_t dst_port;
    uint32_t seq_num;
    uint32_t ack_num;
    uint8_t data_offset_reserved; // 4 bit header len, 4 bit reserved
    uint8_t flags;
    uint16_t window;
    uint16_t checksum;
    uint16_t urgent_pointer;
} tcp_header_t;

// fn declarations 
uint16_t tcp_checksum(const uint8_t *src_ip, const uint8_t *dst_ip,
                      const tcp_header_t *tcp, const uint8_t *payload, size_t payload_len);

void tcp_send_synack(uint16_t src_port, uint16_t dst_port,
                     uint32_t seq, uint32_t ack,
                     const uint8_t *src_ip, const uint8_t *dst_ip);

void tcp_listen(uint16_t port, const uint8_t *my_ip);