/*
 * Copyright (C) 2010-2014 The Paparazzi Team
 *
 * This file is part of paparazzi.
 *
 * paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with paparazzi; see the file COPYING.  If not, write to
 * the Free Software Foundation, 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/** @file modules/digital_cam/gpio_cam_ctrl.h
 *  @brief Digital Camera Control
 *
 * Provides the control of the shutter and the zoom of a digital camera
 * through standard binary IOs of the board.
 *
 * The required initialization (dc_init()) and periodic process.
 */

#ifndef WIFI_CAM_CTRL_H
#define WIFI_CAM_CTRL_H


#include "std.h"
#include "paparazzi.h"
#include <stdio.h>
#include "std.h"

union float_2_byte{
	float value;
	char bytes[4];
};

extern union float_2_byte f2b;

extern void wifi_cam_ctrl_init(void);

/** Periodic */
extern void wifi_cam_ctrl_periodic(void);
extern void time_streamer(void);

extern bool register_shoot_command;
extern bool calculated_target_shot_time;
extern bool tag_image_on_target_rtk;
extern bool tag_next_rtk_msg;
extern bool tagged_image;

extern double register_shoot_command_time;
extern double target_shot_time;
extern double target_rtk_time;

#endif // GPIO_CAM_CTRL_H
