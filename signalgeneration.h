#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <stdbool.h>
#include <stdio.h>
/* Useful macros */
#define SYNC_LINES 2
#define BACKPORCH_LINES 33
#define FRONTPORCH_LINES 10
#define VIDEO_LINES 480
#define SUM(a,b,c) a+b+c
#define BEGINSCREEN SUM(SYNC_LINES, BACKPORCH_LINES, 0)
#define ENDNUMBER SUM(SYNC_LINES, BACKPORCH_LINES, 0) + 56
#define ENDOFSCREEN SUM(SYNC_LINES, BACKPORCH_LINES, VIDEO_LINES) - 1
#define PIX_W 80
#define PIX_H 60
#define SCREEN_CENTER_Y PIX_H/2
#define SCREEN_CENTER_X PIX_W/2
#define LEFTBAR_X 5
#define RIGHTBAR_X 74
#define BARLENGTH 5

/* Color definitions */
#define WHITE 0x3C0
#define BLACK 0x80
#define RED 0x180
#define GREEN 0x282
#define BLUE 0xC0
#define PINK 0xFF

/* Direction definitions */
enum direction {LEFT, RIGHT, UP, DOWN, LEFTUP, RIGHTDOWN, LEFTDOWN, RIGHTUP};

struct ball {
    int16_t x_position_ball;
    int16_t y_position_ball;
    int16_t direction;
    int16_t *score_ptr;
};

struct vga {
    int16_t lines;
    int16_t effective_lines;
    int16_t refresh_count;
    int16_t *current_ball_buffer;
    int16_t *previous_ball_buffer;
    int16_t *state_ptr;
    int16_t *draw_ptr;
    int16_t *second_state_ptr;
};

struct game {
    int16_t score_1;
    int16_t score_2;
    bool start;
    bool reset;
    bool set_score_1;
    int16_t y_topposition_leftbar;
    int16_t y_topposition_rightbar;
};

void HSYNC(void);
void VSYNC(void);

static void moveLeftBar(int16_t *const);
static void moveRightBar(int16_t *const, const struct ball *const);
//static void outOfBoundsHandler(struct ball *const, uint8_t *const, uint8_t *const, uint8_t *const, uint8_t *const, uint8_t *const);
static void outOfBoundsHandler(struct ball *const, struct game *const, struct vga *const);
static void calculateStates(uint16_t *const, const uint8_t *const, const uint8_t *const, const struct ball *const Ball);
static void getBallBuffer(uint16_t *const, const struct ball *const);
static void moveBall(struct ball *const);
static void calculateNewDirection(struct ball *const);
static void setNumber(uint16_t [8][80], const uint16_t [8][8], uint8_t, uint8_t, uint8_t);
static void changeDirectionOnLeftBarHit(struct ball *const, int16_t);
static void changeDirectionOnRightBarHit(struct ball *const, int16_t);


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */


