#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  //parameters for update
  PID::Kp = Kp_;
  PID::Ki = Ki_;
  PID::Kd = Kd_;
  
  //errors for pid update
  PID::p_error = 0.0;
  PID::i_error = 0.0;
  PID::d_error = 0.0;
  
  //save parameter for d_error
  PID::cte_temp = 0.0;
  
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  //p_error update
  PID::p_error = cte;
  //i_error update
  PID::i_error = PID::i_error + cte;
  //d_error update
  PID::d_error = cte-PID::cte_temp;
  
  //save previous cte
  PID::cte_temp = cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  // calculate the error
  return - PID::Kp * PID::p_error - PID::Kd * PID::d_error - PID::Ki * PID::i_error;  
}