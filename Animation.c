
#include "Animation.h"

#include "Model.h"

#define ANIM_MATRIX   8
#define MAXFRAME      (ANIM_MATRIX*(smoothDegree))

long int frame = 0;
int smoothDegree = 16;

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
void calculateMatrix(void) {
  // Prevent matrix overflow
  int myframe = frame % MAXFRAME;
  // for each member
  for (int i = 0; i < 16; i++) {
    float averageAngle;
    int frameSmooth = myframe/smoothDegree;
    int frameSmoothPlusOne = ((myframe/smoothDegree)+1) % ANIM_MATRIX;
    averageAngle = (MovX_walk[i][frameSmooth] * (1.0 - ((float)(myframe%smoothDegree)/(float)smoothDegree))) + (MovX_walk[i][frameSmoothPlusOne] * ((float)(myframe%smoothDegree)/(float)smoothDegree));
    angles[i][0] = averageAngle;
    angles[i][1] = 0.0;
    angles[i][2] = 0.0;
  }
}
