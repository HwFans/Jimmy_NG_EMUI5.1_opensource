#ifndef __FP_VENDOR_H__
#define __FP_VENDOR_H__

enum {
    FP_VENDOR_INVALID = 0,
    FPC_VENDOR,
    GOODIX_VENDOR_3268,
    LEADCORE_VENDOR,
    CHIPSAIL_VENDOR,
    GOODIX_VENDOR_3258,
};

int get_fp_vendor(void);

#endif  /*__FP_VENDOR_H__*/
