#include "sheval.h"


// order 3
void SHEval3(const float fX, const float fY, const float fZ, float *pSH)
{
   float fC0,fC1,fS0,fS1,fTmpA,fTmpB,fTmpC;
   float fZ2 = fZ*fZ;

   pSH[0] = 0.2820947917738781f;
   pSH[2] = 0.4886025119029199f*fZ;
   pSH[6] = 0.9461746957575601f*fZ2 + -0.3153915652525201f;
   fC0 = fX;
   fS0 = fY;

   fTmpA = -0.48860251190292f;
   pSH[3] = fTmpA*fC0;
   pSH[1] = fTmpA*fS0;
   fTmpB = -1.092548430592079f*fZ;
   pSH[7] = fTmpB*fC0;
   pSH[5] = fTmpB*fS0;
   fC1 = fX*fC0 - fY*fS0;
   fS1 = fX*fS0 + fY*fC0;

   fTmpC = 0.5462742152960395f;
   pSH[8] = fTmpC*fC1;
   pSH[4] = fTmpC*fS1;
}

// order 4
void SHEval4(const float fX, const float fY, const float fZ, float *pSH)
{
   float fC0,fC1,fS0,fS1,fTmpA,fTmpB,fTmpC;
   float fZ2 = fZ*fZ;

   pSH[0] = 0.2820947917738781f;
   pSH[2] = 0.4886025119029199f*fZ;
   pSH[6] = 0.9461746957575601f*fZ2 + -0.3153915652525201f;
   pSH[12] = fZ*(1.865881662950577f*fZ2 + -1.119528997770346f);
   fC0 = fX;
   fS0 = fY;

   fTmpA = -0.48860251190292f;
   pSH[3] = fTmpA*fC0;
   pSH[1] = fTmpA*fS0;
   fTmpB = -1.092548430592079f*fZ;
   pSH[7] = fTmpB*fC0;
   pSH[5] = fTmpB*fS0;
   fTmpC = -2.285228997322329f*fZ2 + 0.4570457994644658f;
   pSH[13] = fTmpC*fC0;
   pSH[11] = fTmpC*fS0;
   fC1 = fX*fC0 - fY*fS0;
   fS1 = fX*fS0 + fY*fC0;

   fTmpA = 0.5462742152960395f;
   pSH[8] = fTmpA*fC1;
   pSH[4] = fTmpA*fS1;
   fTmpB = 1.445305721320277f*fZ;
   pSH[14] = fTmpB*fC1;
   pSH[10] = fTmpB*fS1;
   fC0 = fX*fC1 - fY*fS1;
   fS0 = fX*fS1 + fY*fC1;

   fTmpC = -0.5900435899266435f;
   pSH[15] = fTmpC*fC0;
   pSH[9] = fTmpC*fS0;
}

// order 5
void SHEval5(const float fX, const float fY, const float fZ, float *pSH)
{
   float fC0,fC1,fS0,fS1,fTmpA,fTmpB,fTmpC;
   float fZ2 = fZ*fZ;

   pSH[0] = 0.2820947917738781f;
   pSH[2] = 0.4886025119029199f*fZ;
   pSH[6] = 0.9461746957575601f*fZ2 + -0.3153915652525201f;
   pSH[12] = fZ*(1.865881662950577f*fZ2 + -1.119528997770346f);
   pSH[20] = 1.984313483298443f*fZ*pSH[12] + -1.006230589874905f*pSH[6];
   fC0 = fX;
   fS0 = fY;

   fTmpA = -0.48860251190292f;
   pSH[3] = fTmpA*fC0;
   pSH[1] = fTmpA*fS0;
   fTmpB = -1.092548430592079f*fZ;
   pSH[7] = fTmpB*fC0;
   pSH[5] = fTmpB*fS0;
   fTmpC = -2.285228997322329f*fZ2 + 0.4570457994644658f;
   pSH[13] = fTmpC*fC0;
   pSH[11] = fTmpC*fS0;
   fTmpA = fZ*(-4.683325804901025f*fZ2 + 2.007139630671868f);
   pSH[21] = fTmpA*fC0;
   pSH[19] = fTmpA*fS0;
   fC1 = fX*fC0 - fY*fS0;
   fS1 = fX*fS0 + fY*fC0;

   fTmpA = 0.5462742152960395f;
   pSH[8] = fTmpA*fC1;
   pSH[4] = fTmpA*fS1;
   fTmpB = 1.445305721320277f*fZ;
   pSH[14] = fTmpB*fC1;
   pSH[10] = fTmpB*fS1;
   fTmpC = 3.31161143515146f*fZ2 + -0.47308734787878f;
   pSH[22] = fTmpC*fC1;
   pSH[18] = fTmpC*fS1;
   fC0 = fX*fC1 - fY*fS1;
   fS0 = fX*fS1 + fY*fC1;

   fTmpA = -0.5900435899266435f;
   pSH[15] = fTmpA*fC0;
   pSH[9] = fTmpA*fS0;
   fTmpB = -1.770130769779931f*fZ;
   pSH[23] = fTmpB*fC0;
   pSH[17] = fTmpB*fS0;
   fC1 = fX*fC0 - fY*fS0;
   fS1 = fX*fS0 + fY*fC0;

   fTmpC = 0.6258357354491763f;
   pSH[24] = fTmpC*fC1;
   pSH[16] = fTmpC*fS1;
}

