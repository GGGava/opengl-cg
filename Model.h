#ifndef MODEL_H
#define MODEL_H

// Defines
#define TRUNK_HEIGHT 0.4 / SCALE
#define TRUNK_WIDTH 0.05 / SCALE
#define TRUNK_LENGTH 1.2 / SCALE
#define TRUNK 13

#define JOINT_WIDTH 0.07 / SCALE

#define BACK_LEG_1_LENGTH 0.5 /SCALE
#define BACK_LEG_1_WIDTH 0.05 /SCALE

#define NECK_LENGTH 0.30 /SCALE
#define HEAD_LENGTH 0.2 /SCALE
#define HEAD_WIDTH 0.07 /SCALE

// Global Variables
extern int rotateAngle;
extern float SCALE;
extern int frame;

// Movement matrix
extern float angles[16][3];
#define ANGLE_TRUNK                       0
#define ANGLE_NECK                        1
#define ANGLE_HEAD                        2
#define ANGLE_TAIL                        3
#define ANGLE_LEFT_BACK_LEG_JOINT         4
#define ANGLE_LEFT_BACK_LEG               5
#define ANGLE_LOWER_LEFT_BACK_LEG         6
#define ANGLE_RIGHT_BACK_LEG_JOINT        7
#define ANGLE_RIGHT_BACK_LEG              8
#define ANGLE_LOWER_RIGHT_BACK_LEG        9
#define ANGLE_LEFT_FRONT_LEG_JOINT        10
#define ANGLE_LEFT_FRONT_LEG              11
#define ANGLE_LOWER_LEFT_FRONT_LEG        12
#define ANGLE_RIGHT_FRONT_LEG_JOINT       13
#define ANGLE_RIGHT_FRONT_LEG             14
#define ANGLE_LOWER_RIGHT_FRONT_LEG       15

void drawModel();

#endif