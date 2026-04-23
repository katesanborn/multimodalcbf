//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: multimodalcbf.cpp
//
// Code generated for Simulink model 'multimodalcbf'.
//
// Model version                  : 1.35
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Tue Apr 21 10:54:29 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "multimodalcbf.h"
#include "rtwtypes.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "multimodalcbf_types.h"

// Named constants for Chart: '<S11>/Multimodal CBF'
const uint8_T multimodalcbf_IN_nominal = 1U;
const uint8_T multimodalcbf_IN_stop_and_go = 2U;
const uint8_T multimodalcbf_IN_transition = 3U;

// Block signals (default storage)
B_multimodalcbf_T multimodalcbf_B;

// Block states (default storage)
DW_multimodalcbf_T multimodalcbf_DW;

// Real-time model
RT_MODEL_multimodalcbf_T multimodalcbf_M_ = RT_MODEL_multimodalcbf_T();
RT_MODEL_multimodalcbf_T *const multimodalcbf_M = &multimodalcbf_M_;

// Model step function
void multimodalcbf_step(void)
{
  SL_Bus_multimodalcbf_std_msgs_Float64 rtb_BusAssignment1;
  SL_Bus_multimodalcbf_std_msgs_Float64 rtb_BusAssignment2;
  SL_Bus_multimodalcbf_std_msgs_Float64 rtb_BusAssignment3;
  SL_Bus_multimodalcbf_std_msgs_Float64 rtb_SourceBlock_o2_p_0;
  real_T d_min;
  real_T e_term;
  real_T timegap_accel;
  boolean_T b_varargout_1;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // MATLABSystem: '<S7>/SourceBlock'
  b_varargout_1 = Sub_multimodalcbf_52.getLatestMessage(&rtb_SourceBlock_o2_p_0);

  // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S12>/Enable'

  // Start for MATLABSystem: '<S7>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S12>/In1'
    multimodalcbf_B.In1_bg = rtb_SourceBlock_o2_p_0;
  }

  // End of Start for MATLABSystem: '<S7>/SourceBlock'
  // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
  // MATLABSystem: '<S8>/SourceBlock'
  b_varargout_1 = Sub_multimodalcbf_53.getLatestMessage(&rtb_SourceBlock_o2_p_0);

  // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S13>/Enable'

  // Start for MATLABSystem: '<S8>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S13>/In1'
    multimodalcbf_B.In1_b = rtb_SourceBlock_o2_p_0;
  }

  // End of Start for MATLABSystem: '<S8>/SourceBlock'
  // End of Outputs for SubSystem: '<S8>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe1'

  // Chart: '<S11>/Multimodal CBF' incorporates:
  //   Constant: '<S11>/t_min'

  if (multimodalcbf_DW.is_active_c20_multimodalcbf == 0) {
    multimodalcbf_DW.is_active_c20_multimodalcbf = 1U;
    multimodalcbf_DW.durationCounter_1 = 0U;
    multimodalcbf_DW.is_c20_multimodalcbf = multimodalcbf_IN_nominal;

    // Merge: '<S17>/ Merge ' incorporates:
    //   Constant: '<S19>/d_min_nominal'
    //   SignalConversion generated from: '<S19>/d_min'

    d_min = 15.0;

    // BusAssignment: '<Root>/Bus Assignment2' incorporates:
    //   Constant: '<S19>/Constant'
    //   Merge: '<S17>/ Merge 1'
    //   SignalConversion generated from: '<S19>/mode'

    rtb_BusAssignment2.Data = 1.0;

    // Merge: '<S17>/ Merge 2' incorporates:
    //   Constant: '<S19>/Constant1'
    //   SignalConversion generated from: '<S19>/max_accel'

    e_term = 1.5;
  } else {
    switch (multimodalcbf_DW.is_c20_multimodalcbf) {
     case multimodalcbf_IN_nominal:
      if (!(multimodalcbf_B.In1_b.Data <= 5.0)) {
        multimodalcbf_DW.durationCounter_1 = 0U;
      }

      if ((multimodalcbf_B.In1_bg.Data >= (2.0 * multimodalcbf_B.In1_b.Data +
            15.0) - 0.1) && (multimodalcbf_DW.durationCounter_1 >= 60U)) {
        multimodalcbf_DW.is_c20_multimodalcbf = multimodalcbf_IN_stop_and_go;

        // Merge: '<S17>/ Merge ' incorporates:
        //   Constant: '<S20>/d_min_stop_and_go'
        //   SignalConversion generated from: '<S20>/d_min'

        d_min = 5.0;

        // BusAssignment: '<Root>/Bus Assignment2' incorporates:
        //   Constant: '<S20>/Constant'
        //   Merge: '<S17>/ Merge 1'
        //   SignalConversion generated from: '<S20>/mode'

        rtb_BusAssignment2.Data = 2.0;

        // Merge: '<S17>/ Merge 2' incorporates:
        //   Constant: '<S20>/Constant1'
        //   SignalConversion generated from: '<S20>/max_accel'

        e_term = 1.0;
      } else {
        // Merge: '<S17>/ Merge ' incorporates:
        //   Constant: '<S19>/d_min_nominal'
        //   SignalConversion generated from: '<S19>/d_min'

        d_min = 15.0;

        // BusAssignment: '<Root>/Bus Assignment2' incorporates:
        //   Constant: '<S19>/Constant'
        //   Merge: '<S17>/ Merge 1'
        //   SignalConversion generated from: '<S19>/mode'

        rtb_BusAssignment2.Data = 1.0;

        // Merge: '<S17>/ Merge 2' incorporates:
        //   Constant: '<S19>/Constant1'
        //   SignalConversion generated from: '<S19>/max_accel'

        e_term = 1.5;
      }
      break;

     case multimodalcbf_IN_stop_and_go:
      if ((multimodalcbf_B.In1_b.Data >= 7.5) && (multimodalcbf_B.In1_bg.Data >=
           (2.0 * multimodalcbf_B.In1_b.Data + 5.0) - 0.1)) {
        multimodalcbf_DW.is_c20_multimodalcbf = multimodalcbf_IN_transition;

        // BusAssignment: '<Root>/Bus Assignment2' incorporates:
        //   Constant: '<S21>/Constant1'
        //   Merge: '<S17>/ Merge 1'
        //   SignalConversion generated from: '<S21>/mode'

        rtb_BusAssignment2.Data = 3.0;

        // MATLAB Function: '<S21>/MATLAB Function'
        e_term = exp((multimodalcbf_B.In1_b.Data - 6.25) * 3.0);

        // Merge: '<S17>/ Merge ' incorporates:
        //   MATLAB Function: '<S21>/MATLAB Function'
        //   SignalConversion generated from: '<S21>/d_min'

        d_min = e_term / (e_term + 1.0) * 10.0 + 5.0;

        // Merge: '<S17>/ Merge 2' incorporates:
        //   Constant: '<S21>/Constant'
        //   SignalConversion generated from: '<S21>/max_accel'

        e_term = 0.5;
      } else {
        // Merge: '<S17>/ Merge ' incorporates:
        //   Constant: '<S20>/d_min_stop_and_go'
        //   SignalConversion generated from: '<S20>/d_min'

        d_min = 5.0;

        // BusAssignment: '<Root>/Bus Assignment2' incorporates:
        //   Constant: '<S20>/Constant'
        //   Merge: '<S17>/ Merge 1'
        //   SignalConversion generated from: '<S20>/mode'

        rtb_BusAssignment2.Data = 2.0;

        // Merge: '<S17>/ Merge 2' incorporates:
        //   Constant: '<S20>/Constant1'
        //   SignalConversion generated from: '<S20>/max_accel'

        e_term = 1.0;
      }
      break;

     default:
      // case IN_transition:
      if (multimodalcbf_B.In1_b.Data <= 5.0) {
        multimodalcbf_DW.is_c20_multimodalcbf = multimodalcbf_IN_stop_and_go;

        // Merge: '<S17>/ Merge ' incorporates:
        //   Constant: '<S20>/d_min_stop_and_go'
        //   SignalConversion generated from: '<S20>/d_min'

        d_min = 5.0;

        // BusAssignment: '<Root>/Bus Assignment2' incorporates:
        //   Constant: '<S20>/Constant'
        //   Merge: '<S17>/ Merge 1'
        //   SignalConversion generated from: '<S20>/mode'

        rtb_BusAssignment2.Data = 2.0;

        // Merge: '<S17>/ Merge 2' incorporates:
        //   Constant: '<S20>/Constant1'
        //   SignalConversion generated from: '<S20>/max_accel'

        e_term = 1.0;
      } else if ((multimodalcbf_B.In1_bg.Data >= (2.0 *
                   multimodalcbf_B.In1_b.Data + 15.0) - 0.1) &&
                 (multimodalcbf_B.In1_b.Data > 5.0)) {
        multimodalcbf_DW.durationCounter_1 = 0U;
        multimodalcbf_DW.is_c20_multimodalcbf = multimodalcbf_IN_nominal;

        // Merge: '<S17>/ Merge ' incorporates:
        //   Constant: '<S19>/d_min_nominal'
        //   SignalConversion generated from: '<S19>/d_min'

        d_min = 15.0;

        // BusAssignment: '<Root>/Bus Assignment2' incorporates:
        //   Constant: '<S19>/Constant'
        //   Merge: '<S17>/ Merge 1'
        //   SignalConversion generated from: '<S19>/mode'

        rtb_BusAssignment2.Data = 1.0;

        // Merge: '<S17>/ Merge 2' incorporates:
        //   Constant: '<S19>/Constant1'
        //   SignalConversion generated from: '<S19>/max_accel'

        e_term = 1.5;
      } else {
        // BusAssignment: '<Root>/Bus Assignment2' incorporates:
        //   Constant: '<S21>/Constant1'
        //   Merge: '<S17>/ Merge 1'
        //   SignalConversion generated from: '<S21>/mode'

        rtb_BusAssignment2.Data = 3.0;

        // MATLAB Function: '<S21>/MATLAB Function'
        e_term = exp((multimodalcbf_B.In1_b.Data - 6.25) * 3.0);

        // Merge: '<S17>/ Merge ' incorporates:
        //   MATLAB Function: '<S21>/MATLAB Function'
        //   SignalConversion generated from: '<S21>/d_min'

        d_min = e_term / (e_term + 1.0) * 10.0 + 5.0;

        // Merge: '<S17>/ Merge 2' incorporates:
        //   Constant: '<S21>/Constant'
        //   SignalConversion generated from: '<S21>/max_accel'

        e_term = 0.5;
      }
      break;
    }
  }

  if (multimodalcbf_B.In1_b.Data <= 5.0) {
    multimodalcbf_DW.durationCounter_1++;
  } else {
    multimodalcbf_DW.durationCounter_1 = 0U;
  }

  // End of Chart: '<S11>/Multimodal CBF'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe4'
  // MATLABSystem: '<S9>/SourceBlock'
  b_varargout_1 = Sub_multimodalcbf_54.getLatestMessage(&rtb_SourceBlock_o2_p_0);

  // Outputs for Enabled SubSystem: '<S9>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S14>/Enable'

  // Start for MATLABSystem: '<S9>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S14>/In1'
    multimodalcbf_B.In1_e = rtb_SourceBlock_o2_p_0;
  }

  // End of Start for MATLABSystem: '<S9>/SourceBlock'
  // End of Outputs for SubSystem: '<S9>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe4'

  // MATLAB Function: '<S23>/MATLAB Function1' incorporates:
  //   Constant: '<S11>/k'
  //   Constant: '<S11>/t_min'

  timegap_accel = ((multimodalcbf_B.In1_bg.Data - 2.0 *
                    multimodalcbf_B.In1_b.Data) - d_min) * 0.05 + 0.5 *
    multimodalcbf_B.In1_e.Data;

  // MATLAB Function: '<S11>/MATLAB Function' incorporates:
  //   MATLAB Function: '<S23>/MATLAB Function1'

  if ((multimodalcbf_B.In1_b.Data <= 0.0) && (timegap_accel <= 0.0)) {
    d_min = timegap_accel - 1.0;
  } else {
    d_min = timegap_accel;
  }

  // MinMax: '<S11>/Min' incorporates:
  //   MATLAB Function: '<S11>/MATLAB Function'
  //   MATLAB Function: '<S23>/MATLAB Function1'

  if (timegap_accel <= e_term) {
    e_term = timegap_accel;
  }

  if ((e_term <= d_min) || rtIsNaN(d_min)) {
    d_min = e_term;
  }

  // End of MinMax: '<S11>/Min'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe6'
  // MATLABSystem: '<S10>/SourceBlock'
  b_varargout_1 = Sub_multimodalcbf_55.getLatestMessage(&rtb_SourceBlock_o2_p_0);

  // Outputs for Enabled SubSystem: '<S10>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S15>/Enable'

  // Start for MATLABSystem: '<S10>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S15>/In1'
    multimodalcbf_B.In1 = rtb_SourceBlock_o2_p_0;
  }

  // End of Start for MATLABSystem: '<S10>/SourceBlock'
  // End of Outputs for SubSystem: '<S10>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe6'

  // MinMax: '<Root>/MinMax'
  if ((d_min <= multimodalcbf_B.In1.Data) || rtIsNaN(multimodalcbf_B.In1.Data))
  {
    e_term = d_min;
  } else {
    e_term = multimodalcbf_B.In1.Data;
  }

  // End of MinMax: '<Root>/MinMax'

  // Saturate: '<Root>/min//max 1.5//-3.0'
  if (e_term < -3.0) {
    // BusAssignment: '<Root>/Bus Assignment1'
    rtb_BusAssignment1.Data = -3.0;
  } else {
    // BusAssignment: '<Root>/Bus Assignment1'
    rtb_BusAssignment1.Data = e_term;
  }

  // End of Saturate: '<Root>/min//max 1.5//-3.0'

  // Outputs for Atomic SubSystem: '<Root>/Publish1'
  // MATLABSystem: '<S4>/SinkBlock'
  Pub_multimodalcbf_49.publish(&rtb_BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Publish1'

  // BusAssignment: '<Root>/Bus Assignment3'
  rtb_BusAssignment3.Data = d_min;

  // Outputs for Atomic SubSystem: '<Root>/Publish3'
  // MATLABSystem: '<S6>/SinkBlock'
  Pub_multimodalcbf_96.publish(&rtb_BusAssignment3);

  // End of Outputs for SubSystem: '<Root>/Publish3'

  // Outputs for Atomic SubSystem: '<Root>/Publish2'
  // MATLABSystem: '<S5>/SinkBlock'
  Pub_multimodalcbf_93.publish(&rtb_BusAssignment2);

  // End of Outputs for SubSystem: '<Root>/Publish2'
}