// order 6
void SHEval6(const float fX, const float fY, const float fZ, float *pSH)
{
   float fC0,fC1,fS0,fS1,fTmpA,fTmpB,fTmpC;
   float fZ2 = fZ*fZ;

   pSH[0] = 0.2820947917738781f;
   pSH[2] = 0.4886025119029199f*fZ;
   pSH[6] = 0.9461746957575601f*fZ2 + -0.3153915652525201f;
   pSH[12] = fZ*(1.865881662950577f*fZ2 + -1.119528997770346f);
   pSH[20] = 1.984313483298443f*fZ*pSH[12] + -1.006230589874905f*pSH[6];
   pSH[30] = 1.98997487421324f*fZ*pSH[20] + -1.002853072844814f*pSH[12];
   fC0 = fX;
   fS0 = fY;

   fTmpA = -0.48860251190292f;
   pSH[3] = fTmpA*fC0;
   pSH[1] = fTmpA*fS0;
   fTmpB = -1.092548430592079f*fZ;
   pSH[7] = fTmpB*fC0;
   pSH[5] = fTmpB*fS0;
   fTmpC = -2.285228997322329f*fZ2 + 0.4570457994644658f;
   pSH[13] = fTmpC*fC0;
   pSH[11] = fTmpC*fS0;
   fTmpA = fZ*(-4.683325804901025f*fZ2 + 2.007139630671868f);
   pSH[21] = fTmpA*fC0;
   pSH[19] = fTmpA*fS0;
   fTmpB = 2.03100960115899f*fZ*fTmpA + -0.991031208965115f*fTmpC;
   pSH[31] = fTmpB*fC0;
   pSH[29] = fTmpB*fS0;
   fC1 = fX*fC0 - fY*fS0;
   fS1 = fX*fS0 + fY*fC0;

   fTmpA = 0.5462742152960395f;
   pSH[8] = fTmpA*fC1;
   pSH[4] = fTmpA*fS1;
   fTmpB = 1.445305721320277f*fZ;
   pSH[14] = fTmpB*fC1;
   pSH[10] = fTmpB*fS1;
   fTmpC = 3.31161143515146f*fZ2 + -0.47308734787878f;
   pSH[22] = fTmpC*fC1;
   pSH[18] = fTmpC*fS1;
   fTmpA = fZ*(7.190305177459987f*fZ2 + -2.396768392486662f);
   pSH[32] = fTmpA*fC1;
   pSH[28] = fTmpA*fS1;
   fC0 = fX*fC1 - fY*fS1;
   fS0 = fX*fS1 + fY*fC1;

   fTmpA = -0.5900435899266435f;
   pSH[15] = fTmpA*fC0;
   pSH[9] = fTmpA*fS0;
   fTmpB = -1.770130769779931f*fZ;
   pSH[23] = fTmpB*fC0;
   pSH[17] = fTmpB*fS0;
   fTmpC = -4.403144694917254f*fZ2 + 0.4892382994352505f;
   pSH[33] = fTmpC*fC0;
   pSH[27] = fTmpC*fS0;
   fC1 = fX*fC0 - fY*fS0;
   fS1 = fX*fS0 + fY*fC0;

   fTmpA = 0.6258357354491763f;
   pSH[24] = fTmpA*fC1;
   pSH[16] = fTmpA*fS1;
   fTmpB = 2.075662314881041f*fZ;
   pSH[34] = fTmpB*fC1;
   pSH[26] = fTmpB*fS1;
   fC0 = fX*fC1 - fY*fS1;
   fS0 = fX*fS1 + fY*fC1;

   fTmpC = -0.6563820568401703f;
   pSH[35] = fTmpC*fC0;
   pSH[25] = fTmpC*fS0;
}

// order 7
void SHEval7(const float fX, const float fY, const float fZ, float *pSH)
{
   float fC0,fC1,fS0,fS1,fTmpA,fTmpB,fTmpC;
   float fZ2 = fZ*fZ;

   pSH[0] = 0.2820947917738781f;
   pSH[2] = 0.4886025119029199f*fZ;
   pSH[6] = 0.9461746957575601f*fZ2 + -0.3153915652525201f;
   pSH[12] = fZ*(1.865881662950577f*fZ2 + -1.119528997770346f);
   pSH[20] = 1.984313483298443f*fZ*pSH[12] + -1.006230589874905f*pSH[6];
   pSH[30] = 1.98997487421324f*fZ*pSH[20] + -1.002853072844814f*pSH[12];
   pSH[42] = 1.993043457183567f*fZ*pSH[30] + -1.001542020962219f*pSH[20];
   fC0 = fX;
   fS0 = fY;

   fTmpA = -0.48860251190292f;
   pSH[3] = fTmpA*fC0;
   pSH[1] = fTmpA*fS0;
   fTmpB = -1.092548430592079f*fZ;
   pSH[7] = fTmpB*fC0;
   pSH[5] = fTmpB*fS0;
   fTmpC = -2.285228997322329f*fZ2 + 0.4570457994644658f;
   pSH[13] = fTmpC*fC0;
   pSH[11] = fTmpC*fS0;
   fTmpA = fZ*(-4.683325804901025f*fZ2 + 2.007139630671868f);
   pSH[21] = fTmpA*fC0;
   pSH[19] = fTmpA*fS0;
   fTmpB = 2.03100960115899f*fZ*fTmpA + -0.991031208965115f*fTmpC;
   pSH[31] = fTmpB*fC0;
   pSH[29] = fTmpB*fS0;
   fTmpC = 2.021314989237028f*fZ*fTmpB + -0.9952267030562385f*fTmpA;
   pSH[43] = fTmpC*fC0;
   pSH[41] = fTmpC*fS0;
   fC1 = fX*fC0 - fY*fS0;
   fS1 = fX*fS0 + fY*fC0;

   fTmpA = 0.5462742152960395f;
   pSH[8] = fTmpA*fC1;
   pSH[4] = fTmpA*fS1;
   fTmpB = 1.445305721320277f*fZ;
   pSH[14] = fTmpB*fC1;
   pSH[10] = fTmpB*fS1;
   fTmpC = 3.31161143515146f*fZ2 + -0.47308734787878f;
   pSH[22] = fTmpC*fC1;
   pSH[18] = fTmpC*fS1;
   fTmpA = fZ*(7.190305177459987f*fZ2 + -2.396768392486662f);
   pSH[32] = fTmpA*fC1;
   pSH[28] = fTmpA*fS1;
   fTmpB = 2.11394181566097f*fZ*fTmpA + -0.9736101204623268f*fTmpC;
   pSH[44] = fTmpB*fC1;
   pSH[40] = fTmpB*fS1;
   fC0 = fX*fC1 - fY*fS1;
   fS0 = fX*fS1 + fY*fC1;

   fTmpA = -0.5900435899266435f;
   pSH[15] = fTmpA*fC0;
   pSH[9] = fTmpA*fS0;
   fTmpB = -1.770130769779931f*fZ;
   pSH[23] = fTmpB*fC0;
   pSH[17] = fTmpB*fS0;
   fTmpC = -4.403144694917254f*fZ2 + 0.4892382994352505f;
   pSH[33] = fTmpC*fC0;
   pSH[27] = fTmpC*fS0;
   fTmpA = fZ*(-10.13325785466416f*fZ2 + 2.763615778544771f);
   pSH[45] = fTmpA*fC0;
   pSH[39] = fTmpA*fS0;
   fC1 = fX*fC0 - fY*fS0;
   fS1 = fX*fS0 + fY*fC0;

   fTmpA = 0.6258357354491763f;
   pSH[24] = fTmpA*fC1;
   pSH[16] = fTmpA*fS1;
   fTmpB = 2.075662314881041f*fZ;
   pSH[34] = fTmpB*fC1;
   pSH[26] = fTmpB*fS1;
   fTmpC = 5.550213908015966f*fZ2 + -0.5045649007287241f;
   pSH[46] = fTmpC*fC1;
   pSH[38] = fTmpC*fS1;
   fC0 = fX*fC1 - fY*fS1;
   fS0 = fX*fS1 + fY*fC1;

   fTmpA = -0.6563820568401703f;
   pSH[35] = fTmpA*fC0;
   pSH[25] = fTmpA*fS0;
   fTmpB = -2.366619162231753f*fZ;
   pSH[47] = fTmpB*fC0;
   pSH[37] = fTmpB*fS0;
   fC1 = fX*fC0 - fY*fS0;
   fS1 = fX*fS0 + fY*fC0;

   fTmpC = 0.6831841051919144f;
   pSH[48] = fTmpC*fC1;
   pSH[36] = fTmpC*fS1;
}

