#include "advanced_landing.h"
//#include "subsystems/navigation/waypoints.h"
#include "firmwares/fixedwing/nav.h"

#ifdef NAV_ADVANCED_LANDING_APP_DIST
#define NAV_ADVANCED_LANDING_APP_DIST 200
#endif

#ifdef NAV_ADVANCED_LANDING_DIRECTION
#define NAV_ADVANCED_LANDING_DIRECTION 90
#endif

bool advanced_landing_setup(void){
	#ifdef NAV_ADVANCED_LANDING_APP_DIST
	nav_advanced_landing_app_dist = NAV_ADVANCED_LANDING_APP_DIST;
	#endif

	#ifdef NAV_ADVANCED_LANDING_LANDING_DIRECTION
	nav_advanced_landing_direction = NAV_ADVANCED_LANDING_LANDING_DIRECTION * 3.1415 / 180.0;
	#endif
}

bool calc_turning_point(uint8_t home_WP, uint8_t approach_pos, uint8_t target_WP, uint8_t center_WP){
	float rel_pos_x = 0.0, rel_pos_y = 0.0, rel_tar_x = 0.0, rel_tar_y = 0.0, rel_center_x = 0.0, rel_center_y = 0.0;

	rel_pos_x = nav_advanced_landing_app_dist * sinf(nav_advanced_landing_direction);
	rel_pos_y = nav_advanced_landing_app_dist * cosf(nav_advanced_landing_direction);

	WaypointX(approach_pos) = rel_pos_x + WaypointX(home_WP);
	WaypointY(approach_pos) = rel_pos_y + WaypointY(home_WP);

	rel_tar_x = rel_pos_x - 2 * nav_radius * cosf(nav_advanced_landing_direction);
	rel_tar_y = rel_pos_y + 2 * nav_radius * sinf(nav_advanced_landing_direction);

	WaypointX(target_WP) = rel_tar_x + WaypointX(home_WP);
	WaypointY(target_WP) = rel_tar_y + WaypointY(home_WP);

	rel_center_x = rel_pos_x - nav_radius * cosf(nav_advanced_landing_direction);
	rel_center_y = rel_pos_y + nav_radius * sinf(nav_advanced_landing_direction);

	WaypointX(center_WP) = rel_center_x + WaypointX(home_WP);
	WaypointY(center_WP) = rel_center_y + WaypointY(home_WP);
}