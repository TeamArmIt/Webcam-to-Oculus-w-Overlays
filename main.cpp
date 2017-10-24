///////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2017, STEREOLABS.
//
// All rights reserved.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
///////////////////////////////////////////////////////////////////////////

/***********************************************************************************************
** AUTHOR: Saimouli Katragadda 2018

** This code converts oculus roataions into quat and stores into a file					  	  **


***********************************************************************************************/

#include <OVR_CAPI.h>
#include <iostream>
#include "Extras/OVR_Math.h"
#include "OVR_CAPI_D3D.h"
#include <thread>
#include <fstream>

#include <Windows.h>
#include <string>
#include <vector>

#define PI 3.14159

using namespace std;
float yaw, pitch, roll, speed;
float rSpeed, pSpeed, ySpeed;
void HeadTrackingApplication();

int main(void) {
	

	HeadTrackingApplication();
		
	system("pause");
	return 0;
}
 
void HeadTrackingApplication(){
	ofstream myfile;
	myfile.open("headtrackingdata.txt");

	ovrResult result = ovr_Initialize(nullptr);
	if (OVR_FAILURE(result))
		return;

	ovrSession session;
	ovrGraphicsLuid luid;
	result = ovr_Create(&session, &luid);
	if (OVR_FAILURE(result)) {
		ovr_Shutdown();
		return;
	}
	ovrHmdDesc desc = ovr_GetHmdDesc(session);
	ovrSizei resolution = desc.Resolution;

	ovrTrackingState ts;
	ts = ovr_GetTrackingState(session, ovr_GetTimeInSeconds(), ovrTrue);
	//cout << "running app" << endl;
	ovrPosef pose = ts.HeadPose.ThePose;
	ovrQuatf orient = pose.Orientation;

	OVR::Quatf Oculus = pose.Orientation;
	Oculus.GetEulerAngles <OVR::Axis_X, OVR::Axis_Y, OVR::Axis_Z>(&pitch, &yaw, &roll);
	// orientation data
	while (true) {
		ovrTrackingState ts;
		ts = ovr_GetTrackingState(session, ovr_GetTimeInSeconds(), ovrTrue);
		
		if (ts.StatusFlags & (ovrStatus_OrientationTracked | ovrStatus_PositionTracked)){
			ovrPosef pose = ts.HeadPose.ThePose;
			ovrQuatf orient = pose.Orientation;
			OVR::Quatf Oculus = pose.Orientation;
			//Oculus.GetYawPitchpitch;
			Oculus.GetEulerAngles <OVR::Axis_X, OVR::Axis_Y, OVR::Axis_Z> (&pitch,&yaw,&roll);
			pitch = pitch*(180 / PI);
			yaw = yaw*(180 / PI);
			roll = roll*(180 / PI);
			//converting rad to degrees

			//cout << "Orientation data:" << endl;
			cout << "pitch " << pitch << "yaw: "<< yaw<<" roll:"<< roll <<endl;
			
			//cout << "z: " << orient.z << endl;

			//writing to the file 
			//myfile << orient.x << endl;

			rSpeed = roll / 0.01;// to match the speed of the gimbal with the rate of oculus headtracking data 
			pSpeed = pitch / 0.01;
			ySpeed = yaw / 0.01;
			myfile << "A RA("<<roll<<") RS("<< rSpeed <<")" << endl;
			myfile << "A PA(" << pitch << ") PS(" << pSpeed << ")" << endl;
			myfile << "A YA("<<yaw << ") YS("<< ySpeed << ")" << endl;

			this_thread::sleep_for(std::chrono::milliseconds(10));
		}
	}
	ovr_Destroy(session);
	ovr_Shutdown();
}

// 1st value to array 
// 2nd value-1st value  //index 0
// 3rd-2nd value //index 1