// order 8
void SHEval8(const float fX, const float fY, const float fZ, float *pSH)
{
   float fC0,fC1,fS0,fS1,fTmpA,fTmpB,fTmpC;
   float fZ2 = fZ*fZ;

   pSH[0] = 0.2820947917738781f;
   pSH[2] = 0.4886025119029199f*fZ;
   pSH[6] = 0.9461746957575601f*fZ2 + -0.3153915652525201f;
   pSH[12] = fZ*(1.865881662950577f*fZ2 + -1.119528997770346f);
   pSH[20] = 1.984313483298443f*fZ*pSH[12] + -1.006230589874905f*pSH[6];
   pSH[30] = 1.98997487421324f*fZ*pSH[20] + -1.002853072844814f*pSH[12];
   pSH[42] = 1.993043457183567f*fZ*pSH[30] + -1.001542020962219f*pSH[20];
   pSH[56] = 1.994891434824135f*fZ*pSH[42] + -1.000927213921958f*pSH[30];
   fC0 = fX;
   fS0 = fY;

   fTmpA = -0.48860251190292f;
   pSH[3] = fTmpA*fC0;
   pSH[1] = fTmpA*fS0;
   fTmpB = -1.092548430592079f*fZ;
   pSH[7] = fTmpB*fC0;
   pSH[5] = fTmpB*fS0;
   fTmpC = -2.285228997322329f*fZ2 + 0.4570457994644658f;
   pSH[13] = fTmpC*fC0;
   pSH[11] = fTmpC*fS0;
   fTmpA = fZ*(-4.683325804901025f*fZ2 + 2.007139630671868f);
   pSH[21] = fTmpA*fC0;
   pSH[19] = fTmpA*fS0;
   fTmpB = 2.03100960115899f*fZ*fTmpA + -0.991031208965115f*fTmpC;
   pSH[31] = fTmpB*fC0;
   pSH[29] = fTmpB*fS0;
   fTmpC = 2.021314989237028f*fZ*fTmpB + -0.9952267030562385f*fTmpA;
   pSH[43] = fTmpC*fC0;
   pSH[41] = fTmpC*fS0;
   fTmpA = 2.015564437074638f*fZ*fTmpC + -0.9971550440218319f*fTmpB;
   pSH[57] = fTmpA*fC0;
   pSH[55] = fTmpA*fS0;
   fC1 = fX*fC0 - fY*fS0;
   fS1 = fX*fS0 + fY*fC0;

   fTmpA = 0.5462742152960395f;
   pSH[8] = fTmpA*fC1;
   pSH[4] = fTmpA*fS1;
   fTmpB = 1.445305721320277f*fZ;
   pSH[14] = fTmpB*fC1;
   pSH[10] = fTmpB*fS1;
   fTmpC = 3.31161143515146f*fZ2 + -0.47308734787878f;
   pSH[22] = fTmpC*fC1;
   pSH[18] = fTmpC*fS1;
   fTmpA = fZ*(7.190305177459987f*fZ2 + -2.396768392486662f);
   pSH[32] = fTmpA*fC1;
   pSH[28] = fTmpA*fS1;
   fTmpB = 2.11394181566097f*fZ*fTmpA + -0.9736101204623268f*fTmpC;
   pSH[44] = fTmpB*fC1;
   pSH[40] = fTmpB*fS1;
   fTmpC = 2.081665999466133f*fZ*fTmpB + -0.9847319278346618f*fTmpA;
   pSH[58] = fTmpC*fC1;
   pSH[54] = fTmpC*fS1;
   fC0 = fX*fC1 - fY*fS1;
   fS0 = fX*fS1 + fY*fC1;

   fTmpA = -0.5900435899266435f;
   pSH[15] = fTmpA*fC0;
   pSH[9] = fTmpA*fS0;
   fTmpB = -1.770130769779931f*fZ;
   pSH[23] = fTmpB*fC0;
   pSH[17] = fTmpB*fS0;
   fTmpC = -4.403144694917254f*fZ2 + 0.4892382994352505f;
   pSH[33] = fTmpC*fC0;
   pSH[27] = fTmpC*fS0;
   fTmpA = fZ*(-10.13325785466416f*fZ2 + 2.763615778544771f);
   pSH[45] = fTmpA*fC0;
   pSH[39] = fTmpA*fS0;
   fTmpB = 2.207940216581962f*fZ*fTmpA + -0.959403223600247f*fTmpC;
   pSH[59] = fTmpB*fC0;
   pSH[53] = fTmpB*fS0;
   fC1 = fX*fC0 - fY*fS0;
   fS1 = fX*fS0 + fY*fC0;

   fTmpA = 0.6258357354491763f;
   pSH[24] = fTmpA*fC1;
   pSH[16] = fTmpA*fS1;
   fTmpB = 2.075662314881041f*fZ;
   pSH[34] = fTmpB*fC1;
   pSH[26] = fTmpB*fS1;
   fTmpC = 5.550213908015966f*fZ2 + -0.5045649007287241f;
   pSH[46] = fTmpC*fC1;
   pSH[38] = fTmpC*fS1;
   fTmpA = fZ*(13.49180504672677f*fZ2 + -3.113493472321562f);
   pSH[60] = fTmpA*fC1;
   pSH[52] = fTmpA*fS1;
   fC0 = fX*fC1 - fY*fS1;
   fS0 = fX*fS1 + fY*fC1;

   fTmpA = -0.6563820568401703f;
   pSH[35] = fTmpA*fC0;
   pSH[25] = fTmpA*fS0;
   fTmpB = -2.366619162231753f*fZ;
   pSH[47] = fTmpB*fC0;
   pSH[37] = fTmpB*fS0;
   fTmpC = -6.745902523363385f*fZ2 + 0.5189155787202604f;
   pSH[61] = fTmpC*fC0;
   pSH[51] = fTmpC*fS0;
   fC1 = fX*fC0 - fY*fS0;
   fS1 = fX*fS0 + fY*fC0;

   fTmpA = 0.6831841051919144f;
   pSH[48] = fTmpA*fC1;
   pSH[36] = fTmpA*fS1;
   fTmpB = 2.645960661801901f*fZ;
   pSH[62] = fTmpB*fC1;
   pSH[50] = fTmpB*fS1;
   fC0 = fX*fC1 - fY*fS1;
   fS0 = fX*fS1 + fY*fC1;

   fTmpC = -0.7071627325245963f;
   pSH[63] = fTmpC*fC0;
   pSH[49] = fTmpC*fS0;
}

