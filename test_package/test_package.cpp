/*
Bullet Continuous Collision Detection and Physics Library
Copyright (c) 2003-2007 Erwin Coumans  http://continuousphysics.com/Bullet/
This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, 
including commercial applications, and to alter it and redistribute it freely, 
subject to the following restrictions:
1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

///-----includes_start-----
#include "b3RobotSimulatorClientAPI.h"
#include <stdio.h>

/// This is a Hello World program for running a basic Bullet physics simulation

int main(int argc, char** argv)
{
	b3RobotSimulatorClientAPI* sim = new b3RobotSimulatorClientAPI();
	sim->connect(eCONNECT_DIRECT);
	
	// load urdf
	b3RobotSimulatorLoadFileResults mjcfResults;
	sim->loadMJCF("robot.xml",mjcfResults);
	int robotId = mjcfResults.m_uniqueObjectIds[0];

	printf("Num of joints in robot:%d\n", sim->getNumJoints(robotId));
	/// Do some simulation
	b3Scalar fixedTimeStep = 1./240.;
	sim->setTimeStep(fixedTimeStep);
	///-----stepsimulation_start-----
	for (int i = 0; i < 150; i++)
	{
		sim->stepSimulation();

		
	}

	///-----stepsimulation_end-----
	printf("Disconnecting...\n");

	sim->disconnect();
	
	printf("delete sim\n");
	delete sim;

	printf("exit\n");

}
