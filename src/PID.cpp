#include "PID.h"
using namespace std;


/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
	d_error = 0;
	i_error = 0;
	p_error = 0;

}

void PID::UpdateError(double cte) {
	d_error = cte - p_error;
	p_error = cte;
	i_error += cte;
}

double PID::TotalError() {
	double output;
  	double max_output = 1.;
  	double min_output = -1.;

  	output = -( Kp * p_error + Ki * i_error + Kd * d_error) ;

  	if (output > max_output) {
  		output = max_output;
  	}
  	if (output < min_output){
  		output = min_output;
  	}
  	return output;
}