// order 9
void SHEval9(const float fX, const float fY, const float fZ, float *pSH)
{
   float fC0,fC1,fS0,fS1,fTmpA,fTmpB,fTmpC;
   float fZ2 = fZ*fZ;

   pSH[0] = 0.2820947917738781f;
   pSH[2] = 0.4886025119029199f*fZ;
   pSH[6] = 0.9461746957575601f*fZ2 + -0.3153915652525201f;
   pSH[12] = fZ*(1.865881662950577f*fZ2 + -1.119528997770346f);
   pSH[20] = 1.984313483298443f*fZ*pSH[12] + -1.006230589874905f*pSH[6];
   pSH[30] = 1.98997487421324f*fZ*pSH[20] + -1.002853072844814f*pSH[12];
   pSH[42] = 1.993043457183567f*fZ*pSH[30] + -1.001542020962219f*pSH[20];
   pSH[56] = 1.994891434824135f*fZ*pSH[42] + -1.000927213921958f*pSH[30];
   pSH[72] = 1.996089927833914f*fZ*pSH[56] + -1.000600781069515f*pSH[42];
   fC0 = fX;
   fS0 = fY;

   fTmpA = -0.48860251190292f;
   pSH[3] = fTmpA*fC0;
   pSH[1] = fTmpA*fS0;
   fTmpB = -1.092548430592079f*fZ;
   pSH[7] = fTmpB*fC0;
   pSH[5] = fTmpB*fS0;
   fTmpC = -2.285228997322329f*fZ2 + 0.4570457994644658f;
   pSH[13] = fTmpC*fC0;
   pSH[11] = fTmpC*fS0;
   fTmpA = fZ*(-4.683325804901025f*fZ2 + 2.007139630671868f);
   pSH[21] = fTmpA*fC0;
   pSH[19] = fTmpA*fS0;
   fTmpB = 2.03100960115899f*fZ*fTmpA + -0.991031208965115f*fTmpC;
   pSH[31] = fTmpB*fC0;
   pSH[29] = fTmpB*fS0;
   fTmpC = 2.021314989237028f*fZ*fTmpB + -0.9952267030562385f*fTmpA;
   pSH[43] = fTmpC*fC0;
   pSH[41] = fTmpC*fS0;
   fTmpA = 2.015564437074638f*fZ*fTmpC + -0.9971550440218319f*fTmpB;
   pSH[57] = fTmpA*fC0;
   pSH[55] = fTmpA*fS0;
   fTmpB = 2.011869540407391f*fZ*fTmpA + -0.9981668178901745f*fTmpC;
   pSH[73] = fTmpB*fC0;
   pSH[71] = fTmpB*fS0;
   fC1 = fX*fC0 - fY*fS0;
   fS1 = fX*fS0 + fY*fC0;

   fTmpA = 0.5462742152960395f;
   pSH[8] = fTmpA*fC1;
   pSH[4] = fTmpA*fS1;
   fTmpB = 1.445305721320277f*fZ;
   pSH[14] = fTmpB*fC1;
   pSH[10] = fTmpB*fS1;
   fTmpC = 3.31161143515146f*fZ2 + -0.47308734787878f;
   pSH[22] = fTmpC*fC1;
   pSH[18] = fTmpC*fS1;
   fTmpA = fZ*(7.190305177459987f*fZ2 + -2.396768392486662f);
   pSH[32] = fTmpA*fC1;
   pSH[28] = fTmpA*fS1;
   fTmpB = 2.11394181566097f*fZ*fTmpA + -0.9736101204623268f*fTmpC;
   pSH[44] = fTmpB*fC1;
   pSH[40] = fTmpB*fS1;
   fTmpC = 2.081665999466133f*fZ*fTmpB + -0.9847319278346618f*fTmpA;
   pSH[58] = fTmpC*fC1;
   pSH[54] = fTmpC*fS1;
   fTmpA = 2.06155281280883f*fZ*fTmpC + -0.9903379376602873f*fTmpB;
   pSH[74] = fTmpA*fC1;
   pSH[70] = fTmpA*fS1;
   fC0 = fX*fC1 - fY*fS1;
   fS0 = fX*fS1 + fY*fC1;

   fTmpA = -0.5900435899266435f;
   pSH[15] = fTmpA*fC0;
   pSH[9] = fTmpA*fS0;
   fTmpB = -1.770130769779931f*fZ;
   pSH[23] = fTmpB*fC0;
   pSH[17] = fTmpB*fS0;
   fTmpC = -4.403144694917254f*fZ2 + 0.4892382994352505f;
   pSH[33] = fTmpC*fC0;
   pSH[27] = fTmpC*fS0;
   fTmpA = fZ*(-10.13325785466416f*fZ2 + 2.763615778544771f);
   pSH[45] = fTmpA*fC0;
   pSH[39] = fTmpA*fS0;
   fTmpB = 2.207940216581962f*fZ*fTmpA + -0.959403223600247f*fTmpC;
   pSH[59] = fTmpB*fC0;
   pSH[53] = fTmpB*fS0;
   fTmpC = 2.15322168769582f*fZ*fTmpB + -0.9752173865600178f*fTmpA;
   pSH[75] = fTmpC*fC0;
   pSH[69] = fTmpC*fS0;
   fC1 = fX*fC0 - fY*fS0;
   fS1 = fX*fS0 + fY*fC0;

   fTmpA = 0.6258357354491763f;
   pSH[24] = fTmpA*fC1;
   pSH[16] = fTmpA*fS1;
   fTmpB = 2.075662314881041f*fZ;
   pSH[34] = fTmpB*fC1;
   pSH[26] = fTmpB*fS1;
   fTmpC = 5.550213908015966f*fZ2 + -0.5045649007287241f;
   pSH[46] = fTmpC*fC1;
   pSH[38] = fTmpC*fS1;
   fTmpA = fZ*(13.49180504672677f*fZ2 + -3.113493472321562f);
   pSH[60] = fTmpA*fC1;
   pSH[52] = fTmpA*fS1;
   fTmpB = 2.304886114323221f*fZ*fTmpA + -0.9481763873554654f*fTmpC;
   pSH[76] = fTmpB*fC1;
   pSH[68] = fTmpB*fS1;
   fC0 = fX*fC1 - fY*fS1;
   fS0 = fX*fS1 + fY*fC1;

   fTmpA = -0.6563820568401703f;
   pSH[35] = fTmpA*fC0;
   pSH[25] = fTmpA*fS0;
   fTmpB = -2.366619162231753f*fZ;
   pSH[47] = fTmpB*fC0;
   pSH[37] = fTmpB*fS0;
   fTmpC = -6.745902523363385f*fZ2 + 0.5189155787202604f;
   pSH[61] = fTmpC*fC0;
   pSH[51] = fTmpC*fS0;
   fTmpA = fZ*(-17.24955311049054f*fZ2 + 3.449910622098108f);
   pSH[77] = fTmpA*fC0;
   pSH[67] = fTmpA*fS0;
   fC1 = fX*fC0 - fY*fS0;
   fS1 = fX*fS0 + fY*fC0;

   fTmpA = 0.6831841051919144f;
   pSH[48] = fTmpA*fC1;
   pSH[36] = fTmpA*fS1;
   fTmpB = 2.645960661801901f*fZ;
   pSH[62] = fTmpB*fC1;
   pSH[50] = fTmpB*fS1;
   fTmpC = 7.984991490893139f*fZ2 + -0.5323327660595426f;
   pSH[78] = fTmpC*fC1;
   pSH[66] = fTmpC*fS1;
   fC0 = fX*fC1 - fY*fS1;
   fS0 = fX*fS1 + fY*fC1;

   fTmpA = -0.7071627325245963f;
   pSH[63] = fTmpA*fC0;
   pSH[49] = fTmpA*fS0;
   fTmpB = -2.91570664069932f*fZ;
   pSH[79] = fTmpB*fC0;
   pSH[65] = fTmpB*fS0;
   fC1 = fX*fC0 - fY*fS0;
   fS1 = fX*fS0 + fY*fC0;

   fTmpC = 0.72892666017483f;
   pSH[80] = fTmpC*fC1;
   pSH[64] = fTmpC*fS1;
}

