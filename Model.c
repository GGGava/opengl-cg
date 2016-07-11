
#include "Model.h"

#include "Animation.h"

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

// Global Variables
int rotateAngle = 90;
float SCALE = 1.3;

// Movement matrices
float angles[16][3] = {
  {   0.0,    0.0,    0.0}, /* Trunk                    0                     */
  {   0.0,    0.0,    0.0}, /* Neck                     1                     */
  {   0.0,    0.0,    0.0}, /* Head                     2                     */
  {   0.0,    0.0,    0.0}, /* Tail                     3                     */
  {   0.0,    0.0,    0.0}, /* Left Back Leg Joint      4                     */
  {   0.0,    0.0,    0.0}, /* Left Back leg            5                     */
  {   0.0,    0.0,    0.0}, /* Lower Left Back Leg      6                     */
  {   0.0,    0.0,    0.0}, /* Right Back Leg Joint     7                     */
  {   0.0,    0.0,    0.0}, /* Right Back Leg           8                     */
  {   0.0,    0.0,    0.0}, /* Lower Right Back Leg     9                     */
  {   0.0,    0.0,    0.0}, /* Left Front Leg Joint     10                    */
  {   0.0,    0.0,    0.0}, /* Left Front Leg           11                    */
  {   0.0,    0.0,    0.0}, /* Lower Left Front Leg     12                    */
  {   0.0,    0.0,    0.0}, /* Right Front Leg Joint    13                    */
  {   0.0,    0.0,    0.0}, /* Right Front Leg          14                    */
  {   0.0,    0.0,    0.0}  /* Lower Right Front Leg    15                    */
};

void lowerLeftBackLeg(){
  glPushMatrix();
    glRotatef(-35, 1, 0, 0);
    glRotatef(angles[ANGLE_LOWER_LEFT_BACK_LEG][0], 1.0, 0.0, 0.0);
    glRotatef(angles[ANGLE_LOWER_LEFT_BACK_LEG][1], 0.0, 1.0, 0.0);
    glRotatef(angles[ANGLE_LOWER_LEFT_BACK_LEG][2], 0.0, 0.0, 1.0);
    glTranslatef(0, 0, JOINT_WIDTH /1.5);
    glutSolidCylinder(BACK_LEG_1_WIDTH,BACK_LEG_1_LENGTH/1.5, 16, 16);
  glPopMatrix();
}

void leftBackLeg(){
  glPushMatrix();
    glRotatef(100, 1, 0, 0);
    glRotatef(angles[ANGLE_LEFT_BACK_LEG][0], 1.0, 0.0, 0.0);
    glRotatef(angles[ANGLE_LEFT_BACK_LEG][1], 0.0, 1.0, 0.0);
    glRotatef(angles[ANGLE_LEFT_BACK_LEG][2], 0.0, 0.0, 1.0);
    glTranslatef(0, 0, JOINT_WIDTH );
    glutSolidCylinder(BACK_LEG_1_WIDTH,BACK_LEG_1_LENGTH/2, 16, 16);
    glTranslatef(0,0,BACK_LEG_1_LENGTH/2 + JOINT_WIDTH/1.5);
    glutSolidSphere(JOINT_WIDTH/1.5,16,16);
    lowerLeftBackLeg();
  glPopMatrix();
}

void leftBackLegJoint(){
  glPushMatrix();
    glTranslatef(JOINT_WIDTH*1.5, -0.03/SCALE, TRUNK_LENGTH );
    glRotatef(angles[ANGLE_LEFT_BACK_LEG_JOINT][0], 1.0, 0.0, 0.0);
    glRotatef(angles[ANGLE_LEFT_BACK_LEG_JOINT][1], 0.0, 1.0, 0.0);
    glRotatef(angles[ANGLE_LEFT_BACK_LEG_JOINT][2], 0.0, 0.0, 1.0);
    glutSolidSphere(JOINT_WIDTH, 16, 16);
    leftBackLeg();
  glPopMatrix();
}

void lowerRightBackLeg(){
  glPushMatrix();
    glRotatef(-35, 1, 0, 0);
    glRotatef(angles[ANGLE_LOWER_RIGHT_BACK_LEG][0], 1.0, 0.0, 0.0);
    glRotatef(angles[ANGLE_LOWER_RIGHT_BACK_LEG][1], 0.0, 1.0, 0.0);
    glRotatef(angles[ANGLE_LOWER_RIGHT_BACK_LEG][2], 0.0, 0.0, 1.0);
    glTranslatef(0, 0, JOINT_WIDTH /1.5);
    glutSolidCylinder(BACK_LEG_1_WIDTH,BACK_LEG_1_LENGTH/1.5, 16, 16);
  glPopMatrix();
}

