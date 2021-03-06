#include "common.h"
#ifndef OPENSSL_NO_DH
#define DN_new DH_new
#ifndef HEADER_DH_H
# include <openssl/dh.h>
#endif

DH *get_dh2048()
{
    static unsigned char dhp_2048[] = {
	0xE4, 0xA3, 0x67, 0x3B, 0xA3, 0x47, 0xF1, 0x6E, 0xF9, 0x28, 
	0xAE, 0xFF, 0x75, 0x1F, 0xAB, 0x06, 0xF9, 0xEC, 0x66, 0x46, 
	0x3C, 0x1C, 0x7B, 0xEE, 0xFB, 0xDE, 0xA6, 0xDF, 0x58, 0xC6, 
	0x55, 0x2D, 0x6A, 0x63, 0x1F, 0x26, 0x65, 0x1E, 0xDD, 0x73, 
	0xCD, 0xA7, 0x09, 0x1C, 0x6E, 0x89, 0xB8, 0x07, 0x16, 0xDD, 
	0x45, 0xEE, 0x1F, 0xD4, 0x01, 0x7A, 0xB8, 0xE4, 0x62, 0x29, 
	0x2D, 0xF7, 0xED, 0x52, 0xD5, 0xAF, 0x3F, 0xE1, 0x79, 0xBD, 
	0xA8, 0x40, 0x4E, 0x6C, 0x88, 0x63, 0xD4, 0xE4, 0x36, 0x7E, 
	0xE6, 0x49, 0xAC, 0x3C, 0xE9, 0xBC, 0x72, 0x84, 0x31, 0x26, 
	0x12, 0x86, 0xB2, 0x6B, 0xA0, 0x64, 0x66, 0x3A, 0xAD, 0x40, 
	0xE6, 0x3B, 0xE3, 0x36, 0xE0, 0x10, 0x80, 0x0A, 0xA4, 0x1B, 
	0x6D, 0x6F, 0xD6, 0xDE, 0x57, 0x03, 0xBB, 0x01, 0xFD, 0x2C, 
	0x00, 0x7A, 0x88, 0x4B, 0xE1, 0x86, 0x18, 0x24, 0x33, 0x78, 
	0xC0, 0x73, 0x66, 0xBA, 0x5E, 0xCF, 0x42, 0x0C, 0x1F, 0xA5, 
	0x67, 0xA0, 0x5B, 0x13, 0xA9, 0x00, 0x67, 0xD4, 0x3C, 0x80, 
	0x9B, 0x3D, 0x89, 0xDB, 0x36, 0x8C, 0xC6, 0xD3, 0xEB, 0x05, 
	0x2E, 0x0E, 0xBC, 0x72, 0x36, 0xF3, 0xF7, 0xBF, 0xBF, 0x40, 
	0x86, 0x56, 0xFA, 0x5A, 0x20, 0x13, 0xBD, 0xD6, 0x75, 0xDE, 
	0x5F, 0xCC, 0x0A, 0x48, 0xF6, 0xDC, 0x3A, 0x6F, 0x1B, 0x1C, 
	0x9B, 0xFF, 0x84, 0x2C, 0xC8, 0x4F, 0x95, 0xF1, 0x28, 0x1B, 
	0xE0, 0x35, 0x9D, 0x3B, 0xA8, 0xC0, 0xE0, 0xA7, 0x05, 0x8C, 
	0x58, 0xC5, 0x08, 0x0E, 0x5D, 0xA1, 0x5B, 0xED, 0x1F, 0xDC, 
	0xF5, 0x48, 0xF0, 0xA3, 0x53, 0x7A, 0xE9, 0xFC, 0xF0, 0x77, 
	0x44, 0xE8, 0xC9, 0xB7, 0xAB, 0x26, 0x2E, 0x86, 0xE3, 0xE7, 
	0x9F, 0x1C, 0x41, 0xE5, 0xDC, 0x27, 0x40, 0x3A, 0x80, 0xD7, 
	0x94, 0x99, 0xA6, 0x8A, 0xDA, 0x0B
    };
    static unsigned char dhg_2048[] = {
	0x02
    };
    DH *dh = DN_new();

    if (dh == NULL)
        return NULL;
    dh->p = BN_bin2bn(dhp_2048, sizeof (dhp_2048), NULL);
    dh->g = BN_bin2bn(dhg_2048, sizeof (dhg_2048), NULL);
    if (!dh->p || !dh->g) {
        DH_free(dh);
        return NULL;
    }
    return dh;
}
#endif /* OPENSSL_NO_DH */
