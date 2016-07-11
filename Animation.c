
#include "Animation.h"

#include "Model.h"

#define ANIM_MATRIX   8
#define MAXFRAME      (ANIM_MATRIX*(smoothDegree))

long int frame = 0;
int smoothDegree = 16;

char sprint = 0;


const float MovX_sprint[16][ANIM_MATRIX] = {
{ 0,5,10,5,0,-5,-10,-5 },
{0,0,0,0,0,0,0,0 },
{ -10,-20,-30,-20,-10,-15,-20,-15 },
{ 35, 30, 20, 40, 45, 55, 45, 40 },

{ 145, 90, 45, 45, 90, 100, 135, 170 },
{0,0,0,0,0,0,0,0 },
{ -45, -45, 0, -40, -90, -90, -135, -90 },

{ 150, 135, 90, 50, 80, 110, 130, 180 },
{0,0,0,0,0,0,0,0 },
{ -90, -45, -40, 0, -90, -90, -130,-45 },

{ 20, 10, 20, 45, 90, 135, 135, 70 },
{0,0,0,0,0,0,0,0 },
{ 45, 90, 110, 135, 90, 45, 10, 20 },

{ 10, 20, 45, 90, 120, 110, 90, 45 },
{0,0,0,0,0,0,0,0 },
{ 90, 135, 90, 90, 45, 30, 0, 30 },
};




#if 0
const float MovX_walk[16][ANIM_MATRIX] = {
  {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0}, /* Trunk                    0                     */
  {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0}, /* Neck                     1                     */
  {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0}, /* Head                     2                     */
  {  0.0, 10.0, 10.0, 10.0,  0.0, 10.0, 10.0, 10.0}, /* Tail                     3                     */
  {-30.0,-15.0, 15.0, 30.0,  0.0,-30.0,-15.0,-45.0}, /* Right Back Leg Joint      4                     */
  {000.0,000.0,000.0,000.0,000.0,000.0,000.0,000.0}, /* Right Back leg            5                     */
  { 60.0, 90.0, 30.0,-45.0,  0.0, 60.0, 45.0, 60.0}, /* Lower Right Back Leg      6                     */
  {  0.0,  0.0,-30.0,-30.0, 45.0, 30.0, 30.0,-45.0}, /* Left Back Leg Joint     7                     */
  {000.0,000.0,000.0,000.0,000.0,000.0,000.0,000.0}, /* Left Back Leg           8                     */
  {  0.0,  0.0, 60.0,120.0,  0.0,-30.0,-15.0, 45.0}, /* Lower Left Back Leg     9                     */
  {  0.0,-30.0,-30.0,-60.0,-45.0, 60.0, 45.0,-45.0}, /* Right Front Leg Joint     10                    */
  {000.0,000.0,000.0,000.0,000.0,000.0,000.0,000.0}, /* Right Front Leg           11                    */
  { 20.0, 30.0, 45.0, 75.0, 45.0,-90.0,-15.0, 90.0}, /* Lower Right Front Leg     12                    */
  { 30.0, 30.0, 30.0, 30.0, 30.0,-45.0,-45.0, 75.0}, /* Left Front Leg Joint    13                    */
  {000.0,000.0,000.0,000.0,000.0,000.0,000.0,000.0}, /* Left Front Leg          14                    */
  {  0.0,-30.0,-15.0,-15.0,-15.0, 15.0, 60.0,-90.0}  /* Lower Left Front Leg    15                    */
};
#endif

const float MovX_walk[16][ANIM_MATRIX] = {
{0,0,0,0,0,0,0,0 },
{0,0,0,0,0,0,0,0 },
{0,0,0,0,0,0,0,0 },
{55,65,65,65,55,65,65,65 },
{70,115,150,125,125,110,105,85},
{0,0,0,0,0,0,0,0 },
{-45,-100,-90,-30,-45,-55,-70,-60 },
{105,95,85,75,65,85,135,125},
{0,0,0,0,0,0,0,0 },
{-45,-45,-45,-30,-50,-90,-75,-45 },
{65,60,55,70,110,95,80,70 },
{0,0,0,0,0,0,0,0 },
{10,30,40,80,40,20,10,10 },
{90,105,90,65,60,45,50,70 },
{0,0,0,0,0,0,0,0 },
{45,30,20,25,35,30,45,90 }
};


void calculateMatrix(void) {
  // Prevent matrix overflow
  int myframe = frame % MAXFRAME;
  // for each member
  for (int i = 0; i < 16; i++) {
    float averageAngle;
    int frameSmooth = myframe/smoothDegree;
    int frameSmoothPlusOne = ((myframe/smoothDegree)+1) % ANIM_MATRIX;
    if (sprint) {
      averageAngle = (MovX_sprint[i][frameSmooth] * (1.0 - ((float)(myframe%smoothDegree)/(float)smoothDegree))) +
      (MovX_sprint[i][frameSmoothPlusOne] * ((float)(myframe%smoothDegree)/(float)smoothDegree));
    } else {
      averageAngle = (MovX_walk[i][frameSmooth] * (1.0 - ((float)(myframe%smoothDegree)/(float)smoothDegree))) +
      (MovX_walk[i][frameSmoothPlusOne] * ((float)(myframe%smoothDegree)/(float)smoothDegree));
    }
    angles[i][0] = averageAngle;
    angles[i][1] = 0.0;
    angles[i][2] = 0.0;
  }
}