// Model initialize function
void multimodalcbf_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int32_T i;
    char_T b_zeroDelimTopic_0[16];
    char_T b_zeroDelimTopic_2[14];
    char_T b_zeroDelimTopic[10];
    char_T b_zeroDelimTopic_1[8];
    static const char_T b_zeroDelimTopic_3[10] = "lead_dist";
    static const char_T b_zeroDelimTopic_4[10] = "cmd_accel";
    static const char_T b_zeroDelimTopic_5[28] = "multimodalcbf_debug/cbf_acc";
    static const char_T b_zeroDelimTopic_6[29] = "multimodalcbf_debug/cbf_mode";
    static const char_T b_zeroDelimTopic_7[16] = "car/state/vel_x";
    static const char_T b_zeroDelimTopic_8[8] = "rel_vel";
    static const char_T b_zeroDelimTopic_9[14] = "cmd_accel_pre";

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S7>/SourceBlock'
    multimodalcbf_DW.obj_e.matlabCodegenIsDeleted = false;
    multimodalcbf_DW.obj_e.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_3[i];
    }

    Sub_multimodalcbf_52.createSubscriber(&b_zeroDelimTopic[0], 1);
    multimodalcbf_DW.obj_e.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    multimodalcbf_DW.obj_a.matlabCodegenIsDeleted = false;
    multimodalcbf_DW.obj_a.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_4[i];
    }

    Pub_multimodalcbf_49.createPublisher(&b_zeroDelimTopic[0], 1);
    multimodalcbf_DW.obj_a.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish3'
    // Start for MATLABSystem: '<S6>/SinkBlock'
    multimodalcbf_DW.obj.matlabCodegenIsDeleted = false;
    multimodalcbf_DW.obj.isInitialized = 1;
    for (i = 0; i < 28; i++) {
      multimodalcbf_B.b_zeroDelimTopic_m[i] = b_zeroDelimTopic_5[i];
    }

    Pub_multimodalcbf_96.createPublisher(&multimodalcbf_B.b_zeroDelimTopic_m[0],
      1);
    multimodalcbf_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish3'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish2'
    // Start for MATLABSystem: '<S5>/SinkBlock'
    multimodalcbf_DW.obj_d.matlabCodegenIsDeleted = false;
    multimodalcbf_DW.obj_d.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      multimodalcbf_B.b_zeroDelimTopic[i] = b_zeroDelimTopic_6[i];
    }

    Pub_multimodalcbf_93.createPublisher(&multimodalcbf_B.b_zeroDelimTopic[0], 1);
    multimodalcbf_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // Start for MATLABSystem: '<S8>/SourceBlock'
    multimodalcbf_DW.obj_p.matlabCodegenIsDeleted = false;
    multimodalcbf_DW.obj_p.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_7[i];
    }

    Sub_multimodalcbf_53.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    multimodalcbf_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe4'
    // Start for MATLABSystem: '<S9>/SourceBlock'
    multimodalcbf_DW.obj_m.matlabCodegenIsDeleted = false;
    multimodalcbf_DW.obj_m.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      b_zeroDelimTopic_1[i] = b_zeroDelimTopic_8[i];
    }

    Sub_multimodalcbf_54.createSubscriber(&b_zeroDelimTopic_1[0], 1);
    multimodalcbf_DW.obj_m.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe4'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe6'
    // Start for MATLABSystem: '<S10>/SourceBlock'
    multimodalcbf_DW.obj_n.matlabCodegenIsDeleted = false;
    multimodalcbf_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 14; i++) {
      b_zeroDelimTopic_2[i] = b_zeroDelimTopic_9[i];
    }

    Sub_multimodalcbf_55.createSubscriber(&b_zeroDelimTopic_2[0], 1);
    multimodalcbf_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S10>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe6'
  }
}