// order 10
void SHEval10(const float fX, const float fY, const float fZ, float *pSH)
{
   float fC0,fC1,fS0,fS1,fTmpA,fTmpB,fTmpC;
   float fZ2 = fZ*fZ;

   pSH[0] = 0.2820947917738781f;
   pSH[2] = 0.4886025119029199f*fZ;
   pSH[6] = 0.9461746957575601f*fZ2 + -0.3153915652525201f;
   pSH[12] = fZ*(1.865881662950577f*fZ2 + -1.119528997770346f);
   pSH[20] = 1.984313483298443f*fZ*pSH[12] + -1.006230589874905f*pSH[6];
   pSH[30] = 1.98997487421324f*fZ*pSH[20] + -1.002853072844814f*pSH[12];
   pSH[42] = 1.993043457183567f*fZ*pSH[30] + -1.001542020962219f*pSH[20];
   pSH[56] = 1.994891434824135f*fZ*pSH[42] + -1.000927213921958f*pSH[30];
   pSH[72] = 1.996089927833914f*fZ*pSH[56] + -1.000600781069515f*pSH[42];
   pSH[90] = 1.996911195067937f*fZ*pSH[72] + -1.000411437993134f*pSH[56];
   fC0 = fX;
   fS0 = fY;

   fTmpA = -0.48860251190292f;
   pSH[3] = fTmpA*fC0;
   pSH[1] = fTmpA*fS0;
   fTmpB = -1.092548430592079f*fZ;
   pSH[7] = fTmpB*fC0;
   pSH[5] = fTmpB*fS0;
   fTmpC = -2.285228997322329f*fZ2 + 0.4570457994644658f;
   pSH[13] = fTmpC*fC0;
   pSH[11] = fTmpC*fS0;
   fTmpA = fZ*(-4.683325804901025f*fZ2 + 2.007139630671868f);
   pSH[21] = fTmpA*fC0;
   pSH[19] = fTmpA*fS0;
   fTmpB = 2.03100960115899f*fZ*fTmpA + -0.991031208965115f*fTmpC;
   pSH[31] = fTmpB*fC0;
   pSH[29] = fTmpB*fS0;
   fTmpC = 2.021314989237028f*fZ*fTmpB + -0.9952267030562385f*fTmpA;
   pSH[43] = fTmpC*fC0;
   pSH[41] = fTmpC*fS0;
   fTmpA = 2.015564437074638f*fZ*fTmpC + -0.9971550440218319f*fTmpB;
   pSH[57] = fTmpA*fC0;
   pSH[55] = fTmpA*fS0;
   fTmpB = 2.011869540407391f*fZ*fTmpA + -0.9981668178901745f*fTmpC;
   pSH[73] = fTmpB*fC0;
   pSH[71] = fTmpB*fS0;
   fTmpC = 2.009353129741012f*fZ*fTmpB + -0.9987492177719088f*fTmpA;
   pSH[91] = fTmpC*fC0;
   pSH[89] = fTmpC*fS0;
   fC1 = fX*fC0 - fY*fS0;
   fS1 = fX*fS0 + fY*fC0;

   fTmpA = 0.5462742152960395f;
   pSH[8] = fTmpA*fC1;
   pSH[4] = fTmpA*fS1;
   fTmpB = 1.445305721320277f*fZ;
   pSH[14] = fTmpB*fC1;
   pSH[10] = fTmpB*fS1;
   fTmpC = 3.31161143515146f*fZ2 + -0.47308734787878f;
   pSH[22] = fTmpC*fC1;
   pSH[18] = fTmpC*fS1;
   fTmpA = fZ*(7.190305177459987f*fZ2 + -2.396768392486662f);
   pSH[32] = fTmpA*fC1;
   pSH[28] = fTmpA*fS1;
   fTmpB = 2.11394181566097f*fZ*fTmpA + -0.9736101204623268f*fTmpC;
   pSH[44] = fTmpB*fC1;
   pSH[40] = fTmpB*fS1;
   fTmpC = 2.081665999466133f*fZ*fTmpB + -0.9847319278346618f*fTmpA;
   pSH[58] = fTmpC*fC1;
   pSH[54] = fTmpC*fS1;
   fTmpA = 2.06155281280883f*fZ*fTmpC + -0.9903379376602873f*fTmpB;
   pSH[74] = fTmpA*fC1;
   pSH[70] = fTmpA*fS1;
   fTmpB = 2.048122358357819f*fZ*fTmpA + -0.9934852726704042f*fTmpC;
   pSH[92] = fTmpB*fC1;
   pSH[88] = fTmpB*fS1;
   fC0 = fX*fC1 - fY*fS1;
   fS0 = fX*fS1 + fY*fC1;

   fTmpA = -0.5900435899266435f;
   pSH[15] = fTmpA*fC0;
   pSH[9] = fTmpA*fS0;
   fTmpB = -1.770130769779931f*fZ;
   pSH[23] = fTmpB*fC0;
   pSH[17] = fTmpB*fS0;
   fTmpC = -4.403144694917254f*fZ2 + 0.4892382994352505f;
   pSH[33] = fTmpC*fC0;
   pSH[27] = fTmpC*fS0;
   fTmpA = fZ*(-10.13325785466416f*fZ2 + 2.763615778544771f);
   pSH[45] = fTmpA*fC0;
   pSH[39] = fTmpA*fS0;
   fTmpB = 2.207940216581962f*fZ*fTmpA + -0.959403223600247f*fTmpC;
   pSH[59] = fTmpB*fC0;
   pSH[53] = fTmpB*fS0;
   fTmpC = 2.15322168769582f*fZ*fTmpB + -0.9752173865600178f*fTmpA;
   pSH[75] = fTmpC*fC0;
   pSH[69] = fTmpC*fS0;
   fTmpA = 2.118044171189805f*fZ*fTmpC + -0.9836628449792094f*fTmpB;
   pSH[93] = fTmpA*fC0;
   pSH[87] = fTmpA*fS0;
   fC1 = fX*fC0 - fY*fS0;
   fS1 = fX*fS0 + fY*fC0;

   fTmpA = 0.6258357354491763f;
   pSH[24] = fTmpA*fC1;
   pSH[16] = fTmpA*fS1;
   fTmpB = 2.075662314881041f*fZ;
   pSH[34] = fTmpB*fC1;
   pSH[26] = fTmpB*fS1;
   fTmpC = 5.550213908015966f*fZ2 + -0.5045649007287241f;
   pSH[46] = fTmpC*fC1;
   pSH[38] = fTmpC*fS1;
   fTmpA = fZ*(13.49180504672677f*fZ2 + -3.113493472321562f);
   pSH[60] = fTmpA*fC1;
   pSH[52] = fTmpA*fS1;
   fTmpB = 2.304886114323221f*fZ*fTmpA + -0.9481763873554654f*fTmpC;
   pSH[76] = fTmpB*fC1;
   pSH[68] = fTmpB*fS1;
   fTmpC = 2.229177150706235f*fZ*fTmpB + -0.9671528397231821f*fTmpA;
   pSH[94] = fTmpC*fC1;
   pSH[86] = fTmpC*fS1;
   fC0 = fX*fC1 - fY*fS1;
   fS0 = fX*fS1 + fY*fC1;

   fTmpA = -0.6563820568401703f;
   pSH[35] = fTmpA*fC0;
   pSH[25] = fTmpA*fS0;
   fTmpB = -2.366619162231753f*fZ;
   pSH[47] = fTmpB*fC0;
   pSH[37] = fTmpB*fS0;
   fTmpC = -6.745902523363385f*fZ2 + 0.5189155787202604f;
   pSH[61] = fTmpC*fC0;
   pSH[51] = fTmpC*fS0;
   fTmpA = fZ*(-17.24955311049054f*fZ2 + 3.449910622098108f);
   pSH[77] = fTmpA*fC0;
   pSH[67] = fTmpA*fS0;
   fTmpB = 2.401636346922062f*fZ*fTmpA + -0.9392246042043708f*fTmpC;
   pSH[95] = fTmpB*fC0;
   pSH[85] = fTmpB*fS0;
   fC1 = fX*fC0 - fY*fS0;
   fS1 = fX*fS0 + fY*fC0;

   fTmpA = 0.6831841051919144f;
   pSH[48] = fTmpA*fC1;
   pSH[36] = fTmpA*fS1;
   fTmpB = 2.645960661801901f*fZ;
   pSH[62] = fTmpB*fC1;
   pSH[50] = fTmpB*fS1;
   fTmpC = 7.984991490893139f*fZ2 + -0.5323327660595426f;
   pSH[78] = fTmpC*fC1;
   pSH[66] = fTmpC*fS1;
   fTmpA = fZ*(21.39289019090864f*fZ2 + -3.775215916042701f);
   pSH[96] = fTmpA*fC1;
   pSH[84] = fTmpA*fS1;
   fC0 = fX*fC1 - fY*fS1;
   fS0 = fX*fS1 + fY*fC1;

   fTmpA = -0.7071627325245963f;
   pSH[63] = fTmpA*fC0;
   pSH[49] = fTmpA*fS0;
   fTmpB = -2.91570664069932f*fZ;
   pSH[79] = fTmpB*fC0;
   pSH[65] = fTmpB*fS0;
   fTmpC = -9.263393182848905f*fZ2 + 0.5449054813440533f;
   pSH[97] = fTmpC*fC0;
   pSH[83] = fTmpC*fS0;
   fC1 = fX*fC0 - fY*fS0;
   fS1 = fX*fS0 + fY*fC0;

   fTmpA = 0.72892666017483f;
   pSH[80] = fTmpA*fC1;
   pSH[64] = fTmpA*fS1;
   fTmpB = 3.177317648954698f*fZ;
   pSH[98] = fTmpB*fC1;
   pSH[82] = fTmpB*fS1;
   fC0 = fX*fC1 - fY*fS1;
   fS0 = fX*fS1 + fY*fC1;

   fTmpC = -0.7489009518531884f;
   pSH[99] = fTmpC*fC0;
   pSH[81] = fTmpC*fS0;
}




