
#include "Animation.h"

#include "Model.h"

#define ANIM_MATRIX   16
#define MAXFRAME      16*(smoothDegree)

int frame = 0;
char smoothDegree = 8;

const float MovX[16][ANIM_MATRIX] = {
  {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0}, /* Trunk                    0                     */
  {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0}, /* Neck                     1                     */
  {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0}, /* Head                     2                     */
  {  0.0, 10.0, 10.0, 10.0,  0.0, 10.0, 10.0, 10.0,  0.0, 10.0, 10.0, 10.0,  0.0, 10.0, 10.0, 10.0}, /* Tail                     3                     */
  {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0}, /* Left Back Leg Joint      4                     */
  {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0}, /* Left Back leg            5                     */
  {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0}, /* Lower Left Back Leg      6                     */
  {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0}, /* Right Back Leg Joint     7                     */
  {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0}, /* Right Back Leg           8                     */
  {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0}, /* Lower Right Back Leg     9                     */
  {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0}, /* Left Front Leg Joint     10                    */
  {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0}, /* Left Front Leg           11                    */
  {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0}, /* Lower Left Front Leg     12                    */
  {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0}, /* Right Front Leg Joint    13                    */
  {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0}, /* Right Front Leg          14                    */
  {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0}  /* Lower Right Front Leg    15                    */
};
void calculateMatrix(void) {
  // Prevent matrix overflow
  frame %= MAXFRAME;
  // for each member
  for (int i = 0; i < 16; i++) {
    float averageAngle;
    int frameSmooth = frame/smoothDegree;
    int frameSmoothPlusOne = ((frame/smoothDegree)+1) % ANIM_MATRIX;
    averageAngle = (MovX[i][frameSmooth] * (1.0 - ((float)(frame%smoothDegree)/(float)smoothDegree))) + (MovX[i][frameSmoothPlusOne] * ((float)(frame%smoothDegree)/(float)smoothDegree));
    angles[i][0] = averageAngle;
    angles[i][1] = 0.0;
    angles[i][2] = 0.0;
  }
}