// Model terminate function
void multimodalcbf_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  if (!multimodalcbf_DW.obj_e.matlabCodegenIsDeleted) {
    multimodalcbf_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S8>/SourceBlock'
  if (!multimodalcbf_DW.obj_p.matlabCodegenIsDeleted) {
    multimodalcbf_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe4'
  // Terminate for MATLABSystem: '<S9>/SourceBlock'
  if (!multimodalcbf_DW.obj_m.matlabCodegenIsDeleted) {
    multimodalcbf_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe4'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe6'
  // Terminate for MATLABSystem: '<S10>/SourceBlock'
  if (!multimodalcbf_DW.obj_n.matlabCodegenIsDeleted) {
    multimodalcbf_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe6'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Terminate for MATLABSystem: '<S4>/SinkBlock'
  if (!multimodalcbf_DW.obj_a.matlabCodegenIsDeleted) {
    multimodalcbf_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish1'

  // Terminate for Atomic SubSystem: '<Root>/Publish3'
  // Terminate for MATLABSystem: '<S6>/SinkBlock'
  if (!multimodalcbf_DW.obj.matlabCodegenIsDeleted) {
    multimodalcbf_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish3'

  // Terminate for Atomic SubSystem: '<Root>/Publish2'
  // Terminate for MATLABSystem: '<S5>/SinkBlock'
  if (!multimodalcbf_DW.obj_d.matlabCodegenIsDeleted) {
    multimodalcbf_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish2'
}

const char_T* RT_MODEL_multimodalcbf_T::getErrorStatus() const
{
  return (errorStatus);
}

void RT_MODEL_multimodalcbf_T::setErrorStatus(const char_T* const volatile
  aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
