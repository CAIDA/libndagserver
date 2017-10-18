#ifndef NDAGMULTICASTER_H_
#define NDAGMULTICASTER_H_

#include <stdlib.h>
#include <sys/types.h>
#include <libtrace.h>

#define NDAG_MAX_DGRAM_SIZE (8900)

#define NDAG_MAGIC_NUMBER (0x4E444147)
#define NDAG_EXPORT_VERSION 1

/* Note: libtrace.h provides PACKED for us... */

/* Required for multicasting NDAG records */

typedef struct ndagbeaconparams {
    char *groupaddr;
    uint16_t beaconport;
    uint16_t numstreams;
    uint16_t *streamports;
    uint32_t frequency;
    uint16_t monitorid;
} ndag_beacon_params_t;

enum {
    NDAG_PKT_BEACON = 0x01,
    NDAG_PKT_ENCAPERF = 0x02,
    NDAG_PKT_RESTARTED = 0x03,
    NDAG_PKT_ENCAPRT = 0x04,
};

/* == Protocol header structures == */

/* Common header -- is prepended to all exported records */
typedef struct ndag_common_header {
    uint32_t magic;
    uint8_t version;
    uint8_t type;
    uint16_t monitorid;
} PACKED ndag_common_t;

/* Beacon -- structure is too simple to be worth defining as a struct */
/*
 * uint16_t numberofstreams;
 * uint16_t firststreamport;
 * uint16_t secondstreamport;
 * ....
 * uint16_t laststreamport;
 */

int ndag_interrupt_beacon(void);
void *ndag_start_beacon(void *params);
int ndag_create_multicaster_socket(uint16_t port, char *groupaddr);
int ndag_send_encap_records(int sock, char *buf, uint32_t tosend,
        uint16_t reccount);
int ndag_send_encap_libtrace(int sock, libtrace_packet_t *packet);


#endif
// vim: set sw=4 tabstop=4 softtabstop=4 expandtab :