inline float Factorial(int m){
	if(m < 0)
		return 0.f;
	if(m == 1 || m==0)
		return 1.f;
	
	//return Factorial(m-1) * m ;
	float ret = 1.f;
	for(float  i = (float)m; i >0; i-=1.f){
		ret =  ret * i;
	}
	return ret;
}


inline void compute_e1_e2(const Vector &r, int l, int m, float *list_e){
	float fact_1 = Factorial(l-m);
	float fact_2 = Factorial(l+m);
	float aux = (float)(1+ 2 * l);

	list_e[0] = sqrtf((aux * fact_1) / fact_2);
	list_e[1] = sqrtf((aux * fact_2) / fact_1);
}

inline void compute_e3(const Vector &r, int l, int m, float *list_e){
	list_e[2] = sqrtf(r.x * r.x + r.y * r.y);
}

inline void compute_e4(const Vector &r, int l, int m, float *list_e){
	float aux = powf((r.x * r.x + r.y * r.y), 2) * powf(r.LengthSquared(), 2);

	
	aux = 2.f * sqrt(PI) * aux;
	list_e[3] = 1.f / aux;
}


inline void compute_e5(const Vector &r, int l, int m, float *list_e){
	float aux = 3.f * powf(r.x, 4);
	aux = aux - r.y * r.y * (r.y * r.y + r.z * r.z);
	list_e[4] = aux + r.x * r.x * (2.f * r.y * r.y + (2.f + (float)l) * r.z * r.z);
}


