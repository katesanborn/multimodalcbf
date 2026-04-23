//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: multimodalcbf.h
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
#ifndef multimodalcbf_h_
#define multimodalcbf_h_
#include "rtwtypes.h"
#include "slros_initialize.h"
#include "multimodalcbf_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <stddef.h>

// Block signals (default storage)
struct B_multimodalcbf_T {
  char_T b_zeroDelimTopic[29];
  char_T b_zeroDelimTopic_m[28];
  SL_Bus_multimodalcbf_std_msgs_Float64 In1;// '<S15>/In1'
  SL_Bus_multimodalcbf_std_msgs_Float64 In1_e;// '<S14>/In1'
  SL_Bus_multimodalcbf_std_msgs_Float64 In1_b;// '<S13>/In1'
  SL_Bus_multimodalcbf_std_msgs_Float64 In1_bg;// '<S12>/In1'
};

// Block states (default storage) for system '<Root>'
struct DW_multimodalcbf_T {
  ros_slroscpp_internal_block_P_T obj; // '<S6>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_d;// '<S5>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_a;// '<S4>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_n;// '<S10>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_m;// '<S9>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_p;// '<S8>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_e;// '<S7>/SourceBlock'
  uint32_T durationCounter_1;          // '<S11>/Multimodal CBF'
  uint8_T is_active_c20_multimodalcbf; // '<S11>/Multimodal CBF'
  uint8_T is_c20_multimodalcbf;        // '<S11>/Multimodal CBF'
};

// Real-time Model Data Structure
struct tag_RTM_multimodalcbf_T {
  const char_T * volatile errorStatus;
  const char_T* getErrorStatus() const;
  void setErrorStatus(const char_T* const volatile aErrorStatus);
};

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_multimodalcbf_T multimodalcbf_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_multimodalcbf_T multimodalcbf_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void multimodalcbf_initialize(void);
  extern void multimodalcbf_step(void);
  extern void multimodalcbf_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_multimodalcbf_T *const multimodalcbf_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S11>/Scope' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'multimodalcbf'
//  '<S1>'   : 'multimodalcbf/Blank Message1'
//  '<S2>'   : 'multimodalcbf/Blank Message2'
//  '<S3>'   : 'multimodalcbf/Blank Message3'
//  '<S4>'   : 'multimodalcbf/Publish1'
//  '<S5>'   : 'multimodalcbf/Publish2'
//  '<S6>'   : 'multimodalcbf/Publish3'
//  '<S7>'   : 'multimodalcbf/Subscribe'
//  '<S8>'   : 'multimodalcbf/Subscribe1'
//  '<S9>'   : 'multimodalcbf/Subscribe4'
//  '<S10>'  : 'multimodalcbf/Subscribe6'
//  '<S11>'  : 'multimodalcbf/Subsystem Reference'
//  '<S12>'  : 'multimodalcbf/Subscribe/Enabled Subsystem'
//  '<S13>'  : 'multimodalcbf/Subscribe1/Enabled Subsystem'
//  '<S14>'  : 'multimodalcbf/Subscribe4/Enabled Subsystem'
//  '<S15>'  : 'multimodalcbf/Subscribe6/Enabled Subsystem'
//  '<S16>'  : 'multimodalcbf/Subsystem Reference/MATLAB Function'
//  '<S17>'  : 'multimodalcbf/Subsystem Reference/Multimodal CBF'
//  '<S18>'  : 'multimodalcbf/Subsystem Reference/base_algorithm'
//  '<S19>'  : 'multimodalcbf/Subsystem Reference/Multimodal CBF/nominal'
//  '<S20>'  : 'multimodalcbf/Subsystem Reference/Multimodal CBF/stop_and_go'
//  '<S21>'  : 'multimodalcbf/Subsystem Reference/Multimodal CBF/transition'
//  '<S22>'  : 'multimodalcbf/Subsystem Reference/Multimodal CBF/transition/MATLAB Function'
//  '<S23>'  : 'multimodalcbf/Subsystem Reference/base_algorithm/cbf_filter'
//  '<S24>'  : 'multimodalcbf/Subsystem Reference/base_algorithm/cbf_filter/MATLAB Function1'

#endif                                 // multimodalcbf_h_

//
// File trailer for generated code.
//
// [EOF]
//