void rightBackLeg(){
  glPushMatrix();
    glRotatef(100, 1, 0, 0);
    glRotatef(angles[ANGLE_RIGHT_BACK_LEG][0], 1.0, 0.0, 0.0);
    glRotatef(angles[ANGLE_RIGHT_BACK_LEG][1], 0.0, 1.0, 0.0);
    glRotatef(angles[ANGLE_RIGHT_BACK_LEG][2], 0.0, 0.0, 1.0);
    glTranslatef(0, 0, JOINT_WIDTH );
    glutSolidCylinder(BACK_LEG_1_WIDTH,BACK_LEG_1_LENGTH/2, 16, 16);
    glTranslatef(0,0,BACK_LEG_1_LENGTH/2 + JOINT_WIDTH/1.5);
    glutSolidSphere(JOINT_WIDTH/1.5,16,16);
    lowerRightBackLeg();
  glPopMatrix();
}

void rightBackLegJoint(){
  glPushMatrix();
    glTranslatef(-JOINT_WIDTH*1.5, -0.03/SCALE, TRUNK_LENGTH );
    glRotatef(angles[ANGLE_RIGHT_BACK_LEG_JOINT][0], 1.0, 0.0, 0.0);
    glRotatef(angles[ANGLE_RIGHT_BACK_LEG_JOINT][1], 0.0, 1.0, 0.0);
    glRotatef(angles[ANGLE_RIGHT_BACK_LEG_JOINT][2], 0.0, 0.0, 1.0);
    glutSolidSphere(JOINT_WIDTH, 16, 16);
    rightBackLeg();
  glPopMatrix();
}

void backLegs() {
    leftBackLegJoint();
    rightBackLegJoint();
}

void lowerLeftFrontLeg(){
  glPushMatrix();
    glRotatef(35, 1, 0, 0);
    glRotatef(angles[ANGLE_LOWER_LEFT_FRONT_LEG][0], 1.0, 0.0, 0.0);
    glRotatef(angles[ANGLE_LOWER_LEFT_FRONT_LEG][1], 0.0, 1.0, 0.0);
    glRotatef(angles[ANGLE_LOWER_LEFT_FRONT_LEG][2], 0.0, 0.0, 1.0);
    glTranslatef(0, 0, JOINT_WIDTH /1.5);
    glutSolidCylinder(BACK_LEG_1_WIDTH,BACK_LEG_1_LENGTH/1.3, 16, 16);
  glPopMatrix();
}

void leftFrontLeg(){
  glPushMatrix();
    glRotatef(75, 1, 0, 0);
    glRotatef(angles[ANGLE_LEFT_FRONT_LEG][0], 1.0, 0.0, 0.0);
    glRotatef(angles[ANGLE_LEFT_FRONT_LEG][1], 0.0, 1.0, 0.0);
    glRotatef(angles[ANGLE_LEFT_FRONT_LEG][2], 0.0, 0.0, 1.0);
    glTranslatef(0, 0, JOINT_WIDTH*1.3 );
    glutSolidCylinder(BACK_LEG_1_WIDTH,BACK_LEG_1_LENGTH/2, 16, 16);
    glTranslatef(0,0,BACK_LEG_1_LENGTH/2 + JOINT_WIDTH/1.5);
    glutSolidSphere(JOINT_WIDTH/1.5,16,16);
    lowerLeftFrontLeg();
  glPopMatrix();
}

void leftFrontLegJoint(){
  glPushMatrix();
    glTranslatef(JOINT_WIDTH*1.5, -0.08/SCALE,0);
    glRotatef(angles[ANGLE_LEFT_FRONT_LEG_JOINT][0], 1.0, 0.0, 0.0);
    glRotatef(angles[ANGLE_LEFT_FRONT_LEG_JOINT][1], 0.0, 1.0, 0.0);
    glRotatef(angles[ANGLE_LEFT_FRONT_LEG_JOINT][2], 0.0, 0.0, 1.0);
    glutSolidSphere(JOINT_WIDTH*1.3, 16, 16);		
    leftFrontLeg();
  glPopMatrix();
}

void lowerRightFrontLeg(){
  glPushMatrix();
    glRotatef(35, 1, 0, 0);
    glRotatef(angles[ANGLE_LOWER_RIGHT_FRONT_LEG][0], 1.0, 0.0, 0.0);
    glRotatef(angles[ANGLE_LOWER_RIGHT_FRONT_LEG][1], 0.0, 1.0, 0.0);
    glRotatef(angles[ANGLE_LOWER_RIGHT_FRONT_LEG][2], 0.0, 0.0, 1.0);
    glTranslatef(0, 0, JOINT_WIDTH /1.5);
    glutSolidCylinder(BACK_LEG_1_WIDTH,BACK_LEG_1_LENGTH/1.3, 16, 16);
  glPopMatrix();
}

