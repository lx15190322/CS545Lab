/*============================================================================
==============================================================================
                      
                              initUserTasks.c
 
==============================================================================
Remarks:

         Functions needed to initialize and link user tasks for the
         simulation

============================================================================*/

// system headers
#include "SL_system_headers.h"

// local headers
#include "SL.h"
#include "SL_user.h"
#include "SL_integrate.h"
#include "SL_common.h"
#include "SL_dynamics.h"
#include "SL_task_servo.h"

// global variables

// local variables
static int user_tasks_initialized = FALSE;

// external functions
extern void toggleSimulatedBaseState(void);


/*****************************************************************************
******************************************************************************
Function Name	: initUserTasks
Date		: June 1999
   
Remarks:

      initialize tasks that are not permanently linked in the simulation
      This replaces the <ltask facility in vxworks -- just that we cannot
      do on-line linking in C.

******************************************************************************
Paramters:  (i/o = input/output)

  none   

*****************************************************************************/
void
initUserTasks(void)
{

  extern void add_sample_task();
  extern void add_min_jerk_task();
  extern void add_draw_task();
  extern void balance_task();

  freezeBase(TRUE);

  // use the true base state from the simulation servo
  toggleSimulatedBaseState();
  //changeRealTime(TRUE);

  add_sample_task();
  add_min_jerk_task();
  add_draw_task();
  add_balance_task();

  if (!real_robot_flag)
    sprintf(initial_user_command,"go0");

}
