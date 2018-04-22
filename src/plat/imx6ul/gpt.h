#ifndef __PLAT_IMX6UL_GPT__
#define __PLAT_IMX6UL_GPT__

#include <pb_types.h>

#define GP_TIMER1_BASE 0x02098000

#define GP_TIMER_CR  0x0000
#define GP_TIMER_PR  0x0004
#define GP_TIMER_SR  0x0008
#define GP_TIMER_CNT 0x0024

struct gp_timer {
    __iomem base;
    u32 pr;
    u32 cr;
};

void gp_timer_init(struct gp_timer *d);

u32 gp_timer_get_tick(struct gp_timer *d);

#endif