void rightFrontLeg(){
  glPushMatrix();
    glRotatef(75, 1, 0, 0);
    glRotatef(angles[ANGLE_RIGHT_FRONT_LEG][0], 1.0, 0.0, 0.0);
    glRotatef(angles[ANGLE_RIGHT_FRONT_LEG][1], 0.0, 1.0, 0.0);
    glRotatef(angles[ANGLE_RIGHT_FRONT_LEG][2], 0.0, 0.0, 1.0);
    glTranslatef(0, 0, JOINT_WIDTH*1.3 );
    glutSolidCylinder(BACK_LEG_1_WIDTH,BACK_LEG_1_LENGTH/2, 16, 16);
    glTranslatef(0,0,BACK_LEG_1_LENGTH/2 + JOINT_WIDTH/1.5);
    glutSolidSphere(JOINT_WIDTH/1.5,16,16);
    lowerRightFrontLeg();
  glPopMatrix();
}

void rightFrontLegJoint(){
  glPushMatrix();
    glTranslatef(-JOINT_WIDTH*1.5, -0.08/SCALE,0);
    glRotatef(angles[ANGLE_RIGHT_FRONT_LEG_JOINT][0], 1.0, 0.0, 0.0);
    glRotatef(angles[ANGLE_RIGHT_FRONT_LEG_JOINT][1], 0.0, 1.0, 0.0);
    glRotatef(angles[ANGLE_RIGHT_FRONT_LEG_JOINT][2], 0.0, 0.0, 1.0);
    glutSolidSphere(JOINT_WIDTH*1.3, 16, 16);		
    rightFrontLeg();
  glPopMatrix();
}

void frontLegs() {
  leftFrontLegJoint();
  rightFrontLegJoint();
}

void head(){
  glPushMatrix();
    glTranslatef(0,0,NECK_LENGTH + JOINT_WIDTH/3);
    glRotatef(-15, 1, 0, 0);
    glRotatef(angles[ANGLE_HEAD][0], 1.0, 0.0, 0.0);
    glRotatef(angles[ANGLE_HEAD][1], 0.0, 1.0, 0.0);
    glRotatef(angles[ANGLE_HEAD][2], 0.0, 0.0, 1.0);
    glutSolidSphere(JOINT_WIDTH/1.5, 16, 16);
    glTranslatef(0,0,JOINT_WIDTH/3);
    glutSolidCone(HEAD_WIDTH,HEAD_LENGTH,16,16);
  glPopMatrix();
}

void neck() {
  glPushMatrix();
    glRotatef(200, 1, 0, 0);
    glRotatef(angles[ANGLE_NECK][0], 1.0, 0.0, 0.0);
    glRotatef(angles[ANGLE_NECK][1], 0.0, 1.0, 0.0);
    glRotatef(angles[ANGLE_NECK][2], 0.0, 0.0, 1.0);
    glTranslatef(0, 0, JOINT_WIDTH/1.5);
    glutSolidSphere(JOINT_WIDTH/1.5, 16, 16);
    glTranslatef(0, 0, JOINT_WIDTH/1.5);
    glutSolidCylinder(TRUNK_WIDTH,NECK_LENGTH, 16, 16);
    head();
  glPopMatrix();
}

void tail(){
  glPushMatrix();
    glTranslatef(0,0,TRUNK_LENGTH*1.1 + JOINT_WIDTH/3);
    glRotatef(30, 1,0,0);
    glRotatef(angles[ANGLE_TAIL][0], 1.0, 0.0, 0.0);
    glRotatef(angles[ANGLE_TAIL][1], 0.0, 1.0, 0.0);
    glRotatef(angles[ANGLE_TAIL][2], 0.0, 0.0, 1.0);
    glutSolidSphere(JOINT_WIDTH/1.5, 16, 16);
    glTranslatef(0,0,JOINT_WIDTH/3);
    glutSolidCylinder(TRUNK_WIDTH, TRUNK_LENGTH*0.4, 16, 16);
  glPopMatrix();
}

void trunk(){
  glPushMatrix();
    glRotatef(rotateAngle, 0.0, 1.0, 0.0);
    glRotatef(angles[ANGLE_TRUNK][0], 1.0, 0.0, 0.0);
    glRotatef(angles[ANGLE_TRUNK][1], 0.0, 1.0, 0.0);
    glRotatef(angles[ANGLE_TRUNK][2], 0.0, 0.0, 1.0);
    
    
    glTranslatef(0, 0, -TRUNK_LENGTH/2.0);
    glColor3f(1.0, 1.0, 1.0);
    glutWireCylinder(TRUNK_WIDTH*3,TRUNK_LENGTH/2.4, 8, 8);
    glTranslatef(0, 0.1/SCALE, -0.1/SCALE);
    glutSolidCylinder(TRUNK_WIDTH,TRUNK_LENGTH*1.1, 16, 16);
    neck();
    tail();
    backLegs();
    frontLegs();
  glPopMatrix();
}

void drawModel() {
  calculateMatrix();
  trunk();
}
