float SCALE = 1.3;
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

int rotateAngle = 90;

void lowerLeftBackLeg(){
	glPushMatrix();
		glRotatef(-35, 1, 0, 0);
		glTranslatef(0, 0, JOINT_WIDTH /1.5);
		glutSolidCylinder(BACK_LEG_1_WIDTH,BACK_LEG_1_LENGTH/1.5, 16, 16);
	glPopMatrix();
}

void leftBackLeg(){
	glPushMatrix();
		glRotatef(100, 1, 0, 0);
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
		glutSolidSphere(JOINT_WIDTH, 16, 16);		
		leftBackLeg();
	glPopMatrix();
}

void lowerRightBackLeg(){
	glPushMatrix();
		glRotatef(-35, 1, 0, 0);
		glTranslatef(0, 0, JOINT_WIDTH /1.5);
		glutSolidCylinder(BACK_LEG_1_WIDTH,BACK_LEG_1_LENGTH/1.5, 16, 16);
	glPopMatrix();
}

void rightBackLeg(){
	glPushMatrix();
		glRotatef(100, 1, 0, 0);
		glTranslatef(0, 0, JOINT_WIDTH );
		glutSolidCylinder(BACK_LEG_1_WIDTH,BACK_LEG_1_LENGTH/2, 16, 16);
		glTranslatef(0,0,BACK_LEG_1_LENGTH/2 + JOINT_WIDTH/1.5);
		glutSolidSphere(JOINT_WIDTH/1.5,16,16);
		lowerLeftBackLeg();
	glPopMatrix();
}

void rightBackLegJoint(){
	glPushMatrix();
		glTranslatef(-JOINT_WIDTH*1.5, -0.03/SCALE, TRUNK_LENGTH );
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
		glTranslatef(0, 0, JOINT_WIDTH /1.5);
		glutSolidCylinder(BACK_LEG_1_WIDTH,BACK_LEG_1_LENGTH/1.3, 16, 16);
	glPopMatrix();
}

void leftFrontLeg(){
	glPushMatrix();
		glRotatef(75, 1, 0, 0);
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
		glutSolidSphere(JOINT_WIDTH*1.3, 16, 16);		
		leftFrontLeg();
	glPopMatrix();
}

void lowerRightFrontLeg(){
	glPushMatrix();
		glRotatef(35, 1, 0, 0);
		glTranslatef(0, 0, JOINT_WIDTH /1.5);
		glutSolidCylinder(BACK_LEG_1_WIDTH,BACK_LEG_1_LENGTH/1.3, 16, 16);
	glPopMatrix();
}

void rightFrontLeg(){
	glPushMatrix();
		glRotatef(75, 1, 0, 0);
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
		glutSolidSphere(JOINT_WIDTH/1.5, 16, 16);
		glTranslatef(0,0,JOINT_WIDTH/3);
		glutSolidCone(HEAD_WIDTH,HEAD_LENGTH,16,16);
	glPopMatrix();
}

void neck() {
	glPushMatrix();
		glRotatef(200, 1, 0, 0);
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
		glutSolidSphere(JOINT_WIDTH/1.5, 16, 16);
		glTranslatef(0,0,JOINT_WIDTH/3);
		glutSolidCylinder(TRUNK_WIDTH, TRUNK_LENGTH*0.4, 16, 16);
	glPopMatrix();	
}

void trunk(){
	glPushMatrix();
		glRotatef(rotateAngle, 0.0, 1.0, 0.0);
		glRotatef(0, 1.0, 0.0, 0.0);
		glTranslatef(0, 0, -TRUNK_LENGTH/2.0 );
		glColor3f(1.0, 1.0, 1.0);
		glutWireCylinder(TRUNK_WIDTH*3,TRUNK_LENGTH/2.4, 8, 8);
		glTranslatef(0, 0.1/SCALE, -0.1/SCALE);
		glutSolidCylinder(TRUNK_WIDTH,TRUNK_LENGTH*1.1, 16, 16);
		backLegs();
		frontLegs();
		neck();
		tail();
	glPopMatrix();
}
void drawModel() {
	trunk();
}