inline void compute_e6(const Vector &r, int l, int m, float *list_e){
	float aux = powf ((float)m, 2) * r.y * r.y * powf(r.LengthSquared(), 2);
	list_e[5] = aux - (1.f - (float)l) * r.z * r.z * list_e[4];
}


inline void compute_e7(const Vector &r, int l, int m, float *list_e){
	list_e[6] = r.LengthSquared() + (1.f + (float)l) * r.z *r.z;
}


inline void compute_e8(const Vector &r, int l, int m, float *list_e){
	float aux  = 2.f * (float)m * r.x * list_e[2] * r.LengthSquared();
	list_e[7] = aux * fabs(r.y/sqrt(r.x * r.x + r.y * r.y));
}

inline void compute_e9(const Vector &r, int l, int m, float *list_e){
	list_e[8] = (float)(1+l+m) * r.z;
}

inline void compute_e10(const Vector &r, int l, int m, float *list_e){
	list_e[9] = (float)(2+l-m) * r.z * r.LengthSquared();
}

inline void compute_e11(const Vector &r, int l, int m, float *list_e){
	list_e[10] = (float)(1+l-m) * r.z;
}

inline void compute_e12(const Vector &r, int l, int m, float *list_e){
	list_e[11] = (float)(2+l+m) * r.z * r.LengthSquared();
}


inline void compute_e13(const Vector &r, int l, int m, float *list_e){
	float aux = powf(r.x, 4) - r.x * r.x * (2.f * r.y * r.y - r.z * r.z);
	list_e[12] = aux - r.y * r.y * (3.f * r.y * r.y + (2.f + (float)l) * r.z * r.z);
}


inline void compute_e14(const Vector &r, int l, int m, float *list_e){
	float aux = (float)(m*m) * r.x * r.x * r.LengthSquared() * r.LengthSquared();
	list_e[13] = aux + (1.f + (float)l) * r.z * r.z * list_e[12];
}


inline void compute_e15(const Vector &r, int l, int m, float *list_e){
	float aux = powf(r.x, 4) + r.x * r.x * (r.z * r.z - r.y * r.y);
	list_e[14] = aux - 2.f * r.y * r.y * (r.y * r.y + (2.f + (float)l) * r.z * r.z);
}

inline void compute_e16(Vector r, int l, int m, float *list_e){
	list_e[15] = (float)m * (r.y * r.y - r.x * r.x) * r.LengthSquared();
}

inline void compute_e17(const Vector &r, int l, int m, float *list_e){
	list_e[16] = 4.f * (r.x * r.x + r.y * r.y) + (3.f + (float)l) * r.z * r.z;
}

inline void compute_e18(const Vector &r, int l, int m, float *list_e){
	list_e[17] = 3.f * (r.x * r.x + r.y * r.y) + (5.f + (float)(2*l)) * r.z * r.z;
}	

inline void compute_e19(const Vector &r, int l, int m, float *list_e){
	float aux = (float)(m*m) * r.LengthSquared() * r.LengthSquared() + (1.f + (float)l) * r.z * r.z * list_e[16];
	list_e[18] = r.x * fabs(r.y) * aux ;
}

inline void compute_e20(const Vector &r, int l, int m, float *list_e){

	if( r.y != 0.f){
		float aux = sqrt(2.f * PI) * sqrt(r.y * r.y * powf((r.y * r.y + r.x * r.x), 4));
		aux = aux * r.LengthSquared() * r.LengthSquared();
		list_e[19] = r.y / aux;
	}

	else{
		float aux = sqrt(2.f * PI) * sqrt(powf((r.y * r.y + r.x * r.x), 4));
		aux = aux * r.LengthSquared() * r.LengthSquared();
		list_e[19] = 1.f / aux;
	}
}


void compute_list_e(const Vector &r, int l, int m, float *list_e){
	
	compute_e1_e2(r,l,m,list_e);
	compute_e3(r,l,m,list_e);
	compute_e4(r,l,m,list_e);
	compute_e5(r,l,m,list_e);
	compute_e6(r,l,m,list_e);
	compute_e7(r,l,m,list_e);
	compute_e8(r,l,m,list_e);
	compute_e9(r,l,m,list_e);
	compute_e10(r,l,m,list_e);
	compute_e11(r,l,m,list_e);
	compute_e12(r,l,m,list_e);
	compute_e13(r,l,m,list_e);
	compute_e14(r,l,m,list_e);
	compute_e15(r,l,m,list_e);
	compute_e16(r,l,m,list_e);
	compute_e17(r,l,m,list_e);
	compute_e18(r,l,m,list_e);
	compute_e19(r,l,m,list_e);
	compute_e20(r,l,m,list_e);
}



void compute_list_e_lite(const Vector &r, int l, int m, float *list_e){
	
	compute_e1_e2(r,l,m,list_e);
	compute_e3(r,l,m,list_e);
}


inline int SHIndex(int l, int m) {
    return l*l + l + m;
}



inline float shbaisGradX(float *list_e, float *list_legendre,float costheta, float phi, Vector p, int l, int m){
	int shTermPos = SHIndex(l,m);
	int shTermPosmm = SHIndex(l,-m);
	double ret = 0.f;

	double fl = (double)l;
	double fm = (double)m;

	if(m == 0){
		ret = p.z * list_legendre[shTermPos] - p.Length() * list_legendre[SHIndex(l+1,m)];
		ret *=  p.z * p.x * sqrtf(1.f + 2.f * fl)  * (1.f + fl);
		ret = -ret / (2.f * sqrtf(PI) * list_e[2] *  list_e[2] * p.LengthSquared());
	}
	else if(m > 0&& p.y < 0.f){
		
		float aux = (fl + 1.f ) * p.z * list_legendre[shTermPos];
		aux += (fm-fl-1.f) * p.Length() * list_legendre[SHIndex(l+1, m)];
		aux *=  p.x * p.z * cosf(fm * phi);
		aux = aux / (list_e[2] * list_e[2] * p.LengthSquared());
		float aux1 = fm * fabs(sinf(phi)) * list_legendre[shTermPos];

		aux1 = aux1 * sinf(fm * phi);
		aux1 = aux1 / list_e[2];
		ret = (- aux - aux1) * list_e[0] / sqrtf(2.f * PI);
	}else if(m > 0&& p.y >= 0.f){
		float aux = (fl + 1.f ) * p.z * list_legendre[shTermPos];
		aux += (fm-fl-1.f) * p.Length() * list_legendre[SHIndex(l+1, m)];
		aux *=  p.x * p.z * cosf(fm * phi);
		aux = aux / (list_e[2] * list_e[2] * p.LengthSquared());
		float aux1 = fm * fabs(sinf(phi)) * list_legendre[shTermPos] * sinf(fm * phi);
		aux1 = aux1 / list_e[2];
		ret = (- aux + aux1) * list_e[0] / sqrtf(2.f * PI);
	}else if(m < 0&& p.y < 0.f){
		float aux = (fl + 1.f ) * p.z * list_legendre[shTermPosmm];
		aux -= (fm + fl + 1.f) * p.Length() * list_legendre[SHIndex(l+1, -m)];
		aux *=  p.x * p.z * sinf(fm * phi);
		aux = aux / (list_e[2] * list_e[2] * p.LengthSquared());
		float aux1 = fm * fabs(sinf(phi)) * list_legendre[shTermPosmm] * cosf(fm * phi);
		aux1 = aux1 / list_e[2];
		ret = (aux - aux1) * list_e[1] / sqrtf(2.f * PI);
	}else if(m < 0&& p.y >= 0.f){
		float aux = ((float)l + 1.f ) * p.z * list_legendre[shTermPosmm];
		aux -= ((float)(m + l) + 1.f) * p.Length() * list_legendre[SHIndex(l+1, -m)];
		aux *=  p.x * p.z * sinf((float)m * phi);
		aux = aux / (list_e[2] * list_e[2] * p.LengthSquared());
		float aux1 = (float)m * fabs(sinf(phi)) * list_legendre[shTermPosmm] * cosf((float)m * phi);
		aux1 = aux1 / list_e[2];
		ret = (aux + aux1) * list_e[1] / sqrtf(2.f * PI);
	}

	return (float)ret;
}




// Spherical Harmonics Local Definitions
static void legendrep(float x, int lmax, float *out) {
#define P(l,m) out[SHIndex(l,m)]
    // Compute $m=0$ Legendre values using recurrence
    P(0,0) = 1.f;
    P(1,0) = x;
    for (int l = 2; l <= lmax; ++l)
    {
        P(l, 0) = ((2*l-1)*x*P(l-1,0) - (l-1)*P(l-2,0)) / l;
        Assert(!isnan(P(l, 0)));
        Assert(!isinf(P(l, 0)));
    }

    // Compute $m=l$ edge using Legendre recurrence
    float neg = -1.f;
    float dfact = 1.f;
    float xroot = sqrtf(max(0.f, 1.f - x*x));
    float xpow = xroot;
    for (int l = 1; l <= lmax; ++l) {
        P(l, l) = neg * dfact * xpow;
        Assert(!isnan(P(l, l)));
        Assert(!isinf(P(l, l)));
        neg *= -1.f;      // neg = (-1)^l
        dfact *= 2*l + 1; // dfact = (2*l-1)!!
        xpow *= xroot;    // xpow = powf(1.f - x*x, float(l) * 0.5f);
    }

    // Compute $m=l-1$ edge using Legendre recurrence
    for (int l = 2; l <= lmax; ++l)
    {
        P(l, l-1) = x * (2*l-1) * P(l-1, l-1);
        Assert(!isnan(P(l, l-1)));
        Assert(!isinf(P(l, l-1)));
    }

    // Compute $m=1, \ldots, l-2$ values using Legendre recurrence
    for (int l = 3; l <= lmax; ++l)
        for (int m = 1; m <= l-2; ++m)
        {
            P(l, m) = ((2 * (l-1) + 1) * x * P(l-1,m) -
                       (l-1+m) * P(l-2,m)) / (l - m);
            Assert(!isnan(P(l, m)));
            Assert(!isinf(P(l, m)));
        }
    #if 0
        // wrap up with the negative m ones now
        // P(l,-m)(x) = -1^m (l-m)!/(l+m)! P(l,m)(x)
        for (int l = 1; l <= lmax; ++l) {
            float fa = 1.f, fb = fact(2*l);
            // fa = fact(l+m), fb = fact(l-m)
            for (int m = -l; m < 0; ++m) {
                float neg = ((-m) & 0x1) ? -1.f : 1.f;
                P(l,m) = neg * fa/fb * P(l,-m);
                fb /= l-m;
                fa *= (l+m+1) > 1 ? (l+m+1) : 1.;
            }
        }
    #endif
#undef P
}


void legendrep_out(float x, int lmax, float *out){
	legendrep(x,lmax, out);
}



void shbaisGrad(float *out, float costheta, float phi, Vector p, int order){
	int shTermPos = -1;
				
	//We need P(l+2, m) somtime so the size of table should be order+1
	float *list_legendre  = new float[(order + 2) * (order + 2)];
	legendrep_out(costheta, order+1, list_legendre);
	//compute dHdx and dHdy
	float list_e[20];
	for(int l = 0 ; l < order ; ++l){
		for(int m = -l; m <= l; ++m){
			shTermPos = SHIndex(l,m);
						
			compute_list_e(p,l, m, list_e);
			float x = -shbaisGradX(list_e,list_legendre,costheta, phi, p, l, m);

			if(fabs(x) > 10.f){
				x = 0.f;
			}
			if(isnan(x))
				out[shTermPos] = 0.f;
			else
				out[shTermPos] = x;
						
		}
	}

				
	delete[] list_legendre;

}


void ShbaisGrad(float *out, Vector p, int order){
	float costheta = p.z / p.Length();
	float phi = 0.0;

	if(p.y >= 0.0){
		phi = acos(p.x / sqrt(p.x * p.x + p.y * p.y ));
	}
	else{
		phi = 2.0 * PI - acos(p.x / sqrt(p.x * p.x + p.y * p.y ));
	}

	shbaisGrad(out, costheta, phi,  p,  order);
}